//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_DB_H
#define SERVEURCPP_DB_H

// INCLUSIONS

#include <map>
#include <string>

#include "outils/Singleton/SingletonTemplate.h"
#include "types/tsp/coordonnee/Coordonnee.h"

// NAMESPACES

using namespace std;

template <class K, class V>
class Db : public SingletonTemplate<Db<K, V>>
{
    // BINDINGS

    /** Binding singleton. */
    friend class SingletonTemplate<Db<K, V>>;

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
     * Récupère une donnée de la base.
     * @param cle Clé à laquelle récupérer la valeur de sortie.
     * @return Objet.
     */
    const V& get(const K& cle) const
    {
        if (contient(cle))
            return mappeur[cle];

        return nullptr;
    }
};

#endif //SERVEURCPP_DB_H