//
// Created by maxen on 21/12/2025.
//

// INCLUSIONS

#include <sstream>

#include "etat.h"
#include "utils/utils.h"

// FONCTIONS

void Etat::ajouterTacheSurMachine(const int& k, const int& i, const int& quantite)
{
    // On ajoute d'abord la tâche sur la machine pour avoir le nouveau cmax
    OrdonnancementMachine& ordo = this->ordonnancements.at(k);
    ordo.ajouterTache(i, quantite);

    // Recalcul du cmax selon l'ajout fait précédemment
    //this->cmax = Utils::imax(this->camions.at(k).cmax, this->cmax);

    this->cmax = max(ordo.cmax, this->cmax);
}

void Etat::ajouterTacheSurMachineParInstance(const Instance& instance, const int& k, const int& i)
{
    ajouterTacheSurMachine(k, i, instance.p[i]);
}

Etat Etat::getEtatWithMinCmax(const vector<Etat>& etats)
{
    Etat etat = etats.at(0);
    Etat min = etat;

    for (int i = 1; i < etats.size(); i++)
    {
        Etat ei = etats.at(i);
        if (min.cmax > ei.cmax)
            min = ei;
    }

    return min;
}

// SURCHARGES

Etat:: operator string() const
{
    ostringstream o;
    o << "--ETAT--" << endl << "cmax: " << this->cmax << endl << "m : " << this->m << endl;
    o << "Ordonnancements de ETAT : " << endl;
    for (int i = 0; i < this->ordonnancements.size(); i++)
    {
        o << this->ordonnancements.at(i);
    }
    return o.str();
}

bool Etat::operator==(const Etat& source) const
{
    // Egalite des cmax
    if (this->cmax != source.cmax)
        return false;

    // Egalite des m
    if (this->m != source.m)
        return false;

    // Egalite des camions
    if (this->ordonnancements != source.ordonnancements)
        return false;

    return true;
}




