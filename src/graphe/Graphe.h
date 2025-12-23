//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_GRAPHE_H
#define SERVEURCPP_GRAPHE_H
#include "Arete.h"
#include "Pelement.h"
#include "Sommet.h"

/**
 * La classe générique Graphe<S,T> représente un graphe quelconque.
 *
 * T est la nature des informations associées aux sommets
 * et S celle des informations associées aux arêtes.
 *
 * Un graphe est défini par une liste de sommets, par une
 * liste d'arêtes et par un générateur de clefs primaires.
 *
 * @tparam S
 * @tparam T
 */
template <class S, class T>
class Graphe
{
   public:
    Pelement<Sommet<T>>* lSommets;
    Pelement<Arete<S, T>>* lAretes;
    int prochaineClef;

    Graphe()
    {
        lSommets = nullptr;
        lAretes = nullptr;
        prochaineClef = 0;
    }

    /**
     * crée un sommet isolé
     * met à jour prochaineClef
     * @param info
     * @return
     */
    Sommet<T>* creeSommet(const T& info)
    {
        Sommet<T>* nouveauSommet = new Sommet<T>(prochaineClef, info);
        prochaineClef++;

        lSommets = new Pelement<Sommet<T>>(lSommets, nouveauSommet);
        return nouveauSommet;
    }

    /**
     * crée une arête joignant les 2 sommets debut et fin
     *
     * met à jour les champs degre de debut et de fin
     * A l'appel, on suppose que debut et fin sont déjà contenus dans le graphe.
     *
     * L'arête créée contient l'information info.
     *
     * met à jour prochaineClef
     * @param info
     * @param debut
     * @param fin
     * @return
     */
    Arete<S, T>* creeArete(const S& info, Sommet<T>* debut, Sommet<T>* fin)
    {
        Arete<S, T>* nouvelleArete =
            new Arete<S, T>(prochaineClef, info, debut, fin);
        prochaineClef++;
        lAretes = new Pelement<Arete<S, T>>(lAretes, nouvelleArete);
        return nouvelleArete;
    }

    /**
     *
     * @return le nombre de sommets contenus dans le graphe
     */
    int nombreSommets() const { return Pelement<Sommet<T>>::tailleR(lSommets); }

    /**
     *
     * @return  le nombre d'arêtes contenues dans le graphe.
     */
    int nombreAretes() const { return Pelement<Arete<S, T>>::tailleR(lAretes); }

    operator string() const
    {
        ostringstream o;
        o << "Graphe [ prochaine clef = " << prochaineClef;
        o << endl << "Liste sommets : " << endl;
        string chaineSommets = Pelement<Sommet<T>>::toString(lSommets);
        o << chaineSommets;
        o << endl << "Liste aretes : " << endl;
        string chaineAretes = Pelement<Arete<S, T>>::toString(lAretes);

        o << chaineAretes;
        return o.str();
    }

    friend ostream& operator<<(ostream& o, const Graphe& graphe)
    {
        return o << (string)graphe;
    }

   
};

#endif  // SERVEURCPP_GRAPHE_H
