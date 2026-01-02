//
// Created by remik on 02/01/2026.
//

#ifndef SERVEURCPP_ERREURSOCKET_H
#define SERVEURCPP_ERREURSOCKET_H

// INCLUSIONS

#include "exceptions/Erreur.h"


class ErreurSocket : public Erreur
{
public:

    // CONSTRUCTION

    ErreurSocket(const string& msg)
        : Erreur(msg)
    {}
};


#endif //SERVEURCPP_ERREURSOCKET_H