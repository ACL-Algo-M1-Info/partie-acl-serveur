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

class RoutesDb : public Db<string, Route>, public SingletonTemplate<RoutesDb>
{
    // BINDINGS

    /** Binding singleton. */
    friend class SingletonTemplate;

    // METHODES

private:

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

public:

    void recupererDonnees() override
    {
        // TODO faire le chargement des routes depuis le json. Stocker les routes dans la map avec l'association A_B comme clé !
    }

    Route* get(const string& villeA, const string& villeB)
    {
        Route* res = Db::get(formatter(villeA, villeB)); // Cherche selon A_B.

        if (res == nullptr)
            res = Db::get(formatter(villeB, villeA)); // Formattage sur B_A si A_B non trouvé.

        return res;
    }
};


#endif //SERVEURCPP_ROUTESDB_H