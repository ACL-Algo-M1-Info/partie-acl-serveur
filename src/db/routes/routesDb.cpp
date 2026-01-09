//
// Created by remik on 06/01/2026.
//

// INCLUSIONS

#include "routesDb.h"
#include "types/chargeursGeneriques/ChargeurGeneriqueCsv.h"

/**
 * Lit la matrice dans le csv.
 * @param matrice Matrice de données.
 */
void recuperDonneesParFichier(const vector<vector<string>>& matrice, map<string, TypeRoute>& mappeur)
{
    // Vérifie qu'il existe au moins une ligne d'en-tête.
    if (matrice.empty())
        return;

    // Ligne d'en-tête.
    const vector<string>& ligneVilles = matrice.front();

    // Pour chaque ligne subséquente..;
    for (int i = 1; i < matrice.size(); i++)
    {
        // Première cellule : nom de ville.
        const string& ville = matrice[i][0];

        // Parcours en diagonale.
        for (int j = i + 1; j < ligneVilles.size(); j++)
        {
            const string& autreVille = ligneVilles[j];

            // Obtention de la donnée.
            const string& type = matrice[i][j];

            // Parsing & mise dans le dictionnaire.
            TypeRoute res;
            TypeRouteUtils::obtenirTypeRoute(type, res);

            mappeur[RoutesDb::formatter(ville, autreVille)] = res;
        }
    }
}

void RoutesDb::_recupererDonnees()
{
    // Chargement des routes sous forme d'énumérations. Attend un séparateur ';'.
    ChargeurGeneriqueCsv chargeur = ChargeurGeneriqueCsv(';');

    vector<vector<vector<string>>> fichiers;
    chargeur.chargerDossierAvecSeparation(CSV_DIR, fichiers);

    // Parcours de tous les fichiers.
    for (const vector<vector<string>>& fichier : fichiers)
        // Par fichier.
        recuperDonneesParFichier(fichier, this->_mappeur);
}

bool RoutesDb::get(const string& villeA, const string& villeB, TypeRoute& sortie)
{
    if (Db::get(formatter(villeA, villeB), sortie))
        return true;

    if (Db::get(formatter(villeB, villeA), sortie))
        return true;

    sortie = AUTRE;
    return false;
}