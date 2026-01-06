//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_DB_H
#define SERVEURCPP_DB_H

// INCLUSIONS

#include <map>

// NAMESPACES

using namespace std;

template <class K, class V>
class Db
{
protected:

    // VARIABLES

    /** Mappeur. */
    map<K, V> mappeur;

public:

    // METHODES

    /**
     * Récupère les données à mapper.
     */
    virtual void recupererDonnees() = 0;

    /**
     * Détermine si la DB contient une donnée par sa clé.
     * @param cle Clé.
     * @return Contenance.
     */
    bool contient(const K& cle) const
    {
        return mappeur.find(cle) != mappeur.end();
    }

    /**
     * Obtient la taille de la DB
     * @return Taille DB
     */
    int taille() const
    {
        return mappeur.size();
    }

    /**
     * Récupère une donnée de la base.
     * @param cle Clé à laquelle récupérer la valeur de sortie.
     * @return Objet.
     */
    V* get(const K& cle)
    {
        if (contient(cle))
            return &mappeur[cle];

        return nullptr;
    }
};

#endif //SERVEURCPP_DB_H