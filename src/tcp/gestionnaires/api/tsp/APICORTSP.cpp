//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include "APICORTSP.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"

bool APICORTSP::traitementConcret(const RequeteAPI* entree, string* sortie) const
{
    if (estTraitable(entree))
    {
        // TODO TSP DEPUIS L'ENTREE ICI

        *sortie = ReponseSocket<string>(OK, entree->getIdConversation(), "TSP ici !!!!");

        return true;
    }

    return false;
}