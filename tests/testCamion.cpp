//
// Created by maxen on 23/12/2025.
//

#include <iostream>
#include <ostream>
#include <assert.h>

#include "types/camion/camion.h"

int main()
{
    cout << "Camion vide" << endl;
    Camion cam = Camion();
    cout << cam << endl;
    assert(cam.cmax == 0 && cam.tabId.size() == 0);

    cout << "Camion avec la tache 1 et cmax = 3" << endl;
    cam.ajouterTache(1, 3);
    cout << cam << endl;
    assert(cam.cmax == 3 && cam.tabId.size() == 1);

    cout << "Clone" << endl;
    Camion cam2 = Camion(cam);
    cout << cam2 << endl;
    assert(cam2.cmax == 3 && cam.tabId.size() == 1);
    assert(cam == cam2);

    cout << "Ajout tache 2 et cmax = 8 sur l'original" << endl;
    cam.ajouterTache(2, 5);
    cout << cam << endl;
    assert(cam.cmax == 8 && cam.tabId.size() == 2);

    cout << "Vs clone" << endl;
    cout << cam2 << endl;
    assert(cam2.cmax == 3 && cam2.tabId.size() == 1);
    assert(!(cam == cam2));

    return 0;
}