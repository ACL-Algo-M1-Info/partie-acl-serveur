//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#include <assert.h>

#include "../src/types/chargeurs/chargeursJson/ChargeurCoordonneeJson.h"
#include "../src/types/chargeurs/chargeursJson/ChargeurJsonTemplate.h"
#include "../src/types/chargeurs/chargeursJson/ChargeurVecteurJson.h"
#include "types/chargeurs/ChargeurDossier.h"
#include "types/chargeurs/chargeursTxt/ChargeurCoordonneeTexte.h"
#include "types/chargeurs/chargeursTxt/ChargeurVecteurTexte.h"

void afficheSucces(const string &nom) { cout << "Les test de " << nom << " se sont bien deroules !" << endl; }
int main()
{
    {
        cout << "*********************************** TEST CHARGEMENT JSON COORDONNEE **************************************" << endl;
        ChargeurCoordonneeJson chargeur_coordonnee_json;
        Graphe<double, Coordonnee> graphe;
        chargeur_coordonnee_json.charger("../data/fichiersJson/Meurthe-Et-Moselle.json", graphe);
        // cout << "Le graphe charge = " << graphe << endl;
        assert(PElement<Sommet<Coordonnee>>::taille(graphe.lSommets) == 4);
        assert((PElement<Arete<double, Coordonnee>>::taille(graphe.lAretes)) == 0);
        assert(graphe.prochaineClef == 4);
        assert(graphe.lSommets->v->v.ville == "Doncourt-les-conflans");
        afficheSucces("TEST CHARGEMENT JSON COORDONNEE");
    }
    {
        cout << "*********************************** TEST CHARGEMENT JSON VECTEUR **************************************" << endl;
        ChargeurVecteurJson chargeur_vecteur_json;
        Graphe<double, Vecteur2D> graphe;
        chargeur_vecteur_json.charger("../data/fichiersJson/Meurthe-Et-Moselle.json", graphe);
        // cout << "Le graphe charge = " << graphe << endl;
        assert(PElement<Sommet<Vecteur2D>>::taille(graphe.lSommets) == 4);
        assert((PElement<Arete<double, Vecteur2D>>::taille(graphe.lAretes)) == 0);
        assert(graphe.prochaineClef == 4);
        assert(graphe.lSommets->v->v.x == 10);
        afficheSucces("TEST CHARGEMENT JSON VECTEUR");
    }
    {
        cout << "*********************************** TEST CHARGEMENT TEXTE COORDONNEE **************************************" << endl;
        ChargeurCoordonneeTexte chargeur_coordonnee_texte;
        Graphe<double, Coordonnee> graphe;
        chargeur_coordonnee_texte.charger("../data/FichiersTexte/Meurthe-Et-Moselle.txt", graphe);
        // cout << "Le graphe charge = " << graphe << endl;
        assert(PElement<Sommet<Coordonnee>>::taille(graphe.lSommets) == 4);
        assert((PElement<Arete<double, Coordonnee>>::taille(graphe.lAretes)) == 0);
        assert(graphe.prochaineClef == 4);
        assert(graphe.lSommets->s->v->v.ville == "Labry");
        afficheSucces("TEST CHARGEMENT TEXTE COORDONNEE");
    }
    {
        cout << "*********************************** TEST CHARGEMENT TEXTE VECTEUR **************************************" << endl;
        ChargeurVecteurTexte chargeur_vecteur_texte;
        Graphe<double, Vecteur2D> graphe;
        chargeur_vecteur_texte.charger("../data/FichiersTexte/Meurthe-Et-Moselle.txt", graphe);
        // cout << "Le graphe charge = " << graphe << endl;
        assert(PElement<Sommet<Vecteur2D>>::taille(graphe.lSommets) == 4);
        assert((PElement<Arete<double, Vecteur2D>>::taille(graphe.lAretes)) == 0);
        assert(graphe.prochaineClef == 4);
        assert(graphe.lSommets->v->v.x == 10);
        afficheSucces("TEST CHARGEMENT TEXTE VECTEUR");
    }
    {
        cout << "*********************************** TEST CHARGEMENT DOSSIER JSON COORDONNEE **************************************" << endl;
        ChargeurCoordonneeJson chargeur_coordonnee_json;
        ChargeurDossier<double, Coordonnee> chargeur_dossier(&chargeur_coordonnee_json);
        Graphe<double, Coordonnee> graphe;
        chargeur_dossier.charger("../data/13_fichiers_JSON", graphe);
        cout << graphe << endl;
        afficheSucces("TEST CHARGEMENT DOSSIER JSON COORDONNEE");
    }
    return 0;
}