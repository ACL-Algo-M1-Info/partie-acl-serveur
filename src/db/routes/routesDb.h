//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_ROUTESDB_H
#define SERVEURCPP_ROUTESDB_H

// INCLUSIONS

#include <string>

#include "db/db.h"
#include "outils/Singleton/SingletonTemplate.h"
#include "types/tsp/route/route.h"

// NAMESPACES

using namespace std;

class RoutesDb : public Db<string, TypeRoute>, public SingletonTemplate<RoutesDb>
{
    // BINDINGS

    /** Binding singleton. */
    friend class SingletonTemplate;

public:
    // CONSTANTES

    /** Emplacement des fichiers JSON. */
    inline static const string CSV_DIR = "../data/13_routes_CSV";

    // METHODES

protected:

    void _recupererDonnees() override;

public:
    /**
     * Obtient la route depuis le nom des deux villes.
     * @param villeA Ville A.
     * @param villeB Ville B.
     * @return Pointeur de route.
     */
    bool get(const string& villeA, const string& villeB, TypeRoute& sortie);

    /**
     * Formatte une clé.
     * @param A Ville A.
     * @param B Ville B.
     * @return
     */
    static string formatter(const string& A, const string& B)
    {
        return A + "_" + B;
    }
};


#endif //SERVEURCPP_ROUTESDB_H