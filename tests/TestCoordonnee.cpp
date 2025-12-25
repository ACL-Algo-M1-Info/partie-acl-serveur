//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

#include "types/coordonnee/Coordonnee.h"
void testCoordonnee()
{
    Coordonnee<string, double>* coordonnee = new Coordonnee<string, double>("Metz", 49.12, 6.17);
    cout << *coordonnee << endl;

    Coordonnee<char, int>* coordonnee2 = new Coordonnee<char, int>('A', 5, -3);
    cout << *coordonnee2 << endl;
    delete coordonnee;
    delete coordonnee2;
}
int main()
{
    testCoordonnee();
    return 0;
}