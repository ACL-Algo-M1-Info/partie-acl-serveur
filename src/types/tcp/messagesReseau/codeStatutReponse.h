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

    /** Code de réponse de ressource inexistante. */
    ERREUR_INEXISTANT = 404,

    /** Code de réponse d'erreur interne. */
    ERREUR_INTERNE = 500,
} CodeStatutReponse;

} // serv

#endif //SERVEURCPP_CODESTATUTREPONSE_H