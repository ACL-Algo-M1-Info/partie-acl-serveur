//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_ARETE_H
#define SERVEURCPP_ARETE_H
#include "GElement.h"
#include "Sommet.h"

/**
 * La classe générique Arete<S,T>  représente une arête dans un graphe.
 * Elle dérive de GElement<S> et contient deux attributs :
 * debut : de type Sommet<T>* représentant un pointeur sur l'extrémité initiale
 * de l'arête
 * fin : de type Sommet<T>* représentant un pointeur sur 1'extrémité
 * finale de l'arête.
 * Notons que, puisqu'elle hérite de GElement<S>, l'arête
 * dispose aussi d'un attribut v, instance de la classe générique  S,
 * représentant l'information associée à l'arête.
 * @tparam S
 * @tparam T
 */
template <class S, class T>
class Arete : public GElement<S>
{
   public:
    Sommet<T> *debut;
    Sommet<T> *fin;

    /**
     * Un destructeur est nécessaire puisque la destruction d'une arête entraîne
     * une modification du degré des sommets que cette arête connectait.
     * Il modifie par contre ces deux mêmes arguments puisqu'il augmente leurs
     * degrés respectifs !
     * @param clef
     * @param v
     * @param debut
     * @param fin
     */
    Arete(const int clef, const S &v, Sommet<T> *debut, Sommet<T> *fin)
        : GElement<S>(clef, v), debut(debut), fin(fin)
    {
        if (debut != nullptr)
        {
            debut->degre++;
        }
        if (fin != nullptr)
        {
            fin->degre++;
        }
    }

    /**
     * Un destructeur est nécessaire puisque la destruction d'une arête entraîne
     * une modification du degré des sommets que cette arête connectait.
     */
    ~Arete()
    {
        if (debut != nullptr)
        {
            debut->degre--;
        }
        if (fin != nullptr)
        {
            fin->degre--;
        }
    }

    operator string() const
    {
        ostringstream o;
        o << "Arete [ " << static_cast<GElement<S>>(*this)
          << " Debut : " << debut->clef << " Fin : " << fin->clef << " ]";
        return o.str();
    }
    friend ostream &operator<<(ostream &o, const Arete &arete)
    {
        return o << (string)arete;
    }
    /**
     *
     * vérifie si *this s'appuie sur s1 et s2
     *
     * DONNEES : *this, s1, s2
     *
     * RESULTATS : true si *this s'appuie sur s1 et s2 c'est-à-dire si (début ==
     * s1 et fin == s2) ou (début == s2 et fin == s1), false sinon
     *
     * @param s1
     * @param s2
     * @return
     */
    bool estEgal(const Sommet<T> *s1, const Sommet<T> *s2) const
    {
        return (this->debut == s1 && this->fin == s2) ||
               (this->debut == s2 && this->fin == s1);
    }
};

#endif  // SERVEURCPP_ARETE_H
