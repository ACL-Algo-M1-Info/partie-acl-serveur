//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include <iostream>

#include "APICOROrdo.h"

#include "algo/algo.h"
#include "types/instance/instance.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"
#include "utils/utils.h"

using namespace std;
using reponse = vector<vector<int>>;

bool APICOROrdo::traitementConcret(const RequeteAPI* entree, string* sortie) const
{
    if (estTraitable(entree))
    {
        //  ORDONNANCEMENT DEPUIS L'ENTREE ICI
        // [n, m, [...pj]]

        int tailleArgs = entree->args.size();

        //Vérification des arguments : au moins le nombre. Il faut au moins 1 argument (soit juste le nombre de camions avec aucune tâche à faire).
        if (tailleArgs < 2)
        {
            // On quitte la requête.
            *sortie = ReponseSocket<string>(ERREUR_FORMAT_INVALIDE, entree->getIdConversation(), "Impossible de résoudre l'ordonnancement si le nombre de machines n'est pas précisé").enJson();
            return true;
        }

        //1re étape : marshalling. On reçoit [n, m, [...pj]] depuis la requête API.
        int m = entree->args[0].get<int>();

        // Parsing du json pour avoir un vector<int>.
        vector<int> intermediaire = Utils::jsonVersT<int>( entree->args[1].get<vector<json>>() );

        // Obtention de la taille n.
        int n = intermediaire.size();

        // On obtient le tableau sous forme C classique.
        int* p = intermediaire.data();

        //2e étape : création de l'objet d'instance.
        Instance instance = Instance(n, m, p);

        //3e étape : lancement de l'algo et obtention des résultats.
        Algo alg = Algo(instance);
        Etat etatRes = alg.algoProgrammationDynamique();

        //4e étape : renvoie des résultats. On doit avoir [[1, 2, 3], [4, ...], ...]
        reponse res;

        for (int i = 0; i < etatRes.m; i++)
        {
            // Ordo actuel.
            const OrdonnancementMachine& ordo = etatRes.ordonnancements[i];

            // Vecteur à retranscrire créé. On peut utiliser le tabId de l'ordo car c'est un vector<int>.
            res.push_back(ordo.tabId);
        }

        *sortie = ReponseSocket<reponse>(OK, entree->getIdConversation(), res).enJson();

        return true;
    }

    return false;
}