//
// Created by maxen on 22/12/2025.
//

#pragma once

// INCLUSIONS

#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

#include "../types/graphe//Graphe.h"
#include "types/instance/instance.h"
#include "utils/json.h"

// USINGS

using namespace std;
using nlohmann::json;

// CLASSES

class Utils
{
   public:
    // FONCTIONS

    /**
     * Retrouve l'entier maximal dans l'array. L'array ne doit pas être vide
     * @param n Taille de l'array > 0
     * @param a Array
     * @return L'entier max dans l'array
     */
    static int maxArrayInt(int n, const int* a);

    /**
     * Parse un vecteur de json en vecteur de T
     * @tparam T Type à récupérer
     * @param v Vecteur de json
     * @return Vecteur de T
     */
    template <class T>
    static vector<T> jsonVersT(vector<json> v)
    {
        vector<T> res;

        for (int i = 0; i < v.size(); i++) res.push_back(v[i].get<T>());

        return res;
    }

    /**
     * Parse un dictionnaire pointant vers du json en dictionnaire, conservant les clés et parsant le json en T
     * @tparam K Type de clé
     * @tparam T Type à récupérer pour les valeurs
     * @param m Map associant des clés K à du json
     * @return Map de clés K et de valeurs T
     */
    template <class K, class T>
    static map<K, T> jsonVersT(map<K, json> m)
    {
        map<K, T> res;

        for (const pair<const K, json>& p : m) res[p.first] = p.second.template get<T>();

        return res;
    }

    /**
     * Trim à gauche d'un string.
     * @param s String à trim.
     */
    static void ltrim(string &s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(),
            [](char ch){ return !isspace(ch); }));
    }

    /**
     * Trim à droite d'un string.
     * @param s String à trim.
     */
    static void rtrim(string &s)
    {
        s.erase(find_if(s.rbegin(), s.rend(),
            [](char ch){ return !isspace(ch); }).base(), s.end());
    }

    /**
     * Trim d'un string.
     * @param s String à trim.
     */
    static void trim(string &s)
    {
        ltrim(s);
        rtrim(s);
    }

    template <class COMPARAISON>
    static void triFusion(int i, int j, Instance& instance, int* tp, COMPARAISON comparaison);

    /**
     * Applique l'ordre de Jackson sur les qi d'une instance
     *
     * @param instance l'instance où l'on veut appliquer l'ordre
     */
    static void triJackson(Instance& instance);

    /**
     * Cherche parmis les parents de i, le plus lointain ancêtre de i (la racine)
     * Possible de le faire en récursif avec cas de base : i == parent[i]
     * @tparam T
     * @param i
     * @param parents
     * @return la racine de i
     */
    template <class T>
    static T trouveRacine(T i, map<T, T>& parents)
    {
        while (i != parents[i])
        {
            i = parents[i];
        }
        return i;
    }
    /**
     * Trouve les racines de a et b
     * Si les deux racines sont différentes, racineB devient le parent de racineA
     * @tparam T
     * @param a
     * @param b
     * @param parents
     */
    template <class T>
    static void unionEnsemble(T a, T b, map<T, T>& parents)
    {
        T racineA = trouveRacine(a, parents);
        T racineB = trouveRacine(b, parents);

        if (racineA != racineB)
        {
            cout << "Le parent de " << racineA << " devient " << racineB << endl;
            parents[racineA] = racineB;
        }
    }
    template <class T>
    static void afficheMap(const map<T, T>& maMap)
    {
        cout << "Map : " << endl;
        typename map<T, T>::const_iterator it;
        for (it = maMap.begin(); it != maMap.end(); ++it)
        {
            cout << "Element " << it->first << " a pour parent " << it->second << endl;
        }
    }

    template <class T>
    static void afficheSet(const set<T>& ensemble)
    {
        cout << "Set : " << endl;
        typename set<T>::const_iterator it;
        cout << "{ ";
        for (it = ensemble.begin(); it != ensemble.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << "}";
    }

    /**
     * HYPOTHESE : le graphe ne contient qu'une liste de sommet
     * Methode utilitaire qui lance toutes les étapes de l'heuristique TSP
     * @tparam S
     * @tparam T
     * @tparam FONCTEURDISTANCE
     * @param graphe
     * @param distance
     * @return
     */
    template <class S, class T, class FONCTEURDISTANCE>
    static Graphe<S, T>* resoudreTSPComplet(Graphe<S, T>& graphe, const FONCTEURDISTANCE& distance)
    {
        graphe.rendreComplet(distance);
        // cout << "Graphe complet" << endl << graphe << endl;
        int nbArete = PElement<Arete<S, T>>::tailleR(graphe.lAretes);
        Graphe<S, T>* acpm = graphe.kruskal();
        PElement<Sommet<T>>* tournee = acpm->TSP();
        Graphe<S, T>* resultat = graphe.construireGrapheTournee(tournee);

        delete acpm;
        PElement<Sommet<T>>::efface1(tournee);
        return resultat;
    }
};
