//
// Created by maxen on 22/12/2025.
//

#include "instance.h"

// FONCTIONS

// SURCHARGES

Instance::operator string() const
{
    ostringstream o;
    o << "--Instance--" << endl << "n : " << this->n << endl << "m : " << this->m << endl;
    return o.str();
}