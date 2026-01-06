//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include "APICORTSP.h"

#include "db/routes/routesDb.h"
#include "db/villes/villesDb.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"

bool APICORTSP::traitementConcret(const RequeteAPI* entree, string* sortie) const
{
    if (estTraitable(entree))
    {
        VillesDb* villesDb = VillesDb::getInstance();
        RoutesDb* routesDb = RoutesDb::getInstance();

        // TODO implémenter
        // Parser les arguments

        // Vérifier chaque ville (dans la DB) si inexistant, retourner

        // Créer le graphe depuis vector<Coordonnée>

        // Appliquer l'algo pour avoir la solution

        // Générer la réponse selon le modèle choisi

        // Renvoyer la réponse

        *sortie = ReponseSocket<string>(OK, entree->getIdConversation(), "TSP ici !!!!");

        return true;
    }

    return false;
}