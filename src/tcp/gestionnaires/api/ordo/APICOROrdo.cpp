//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include "APICOROrdo.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"

bool APICOROrdo::traitementConcret(const RequeteAPI* entree, string* sortie) const
{
    if (estTraitable(entree))
    {
        // TODO ORDONNANCEMENT DEPUIS L'ENTREE ICI

        *sortie = ReponseSocket<string>(OK, entree->getIdConversation(), "Ordonnancement ici !!!!");

        return true;
    }

    return false;
}