//
// Created by lucas on 22/12/2025.
//

#include "TemplateCOR.h"

template <class E, class S>
bool TemplateCOR<E, S>::traitement(const E* entree, S* sortie) const
{
    if(traitementConcret(entree, sortie)) return true;

    if (suivant != nullptr) return suivant->traitement(entree, sortie);

    return false;
}