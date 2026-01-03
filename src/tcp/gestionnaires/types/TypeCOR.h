//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_TYPECOR_H
#define SERVEURCPP_TYPECOR_H

// INCLUSIONS

#include <string>

#include "outils/COR/TemplateCOR.h"
#include "types/tcp/messagesReseau/socket/requeteSocket/requeteSocket.h"

// NAMESPACES

using namespace std;
using namespace serv;

class TypeCOR : public TemplateCOR<RequeteSocket, string>
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Constructeur se basant sur le DP composite
     * @param maillonSuivant Prochaine
     */
    TypeCOR(const TypeCOR* maillonSuivant)
        : TemplateCOR<RequeteSocket, string>(maillonSuivant)
    {}

    // GETTERS / SETTERS

    /**
     * Obtient le type que le maillon traite.
     * @return Type traité par le maillon.
     */
    virtual CodeTypeRequete getType() const = 0;

    // METHODES

    bool traitement(const RequeteSocket* entree, string* sortie) const override
    {
        // Prévérification de l'entrée.
        if (entree == nullptr)
            return false;

        return traitementMaillon(entree, sortie);
    }

    /**
     * Détermine si le maillon peut traiter l'entrée.
     * @return Si le type de l'entrée correspond à ce que traite le maillon.
     */
    bool estTraitable(const RequeteSocket* entree) const
    {
        return entree->type == getType();
    }
};


#endif //SERVEURCPP_TYPECOR_H