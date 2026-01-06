//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_GRAPHE_H
#define SERVEURCPP_GRAPHE_H
#include <map>
#include <set>
#include <vector>
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
    /************************************************************** MÉTHODE PRIVÉE ***************************************************************/
   private:
    /**
     * Méthode privée pour le constructeur par copie et pour l'opérateur
     * d'affectation ! deux étapes :
     * 1) Pour chaque sommet de graphe, je copie tous les sommets et je conserve une
     * correspondance avec les anciens dans une liste de paire
     * 2) Pour chaque arete de graphe, on retrouve son début et sa fin sauvegardés dans le
     * dictionnaire, on crée alors une nouvelle arête avec les nouveaux sommets
     * correspondant aux anciens
     * @param graphe
     */
    void copie(const Graphe<S, T>& graphe)
    {
        typedef pair<Sommet<T>*, Sommet<T>*> DicoAncienNouveau;
        PElement<DicoAncienNouveau>* sommetAncienNouveau = nullptr;
        this->lAretes = nullptr;
        this->lSommets = nullptr;
        PElement<Sommet<T>>* itS = graphe.lSommets;
        this->prochaineClef = graphe.prochaineClef;
        while (itS != nullptr)
        {
            Sommet<T>* ancienSommet = itS->v;
            Sommet<T>* nouveauSommet = new Sommet<T>(ancienSommet->clef, ancienSommet->v);

            DicoAncienNouveau* nouvellePaire = new DicoAncienNouveau(ancienSommet, nouveauSommet);
            sommetAncienNouveau = new PElement<DicoAncienNouveau>(sommetAncienNouveau, nouvellePaire);

            this->lSommets = new PElement<Sommet<T>>(lSommets, nouveauSommet);
            itS = itS->s;
        }

        PElement<Arete<S, T>>* itA = graphe.lAretes;
        while (itA != nullptr)
        {
            PElement<DicoAncienNouveau>* it = sommetAncienNouveau;
            Arete<S, T>* a = itA->v;
            Sommet<T>* nouveauDebut = nullptr;
            Sommet<T>* nouvelleFin = nullptr;
            while (it != nullptr)
            {
                Sommet<T>* ancienSommet = it->v->first;
                if (a->debut == ancienSommet)
                {
                    nouveauDebut = it->v->second;
                }
                if (a->fin == ancienSommet)
                {
                    nouvelleFin = it->v->second;
                }

                if (nouveauDebut != nullptr && nouvelleFin != nullptr)
                {
                    Arete<S, T>* nouvelleArete = new Arete<S, T>(a->clef, a->v, nouveauDebut, nouvelleFin);
                    this->lAretes = new PElement<Arete<S, T>>(lAretes, nouvelleArete);
                    break;
                }
                it = it->s;
            }
            itA = itA->s;
        }
        PElement<DicoAncienNouveau>::efface2(sommetAncienNouveau);
    }

    /**
     * Méthode privée, sert pour destructeur et opérateur d'affectation !
     */
    void vider()
    {
        PElement<Arete<S, T>>::efface2(lAretes);
        PElement<Sommet<T>>::efface2(lSommets);
        this->prochaineClef = 0;
    }

    /**
     * Cherche parmis les parents de i, le plus lointain ancêtre de i (la racine)
     * Possible de le faire en récursif avec cas de base : i == parent[i]
     * @param i
     * @param parents
     * @return la racine de i
     */
    int trouveRacine(int i, map<int, int>& parents)
    {
        while (i != parents[i])
        {
            i = parents[i];
        }
        return i;
    }

   public:
    PElement<Sommet<T>>* lSommets;
    PElement<Arete<S, T>>* lAretes;
    int prochaineClef;

    /************************************************************** CONSTRUCTEURS ET DESTRUCTEUR
     * ***************************************************************/
    /**
     * Constructeur
     */
    Graphe()
    {
        lSommets = nullptr;
        lAretes = nullptr;
        prochaineClef = 0;
    }

    void remplirGraphe(vector<T> sommets)
    {
        for (int i = 0; i < sommets.size(); i++)
        {
            creeSommet(sommets[i]);
        }
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
        // cout << "Destructeur graphe a ete appele ouille ouille !" << endl;
        vider();
    }

    /************************************************************** MÉTHODE EXERCICES ***************************************************************/
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
     * @return la liste contenant les paires adjacentes sommet/arête à sommet (exemple Sommet = A et A connecté à B => paire : < B, A---B >
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
     * @return la liste des arêtes adjacentes à sommet
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
     * @return la liste des voisins
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
    /************************************************************** UTILITAIRES ET MÉTHODE POUR L'HEURISTIQUE
    ***************************************************************/
    /**
     * HYPOTHESE : Le graphe est supposé constitué uniquement d'une liste de sommets
     * Transforme le graphe actuel en graphe complet.
     * Crée une arête entre chaque paire de sommets et effectue le poids de l'arête qui les relie.
     * Si le graphe à n sommets il aura donc (n(n-1))/2 arêtes après l'appel de cette méthode.
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

    /**
     * Algorithme de kruskal :
     * 1) Tous les sommets du graphe seront présents donc on peut les recopier.
     * 2) On tri les arêtes par poids croissant
     * 3) Par chacune des arêtes triées, on l'ajoute à l'ACPM si on ne crée pas de cycle
     * @return l'Arbre couvrant de poids minimum de *this
     */
    Graphe<S, T>* kruskal()
    {
        Graphe<S, T>* ACPM = new Graphe();
        PElement<Sommet<T>>* itS = this->lSommets;
        map<int, Sommet<T>*> correspondance;
        map<int, int> parents;

        // Copie de tous les sommets du graphe dans l'ACPM
        // On en profite pour entretenir une map (utile pour détecter les cycles..)
        while (itS != nullptr)
        {
            Sommet<T>* ancien = itS->v;
            Sommet<T>* nouveau = ACPM->creeSommet(ancien->v);

            // -- Ce bloc a été rajouté pour permettre de retrouver les arêtes à l'aide des identifiants dans le graphe complet
            nouveau->clef = ancien->clef;
            if (nouveau->clef >= ACPM->prochaineClef)
            {
                ACPM->prochaineClef = nouveau->clef + 1;
            }
            // --
            correspondance[ancien->clef] = nouveau;
            parents[ancien->clef] = ancien->clef;
            itS = itS->s;
        }

        PElement<Arete<S, T>>* itA = this->lAretes;
        PElement<Arete<S, T>>* listeAreteTriee = nullptr;

        // La liste des arêtes triées
        while (itA != nullptr)
        {
            PElement<Arete<S, T>>::insertionOrdonnee(itA->v, listeAreteTriee, estPlusPetitOuEgal);
            itA = itA->s;
        }

        PElement<Arete<S, T>>* itListeTriee = listeAreteTriee;
        // Pour chaque arête triée
        // On regarde si l'ajout du sommet debut et fin ne crée pas de cycle
        // Autrement dit si debut et fin ont une racine commune, alors il y a un cycle et donc on ne fait rien
        // Sinon on ajoute l'arête dans l'ACPM
        while (itListeTriee != nullptr)
        {
            Arete<S, T>* a = itListeTriee->v;
            int clefSommetDebut = a->debut->clef;
            int clefSommetFin = a->fin->clef;

            int racineDebut = trouveRacine(clefSommetDebut, parents);
            int racineFin = trouveRacine(clefSommetFin, parents);

            if (racineDebut != racineFin)
            {
                parents[racineDebut] = racineFin;
                Sommet<T>* debut = correspondance[clefSommetDebut];
                Sommet<T>* fin = correspondance[clefSommetFin];
                ACPM->creeArete(a->v, debut, fin);
            }

            itListeTriee = itListeTriee->s;
        }

        PElement<Arete<S, T>>::efface1(listeAreteTriee);
        return ACPM;
    }

    /**
     * Parcours prefixe sur l'ACPM en ne notant les sommets que lors de leur première découverte
     * => cycle eulérien
     * Le parcours récursif simile le passage sur les arêtes dédoublées
     * => cycle eulérien transformé en cyle hamiltonien (en réalité on a bien une ligne droite mais il faut refermer le cycle avec le sommet de
     * depart, charge à l'appelant (c-a-d algo TSP))
     * @param s
     * @param sommetsVisites
     * @param tournee
     */
    void DFS(Sommet<T>* s, set<int>& sommetsVisites, PElement<Sommet<T>>*& tournee)
    {
        sommetsVisites.insert(s->clef);
        tournee = new PElement<Sommet<T>>(tournee, s);
        PElement<Sommet<T>>* lesVoisinsDeS = voisins(s);
        PElement<Sommet<T>>* it = lesVoisinsDeS;

        while (it != nullptr)
        {
            Sommet<T>* voisin = it->v;
            if (sommetsVisites.find(voisin->clef) == sommetsVisites.end())
            {
                DFS(voisin, sommetsVisites, tournee);
            }
            it = it->s;
        }

        PElement<Sommet<T>>::efface1(lesVoisinsDeS);
    }

    /**
     * HYPOTHESE : La méthode est lancée sur un ACPM
     * Méthode principale de l'heuristique TSP
     * Prépare la tournée de sommet et ferme la boucle pour obtenir le cycle hamiltonien
     * @return une tournée <= 2*OPT (et quelques ...)
     */
    PElement<Sommet<T>>* TSP()
    {
        PElement<Sommet<T>>* tournee = nullptr;

        if (lSommets != nullptr)
        {
            set<int> sommetsVisites;
            Sommet<T>* depart = lSommets->v;
            DFS(depart, sommetsVisites, tournee);
            tournee = new PElement<Sommet<T>>(tournee, depart);
        }

        return tournee;
    }

    /**
     * HYPOTHESE : Est lancée sur un graphe complet pour retrouver toutes les arêtes de la tournée
     * (En particulier celle qui permet de fermer le cycle qu'on perd avec l'ACPM)
     * @param tournee
     * @return un graphe qui ne contient que les arêtes de la tournée
     */
    Graphe<S, T>* construireGrapheTournee(PElement<Sommet<T>>* tournee) const
    {
        Graphe<S, T>* resultat = new Graphe<S, T>();
        map<int, Sommet<T>*> correspondance;
        map<int, Sommet<T>*> sommetsDuGrapheComplet;
        PElement<Sommet<T>>* itS = this->lSommets;
        while (itS != nullptr)
        {
            sommetsDuGrapheComplet[itS->v->clef] = itS->v;
            itS = itS->s;
        }

        PElement<Sommet<T>>* it = tournee;
        while (it != nullptr)
        {
            Sommet<T>* sommetACPM = it->v;
            if (correspondance.find(sommetACPM->clef) == correspondance.end())
            {
                Sommet<T>* nouveau = resultat->creeSommet(sommetACPM->v);
                correspondance[sommetACPM->clef] = nouveau;
            }
            it = it->s;
        }

        it = tournee;

        while (it != nullptr && it->s != nullptr)
        {
            Sommet<T>* ancienS1 = it->v;
            Sommet<T>* ancienS2 = it->s->v;

            Sommet<T>* s1Complet = sommetsDuGrapheComplet[ancienS1->clef];
            Sommet<T>* s2Complet = sommetsDuGrapheComplet[ancienS2->clef];

            Arete<S, T>* areteOriginale = getAreteParSommets(s1Complet, s2Complet);
            S poids = 0;
            if (areteOriginale != nullptr)
            {
                poids = areteOriginale->v;
            }
            else
            {
                // Ce cas ne devrait pas arriver car this est complet !!
                cerr << "Il faut lancer cette methode sur un graphe complet .." << endl;
            }
            Sommet<T>* nouveauS1 = correspondance[ancienS1->clef];
            Sommet<T>* nouveauS2 = correspondance[ancienS2->clef];

            resultat->creeArete(poids, nouveauS1, nouveauS2);
            it = it->s;
        }
        return resultat;
    }

    /**
     *
     * @return la somme du poids des arêtes de this
     */
    S sommePoids() const
    {
        S total = 0;
        PElement<Arete<S, T>>* it = lAretes;
        while (it != nullptr)
        {
            total += it->v->v;
            it = it->s;
        }
        return total;
    }
};

#endif  // SERVEURCPP_GRAPHE_H
