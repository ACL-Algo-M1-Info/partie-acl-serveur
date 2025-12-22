//
// Created by maxen on 21/12/2025.
//

// INCLUSIONS

#include "etat.h"

// FONCTIONS

void Etat::ajouterTacheSurMachine(const int& k, const int& i, const int& quantite)
{
    // On ajoute d'abord la tâche sur la machine pour avoir le nouveau cmax
    this->camions.at(k).ajouterTache(i, quantite);

    // Recalcul du cmax selon l'ajout fait précédemment
    //TODO
    // A REECRIRE
}

void Etat::ajouterTacheSurMachineParInstance(const Instance& instance, const int& k, const int& i)
{
    ajouterTacheSurMachine(k, i, instance.quantites[i]);
}

// SURCHARGES

Etat:: operator string() const
{
    ostringstream o;
    o << "--ETAT--" << endl << "lmax: " << this->cmax << endl << "m : " << this->m << endl << "camions: " << this->camions;
    return o.str();
}

bool Etat::operator==(const Etat& source) const
{
    // Egalite des lmax
    //TODO
    // A ENLEVER ?
    if (this->cmax != source.cmax)
        return false;

    // Egalite des m
    if (this->m != source.m)
        return false;

    // Egalite des camions
    if (m != source.m)
        return false;

    if (this->camions != source.camions)
        return false;

    return true;
}




