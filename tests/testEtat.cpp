//
// Created by maxen on 23/12/2025.
//

#include <iostream>
#include <assert.h>

#include "../src/types/etat/etat.h"

int main()
{
    Etat e = Etat(2);

    cout << "Etat vide sur 2 machines" << endl;
    cout << e << endl;

    cout << "On doit avoir la tache 1 sur la premiere machine, qui a un cmax de 5" << endl;
    e.ajouterTacheSurMachine(0, 1, 5);
    cout << e << endl;

    cout << "Clone" << endl;
    Etat e2 = Etat(e);
    cout << e2 << endl;
    assert(e == e2);

    cout << "On doit avoir la tache 2 sur la deuxieme machine, qui a un cmax de 4" << endl;
    e.ajouterTacheSurMachine(1, 2, 4);
    cout << e << endl;

    cout << "Vs clone" << endl;
    cout << e2 << endl;
    assert(!(e == e2));

    return 0;
}