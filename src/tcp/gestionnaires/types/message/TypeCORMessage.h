//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_TYPECORMESSAGE_H
#define SERVEURCPP_TYPECORMESSAGE_H

// INCLUSIONS

#include <iostream>

#include "tcp/gestionnaires/types/TypeCOR.h"
#include "types/tcp/messagesReseau/message/requeteMessage/requeteMessage.h"

class TypeCORMessage : public TypeCOR
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    TypeCORMessage(TypeCOR* suivant)
        : TypeCOR(suivant)
    {}

    // GETTER / SETTER

    CodeTypeRequete getType() const override
    {
        return CodeTypeRequete::MESSAGE;
    }

    // METHODES

    bool traitementConcret(const RequeteSocket* entree, string* sortie) const override;
};


#endif //SERVEURCPP_TYPECORMESSAGE_H