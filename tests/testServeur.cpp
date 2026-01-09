//
// Created by remik on 02/01/2026.
//

#include <winsock2.h> // Garder en 1er sinon conflit avec byte à cause d'unwrap std
#include <iostream>

#include "db/routes/routesDb.h"
#include "db/villes/villesDb.h"
#include "tcp/socketServeur/socketServeur.h"
#include "types/chargeursGeneriques/ChargeurGeneriqueJson.h"

using namespace serv;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Chargement des singletons
    RoutesDb* r = RoutesDb::getInstance();
    VillesDb* v = VillesDb::getInstance();

    r->recupererDonnees();
    v->recupererDonnees();

    string ip = "127.0.0.1";
    short port = 9111;
    bool valid = true;

    // do
    // {
    //     cout << "Choisissez l'adresse du serveur : ";
    //     cin >> ip;
    //
    //     cout << "Choisissez le port : ";
    //     cin >> port;
    //
    //     valid = SocketServeur::adresseEstDisponible(ip, port);
    //
    //     if (!valid)
    //         cerr << ip << ":" << port << " invalides !" << endl;
    // }
    // while (!valid);

    SocketServeur *s = SocketServeur::getInstance();

    s->ecouter(ip, port);
    s->accepterRequetes();

    return 0;
}