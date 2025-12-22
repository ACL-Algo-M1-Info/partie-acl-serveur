//
// Created by MEGACHEESEKEBAB on 22/12/2025.
//
#include "../src/graphe/Pelement.h"

int main()
{
    {
        cout << "*********************************** TEST TAILLE "
                "**********************************"
             << endl;
        double* a = new double(2);
        double* b = new double(5);
        double* c = new double(7.5);
        double* d = new double(9);
        Pelement<double>* l1 = nullptr;
        l1 = new Pelement<double>(l1, a);
        l1 = new Pelement<double>(l1, b);
        l1 = new Pelement<double>(l1, c);
        l1 = new Pelement<double>(l1, d);

        string s1 = "carotte";
        string s2 = "cerise";
        string s3 = "orange";
        Pelement<string>* l2 = nullptr;
        l2 = new Pelement<string>(l2, &s1);
        l2 = new Pelement<string>(l2, &s2);
        l2 = new Pelement<string>(l2, &s3);

        int tailleListe = Pelement<double>::taille(l1);
        cout << "taille l1 : " << tailleListe << endl;

        int tailleListeR = Pelement<double>::tailleR(l1);
        cout << "taille r l1 : " << tailleListeR << endl;

        tailleListe = Pelement<string>::taille(l2);
        cout << "taille l1 : " << tailleListe << endl;

        tailleListeR = Pelement<string>::tailleR(l2);
        cout << "taille r l1 : " << tailleListeR << endl;

        cout << l1 << endl;
        cout << l2 << endl;
    }
    {
        cout << "*********************************** TEST INSERTION ET DEPILER "
                "**********************************"
             << endl;
        Pelement<double>* l3 = nullptr;
        double* valIns1 = new double(-7);
        double* valIns2 = new double(6);
        double* valIns3 = new double(13);
        Pelement<double>::insertionOrdonnee(valIns1, l3, estPlusPetitOuEgal);
        Pelement<double>::insertionOrdonnee(valIns2, l3, estPlusPetitOuEgal);
        Pelement<double>::insertionOrdonnee(valIns3, l3, estPlusPetitOuEgal);
        cout << l3 << endl;

        Pelement<string>* l4 = nullptr;
        string s1 = "fraise";
        string s2 = "ananas";
        string s3 = "pomme";

        Pelement<string>::insertionOrdonnee(&s1, l4, estPlusPetitOuEgal);
        Pelement<string>::insertionOrdonnee(&s2, l4, estPlusPetitOuEgal);
        Pelement<string>::insertionOrdonnee(&s3, l4, estPlusPetitOuEgal);

        cout << l4 << endl;

        string* chaine = Pelement<string>::depiler(l4);
        cout << *chaine << endl;
        cout << l4 << endl;
        chaine = Pelement<string>::depiler(l4);
        cout << *chaine << endl;
        cout << l4 << endl;
        chaine = Pelement<string>::depiler(l4);
        cout << *chaine << endl;
        cout << l4 << endl;

        try
        {
            chaine = Pelement<string>::depiler(l4);
            cout << *chaine << endl;
            cout << l4 << endl;
        }
        catch (const Erreur& e)
        {
            cout << e.getMessage();
        }
    }
    {
        cout << "*********************************** TEST RETIRER "
                "**********************************"
             << endl;
        double* a = new double(2);
        double* b = new double(5);
        double* c = new double(7.5);
        double* d = new double(9);
        Pelement<double>* l1 = nullptr;
        l1 = new Pelement<double>(l1, a);
        l1 = new Pelement<double>(l1, b);
        l1 = new Pelement<double>(l1, c);
        l1 = new Pelement<double>(l1, d);

        string s1 = "carotte";
        string s2 = "cerise";
        string s3 = "orange";
        Pelement<string>* l2 = nullptr;
        l2 = new Pelement<string>(l2, &s1);
        l2 = new Pelement<string>(l2, &s2);
        l2 = new Pelement<string>(l2, &s3);
        cout << l1 << endl;

        bool v = Pelement<double>::retire(d, l1);
        cout << l1 << (v ? " Succes " : "Echec ") << endl;
        v = Pelement<double>::retire(a, l1);
        cout << l1 << (v ? " Succes " : "Echec ") << endl;
        v = Pelement<double>::retire(d, l1);
        cout << l1 << (v ? " Succes " : "Echec ") << endl;

        v = Pelement<string>::retire(&s1, l2);
        cout << l2 << (v ? " Succes" : " Echec") << endl;
        v = Pelement<string>::retire(&s2, l2);
        cout << l2 << (v ? " Succes" : " Echec") << endl;
        v = Pelement<string>::retire(&s1, l2);
        cout << l2 << (v ? " Succes" : " Echec") << endl;
    }
    {
        cout << "*********************************** TEST EFFACE1 "
                "**********************************"
             << endl;
        double* a = new double(2);
        double* b = new double(5);
        double* c = new double(7.5);
        double* d = new double(9);
        Pelement<double>* l1 = nullptr;
        l1 = new Pelement<double>(l1, a);
        l1 = new Pelement<double>(l1, b);
        l1 = new Pelement<double>(l1, c);
        l1 = new Pelement<double>(l1, d);

        string s1 = "carotte";
        string s2 = "cerise";
        string s3 = "orange";
        Pelement<string>* l2 = nullptr;
        l2 = new Pelement<string>(l2, &s1);
        l2 = new Pelement<string>(l2, &s2);
        l2 = new Pelement<string>(l2, &s3);
        cout << l1 << endl;
        cout << l2 << endl;

        Pelement<double>::efface1(l1);
        cout << l1 << endl;
        Pelement<double>::efface1(l1);
        cout << l1 << endl;

        Pelement<string>::efface1(l2);
        cout << l2 << endl;
        Pelement<string>::efface1(l2);
        cout << l2 << endl;
    }
    {
        cout << "*********************************** TEST EFFACE2 "
                "**********************************"
             << endl;
        double* a = new double(2);
        double* b = new double(5);
        double* c = new double(7.5);
        double* d = new double(9);
        Pelement<double>* l1 = nullptr;
        l1 = new Pelement<double>(l1, a);
        l1 = new Pelement<double>(l1, b);
        l1 = new Pelement<double>(l1, c);
        l1 = new Pelement<double>(l1, d);

        string* s1 = new string("carotte");
        string* s2 = new string("cerise");
        string* s3 = new string("orange");
        Pelement<string>* l2 = nullptr;
        l2 = new Pelement<string>(l2, s1);
        l2 = new Pelement<string>(l2, s2);
        l2 = new Pelement<string>(l2, s3);
        cout << l1 << endl;
        cout << l2 << endl;
        Pelement<double>::efface2(l1);
        cout << l1 << endl;

        Pelement<double>::efface2(l1);
        cout << l1 << endl;

        Pelement<string>::efface2(l2);
        cout << l2 << endl;
        Pelement<string>::efface2(l2);
        cout << l2 << endl;
    }
    {
        cout << "*********************************** TEST COPIE1 "
                "**********************************"
             << endl;

        double* a = new double(2);
        double* b = new double(5);
        double* c = new double(7.5);
        double* d = new double(9);
        Pelement<double>* l1 = nullptr;
        l1 = new Pelement<double>(l1, a);
        l1 = new Pelement<double>(l1, b);
        l1 = new Pelement<double>(l1, c);
        l1 = new Pelement<double>(l1, d);

        Pelement<double>* l2 = Pelement<double>::copie1(l1);

        cout << l1 << endl;
        cout << l2 << endl;

        Pelement<double>::insertionOrdonnee(new double(45), l2,
                                            estPlusPetitOuEgal);
        cout << l1 << endl;
        cout << l2 << endl;

        *(l2->v) = 777;
        cout << l1 << endl;
        cout << l2 << endl;
    }

    {
        cout << "*********************************** TEST COPIE2 "
                "**********************************"
             << endl;

        double* a = new double(2);
        double* b = new double(5);
        double* c = new double(7.5);
        double* d = new double(9);
        Pelement<double>* l1 = nullptr;
        l1 = new Pelement<double>(l1, a);
        l1 = new Pelement<double>(l1, b);
        l1 = new Pelement<double>(l1, c);
        l1 = new Pelement<double>(l1, d);

        Pelement<double>* l2 = Pelement<double>::copie2(l1);

        cout << l1 << endl;
        cout << l2 << endl;

        Pelement<double>::insertionOrdonnee(new double(45), l2,
                                            estPlusPetitOuEgal);
        cout << l1 << endl;
        cout << l2 << endl;

        *(l2->v) = 777;
        cout << l1 << endl;
        cout << l2 << endl;
    }

    return 0;
}
