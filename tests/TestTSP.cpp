#include "../src/graphe/Graphe.h"

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
    graphe.creeArete(5,sE,sD);
    cout << graphe << endl;

    Graphe<int,char> *acpm = graphe.kruskal();
    cout << "l'acpm de graphe : " << endl;
    cout << *acpm << endl;
}
int main()
{
    testMap();
    testMapTemplate();
    testKruskal();
    return 0;
}