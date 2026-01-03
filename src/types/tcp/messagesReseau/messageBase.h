//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_MESSAGEBASE_H
#define SERVEURCPP_MESSAGEBASE_H

namespace serv
{

class MessageBase
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    virtual ~MessageBase() = default;

    // METHODES

    /**
     * Obtention de l'ID de conversation.
     * @return ID de conversation.
     */
    virtual int getIdConversation() const = 0;
};

}

#endif //SERVEURCPP_MESSAGEBASE_H