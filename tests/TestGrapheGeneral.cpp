//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//
#include "../src/graphe/AElement.h"
int main()
{
    {
        cout << "*********************************** TEST AElement "
                "**********************************"
             << endl;
        AElement *aElement = new AElement(45);
        AElement aElement2(-1);
        cout << (string)(*aElement) << endl;
        cout << *aElement << endl;

        cout << (string)aElement2 << endl;
        cout << aElement2 << endl;
        delete aElement;
    }
    return 0;
}