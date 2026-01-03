//
// Created by lucas on 22/12/2025.
//

#pragma once

#include "InterfTemplateCOR.h"

/**
 * Template d'une chaine de responsabilité
 * @tparam : classe de l'objet d'entrée
 * @tparam : classe de l'objet de sortie
 */
template <class E, class S>
class TemplateCOR : public InterfTemplateCOR<E, S>
{
public:

    const TemplateCOR* suivant;

    /**
     * Constructeur de la COR
     * @param maillonSuivant : pointeur vers le prochain maillon de la chaine
     */
    explicit TemplateCOR(const TemplateCOR* maillonSuivant) : suivant(maillonSuivant){}

    /**
     * Détruit le maillon suivant à la destruction.
     */
    virtual ~TemplateCOR()
    {
        if (suivant != nullptr)
            delete suivant;
    }

    bool traitement(const E* entree, S* sortie) const override
    {
        return traitementMaillon(entree, sortie);
    }

    /**
     * Parcours du chaînage.
     * @param entree : entrée à analyser
     * @param sortie : sortie à renvoyer
     * @return : vrai en cas de réussite du traitement, faux en cas d'échec
     */
    bool traitementMaillon(const E* entree, S* sortie) const
    {
        if(traitementConcret(entree, sortie)) return true;

        if (suivant != nullptr) return suivant->traitementMaillon(entree, sortie);

        return false;
    }

    /**
     * Méthode à implémenter dans les enfants de la classe
     * Représente le traitement concret dans les différents cas détectés par la
     * COR
     * @param entree : entrée à analyser
     * @param sortie : sortie à renvoyer
     * @return : vrai en cas de réussite du traitement, faux en cas d'échec
     */
    virtual bool traitementConcret(const E* entree, S* sortie) const = 0;
};

