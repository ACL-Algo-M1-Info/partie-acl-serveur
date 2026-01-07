//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include "TypeCORAPI.h"
#include "cor/corUtils.h"
#include "types/tcp/messagesReseau/api/requeteAPI/requeteAPI.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"

void erreurReponseFormat(const RequeteSocket* entree, string* sortie)
{
    *sortie = ReponseSocket<string>(ERREUR_FORMAT_INVALIDE, entree->getIdConversation(), "Format de la requête API invalide").enJson();
}

bool TypeCORAPI::traitementConcret(const RequeteSocket* entree, string* sortie) const
{
    // Succès sur ce maillon.
    if (entree != nullptr && entree->type == getType())
    {
        try
        {
            // Parsing API.
            RequeteAPI api = RequeteAPI(*entree);

            // Lancement commande API.
            bool ret = CORUtils::getInstance()->apiCorRacine->traitement(&api, sortie);

            // Aucune commande trouvée.
            if (!ret)
                *sortie = ReponseSocket<string>(ERREUR_INEXISTANT, entree->getIdConversation(), "La commande n'existe pas").enJson();
        }
        catch (nlohmann::detail::parse_error& e)
        {
            erreurReponseFormat(entree, sortie);
        }
        catch (nlohmann::detail::type_error& e)
        {
            erreurReponseFormat(entree, sortie);
        }

        // Succès.
        return true;
    }

    // Pas un succès.
    return false;
}