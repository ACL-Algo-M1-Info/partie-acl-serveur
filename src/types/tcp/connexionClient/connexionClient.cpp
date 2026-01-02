//
// Created by remik on 02/01/2026.
//

#include <iostream>
#include <sstream>
#include <cstring>
#include <chrono>

#include "connexionClient.h"
#include "exceptions/Erreur.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"
#include "types/tcp/messagesReseau/socket/requeteSocket/requeteSocket.h"
#include "types/tcp/socketServeur/socketServeur.h"

// NAMESPACES

using namespace std::chrono;

namespace serv
{

void ConnexionClient::operator ()() const
{
    try
    {
        // Détermine si le socket doit être fermé.
        bool fin = false;

        do
        {
            ostringstream s;

            // Buffer du message à recevoir.
            char buffer[LONGUEUR_MAX];

            // Réception du message.
            int nbOctetsRecus = recv(this->_sock, buffer, LONGUEUR_MAX - 1, 0);

            // Erreur de réception.
            if (nbOctetsRecus == SOCKET_ERROR)
            {
                s << "Impossible de poll le socket " << this->_id;
                throw ErreurSocket(s.str());
            }

            // Déconnexion (flux vide).
            if (nbOctetsRecus == 0)
            {
                fin = true;
                continue;
            }

            // On termine la chaîne par \0 pour utiliser la méthode strchr.
            buffer[nbOctetsRecus] = '\0';

            // On cherche \r.
            char* p = strchr(buffer, '\r');

            // Si \r trouvé, on coupe la chaîne à *p.
            if (p)
                *p = '\0';

            // Sinon, on relocalise à la toute fin de la chaine reçue.
            else
                p = buffer + nbOctetsRecus;

            // Ainsi, la variable p pointe vers le '\0' de la chaîne. On peut donc en déduire la taille de la chaîne SANS \0:
            int len = p - buffer; // Sans \0 !

            cout << "Message \"" << buffer << "\" reçu sur le socket " << this->_id << " (d'une longueur " << len << ")" << endl;

            // Conversion du message obtenu en string puis en objet spécialisé.
            string recuStr(buffer, len);
            string reponseStr;

            try
            {
                // On parse le message. Throws une erreur si parsing invalide.
                RequeteSocket recu = RequeteSocket(recuStr);

                // Traitement par la COR.
                bool succes = false; // TODO écrire le COR

                // Si pas de succès, alors il faut envoyer une erreur disant que le traitement demandé n'existe pas.
                if (!succes)
                {
                    reponseStr = ReponseSocket<string>(CodeStatutReponse::ERREUR_INEXISTANT, recu.idConversation, "La ressource demandée n'existe pas").enJson();
                }
            }
            catch (exception& e)
            {
                cerr << "Erreur sur l'interlocuteur " << _id << " : " << e.what() << endl;

                // En cas d'erreur, envoi d'une erreur automatique : source inconnue. L'id client 0 signale une erreur au client.
                reponseStr = ReponseSocket<string>(CodeStatutReponse::ERREUR_INTERNE, 0, "Une erreur interne s'est produite").enJson();
            }

            // Calcul des tailles.
            int lenReponseAEnvoyer = (int)reponseStr.length() + 2; // Taille de la réponse (sans \0) avec \r\n en fin.

            // Postfixage de reponseStr
            reponseStr = reponseStr + "\r\n";

            // Envoi sur le réseau
            cout << "Réponse envoyée : \"" << reponseStr << "\" pour le socket " << this->_id << " (d'une longueur " << lenReponseAEnvoyer << ")" << endl;

            // On renvoie la réponse. Si la réponse n'a pas pu être envoyée, on crash la connexion.
            if (send(this->_sock, reponseStr.c_str(), lenReponseAEnvoyer, 0) == SOCKET_ERROR)
                throw ErreurSocket("Envoi de réponse impossible");

            // Sleep périodique.
            this_thread::sleep_for(milliseconds(5));
        }
        while (!fin);
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

    cout << "Déconnexion de la socket d'id " << this->_id << endl;

    // Fermeture du socket auprès du serveur.
    SocketServeur::getInstance()->fermerConnexionClient(*this);
}

} // serv