//
// Created by MEGACHEESEKEBAB on 06/01/2026.
//

#ifndef SERVEURCPP_CHARGEURGENERIQUEJSON_H
#define SERVEURCPP_CHARGEURGENERIQUEJSON_H
#include "Chargeur.h"
#include "utils/json.h"
using json = nlohmann::json;

template<class T>
class ChargeurGeneriqueJson:public Chargeur<T>
{
public:
    T chargerFichier(ifstream& fichier) const
    {
        json donnees;
        fichier >> donnees;
        return donnees;
    }
};

#endif  // SERVEURCPP_CHARGEURGENERIQUEJSON_H
