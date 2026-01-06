//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURCOORDONNEEJSON_H
#define SERVEURCPP_CHARGEURCOORDONNEEJSON_H
#include "../../tsp/coordonnee/Coordonnee.h"
#include "ChargeurJsonTemplate.h"
class ChargeurCoordonneeJson : public ChargeurJsonTemplate<double, Coordonnee>
{
   protected:
    Coordonnee creerElement(const json& ligne) override
    {
        Coordonnee coord = ligne; // Par convertisseur implicite & constructeur par défaut
        return coord;
    }
};

#endif  // SERVEURCPP_CHARGEURCOORDONNEEJSON_H
