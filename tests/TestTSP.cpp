#include <assert.h>

#include "../src/types/graphe/Graphe.h"
#include "utils/utils.h"
//
// Created by MEGACHEESEKEBAB on 28/12/2025.
//

int trouveRacine(int i, map<int, int>& parents)
{
    while (i != parents[i])
    {
        i = parents[i];
    }
    return i;
}

void unionEnsemble(int a, int b, map<int, int>& parents)
{
    int racineA = trouveRacine(a, parents);
    int racineB = trouveRacine(b, parents);
    if (racineA != racineB)
    {
        cout << "Le parent de " << racineA << " devient " << racineB << endl;
        parents[racineA] = racineB;
    }
    else
    {
        cout << a << " et " << b << " sont déjà dans le meme groupe" << endl;
    }
}
void afficheMap(const map<int, int>& parents)
{
    cout << "Map : " << endl;
    map<int, int>::const_iterator it;
    for (it = parents.begin(); it != parents.end(); ++it)
    {
        cout << "Element " << it->first << " a pour parent " << it->second << endl;
    }
}
void testMap()
{
    cout << "************************** testMap ***************************" << endl;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    map<int, int> parents;
    parents[a] = a;
    parents[b] = b;
    parents[c] = c;
    parents[d] = d;
    afficheMap(parents);

    cout << "Union de 1 et 2..." << endl;
    unionEnsemble(a, b, parents);
    afficheMap(parents);

    cout << "Union de 3 et 4..." << endl;
    unionEnsemble(c, d, parents);
    afficheMap(parents);

    cout << "Union de 1 et 3..." << endl;
    unionEnsemble(1, 3, parents);
    afficheMap(parents);

    cout << "Racine de 1 = " << trouveRacine(a, parents) << endl;
}

void testMapTemplate()
{
    cout << "************************** testMapTemplate ***************************" << endl;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    map<int, int> parents;
    parents[a] = a;
    parents[b] = b;
    parents[c] = c;
    parents[d] = d;
    Utils::afficheMap(parents);
    int racineA = Utils::trouveRacine(a, parents);
    int racineB = Utils::trouveRacine(b, parents);
    cout << "La racine de a est : " << racineA << endl;
    cout << "La racine de b est : " << racineB << endl;
    Utils::unionEnsemble(a, b, parents);
    racineA = Utils::trouveRacine(a, parents);
    racineB = Utils::trouveRacine(b, parents);
    cout << "Apres l'union, la racine de a est : " << racineA << endl;
    cout << "Apres l'union, la racine de b est : " << racineB << endl;
    Utils::afficheMap(parents);
}

void testKruskal()
{
    cout << "************************** test Kruskal ***************************" << endl;
    /* Graphe du cours modélisation L3 premier exemple Kruskal */
    Graphe<int, char> graphe;
    Sommet<char>* sA = graphe.creeSommet('A');
    Sommet<char>* sB = graphe.creeSommet('B');
    Sommet<char>* sC = graphe.creeSommet('C');
    Sommet<char>* sD = graphe.creeSommet('D');
    Sommet<char>* sE = graphe.creeSommet('E');
    Sommet<char>* sF = graphe.creeSommet('F');
    graphe.creeArete(3, sA, sB);
    graphe.creeArete(4, sA, sC);
    graphe.creeArete(7, sA, sF);
    graphe.creeArete(4, sB, sC);
    graphe.creeArete(9, sC, sE);
    graphe.creeArete(9, sC, sD);
    graphe.creeArete(1, sC, sF);
    graphe.creeArete(5, sE, sD);
    cout << graphe << endl;

    Graphe<int, char>* acpm = graphe.kruskal();
    cout << "l'acpm de graphe : " << endl;
    cout << *acpm << endl;
}

void testDedouble()
{
    cout << "************************** test dedoublage ***************************" << endl;
    Graphe<int, char> graphe;
    Sommet<char>* sA = graphe.creeSommet('A');
    Sommet<char>* sB = graphe.creeSommet('B');
    Sommet<char>* sC = graphe.creeSommet('C');
    graphe.creeArete(7, sA, sB);
    graphe.creeArete(12, sB, sC);
    graphe.creeArete(2, sA, sC);
    cout << graphe;
    Graphe<int, char>* acpm = graphe.kruskal();
    cout << "acmp = " << endl << *acpm << endl;
    acpm->dedoubleArete();
    cout << "acmp dedouble = " << endl << *acpm << endl;
}

void testSet()
{
    cout << "************************** test set ***************************" << endl;
    set<int> E;
    E.insert(2);
    E.insert(1);
    E.insert(2);
    assert(E.size() == 2);
    assert(E.count(2) == 1);
    assert(E.find(1) != E.end());
    assert(E.find(13) == E.end());
    Utils::afficheSet(E);
    cout << endl;
}

void testTSP()
{
    cout << "************************** test TSP ***************************" << endl;
    /* Instance page wikipedia cycle = ACBDA poids = 7*/
    Graphe<int, char> graphe;
    Sommet<char>* sA = graphe.creeSommet('A');
    Sommet<char>* sB = graphe.creeSommet('B');
    Sommet<char>* sC = graphe.creeSommet('C');
    Sommet<char>* sD = graphe.creeSommet('D');
    graphe.creeArete(4, sA, sB);
    graphe.creeArete(3, sA, sC);
    graphe.creeArete(1, sA, sD);
    graphe.creeArete(1, sB, sC);
    graphe.creeArete(2, sB, sD);
    graphe.creeArete(5, sC, sD);
    cout << "Affichage graphe complet" << endl;
    cout << graphe << endl;
    Graphe<int, char>* acpm = graphe.kruskal();
    cout << "Affichage ACPM" << endl;
    cout << *acpm << endl;
    PElement<Sommet<char>>* tournee = acpm->TSP();
    cout << PElement<Sommet<char>>::toString(tournee) << endl;
    Graphe<int, char>* grapheTournee = graphe.construireGrapheTournee(tournee);
    cout << "Affichage Graphe tournee" << endl;
    cout << *grapheTournee << endl;
    int poidsTotal = grapheTournee->sommePoids();
    cout << "Poids total = " << poidsTotal << endl;

    cout << "************************** test TSP2 ***************************" << endl;
    /* Instance une autre instance : cycle = ACBDA poids = 10 mais l'heuristique trouve ABCDA poids = 11 */
    Graphe<int, char> graphe2;
    Sommet<char>* s2A = graphe2.creeSommet('A');
    Sommet<char>* s2B = graphe2.creeSommet('B');
    Sommet<char>* s2C = graphe2.creeSommet('C');
    Sommet<char>* s2D = graphe2.creeSommet('D');
    graphe2.creeArete(1, s2A, s2B);
    graphe2.creeArete(2, s2A, s2C);
    graphe2.creeArete(3, s2A, s2D);
    graphe2.creeArete(2, s2B, s2C);
    graphe2.creeArete(3, s2B, s2D);
    graphe2.creeArete(5, s2C, s2D);

    cout << "Affichage graphe complet 2" << endl << graphe2;
    Graphe<int, char>* acpm2 = graphe2.kruskal();
    cout << "Affichage ACPM 2" << *acpm2;
    PElement<Sommet<char>>* tournee2 = acpm2->TSP();
    cout << "Tourne optimale " << PElement<Sommet<char>>::toString(tournee2);
    Graphe<int, char>* graphetournee2 = graphe2.construireGrapheTournee(tournee2);
    cout << "Graphe de la tournee 2 " << endl << *graphetournee2 << endl;
    int poidsTotal2 = graphetournee2->sommePoids();
    cout << "Poids total tournee 2 = " << poidsTotal2 << endl;
}
int main()
{
    testMap();
    testMapTemplate();
    testKruskal();
    testDedouble();
    testSet();
    testTSP();
    return 0;
}