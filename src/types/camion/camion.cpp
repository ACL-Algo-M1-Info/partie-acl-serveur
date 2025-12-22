//
// Created by maxen on 22/12/2025.
//

// INCLUSIONS

#include <ostream>

#include "camion.h"


// FONCTIONS

void Camion::ajouterTache(const int& i, const int& quantite)
{
    // Appending dans le tableau
    this->tabId.push_back(i);

    // Ajout de la quantite au cmax
    this->cmax += quantite;
}

void Camion::ajouterTacheParInstance(const int& i, const Instance& instance)
{
    this->ajouterTache(i, instance.quantites[i]);
}

// SURCHARGES

Camion::operator string() const
{
    ostringstream o;
    o << "--Camion--" << endl << "cmax = " << this->cmax << endl << "tâches : " << this->tabId << endl;
    return o.str();
}

bool Camion::operator==(const Camion& c) const
{
    if (this->cmax != c.cmax)
        return false;

    if (this->tabId != c.tabId)
        return false;

    return true;
}
