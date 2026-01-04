//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURCOORDONNEEJSON_H
#define SERVEURCPP_CHARGEURCOORDONNEEJSON_H
#include "../../coordonnee/Coordonnee.h"
#include "ChargeurJsonTemplate.h"
class ChargeurCoordonneeJson : public ChargeurJsonTemplate<double, Coordonnee>
{
   protected:
    Coordonnee creerElement(const json& ligne) override
    {
        string ville = ligne["ville"];
        double latitude = ligne["latitude"];
        double longitude = ligne["longitude"];
        return Coordonnee(ville, latitude, longitude);
    }
};

#endif  // SERVEURCPP_CHARGEURCOORDONNEEJSON_H
