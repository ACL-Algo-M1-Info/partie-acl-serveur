//
// Created by maxen on 29/12/2025.
//

#include <iostream>

#include "algo/algo.h"
#include "types/etat/etat.h"
#include "types/instance/instance.h"
#include "types/ordonnancementMachine/ordonnancementMachine.h"

int main()
{
    int n = 3;
    int m = 2;

    int p[] = { 3, 8, 4 };
    Instance instance = Instance(n, m, p);

    Algo algorithme = Algo(instance);

    Etat minCmax = algorithme.algoProgrammationDynamique();
    cout << minCmax << endl;

    return 0;
}