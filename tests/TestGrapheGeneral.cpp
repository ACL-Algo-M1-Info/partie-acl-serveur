//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//
#include <assert.h>

#include "../src/types/graphe/AElement.h"
#include "../src/types/graphe/Arete.h"
#include "../src/types/graphe/GElement.h"
#include "../src/types/graphe/Graphe.h"
#include "../src/types/graphe/Sommet.h"
int main()
{
    {
        cout << "*********************************** TEST AElement "
                "**********************************"
             << endl;
        AElement* aElement = new AElement(45);
        AElement aElement2(-1);
        cout << (string)(*aElement) << endl;
        cout << *aElement << endl;

        cout << (string)aElement2 << endl;
        cout << aElement2 << endl;
        delete aElement;
    }
    {
        cout << "*********************************** TEST GElement "
                "**********************************"
             << endl;

        GElement<double> gElementDouble(12, 5.6);
        cout << (string)gElementDouble << endl;
        cout << gElementDouble << endl;

        GElement<string> gElementString(5, "Jarny");
        cout << (string)gElementString << endl;
        cout << gElementString << endl;

        GElement<int>* gElementInt = new GElement<int>(1, -15);
        cout << (string)*gElementInt << endl;
        cout << *gElementInt << endl;

        delete gElementInt;
    }
    {
        cout << "*********************************** TEST Sommet "
                "**********************************"
             << endl;
        Sommet<int> sommetInt(1, 2);
        cout << (string)sommetInt << endl;
        cout << sommetInt << endl;

        Sommet<string> sommetString(4, "Busan");
        cout << (string)sommetString << endl;
        cout << sommetString << endl;

        Sommet<double>* sommetDouble = new Sommet<double>(1, 45.9);
        cout << (string)*sommetDouble << endl;
        cout << *sommetDouble << endl;
        delete sommetDouble;
    }
    {
        cout << "*********************************** TEST Arete "
                "**********************************"
             << endl;
        Sommet<double>* s1 = new Sommet<double>(5, 3.1);
        Sommet<double>* s2 = new Sommet<double>(10, 3.6);
        Sommet<double>* s3 = new Sommet<double>(15, .1);
        Arete<string, double>* a1 = new Arete<string, double>(1, "Paris", s1, s2);
        cout << (string)*a1 << endl;
        cout << *a1 << endl;
        cout << *s1 << endl;

        Arete<char, double> a2(2, 'C', s1, s3);
        cout << (string)a2 << endl;
        cout << a2 << endl;
        cout << *s1 << endl;
        cout << *s2 << endl;
        cout << *s3 << endl;

        cout << "*********************************** TEST EGALITE "
                "**********************************"
             << endl;
        cout << "a1 relie t-il s2 et s1 ?" << endl;
        if (a1->estEgal(s2, s1))
        {
            cout << "Oui ! " << *a1 << " est bien egal a :" << endl << *s1 << " relie a " << *s2 << endl;
        }
        else
        {
            cout << "Non ces deux sommets ne compose pas l'arete";
        }

        cout << "a1 relie t-il s2 et s3 ?" << endl;
        if (a1->estEgal(s2, s3))
        {
            cout << "Oui ! " << *a1 << " est bien egal a :" << endl << *s2 << " relie a " << *s3 << endl;
        }
        else
        {
            cout << "Non ces deux sommets ne compose pas l'arete a1" << endl;
        }

        cout << "a2 relie t-il s2 et s3 ?" << endl;
        if (a2.estEgal(s1, s3))
        {
            cout << "Oui ! " << a2 << " est bien egal a :" << endl << *s1 << " relie a " << *s2 << endl;
        }
        else
        {
            cout << "Non ces deux sommets ne compose pas l'arete a3" << endl;
        }

        int degreAvantDelete = s1->degre;
        cout << "degre avant delete = " << degreAvantDelete << endl;
        delete a1;
        int degreApresDelete = s1->degre;
        cout << "degre apres delete = " << degreApresDelete << endl;
        delete s1;
        delete s2;
        delete s3;
    }

    Graphe<char, string> g2;  // pour vérifier que
    // l'opérateur = et que le
    // destructeur fonctionnent bien
    {
        cout << "*********************************** TEST GRAPHE "
                "**********************************"
             << endl;
        Graphe<char, string> g1;

        Sommet<string>*s0, *s1, *s2, *s3;
        s0 = g1.creeSommet("king's Landing");
        s1 = g1.creeSommet("Winterfall");
        s2 = g1.creeSommet("DragonStone");
        s3 = g1.creeSommet("The wall");

        cout << (string)g1 << endl;
        cout << g1 << endl;

        //----------------- on connecte certains sommets -------------------

        Arete<char, string>*a0, *a1, *a2, *a3;
        a0 = g1.creeArete('a', s1, s0);
        a1 = g1.creeArete('b', s2, s1);
        a2 = g1.creeArete('c', s3, s2);
        a3 = g1.creeArete('d', s3, s1);

        //------------------ faire le dessin du graphe sur papier en notant les
        // noms et les degrés pour comprendre la suite ----------------

        cout << "Le graphe cree g1 est " << endl << g1 << endl;
        cout << "le nombre de sommets de g1 est : " << g1.nombreSommets() << endl;
        cout << "le nombre d'aretes de g1 est : " << g1.nombreAretes() << endl;

        assert(g1.nombreSommets() == 4 && g1.nombreAretes() == 4);

        cout << "*********************************** TEST GRAPHE VOISINS ET "
                "ARETES "
                "ADJACENTES "
                "**********************************"
             << endl;

        PElement<Sommet<string>>* l0 = g1.voisins(s0);
        cout << "La liste des voisins de s0 est : " << endl << l0 << endl;
        PElement<Arete<char, string>>* adj0 = g1.aretesAdjacentes(s0);

        cout << "La liste des aretes adjacentes a s0 est : " << endl << adj0 << endl;

        PElement<Sommet<string>>* l1 = g1.voisins(s1);
        cout << "La liste des voisins de s1 est : " << endl << l1 << endl;
        PElement<Arete<char, string>>* adj1 = g1.aretesAdjacentes(s1);

        cout << "La liste des aretes adjacentes a s1 est : " << endl << adj1 << endl;

        PElement<Sommet<string>>* l2 = g1.voisins(s2);
        cout << "La liste des voisins de s2 est : " << endl << l2 << endl;
        PElement<Arete<char, string>>* adj2 = g1.aretesAdjacentes(s2);

        cout << "La liste des aretes adjacentes a s2 est : " << endl << adj2 << endl;

        PElement<Sommet<string>>* l3 = g1.voisins(s3);
        cout << "La liste des voisins de s3 est : " << endl << l3 << endl;
        PElement<Arete<char, string>>* adj3 = g1.aretesAdjacentes(s3);

        cout << "La liste des aretes adjacentes a s3 est : " << endl << adj3 << endl;

        cout << "*********************************** TEST GRAPHE "
                "getAreteParSommet "
                "**********************************"
             << endl;
        Arete<char, string>* a = g1.getAreteParSommets(s1, s3);
        cout << "l'arete joignant s1 et s3 est : " << endl << *a << endl;

        // Graphe<char, string> g2;
        g2 = g1;
    }
    // à la fin de ce bloc, le destructeur est appelé
    //  pour g1.
    // cela permet de vérifier que l'op = a fait une
    // vraie copie de g1

    cout << "*********************************** TEST GRAPHE "
            "COPIE ET DESTRUCTEUR"
            "**********************************"
         << endl;
    cout << "le graphe cree g2 comme copie de g1 est :" << endl << g2 << endl;

    return 0;
}