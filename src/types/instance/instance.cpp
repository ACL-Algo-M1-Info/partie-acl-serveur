//
// Created by maxen on 22/12/2025.
//

#include "instance.h"

#include "utils/utils.h"

// CONSTRUCTEUR

Instance::Instance(const int& n, const  int& m, int* quantites) : n(n), m(m)
{
    this->quantites = new int[n];
    for (int i = 0; i < n; i++)
    {
        this->quantites[i] = quantites[i];
    }
}

Instance::Instance(const Instance& source) : n(source.n), m(source.m)
{
    this->quantites = new int[n];
    for (int i = 0; i < n; i++)
    {
        this->quantites[i] = source.quantites[i];
    }
}

// FONCTIONS

int Instance::obtenirPmax() const
{
    return Utils::maxArrayInt(this->n, this->quantites);
}

// SURCHARGES

Instance::operator string() const
{
    ostringstream o;
    o << "--Instance--" << endl << "n : " << this->n << endl << "m : " << this->m << endl;
    o << "quantites : " << endl;
    o << "{";
    for (int i = 0; i < this->n; i++)
    {
        o << "  " << quantites[i];
    }
    o << " }" << endl;
    return o.str();
}

bool Instance::operator==(const Instance& instance) const
{

    if (this->m != instance.m)
        return false;

    if (this->n != instance.n)
        return false;

    for (int i = 0; i < this->n; i++)
    {
        if (this->quantites[i] != instance.quantites[i])
            return false;
    }

    return true;
}