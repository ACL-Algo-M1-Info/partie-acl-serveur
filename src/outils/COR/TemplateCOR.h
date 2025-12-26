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
    const TemplateCOR* suivant;

   public:
    /**
     * Constructeur de la COR
     * @param maillonSuivant : pointeur vers le prochain maillon de la chaine
     */
    explicit TemplateCOR(const TemplateCOR* maillonSuivant) : suivant(maillonSuivant){}

    /**
     * Implémentation de la méthode traitement de l'interface
     * @param entree : entrée à analyser
     * @param sortie : sortie à renvoyer
     * @return : vrai en cas de réussite du traitement, faux en cas d'échec
     */
    bool traitement(const E* entree, S* sortie) const;

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

