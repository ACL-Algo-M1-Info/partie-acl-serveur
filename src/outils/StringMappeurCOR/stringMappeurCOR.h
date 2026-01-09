//
// Created by remik on 09/01/2026.
//

#ifndef SERVEURCPP_TYPEROUTECOR_H
#define SERVEURCPP_TYPEROUTECOR_H

// INCLUSIONS

#include <string>

#include "outils/COR/TemplateCOR.h"

// NAMESPACES

using namespace std;

template <class T>
class StringMappeurCOR : public TemplateCOR<string, T>
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    StringMappeurCOR(StringMappeurCOR* suivant)
        : TemplateCOR<string, T>(suivant)
    {}

    // METHODES

    bool traitementConcret(const string* entree, T* sortie) const
    {
        // Succès.
        if (entree == getNom())
        {
            *sortie = getValeur();

            return true;
        }

        // Sans succès.
        return false;
    }

    /**
     * Obtient le nom associé à la valeur.
     * @return Nom.
     */
    virtual string getNom() const = 0;

    /**
     * Obtient la valeur associée au nom.
     * @return Valeur.
     */
    virtual T getValeur() const = 0;
};


#endif //SERVEURCPP_TYPEROUTECOR_H