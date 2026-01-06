//
// Created by MEGACHEESEKEBAB on 06/01/2026.
//

#ifndef SERVEURCPP_CHARGEURGENERIQUEJSON_H
#define SERVEURCPP_CHARGEURGENERIQUEJSON_H
#include "Chargeur.h"
#include "utils/json.h"
using json = nlohmann::json;

template <class T>
class ChargeurGeneriqueJson : public Chargeur<T>
{
   public:
   void chargerFichier(ifstream& fichier, vector<T>& resultat) const
    {
        json donnees;
        fichier >> donnees;
        resultat = donnees;
    }
};

#endif  // SERVEURCPP_CHARGEURGENERIQUEJSON_H
