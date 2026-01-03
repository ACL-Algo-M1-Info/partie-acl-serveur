//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_APICOR_H
#define SERVEURCPP_APICOR_H

// INCLUSIONS

#include "types/tcp/messagesReseau/api/requeteAPI/requeteAPI.h"
#include "outils/COR/TemplateCOR.h"

// NAMESPACES

using namespace std;
using namespace serv;

class APICOR : public TemplateCOR<RequeteAPI, string>
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Constructeur se basant sur le DP composite
     * @param maillonSuivant Prochaine
     */
    APICOR(const APICOR* maillonSuivant)
        : TemplateCOR<RequeteAPI, string>(maillonSuivant)
    {}

    // GETTERS / SETTERS

    /**
     * Obtient la commande API à traiter.
     * @return Commande traitée par le maillon.
     */
    virtual string getAPICommande() const = 0;

    /**
     * Obtient le nombre d'arguments de la commande API à traiter.
     * @return Le nombre d'arguments attendus. Si le nombre est négatif, accepte un nombre infini d'arguments.
     */
    virtual int getNombreArguments() const = 0;

    // METHODES

    bool traitement(const RequeteAPI* entree, string* sortie) const override
    {
        // Prévérification de l'entrée.
        if (entree == nullptr)
            return false;

        return traitementMaillon(entree, sortie);
    }

    /**
     * Détermine si le maillon peut traiter l'entrée.
     * @return Si le type de l'entrée correspond à ce que traite le maillon.
     */
    bool estTraitable(const RequeteAPI* entree) const
    {
        return entree->commande == getAPICommande()
            && (
                getNombreArguments() < 0 // Si getNombreArguments() < 0, nombre infini donc aucune vérification.
                ||
                entree->args.size() == getNombreArguments() // Sinon, il faut un matching de taille sur les arguments.
            );
    }
};


#endif //SERVEURCPP_APICOR_H