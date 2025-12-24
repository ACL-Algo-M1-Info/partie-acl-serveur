//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_GRAPHE_H
#define SERVEURCPP_GRAPHE_H
#include "Arete.h"
#include "Pelement.h"
#include "Sommet.h"
#include "foncteurs/FoncteurUtils.h"

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
    /**************************************************************
     **************************************************************
     * TRUCS FACTORISES POUR CONSTRUCTEUR PAR COPIE ET DESTRUCTEUR*
     */
   private:
    /**
     * Méthode privée pour le constructeur par copie et pour l'opérateur
     * d'affectation ! très chiant à faire en deux étapes : 1) Pour chaque
     * sommet de graphe, je copie tous les sommets et je conserve une
     * correspondance avec les anciens dans une liste de paire 2) Pour chaque
     * arete de graphe, on retrouve son début et sa fin sauvegardés dans le
     * dictionnaire, on crée alors une nouvelle arête avec les nouveaux sommets
     * correspondant aux anciens
     * @param graphe
     */
    void copie(const Graphe<S, T>& graphe)
    {
        this->prochaineClef = graphe.prochaineClef;
        this->lAretes = nullptr;
        this->lSommets = nullptr;

        Pelement<pair<Sommet<T>*, Sommet<T>*>>* dicoAncienNouveau = nullptr;
        Pelement<Sommet<T>>* anciensSommets = graphe.lSommets;

        while (anciensSommets != nullptr)
        {
            Sommet<T>* ancienSommet = anciensSommets->v;
            Sommet<T>* nouveauSommet = new Sommet<T>(ancienSommet->clef, ancienSommet->v);

            this->lSommets = new Pelement<Sommet<T>>(this->lSommets, nouveauSommet);
            pair<Sommet<T>*, Sommet<T>*>* paire = new pair<Sommet<T>*, Sommet<T>*>(ancienSommet, nouveauSommet);
            dicoAncienNouveau = new Pelement<pair<Sommet<T>*, Sommet<T>*>>(dicoAncienNouveau, paire);
            anciensSommets = anciensSommets->s;
        }
        // Ici j'ai un dico : { Ancien <--> Nouveau }, pour tout sommet dans
        // graphe

        Pelement<Arete<S, T>>* anciennesAretes = graphe.lAretes;

        while (anciennesAretes != nullptr)
        {
            Arete<S, T>* ancienneArete = anciennesAretes->v;
            Sommet<T>* nouveauDebut = nullptr;
            Sommet<T>* nouvelleFin = nullptr;

            CritereSommetAvecPaire<T> critereDebut(ancienneArete->debut);
            // appartient par à la recherche de la paire qui contient le sommet recherche (le debut de l'ancienne arète)
            Pelement<pair<Sommet<T>*, Sommet<T>*>>* resultatDebut =
                Pelement<pair<Sommet<T>*, Sommet<T>*>>::appartient(dicoAncienNouveau, critereDebut);
            if (resultatDebut != nullptr)
            {
                // si il l'a trouvé, on récupère sa correspondance (le nouveau sommet, c'est à dire le nouveau début de la nouvelle arète)
                nouveauDebut = resultatDebut->v->second;
            }

            CritereSommetAvecPaire<T> critereFin(ancienneArete->fin);
            // et symétriquement..
            Pelement<pair<Sommet<T>*, Sommet<T>*>>* resultatFin = Pelement<pair<Sommet<T>*, Sommet<T>*>>::appartient(dicoAncienNouveau, critereFin);

            if (resultatFin != nullptr)
            {
                nouvelleFin = resultatFin->v->second;
            }
            Arete<S, T>* nouvelleArete = new Arete<S, T>(ancienneArete->clef, ancienneArete->v, nouveauDebut, nouvelleFin);
            this->lAretes = new Pelement<Arete<S, T>>(this->lAretes, nouvelleArete);
            anciennesAretes = anciennesAretes->s;
        }
        Pelement<pair<Sommet<T>*, Sommet<T>*>>::efface2(dicoAncienNouveau);
    }

    /**
     * Méthode privée, sert pour destructeur et opérateur d'affectation !
     */
    void vider()
    {
        Pelement<Sommet<T>>::efface2(lSommets);
        Pelement<Arete<S, T>>::efface2(lAretes);
        this->prochaineClef = 0;
    }

   public:
    Pelement<Sommet<T>>* lSommets;
    Pelement<Arete<S, T>>* lAretes;
    int prochaineClef;

    /**************************************************************
     **************************************************************
     * ************** CONSTRUCTEURS ET DESTRUCTEUR ****************
     */
    /**
     * Constructeur
     */
    Graphe()
    {
        lSommets = nullptr;
        lAretes = nullptr;
        prochaineClef = 0;
    }

    /**
     * Constructeur par copie
     * @param graphe
     */
    Graphe(const Graphe<S, T>& graphe) { copie(graphe); }

    const Graphe<S, T>& operator=(const Graphe<S, T>& graphe)
    {
        if (this != &graphe)
        {
            vider();
            copie(graphe);
        }
        return *this;
    }

    ~Graphe()
    {
        cout << "j'ai ete appele  ouille ouille !!" << endl;
        vider();
    }

    /**************************************************************
     **************************************************************
     * ************************ TOUT LE RESTE *********************
     */
    /**
     * Crée un sommet isolé
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
        Arete<S, T>* nouvelleArete = new Arete<S, T>(prochaineClef, info, debut, fin);
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

    friend ostream& operator<<(ostream& o, const Graphe& graphe) { return o << (string)graphe; }

    /**
     *(TODO POURRAIT OU DEVRAIT ETRE PRIVEE)
     * Construit, pour le sommet sommet, la liste de toutes les associations
     * (voisin de sommet, arête incidente en sommet).
     * De cette liste, on peut donc déduire facilement, par exemple, la liste
     * des voisins de sommet ou encore la liste des arêtes adjacentes à sommet.
     * @param sommet
     * @return
     */
    Pelement<pair<Sommet<T>*, Arete<S, T>*>>* adjacences(const Sommet<T>* sommet) const
    {
        Pelement<pair<Sommet<T>*, Arete<S, T>*>>* listeAssociation = nullptr;

        Pelement<Arete<S, T>>* it = lAretes;

        while (it != nullptr)
        {
            Arete<S, T>* a = it->v;
            Sommet<T>* voisin = nullptr;

            if (sommet == a->debut)
            {
                voisin = a->fin;
            }
            else if (sommet == a->fin)
            {
                voisin = a->debut;
            }

            if (voisin != nullptr)
            {
                pair<Sommet<T>*, Arete<S, T>*>* paire = new pair<Sommet<T>*, Arete<S, T>*>(voisin, a);
                listeAssociation = new Pelement<pair<Sommet<T>*, Arete<S, T>*>>(listeAssociation, paire);
            }
            it = it->s;
        }
        return listeAssociation;
    }

    /**
     * Construit, pour le sommet sommet, la liste de toutes les  arêtes
     * incidentes en sommet.
     * @param sommet
     * @return
     */
    Pelement<Arete<S, T>>* aretesAdjacentes(const Sommet<T>* sommet) const
    {
        Pelement<pair<Sommet<T>*, Arete<S, T>*>>* listeAssociation = adjacences(sommet);
        Pelement<pair<Sommet<T>*, Arete<S, T>*>>* it = listeAssociation;
        Pelement<Arete<S, T>>* listeAretesAdjacentes = nullptr;
        while (it != nullptr)
        {
            pair<Sommet<T>*, Arete<S, T>*>* paire = it->v;

            listeAretesAdjacentes = new Pelement<Arete<S, T>>(listeAretesAdjacentes, paire->second);

            it = it->s;
        }

        Pelement<pair<Sommet<T>*, Arete<S, T>*>>::efface2(listeAssociation);
        return listeAretesAdjacentes;
    }

    /**
     * Construit, pour le sommet sommet, la liste de tous les sommets voisins en
     * sommet.
     * @param sommet
     * @return
     */
    Pelement<Sommet<T>>* voisins(const Sommet<T>* sommet) const
    {
        Pelement<pair<Sommet<T>*, Arete<S, T>*>>* listeAssociation = adjacences(sommet);
        Pelement<Sommet<T>>* listeVoisins = nullptr;

        Pelement<pair<Sommet<T>*, Arete<S, T>*>>* it = listeAssociation;

        while (it != nullptr)
        {
            pair<Sommet<T>*, Arete<S, T>*>* paire = it->v;
            listeVoisins = new Pelement<Sommet<T>>(listeVoisins, paire->first);
            it = it->s;
        }

        Pelement<pair<Sommet<T>*, Arete<S, T>*>>::efface2(listeAssociation);
        return listeVoisins;
    }

    /**
     * Cherche l'arête s1 - s2 ou l'arête s2 - s1 si elle existe
     *
     * DONNEES : s1 et s2 deux sommets quelconques du graphe
     * RESULTATS : l'arête s'appuyant sur s1 et s2 si elle existe, NULL sinon
     *
     * */
    Arete<S, T>* getAreteParSommets(const Sommet<T>* s1, const Sommet<T>* s2) const
    {
        CritereLiaison<S, T> condition(s1, s2);
        Pelement<Arete<S, T>>* res = Pelement<Arete<S, T>>::appartient(lAretes, condition);

        if (res != nullptr)
        {
            return res->v;
        }
        return nullptr;
    }
};

#endif  // SERVEURCPP_GRAPHE_H
