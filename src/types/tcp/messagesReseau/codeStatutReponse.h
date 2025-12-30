//
// Created by remik on 30/12/2025.
//

#ifndef SERVEURCPP_CODESTATUTREPONSE_H
#define SERVEURCPP_CODESTATUTREPONSE_H

// NAMESPACES

namespace serv
{

/**
 * Énumération des codes possibles pour le statut de réponse d'une requête.
 * Se base sur les codes du protocole HTTP.
 */
typedef enum _CodeStatutReponse
{
    /** Code de réponse validant une requête. */
    OK = 200,


} CodeStatutReponse;

} // serv

#endif //SERVEURCPP_CODESTATUTREPONSE_H