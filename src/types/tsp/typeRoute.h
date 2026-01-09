//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_TYPEROUTE_H
#define SERVEURCPP_TYPEROUTE_H

// INCLUSIONS

#include <string>
#include <unordered_map>

// NAMESPACES

using namespace std;

typedef enum _TypeRoute
{
    /** Type autoroute. */
    AUTOROUTE = 31,

    /** Type autre. */
    AUTRE = 0,

    /** Type communal. */
    COMMUNALE = 999,

    /** Type départementale. */
    DEPARTEMENTALE = 752,

    /** Type nationale. */
    NATIONALE = 4,

    /** Type route européenne. */
    ROUTE_EUROPEENNE = 336,

    /** Type voie rapide. */
    VOIE_RAPIDE = 114,

} TypeRoute;

/**
 * Conversion des strings en énumération. Un COR n'a pas été utilisé car c'est une structure lourde pour ce traitement aussi simple.
 * Le principe OCP autorise l'usage de maps pour ce genre de traitement aussi simple.
 */
class TypeRouteUtils
{
    // VARIABLES

    inline static unordered_map<string, TypeRoute> CONVERSION = unordered_map<string, TypeRoute>
    {
        {"Autoroute", AUTOROUTE},
        {"Communale", COMMUNALE},
        {"Départementale", DEPARTEMENTALE},
        {"Nationale", NATIONALE},
        {"Route européenne", ROUTE_EUROPEENNE},
        {"Voie rapide", VOIE_RAPIDE},
    };

    // METHODES
public:

    /**
     * Obtient le type de route selon le string.
     * @param entree
     * @param sortie
     * @return
     */
    static bool obtenirTypeRoute(const string& entree, TypeRoute& sortie)
    {
        unordered_map<string, TypeRoute>::iterator it = CONVERSION.find(entree);

        if (it != CONVERSION.end())
        {
            sortie = it->second;
            return true;
        }

        sortie = AUTRE;
        return false;
    }
};

#endif //SERVEURCPP_TYPEROUTE_H