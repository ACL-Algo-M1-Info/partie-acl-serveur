//
// Created by remik on 29/12/2025.
//

#ifndef SERVEURCPP_MESSAGEBASERECU_H
#define SERVEURCPP_MESSAGEBASERECU_H

// INCLUSIONS

#include "exceptions/ErreurFormat/erreurFormat.h"
#include "types/messagesReseau/base/messageBase/messageBase.h"
#include "utils/json.h"

using json = nlohmann::json;

namespace serv
{

template <class DATA>
class MessageBaseRecu : public MessageBase<DATA>
{
public:

    // VARIABLES

    /** Contenu JSON du message initial. */
    string contenu;

    /** JSON obtenu. */
    json message;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Construit un message reçu et parse le contenu. Doit être un json valide.
     * @param contenu Contenu json en string.
     * @throws json::parse_error Erreur de parsing : json invalide.
     */
    MessageBaseRecu(const string& contenu)
        : contenu(contenu)
    {
        // Throws un json::parse_error si invalide.
        message = json::parse(contenu);

        // Structure incorrecte
        if (!messageRespecteStructure())
            throw ErreurFormat("Message au format invalide");

        this->type = message[ MessageBase<DATA>::SEGMENT_TYPE ];
        this->data = message[ MessageBase<DATA>::SEGMENT_DATA ];
    }

    // METHODES

    /**
     * Décrit si le json obtenu est un dictionnaire.
     * @return Si le json parsé est un dictionnaire.
     */
    bool messageEstDictionnaire() const
    {
        return message.is_object();
    }

    /**
     * Détermine si le json obtenu respect a minima la structure attendue {type: string, data: DATA}.
     * @return Si le json parsé respecte la structure minimale.
     */
    bool messageRespecteStructure() const
    {
        return messageEstDictionnaire()
            && message.contains(MessageBase<DATA>::SEGMENT_TYPE)
            && message.contains(MessageBase<DATA>::SEGMENT_DATA);
    }

    // OPERATEURS

    /**
     * Opérateur string
     */
    operator string() const
    {
        return this->contenu;
    }

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const MessageBaseRecu& m)
    {
        return s << (string)m;
    }
};

} // serv

#endif //SERVEURCPP_MESSAGEBASERECU_H