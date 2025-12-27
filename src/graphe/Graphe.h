//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_GRAPHE_H
#define SERVEURCPP_GRAPHE_H
#include "Arete.h"
#include "PElement.h"
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

        typedef pair<Sommet<T>*, Sommet<T>*> DicoAncienNouveau;

        PElement<DicoAncienNouveau>* dicoAncienNouveau = nullptr;
        PElement<Sommet<T>>* anciensSommets = graphe.lSommets;

        while (anciensSommets != nullptr)
        {
            Sommet<T>* ancienSommet = anciensSommets->v;
            Sommet<T>* nouveauSommet = new Sommet<T>(ancienSommet->clef, ancienSommet->v);

            this->lSommets = new PElement<Sommet<T>>(this->lSommets, nouveauSommet);
            DicoAncienNouveau* paire = new DicoAncienNouveau(ancienSommet, nouveauSommet);
            dicoAncienNouveau = new PElement<DicoAncienNouveau>(dicoAncienNouveau, paire);
            anciensSommets = anciensSommets->s;
        }
        // Ici j'ai un dico : { Ancien <--> Nouveau }, pour tout sommet dans
        // graphe

        PElement<Arete<S, T>>* anciennesAretes = graphe.lAretes;

        while (anciennesAretes != nullptr)
        {
            Arete<S, T>* ancienneArete = anciennesAretes->v;
            Sommet<T>* nouveauDebut = nullptr;
            Sommet<T>* nouvelleFin = nullptr;

            CritereSommetAvecPaire<T> critereDebut(ancienneArete->debut);
            // Appartient par à la recherche de la paire qui contient le sommet recherche (le debut de l'ancienne arète)
            PElement<DicoAncienNouveau>* resultatDebut = PElement<DicoAncienNouveau>::appartient(dicoAncienNouveau, critereDebut);
            if (resultatDebut != nullptr)
            {
                // Si il l'a trouvé, on récupère sa correspondance (le nouveau sommet, c'est à dire le nouveau début de la nouvelle arète)
                nouveauDebut = resultatDebut->v->second;
            }

            CritereSommetAvecPaire<T> critereFin(ancienneArete->fin);
            // et symétriquement..
            PElement<DicoAncienNouveau>* resultatFin = PElement<DicoAncienNouveau>::appartient(dicoAncienNouveau, critereFin);

            if (resultatFin != nullptr)
            {
                nouvelleFin = resultatFin->v->second;
            }
            Arete<S, T>* nouvelleArete = new Arete<S, T>(ancienneArete->clef, ancienneArete->v, nouveauDebut, nouvelleFin);
            this->lAretes = new PElement<Arete<S, T>>(this->lAretes, nouvelleArete);
            anciennesAretes = anciennesAretes->s;
        }
        PElement<DicoAncienNouveau>::efface2(dicoAncienNouveau);
    }

    /**
     * Méthode privée, sert pour destructeur et opérateur d'affectation !
     */
    void vider()
    {
        PElement<Sommet<T>>::efface2(lSommets);
        PElement<Arete<S, T>>::efface2(lAretes);
        this->prochaineClef = 0;
    }

   public:
    PElement<Sommet<T>>* lSommets;
    PElement<Arete<S, T>>* lAretes;
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
        cout << "Destructeur graphe a ete appele ouille ouille !" << endl;
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

        lSommets = new PElement<Sommet<T>>(lSommets, nouveauSommet);
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
        lAretes = new PElement<Arete<S, T>>(lAretes, nouvelleArete);
        return nouvelleArete;
    }

    /**
     *
     * @return le nombre de sommets contenus dans le graphe
     */
    int nombreSommets() const { return PElement<Sommet<T>>::tailleR(lSommets); }

    /**
     *
     * @return  le nombre d'arêtes contenues dans le graphe.
     */
    int nombreAretes() const { return PElement<Arete<S, T>>::tailleR(lAretes); }

    operator string() const
    {
        ostringstream o;
        int nbSommets = nombreSommets();
        int nbAretes = nombreAretes();
        o << "Graphe [ prochaine clef = " << prochaineClef << ", nombre de sommet = " << nbSommets << ", nombre d'aretes = " << nbAretes;
        o << endl << "Liste sommets : " << endl;
        string chaineSommets = PElement<Sommet<T>>::toString(lSommets);
        o << chaineSommets;
        o << endl << "Liste aretes : " << endl;
        string chaineAretes = PElement<Arete<S, T>>::toString(lAretes);

        o << chaineAretes << endl << " ]" << endl;
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
    PElement<pair<Sommet<T>*, Arete<S, T>*>>* adjacences(const Sommet<T>* sommet) const
    {
        typedef pair<Sommet<T>*, Arete<S, T>*> PaireSommetArete;
        PElement<PaireSommetArete>* resultat = nullptr;

        PElement<Arete<S, T>>* it = lAretes;

        while (it != nullptr)
        {
            Arete<S, T>* a = it->v;
            Sommet<T>* voisin = nullptr;
            if (a->debut == sommet)
            {
                voisin = a->fin;
            }
            else if (a->fin == sommet)
            {
                voisin = a->debut;
            }

            if (voisin != nullptr)
            {
                PaireSommetArete* nouvellePaire = new PaireSommetArete(voisin, a);
                resultat = new PElement<PaireSommetArete>(resultat, nouvellePaire);
            }
            it = it->s;
        }
        return resultat;
    }

    /**
     * Construit, pour le sommet sommet, la liste de toutes les  arêtes
     * incidentes en sommet.
     * @param sommet
     * @return
     */
    PElement<Arete<S, T>>* aretesAdjacentes(const Sommet<T>* sommet)
    {
        PElement<Arete<S, T>>* listesAretesAdjacentes = nullptr;
        typedef pair<Sommet<T>*, Arete<S, T>*> PaireSommetArete;
        PElement<PaireSommetArete>* paires = adjacences(sommet);

        while (paires != nullptr)
        {
            listesAretesAdjacentes = new PElement<Arete<S, T>>(listesAretesAdjacentes, paires->v->second);
            paires = paires->s;
        }
        PElement<PaireSommetArete>::efface2(paires);
        return listesAretesAdjacentes;
    }

    /**
     * Construit, pour le sommet sommet, la liste de tous les sommets voisins en
     * sommet.
     * @param sommet
     * @return
     */
    PElement<Sommet<T>>* voisins(const Sommet<T>* sommet)
    {
        PElement<Sommet<T>>* listeVoisins = nullptr;
        typedef pair<Sommet<T>*, Arete<S, T>*> PaireSommetArete;
        PElement<PaireSommetArete>* paires = adjacences(sommet);
        while (paires != nullptr)
        {
            listeVoisins = new PElement<Sommet<T>>(listeVoisins, paires->v->first);
            paires = paires->s;
        }
        PElement<PaireSommetArete>::efface2(paires);
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
        PElement<Arete<S, T>>* res = PElement<Arete<S, T>>::appartient(lAretes, condition);

        if (res != nullptr)
        {
            return res->v;
        }
        return nullptr;
    }

    /**
     * Transforme le graphe actuel en graphe complet.
     * Crée une arête entre chaque paire de sommets.
     * Si le graphe à n sommets il aura donc (n(n-1))/2 arêtes après l'appel de cette méthode
     */
    template <class FONCTEURDISTANCE>
    void rendreComplet(const FONCTEURDISTANCE& calculPoids)
    {
        PElement<Sommet<T>>* it1 = lSommets;

        while (it1 != nullptr)
        {
            Sommet<T>* s1 = it1->v;
            PElement<Sommet<T>>* it2 = it1->s;
            while (it2 != nullptr)
            {
                Sommet<T>* s2 = it2->v;

                S poids = calculPoids(s1->v, s2->v);
                creeArete(poids, s1, s2);

                it2 = it2->s;
            }
            it1 = it1->s;
        }
    }
};

#endif  // SERVEURCPP_GRAPHE_H
