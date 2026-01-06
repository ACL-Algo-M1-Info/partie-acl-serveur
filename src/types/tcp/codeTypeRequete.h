//
// Created by remik on 30/12/2025.
//

#ifndef SERVEURCPP_CODETYPEREQUETE_H
#define SERVEURCPP_CODETYPEREQUETE_H

// NAMESPACES

namespace serv
{

/**
 * Énumération des codes possibles pour le type de requête.
 */
typedef enum _CodeTypeRequete
{
    /** Code de requête API. */
    API = 10,

    /** Code d'impression de message sur le serveur. */
    MESSAGE = 45,

} CodeTypeRequete;

} // serv

#endif //SERVEURCPP_CODETYPEREQUETE_H