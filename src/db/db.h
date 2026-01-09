//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_DB_H
#define SERVEURCPP_DB_H

// INCLUSIONS

#include <map>
#include <mutex>

// NAMESPACES

using namespace std;

template <class K, class V>
class Db
{
    // VARIABLES

private:

    /** Mutex sur le _mappeur. */
    mutex _mappeurMutex;

    /** Empêche les mappings subséquents. */
    bool _mapped = false;

protected:

    /** Mappeur. Thread-safe car readonly. */
    map<K, V> _mappeur;

    // METHODES

    /**
     * Méthode à override pour la récupération des données.
     * Devrait utiliser un objet annexe pour permettre le chargement des données depuis des formats de fichier différents.
     */
    virtual void _recupererDonnees() = 0;

public:

    /**
     * Récupère les données à mapper.
     */
    void recupererDonnees()
    {
        if (_mapped)
            return;

        _recupererDonnees();
        _mapped = true;
    }

    /**
     * Détermine si la DB contient une donnée par sa clé.
     * @param cle Clé.
     * @return Contenance.
     */
    bool contient(const K& cle) const
    {
        return _mappeur.find(cle) != _mappeur.end();
    }

    /**
     * Obtient la taille de la DB
     * @return Taille DB
     */
    int taille() const
    {
        return _mappeur.size();
    }

    /**
     * Récupère une donnée de la base.
     * @param cle Clé à laquelle récupérer la valeur de sortie.
     * @return Objet.
     */
    bool get(const K& cle, V& valeur)
    {
        {   // Lock threadsafe.
            lock_guard lock(_mappeurMutex);

            typename map<K, V>::iterator it = _mappeur.find(cle);

            if (it != _mappeur.end())
            {
                valeur = it->second;
                return true;
            }
        }

        return false;
    }
};

#endif //SERVEURCPP_DB_H