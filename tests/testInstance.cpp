//
// Created by maxen on 23/12/2025.
//

#include <assert.h>

#include <iostream>

#include "../src/types/instance/instance.h"

int main()
{
    int quantites[] = {5, 4, 3, 2, 1};
    Instance i = Instance(5, 3, quantites);

    cout << "Instance" << endl;
    cout << i << endl;

    cout << "Clone" << endl;
    Instance i2 = Instance(i);
    cout << i2 << endl;
    assert(i == i2);

    cout << "Modification i sur quantites[0]" << endl;
    i.quantites[0] = 1;
    cout << i << endl;
    cout << i2 << endl;
    assert(!(i == i2));

    cout << "Chercher le pmax sur i2" << endl;
    int pmax = i2.obtenirPmax();
    cout << "pmax : " << pmax << endl;
    assert(pmax == 5);
}