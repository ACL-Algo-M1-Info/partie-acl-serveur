//
// Created by maxen on 29/12/2025.
//

// INCLUSIONS

#include <vector>

#include "algo.h"
#include "utils/utils.h"

// USINGS

using namespace std;

// FONCTIONS

Etat Algo::algoProgrammationDynamique()
{
    Utils::triJackson(instance);

    Etat etat = Etat(instance.m);
    vector<Etat> etats;
    etats.push_back(etat);

    // Pour chaque tâche
    for (int j = 0; j < instance.n; j++)
    {
        vector<Etat> etats2;

        // Pour chaque etat dans E
        for (int e = 0; e < etats.size(); e++)
        {
            Etat ei = etats.at(e);

            // Pour chaque machine
            for (int k = 0; k < instance.m; k++)
            {
                Etat etatEvolue = Etat(ei);
                etatEvolue.ajouterTacheSurMachine(k, j, instance.p[j]);
                etats2.push_back(etatEvolue);
            }
        }
        etats = etats2;
    }

    return Etat::getEtatWithMinCmax(etats);
}
