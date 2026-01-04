//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEUR_H
#define SERVEURCPP_CHARGEUR_H
#include <string>

#include "types/graphe/Graphe.h"
using namespace std;
template <class S, class T>
class Chargeur
{
   public:
    virtual ~Chargeur() = default;

    virtual void charger(const string& chemin, Graphe<S, T>& graphe) = 0;
};

#endif  // SERVEURCPP_CHARGEUR_H
