//
// Created by remik on 29/12/2025.
//

#ifndef SERVEURCPP_MESSAGEBASEREPONSE_H
#define SERVEURCPP_MESSAGEBASEREPONSE_H

// INCLUSIONS

#include <string>

#include "utils/json.h"
#include "../messageBase/messageBase.h"

// NAMESPACES

using json = nlohmann::json;
using namespace std;

namespace serv
{

template <class DATA>
class MessageBaseReponse : public MessageBase<DATA>
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     *
     * @param type
     * @param data
     */
    MessageBaseReponse(const string& type, const DATA& data): MessageBase<DATA>(type, data) {}

    // METHODES

    /**
     * Transforme le message au format JSON.
     * @return Message au format JSON.
     */
    string enJson() const
    {
        // Mise en place du json.
        json j;

        j[ this->SEGMENT_TYPE ] = this->type;
        j[ this->SEGMENT_DATA ] = this->data;

        // Renvoie au format string
        return j.dump();
    }

    // OPERATEURS

    /**
     * Opérateur string.
     */
    operator string() const
    {
        return this->enJson();
    }

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const MessageBaseReponse& m)
    {
        return s << (string)m;
    }
};

} // namespace serv

#endif  // SERVEURCPP_MESSAGEBASEREPONSE_H
