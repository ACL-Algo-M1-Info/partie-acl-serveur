//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//
#include "../src/graphe/AElement.h"
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
    return 0;
}