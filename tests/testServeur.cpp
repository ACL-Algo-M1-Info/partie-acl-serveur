//
// Created by remik on 02/01/2026.
//

#include <iostream>
#include "types/tcp/socketServeur/socketServeur.h"

using namespace std;
using namespace serv;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

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