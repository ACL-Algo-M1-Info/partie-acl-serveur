//
// Created by remik on 29/12/2025.
//

#ifndef SERVEURCPP_ERREURFORMAT_H
#define SERVEURCPP_ERREURFORMAT_H
#include "exceptions/Erreur.h"


class ErreurFormat : public Erreur
{
public:

    // CONSTRUCTION

    ErreurFormat(const string& msg)
        : Erreur(msg)
    {}
};


#endif //SERVEURCPP_ERREURFORMAT_H