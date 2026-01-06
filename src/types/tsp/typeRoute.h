//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_TYPEROUTE_H
#define SERVEURCPP_TYPEROUTE_H

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

#endif //SERVEURCPP_TYPEROUTE_H