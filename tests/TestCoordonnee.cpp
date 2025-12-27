//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

#include "foncteurs/FoncteurUtils.h"
#include "types/coordonnee/Coordonnee.h"
void testCoordonnee()
{
    Coordonnee<string, double>* coordonnee = new Coordonnee<string, double>("Metz", 49.12, 6.17);
    cout << *coordonnee << endl;

    Coordonnee<char, int>* coordonnee2 = new Coordonnee<char, int>('A', 5, -3);
    cout << *coordonnee2 << endl;

    Coordonnee<char, int>* coordonnee3 = new Coordonnee<char, int>('B', 0, 0);

    DistanceEuclidienneCoordonnee distance_euclidienne;
    double d = distance_euclidienne(*coordonnee3, *coordonnee2);
    cout << "la distance euclidienne entre A et B = " << d << endl;

    delete coordonnee;
    delete coordonnee2;
    delete coordonnee3;
}
int main()
{
    testCoordonnee();
    return 0;
}