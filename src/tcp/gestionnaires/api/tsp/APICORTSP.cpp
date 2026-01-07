//
// Created by remik on 03/01/2026.
//

// INCLUSIONS

#include <unordered_set>

#include "APICORTSP.h"

#include "db/routes/routesDb.h"
#include "db/villes/villesDb.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"
#include "types/tsp/trajetReponse/trajetReponse.h"
#include "utils/utils.h"

// NAMESPACES

/**
 * Permet de vérifier si les villes sont valides.
 * @param coordonnees Vecteurs de coordonnées.
 * @return Si le nom des villes sont valides.
 */
bool initialiserCoordonnees(const vector<vector<string>>& listeVilles, vector<vector<Coordonnee>>& listeCoordonnees)
{
    VillesDb* vDb = VillesDb::getInstance();

    for (const vector<string>& villes : listeVilles)
    {
        listeCoordonnees.emplace_back();
        vector<Coordonnee>& c = listeCoordonnees.back();

        for (const string& ville : villes)
        {
            Coordonnee coord;

            // Le nom de la ville n'est pas clé dans la db.
            if (!vDb->get(ville, coord))
                return false;

            c.push_back( coord );
        }
    }

    return true;
}

/**
 * Marshall des Graphes* au format [TrajetCamionReponse].
 * Hypothèse : Aucun graphe ne partage une même ville.
 * @param graphes
 * @return
 */
bool produireSolution(const vector<Graphe<double, Coordonnee>*>& graphes, vector<TrajetReponse>& sortie)
{
    RoutesDb* rDb = RoutesDb::getInstance();

    for (Graphe<double, Coordonnee>* graphe : graphes)
    {
        sortie.emplace_back();
        TrajetReponse& reponse = sortie.back();

        // On parcourt les arêtes pour rajouter des objets Route & Coordonnée dans la réponse.

        // Liste des arêtes.
        PElement<Arete<double, Coordonnee>>* iterateurArete = graphe->lAretes;

        // Ajout de la distance totale.
        reponse.distanceTotale = graphe->sommePoids();

        // Parcours implicit pour rajouter les informations des villes & des routes.
        while (iterateurArete != nullptr)
        {
            Arete<double, Coordonnee>* arete = iterateurArete->v;

            double distance = arete->v;

            // L'ordre est inversé parce que ça permet de faire un parcours en insérant que le début dans la liste.
            Coordonnee& debut = arete->debut->v;

            // Ajout de la ville de début. Va progressivement rajouter toutes les villes une unique fois selon l'hypothèse.
            reponse.villes.push_back(debut);

            // TODO récupérer le type de route depuis la db

            // Ajout de l'arête sous forme d'objet route.
            Route r = Route(distance, AUTRE);
            reponse.routes.push_back(r);

            // Itération.
            iterateurArete = iterateurArete->s;
        }
    }

    return true;
}

bool APICORTSP::traitementConcret(const RequeteAPI* entree, string* sortie) const
{
    if (estTraitable(entree))
    {
        // Etape 1 : Parser les arguments
        vector<vector<string>> villes = Utils::jsonVersT<vector<string>>(entree->args[0]);
        vector<vector<Coordonnee>> coords;

        // Vérifier chaque ville (dans la DB) si inexistant, retourner sinon.
        if (!initialiserCoordonnees(villes, coords))
        {
            *sortie = ReponseSocket<string>(ERREUR_FORMAT_INVALIDE, entree->getIdConversation(), "Ville(s) invalide(s)");
            return true;
        }

        // Etape 2 : Créer les graphes depuis chaque vector<Coordonnee>. graphes[i] est le graphe associé au vector coords[i]
        vector<Graphe<double, Coordonnee>> graphes;

        for (vector<Coordonnee>& c : coords)
        {
            graphes.emplace_back();
            Graphe<double, Coordonnee>& g = graphes.back();

            // Init pour chaque graphe pour le vector<Coordonnee> correspondant.
            g.remplirGraphe(c);
        }

        // Etape 3 : Appliquer l'algo pour avoir la solution pour chaque graphe.
        DistanceGeodesiqueCoordonnee calculDistance;
        vector<Graphe<double, Coordonnee>*> solutions;

        for (Graphe<double, Coordonnee>& graphe : graphes)
            solutions.push_back(
                Utils::resoudreTSPComplet(graphe, calculDistance)
            );

        // Etape 4 : Générer la réponse selon le modèle choisi & formatter la réponse pour l'envoi.
        vector<TrajetReponse> reponse;

        if (!produireSolution(solutions, reponse))
        {
            *sortie = ReponseSocket<string>(ERREUR_FORMAT_INVALIDE, entree->getIdConversation(), "Route(s) inexistante(s) entre certaines villes");
            return true;
        }

        *sortie = ReponseSocket<vector<TrajetReponse>>(OK, entree->getIdConversation(), reponse).enJson();

        // Etape 5 : Cleanup.
        for (Graphe<double, Coordonnee>* graphe : solutions)
            delete graphe;

        return true;
    }

    return false;
}