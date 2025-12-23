//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_FONCTEURUTILS_H
#define SERVEURCPP_FONCTEURUTILS_H
#include "../Formes/FormeUtils.h"
class CritereCouleur
{
   public:
    string couleurRecherchee;
    CritereCouleur(const string& couleurRecherchee)
        : couleurRecherchee(couleurRecherchee)
    {
    }

    bool operator()(const Forme* f)const
    {
        return couleurRecherchee == f->getCouleur();
    }
};

#endif  // SERVEURCPP_FONCTEURUTILS_H
