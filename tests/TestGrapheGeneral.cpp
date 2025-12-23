//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//
#include "../src/graphe/AElement.h"
#include "graphe/Arete.h"
#include "graphe/GElement.h"
#include "graphe/Sommet.h"
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
        Arete<string, double>* a1 =
            new Arete<string, double>(1, "Paris", s1, s2);
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
            cout << "Oui ! " << *a1 << " est bien egal a :" << endl
                 << *s1 << " relie a " << *s2 << endl;
        }
        else
        {
            cout << "Non ces deux sommets ne compose pas l'arete";
        }

        cout << "a1 relie t-il s2 et s3 ?" << endl;
        if (a1->estEgal(s2, s3))
        {
            cout << "Oui ! " << *a1 << " est bien egal a :" << endl
                 << *s2 << " relie a " << *s3 << endl;
        }
        else
        {
            cout << "Non ces deux sommets ne compose pas l'arete a1" << endl;
        }

        cout << "a2 relie t-il s2 et s3 ?" << endl;
        if (a2.estEgal(s1, s3))
        {
            cout << "Oui ! " << a2 << " est bien egal a :" << endl
                 << *s1 << " relie a " << *s2 << endl;
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

    return 0;
}