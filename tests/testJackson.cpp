//
// Created by maxen on 29/12/2025.
//

#include <iostream>

#include "../src/utils/utils.h"

int main()
{
    int n = 5;
    int m = 3;

    int p[] = { 5, 3, 1, 5, 9 };

    Instance instance = Instance(n, m, p);

    cout << instance << endl;

    Utils::triJackson(instance);

    cout << "Apres le tri de Jackson : " << endl << instance << endl;

    return 0;
}