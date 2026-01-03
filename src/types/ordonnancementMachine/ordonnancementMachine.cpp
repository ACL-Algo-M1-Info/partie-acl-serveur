//
// Created by maxen on 22/12/2025.
//

// INCLUSIONS

#include <ostream>
#include <sstream>

#include "ordonnancementMachine.h"

// FONCTIONS

void OrdonnancementMachine::ajouterTache(const int& i, const int& pi)
{
    // Appending dans le tableau
    this->tabId.push_back(i);

    // Ajout de la pi au cmax
    this->cmax += pi;
}

void OrdonnancementMachine::ajouterTacheParInstance(const int& i, const Instance& instance)
{
    this->ajouterTache(i, instance.p[i]);
}

// SURCHARGES

OrdonnancementMachine::operator string() const
{
    ostringstream o;
    o << "--OrdonnancementMachine--" << endl << "cmax = " << this->cmax << endl;
    return o.str();
}

bool OrdonnancementMachine::operator==(const OrdonnancementMachine& c) const
{
    if (this->cmax != c.cmax)
        return false;

    if (this->tabId != c.tabId)
        return false;

    return true;
}
