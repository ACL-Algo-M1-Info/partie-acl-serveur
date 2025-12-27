//
// Created by lucas on 22/12/2025.
//

#pragma once


/**
 * Template de l'interface que TemplateCOR doit étendre
 * @param : classe de l'objet d'entrée
 * @param : classe de l'objet de sortie
 */
template <class E, class S>
class InterfTemplateCOR {
public:
    /**
     * Methode principale de la COR, permet de parcourt la chaine et de s'arrêter en cas d'aboutissement d'un traitement
     * @param entree : entrée à analyser
     * @param sortie  : sortie à renvoyer
     * @return : vrai en cas de réussite du traitement, faux en cas d'échec
     */
    virtual bool traitement(const E* entree, S* sortie) const = 0;
};