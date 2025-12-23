//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_AELEMENT_H
#define SERVEURCPP_AELEMENT_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * AElement (pour Ancêtre-Elément) est la classe de base de GElement<T>.
 * Elle permet de factoriser la notion de clef. AElement est donc une classe dont
 * le seul attribut est un entier clef servant de clef primaire.
 */
class AElement
{
   public:
    int clef;
    explicit AElement(const int& clef) : clef(clef) {}
    operator string() const
    {
        ostringstream o;
        o << "AElement [ clef = " << clef << " ]";
        return o.str();
    }

    friend ostream& operator<<(ostream& o, const AElement& a_element)
    {
        return o << (string)a_element;
    }
};

#endif  // SERVEURCPP_AELEMENT_H
