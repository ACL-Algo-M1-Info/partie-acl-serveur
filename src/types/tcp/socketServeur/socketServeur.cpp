//
// Created by remik on 02/01/2026.
//

// INCLUSIONS

#include <iostream>
#include <sstream>
#include <ws2tcpip.h>

#include "socketServeur.h"

namespace serv
{

void SocketServeur::accepterRequetes()
{
    // Il faut que le serveur soit connecté.
    if (!this->estConnecte())
        return;

    // Compteur d'ID client.
    int id = 1;

    // Boucle d'attente.
    while (true)
    {
        // On accepte le socket actuel.
        SOCKET sock = accept(this->_socketServeur, NULL, NULL);

        if (sock == INVALID_SOCKET)
        {
            cout << "Impossible d'accepter le socket entrant" << endl;
            continue;
        }

        cout << "Nouvelle connexion d'id " << id << endl;

        // Stockage de l'interlocuteur & mise en thread. Le thread utilise le foncteur de la classe ConnexionClient pour démarrer l'interlocuteur.
        // Attention à l'exclusion mutuelle : quand les sockets se free eux-mêmes !

        {   // Lock sur _clients.
            lock_guard lock(this->_clientsMutex);

            this->_clients[id] = ConnexionClient(sock, id);
        }

        // On enlève le thread.
        {   // Lock sur _threads.
            lock_guard lock(this->_threadMutex);

            this->_threads[id] = thread(this->_clients[id]);
            this->_threads[id].detach();
        }

        id++;
    }
}

bool SocketServeur::adresseEstDisponible(const string& ip, short port)
{
    ostringstream s;
    s << port;
    string portStr = s.str();

    return getaddrinfo(ip.c_str(), portStr.c_str(), NULL, NULL);;
}

void SocketServeur::ecouter(const string& ip, short port)
{
    ostringstream s;

    // Ne peut pas listen s'il listen déjà.
    if (this->estConnecte())
        return;

    // Créé les infos de listen.
    this->_serveurAddresse.sin_family = FAMILLE_ADRESSE;
    this->_serveurAddresse.sin_addr.s_addr = inet_addr(ip.c_str());
    this->_serveurAddresse.sin_port = htons(port);

    // On part du principe que la vérification d'adresse a été gérée au préalable.

    // Liaison de l'adresse.
    int r = bind(this->_socketServeur, (SOCKADDR*) &this->_serveurAddresse, sizeof(this->_serveurAddresse));

    if (r == SOCKET_ERROR)
    {
        s << "Impossible de se lier à l'adresse " << ip << ":" << port;
        throw ErreurSocket(s.str());
    }

    // Ecoute du socket.
    r = listen(this->_socketServeur, SOMAXCONN);

    if (r == SOCKET_ERROR)
    {
        s << "Impossible de listen l'adresse " << ip << ":" << port;
        throw ErreurSocket(s.str());
    }

    cout << "Serveur démarré sur " << ip << ":" << port << endl;

    this->_ip = ip;
    this->_port = port;
}

void SocketServeur::fermerConnexionClient(const ConnexionClient& connexion)
{
    int id = connexion.getId();

    // Fermeture de la socket.
    connexion.fermerSocket();

        {   // Lock sur _clients.
        lock_guard lock(this->_clientsMutex);

        // Suppression du client de la map.
        this->_clients.erase(id);
        }

    // On enlève le thread.
        {   // Lock sur _threads.
        lock_guard lock(this->_threadMutex);

        this->_threads.erase(id);
        }
}

} // serv