//
// Created by remik on 02/01/2026.
//

#ifndef SERVEURCPP_SOCKETSERVEUR_H
#define SERVEURCPP_SOCKETSERVEUR_H

// INCLUDES

#include <string>
#include <thread>
#include <winsock2.h>
#include <map>
#include <mutex>

#include "exceptions/erreurSocket/erreurSocket.h"
#include "outils/Singleton/SingletonTemplate.h"
#include "tcp/connexionClient/connexionClient.h"

// DEFINES

/** Nombre maximal de clients. */
#define CLIENTS_MAX 50

// NAMESPACES

using namespace std;

namespace serv
{

class SocketServeur : public SingletonTemplate<SocketServeur>
{
    // BINDINGS

    /** Binding singleton. */
    friend class SingletonTemplate<SocketServeur>;

public:
    // CONSTANTES

    /** Famille d'adresse. IPv4. */
    const int FAMILLE_ADRESSE = AF_INET;

    /** Type de fonctionnement du socket. Fonctionne en flux. */
    const int TYPE_SOCKET = SOCK_STREAM;

    /** Usage du TCP. */
    const int PROTOCOLE = IPPROTO_TCP;

    // VARIABLES

private:

    /** Interlocuteurs pour chaque client. */
    map<int, ConnexionClient> _clients;

    /** Mutex pour la manipulation du dictionnaire des clients. */
    mutex _clientsMutex;

    /** IP à laquelle le serveur est connecté. */
    string _ip;

    /** Port auquel le serveur est connecté. -1 si non assigné. */
    short _port = -1;

    /** Structure d'adresse du serveur. */
    SOCKADDR_IN _serveurAddresse;

    /** Socket du serveur. */
    SOCKET _socketServeur;

    /** Stockage des threads. */
    map<int, thread> _threads;

    /** Mutex pour la manipulation du dictionnaire des threads. */
    mutex _threadMutex;

    /** Données de la librairie winsock2. */
    WSADATA _wsaData;

    // CONSTRUCTEUR / DESTRUCTEUR

    /** Constructeur privé. */
    SocketServeur()
    {
        // Démarrage WSA.
        if (WSAStartup(MAKEWORD(2, 0), &_wsaData))
            throw ErreurSocket("Impossible d'initialiser winsock2");

        // Démarrage socket
        _socketServeur = socket(FAMILLE_ADRESSE, TYPE_SOCKET, PROTOCOLE);

        if (_socketServeur == INVALID_SOCKET)
            throw ErreurSocket("Impossible de créer le socket");
    }

    /** Destructeur déliant la librairie winsock2. */
    ~SocketServeur()
    {
        // Cleanup de la dll.
        WSACleanup();
    }

    // GETTER / SETTER

public:

    /**
     * Décrit si le server est connecté.
     * @return L'état de connexion du serveur.
     */
    bool estConnecte() const
    {
        return _port >= 0;
    }

    /**
     * Obtention de l'adresse IP.
     * @return Adresse IP. Chaîne vide si le serveur n'est pas connecté.
     */
    string getAdresseIp() const
    {
        return _ip;
    }

    /**
     * Obtention du port.
     * @return Port. -1 si le serveur n'est pas connecté.
     */
    short getPort() const
    {
        return _port;
    }

    // METHODES

    /**
     * Accepte successivement les requêtes
     */
    virtual void accepterRequetes();

    /**
     * Détermine si l'adresse IP & le port est disponible.
     * @param ip IP à vérifier.
     * @param port Port à vérifier.
     * @return Disponibilité de ip:port.
     */
    static bool adresseEstDisponible(const string& ip, short port);

    /**
     * Écoute l'association ip:port pour de nouvelles connexions.
     * @param ip IP à laquelle se conneter.
     * @param port Port auquel se connecter.
     */
    void ecouter(const string& ip, short port);

    /**
     * Ferme une connexion client.
     * @param connexion Connexion client à fermer.
     */
    void fermerConnexionClient(const ConnexionClient& connexion);
};

} // serv

#endif //SERVEURCPP_SOCKETSERVEUR_H