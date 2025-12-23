//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_SOMMET_H
#define SERVEURCPP_SOMMET_H
#include "GElement.h"

/**
 * La classe générique Sommet<T>  représente un sommet dans un graphe.
 * Elle dérive de GElement<T> et contient un seul attribut, degre, qui est un
 * nombre entier représentant le degré du sommet.
 * @tparam T
 */
template <class T>
class Sommet : public GElement<T>
{
   public:
    int degre;
    /**
     * Par défaut, un sommet est créé isolé, donc de degré nul.
     * @param clef
     * @param v
     */
    Sommet(const int& clef, const T& v) : GElement<T>(clef, v), degre(0) {}
    operator string() const
    {
        ostringstream o;
        o << "Sommet [ " << static_cast<GElement<T>>(*this)
          << ", degre = " << degre << " ]";
        return o.str();
    }

    friend ostream& operator<<(ostream& o, const Sommet& sommet)
    {
        return o << (string)sommet;
    }
};

#endif  // SERVEURCPP_SOMMET_H
