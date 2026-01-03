//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_REQUETEMESSAGE_H
#define SERVEURCPP_REQUETEMESSAGE_H

// INCLUSIONS

#include "types/tcp/messagesReseau/socket/requeteSocket/requeteSocket.h"
#include "utils/json.h"

// NAMESPACES

using namespace std;
using json = nlohmann::json;

namespace serv
{

class RequeteMessage : MessageBase
{
public:

    // VARIABLES

    /** Requête obtenue (précédemment). */
    const RequeteSocket& precedent;

    /** jsonMessage du contenu data. */
    json jsonMessageMessage;

    /** Message. */
    string message;

    // CONSTRUCTEUR / DESTRUCTEUR

    RequeteMessage(const RequeteSocket& requeteInitiale)
        : precedent(requeteInitiale), jsonMessageMessage(requeteInitiale.data)
    {
        this->message = jsonMessageMessage.get<string>();
    }

    // GETTER / SETTER

    int getIdConversation() const override
    {
        return this->precedent.getIdConversation();
    }

    // OPERATEURS

    /**
     * Opérateur string
     */
    operator string() const
    {
        return this->precedent;
    }

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const RequeteMessage& m)
    {
        return s << (string)m;
    }
};

} // serv

#endif //SERVEURCPP_REQUETEMESSAGE_H