//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_GELEMENT_H
#define SERVEURCPP_GELEMENT_H
#include "AElement.h"

/**
 * GElement<T> (pour Graphe-Element) est la classe de base dont héritent les
 * classes Sommet<T> et Arete<S,T> (en fait, Arete<S,T> hérite de GElement<S>).
 * GElement<T> hérite de AElement. *GElement<T> permet de factoriser
 * l'information v présente à la fois dans les classes Sommet<T> et Arete<S,T>.
 * GElement<T> est donc une classe dont le seul attribut est un attribut v (pour
 * valeur) de type T.
 * @tparam T
 */
template <class T>
class GElement : public AElement
{
   public:
    T v;
    GElement(const int& clef, const T& v) : AElement(clef), v(v) {}

    operator string() const
    {
        ostringstream o;
        o << "GElement [ clef = " << clef << ", v = " << v << " ]";
        return o.str();
    }

    friend ostream& operator<<(ostream& o, const GElement& gElement) { return o << (string)gElement; }
};

#endif  // SERVEURCPP_GELEMENT_H
