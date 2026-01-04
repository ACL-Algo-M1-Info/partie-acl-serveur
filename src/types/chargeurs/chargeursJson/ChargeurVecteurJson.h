//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURVECTEURJSON_H
#define SERVEURCPP_CHARGEURVECTEURJSON_H
#include "ChargeurJsonTemplate.h"
#include "types/vecteur/Vecteur2D.h"

class ChargeurVecteurJson : public ChargeurJsonTemplate<double, Vecteur2D>
{
   protected:
    Vecteur2D creerElement(const json& ligne) override
    {
        double x = ligne["latitude"];
        double y = ligne["longitude"];
        return Vecteur2D(x, y);
    }
};

#endif  // SERVEURCPP_CHARGEURVECTEURJSON_H
