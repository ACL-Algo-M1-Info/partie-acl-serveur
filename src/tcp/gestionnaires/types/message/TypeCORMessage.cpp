//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include "TypeCORMessage.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"

bool TypeCORMessage::traitementConcret(const RequeteSocket* entree, string* sortie) const
{
    // Succès sur ce maillon.
    if (entree != nullptr && entree->type == getType())
    {
        // Marshalling.
        RequeteMessage message = RequeteMessage(*entree);

        // Affichage dans la console.
        cout << "[MESSAGE]: " << message << endl;

        // Envoi de la réponse.
        *sortie = ReponseSocket<string>(CodeStatutReponse::OK, entree->idConversation, "Imprimé dans la console").enJson();

        // Succès.
        return true;
    }

    // Pas un succès.
    return false;
}