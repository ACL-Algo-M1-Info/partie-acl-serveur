//
// Created by MEGACHEESEKEBAB on 22/12/2025.
//

#ifndef TPACL_PELEMENT_H
#define TPACL_PELEMENT_H

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#include "../Exceptions/Erreur.h"
#include "../Formes/FormeUtils.h"
using namespace std;

/**
 * Un maillon de la liste chaînée est de type PElement<T>. Il contient 2
 * attributs : un lien vers le maillon suivant; ce lien est noté s. un lien vers
 * la valeur (c'est-à-dire l'information associée à ce maillon). Ce lien est
 * noté v. v est un pointeur vers une instance d'une classe T générique.
 * @tparam T
 */
template <class T>
class PElement
{
   public:
    PElement<T>* s;
    T* v;

    PElement(PElement<T>* s, T* v) : s(s), v(v) {}

    operator string() const
    {
        ostringstream o;
        o << "v = " << v;
        return o.str();
    }

    static int taille(const PElement<T>* l)
    {
        int taille = 0;
        const PElement<T>* it = l;
        while (it != nullptr)
        {
            taille++;
            it = it->s;
        }
        return taille;
    }

    /**
     * Calcule la taille de la liste l
     * @param l
     * @return la taille de la liste l
     */
    static int tailleR(const PElement<T>* l)
    {
        if (l == nullptr)
        {
            return 0;
        }
        return 1 + tailleR(l->s);
    }

    /**
     * Transforme la liste p en string.
     * On suppose que l'opérateur << d'écriture sur un flux est défini pour la
     * classe T.
     * @param p
     * @param debut
     * @param separateur
     * @param fin
     * @return
     */
    static const string toString(const PElement<T>* p, const char* debut = "( ", const char* separateur = ", ", const char* fin = " )")
    {
        ostringstream o;
        const PElement<T>* it = p;
        o << debut;
        // o << endl;
        while (it != nullptr)
        {
            o << *it->v;
            if (it->s != nullptr)
            {
                o << separateur;
                o << endl;
            }
            it = it->s;
        }
        o << fin;
        return o.str();
    }

    /**
     * Insère en ordre la nouvelle valeur a dans la liste l en se servant de la
     * méthode de comparaison estPlusPetitOuEgal. l peut être modifiée par
     * l'appel (d'où le &) On suppose que, avant l'appel, l est ordonnée par
     * ordre croissant (l'ordre est défini par estPlusPetitOuEgal). Après
     * l'appel, l est encore ordonnée.
     * @param a
     * @param l
     * @param estPlusPetitOuEgal
     */
    static void insertionOrdonnee(T* a, PElement<T>*& l, bool (*estPlusPetitOuEgal)(const T* a1, const T* a2))
    {
        if (l == nullptr || estPlusPetitOuEgal(a, l->v))
        {
            l = new PElement<T>(l, a);
        }
        else
        {
            insertionOrdonnee(a, l->s, estPlusPetitOuEgal);
        }
    }

    /**
     * Retire l'élément situé en tête de l et le renvoie.
     * Le premier maillon de l est effacé.
     * l est donc modifiée par l'appel.
     * En sortie l compte un maillon de moins.
     * @param l
     * @return
     */
    static T* depiler(PElement<T>*& l)
    {
        if (l == nullptr)
        {
            throw Erreur("La liste est vide");
        }
        T* res = l->v;
        PElement<T>* temp = l;
        l = l->s;
        delete temp;
        return res;
    }

    /**
     * Retire la 1ère occurrence de a de l si a est présent dans l, sinon ne
     * fait rien. L'élément trouvé v n'est pas effacé mais le maillon le
     * contenant est effacé. La comparaison est faite sur les pointeurs v.
     * @param a
     * @param l
     * @return
     */
    static bool retire(const T* a, PElement<T>*& l)
    {
        if (l == nullptr)
        {
            return false;
        }
        if (a == l->v)
        {
            PElement<T>* temp = l;
            l = l->s;
            delete temp;
            return true;
        }
        return retire(a, l->s);
    }

    /**
     *  Efface tous les maillons de  la liste l mais qui n'efface pas les
     * données *v. En sortie l vaut NULL. Ne fait rien si l vaut NULL à l'appel.
     * @param l
     */
    static void efface1(PElement<T>*& l)
    {
        if (l == nullptr)
        {
            return;
        }

        efface1(l->s);
        delete l;
        l = nullptr;
    }

    /**
     * Efface tous les maillons de  la liste l et toutes les données *v.
     * En sortie l vaut NULL. Ne fait rien si l vaut NULL à l'appel.
     * @param l
     */
    static void efface2(PElement<T>*& l)
    {
        if (l == nullptr)
        {
            return;
        }
        efface2(l->s);
        delete (l->v);
        delete (l);
        l = nullptr;
    }

    /**
     * Réalise une copie de la liste l sans réaliser une copie des données *v.
     * Réalise donc une copie partageant les données *v avec l
     * @param l
     * @return
     */
    static PElement<T>* copie1(PElement<T>* l)
    {
        if (l == nullptr)
        {
            return nullptr;
        }
        return new PElement<T>(copie1(l->s), l->v);
    }

    /**
     * Réalise une copie de la liste l en recopiant toutes les données *v.
     * Réalise donc une copie ne partageant aucune  donnée  avec l.
     * @param l
     * @return
     */
    static PElement<T>* copie2(PElement<T>* l)
    {
        if (l == nullptr)
        {
            return nullptr;
        }
        T* newV = new T(*(l->v));
        return new PElement<T>(copie2(l->s), newV);
    }

    /**
     * réalise une copie de la liste l en recopiant toutes les données *v à
     * l'aide de la méthode  v->copie(). Réalise donc une copie ne partageant
     * aucune  donnée  avec l. Et si la classe T possède la méthode virtuelle
     * copie(), l peut être hétérogène et la méthode copie3 produit une copie de
     * cette liste hétérogène.
     * @param l
     * @return
     */
    static PElement<T>* copie3(PElement<T>* l)
    {
        if (l == nullptr)
        {
            return nullptr;
        }
        T* newV = l->v->copie();
        return new PElement<T>(copie3(l->s), newV);
    }

    /**
     * Recherche si a appartient à l.
     * Renvoie un pointeur sur le maillon de l contenant a. Renvoie NULL si a
     * n'appartient pas à l.
     * @param a
     * @param l
     * @return
     */
    static PElement<T>* appartient(const T* a, PElement<T>* l)
    {
        if (l == nullptr)
        {
            return nullptr;
        }
        if (*a == *(l->v))
        {
            return l;
        }
        return appartient(a, l->s);
    }

    /**
     * recherche dans l le premier élément vérifiant la condition condition.
     * renvoie un pointeur sur le premier  maillon de l vérifiant la condition.
     * Renvoie NULL si aucun maillon ne vérifie la conditon. condition est
     * supposée avoir la signature : bool condition(const T * a)
     * @tparam FONCTEUR
     * @param l
     * @param condition
     * @return
     */
    template <class FONCTEUR>
    static PElement<T>* appartient(PElement<T>* l, const FONCTEUR& condition)
    {
        if (l == nullptr)
        {
            return nullptr;
        }
        if (condition(l->v))
        {
            return l;
        }
        return appartient(l->s, condition);
    }
};

template <class T>
ostream& operator<<(ostream& o, const PElement<T>* p)
{
    return o << PElement<T>::toString(p);
}

inline bool estPlusPetitOuEgal(const double* a1, const double* a2) { return *a1 <= *a2; }

inline bool estPlusPetitOuEgal(const Forme* f1, const Forme* f2) { return *f1 <= *f2; }

inline bool estPlusPetitOuEgal(const string* s1, const string* s2) { return s1->compare(*s2) <= 0; }

#endif  // TPACL_PELEMENT_H
