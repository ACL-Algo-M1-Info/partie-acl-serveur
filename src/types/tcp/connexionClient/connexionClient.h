//
// Created by remik on 02/01/2026.
//

#ifndef SERVEURCPP_CONNEXIONCLIENT_H
#define SERVEURCPP_CONNEXIONCLIENT_H

// INCLUSIONS

#include <thread>
#include <winsock2.h>

// DEFINES

/** Longueur maximale d'un message. */
#define LONGUEUR_MAX 65536 // 2^16

// NAMESPACES

using namespace std;

namespace serv
{

class ConnexionClient
{
    // VARIABLES
private:

    /** ID client. */
    int _id;

    /** Socket client. */
    SOCKET _sock;

    // CONSTRUCTEUR

public:

    /**
     * Constructeur par défaut de construction d'un interlocuteur client.
     * @param sock Socket.
     * @param id ID client.
     */
    ConnexionClient(SOCKET sock = INVALID_SOCKET, int id = -1)
        : _sock(sock), _id(id)
    {}

    // GETTER / SETTER

    /**
     * Renvoie l'id client.
     * @return ID client.
     */
    int getId() const
    {
        return _id;
    }

    // METHODES

    /**
     * Ferme le socket.
     */
    void fermerSocket() const
    {
        closesocket(_sock);
    }

    // OPERATEURS

    /**
     * Foncteur lancé par le serveur dans la mise en thread.
     * @return
     */
    void operator ()() const;
};

} // serv

#endif //SERVEURCPP_CONNEXIONCLIENT_H