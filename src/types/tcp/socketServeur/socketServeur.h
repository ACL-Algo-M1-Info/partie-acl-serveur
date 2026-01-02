//
// Created by remik on 02/01/2026.
//

#ifndef SERVEURCPP_SOCKETSERVEUR_H
#define SERVEURCPP_SOCKETSERVEUR_H

// INCLUDES

#include <winsock2.h>

namespace serv
{

class SocketServeur
{
public:
    // CONSTANTES

    /** Famille d'adresse. IPv4. */
    const int ADDR_IPV4 = AF_INET;

    /** Type de fonctionnement du socket. Fonctionne en flux. */
    const int TYPE_SOCKET = SOCK_STREAM;

    /** Usage du TCP. */
    const int PROTOCOLE = IPPROTO_TCP;

    // VARIABLES

private:

    /** Socket du serveur. */
    SOCKET _socketServeur;

    /** Données de la librairie winsock2. */
    WSADATA _wsaData;

    /** Décrit si le serveur est connecté. */
    bool _estConnecte = false;

    // CONSTRUCTEUR / DESTRUCTEUR

private:

    /** Constructeur privé. */
    SocketServeur() = default;

    /**  */
    ~SocketServeur()
    {
        // Cleanup de la dll.
        WSACleanup();
    }

public:
};

} // serv

#endif //SERVEURCPP_SOCKETSERVEUR_H