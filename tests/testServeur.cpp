//
// Created by remik on 21/12/2025.
//

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <cstring>

#include <thread>
#include <winsock2.h>

#define MAX_L 500

#define SEPARATEUR '\r'

const char SHIFT = 'a' - 'A';

using namespace std;
using namespace std::chrono;

class Erreur
{
public:
    string msg;

    Erreur(const string& msg)
        : msg(msg)
    {}

    operator string()
    {
        return msg;
    }
};

class Interlocuteur
{
public:
    SOCKET client;

    Interlocuteur(const SOCKET client = INVALID_SOCKET)
        : client(client)
    {}

    string inversion(const string& str) const
    {
        ostringstream res;

        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];

            if (c >= 'A' && c <= 'Z')
                res << (char)(c + SHIFT);

            else if (c >= 'a' && c <= 'z')
                res << (char)(c - SHIFT);

            else
                res << c;
        }

        return res.str();
    }

    string controlString(const string& str, int size = -1) const
    {
        ostringstream ss;

        if (size == -1)
            size = str.length() + 1;

        // Contrôle
        for (int i = 0; i < size; i++)
        {
            char a = str.c_str()[i];

            if (a == '\0')
                ss << "\\0";
            else if (a == '\r')
                cout << "\\r";
            else if (a == '\n')
                cout << "\\n";
            else
                cout << a;
        }

        return ss.str();
    }

    // Foncteur pour effectuer une tâche en parallèle des autres tâches
    void operator()() const
    {
        try
        {
            bool fin = false;

            do
            {
                char buffer[MAX_L];

                int nbOctetsRecus = recv(client, buffer, MAX_L-1, 0);

                // Erreur
                if (nbOctetsRecus == SOCKET_ERROR)
                    throw Erreur("Impossible de poll le socket");

                // Déco
                if (nbOctetsRecus == 0)
                {
                    fin = true;
                    continue;
                }

                buffer[nbOctetsRecus] = '\0';
                char* p = strchr(buffer, '\r'); // Préremplissage

                if (p)
                    *p = '\0';
                else
                    p = buffer + nbOctetsRecus; // Relocalisation de la fin du message

                int L = p - buffer; // Taille str sans le \0
                int LResp = L + 3; // Taille de la réponse (2 cars en + pour \r\n et il reste le \0)
                int LSend = L + 2; // Message final sans \0

                cout << "Message \"" << buffer << "\" (\"" << controlString(string(buffer)) << "\") reçu d'une longueur " << L << endl;

                // On retourne le message
                char resp[LResp]; // Ajout de \r\n donc 2 chars en +

                // Application de la transformation
                strncpy(resp, inversion(string(buffer)).c_str(), L);

                // Reconstruction de la fin du string
                resp[L] = '\r';
                resp[L + 1] = '\n';
                resp[L + 2] = '\0';

                cout << "Message renvoyé : " << "\"" << resp << "\" (\"" << controlString(string(resp), LSend) << "\") d'une longueur " << L + 2 << endl;

                // Envoi sans le \0 final donc L + 2 car ajout \r\n
                if (send(client, resp, LSend, 0) == SOCKET_ERROR)
                    throw Erreur("Envoi de la réponse impossible");

                // Sleep périodique
                this_thread::sleep_for(milliseconds(5));
            }
            // TODO déterminer la fin via statut de connexion du socket
            while (!fin);
        }
        catch (Erreur& e)
        {
            cerr << e.msg << endl;
        }

        cout << "Déco client" << endl;
        closesocket(client);
    }
};

class Serveur
{
public:
    bool etatConnexion = false;

    SOCKET serveur;
    WSAData data;

    int familleAddr = AF_INET; // IPv4
    int typeSock = SOCK_STREAM; // Type stream continu (vu depuis le début)
    int proto = IPPROTO_TCP; // TCP

    Serveur()
    {
        if (WSAStartup(MAKEWORD(2, 0), &data))
            throw Erreur("Impossible de créer le serveur");
    }

    void ecouter(const string& ip, short port)
    {
        // Démarrage socket
        if ((serveur = socket(familleAddr, typeSock, proto)) == INVALID_SOCKET)
            throw Erreur("Impossible de créer le socket");

        // Créé infos pour listen du serveur
        SOCKADDR_IN servAddr;
        servAddr.sin_family = familleAddr;
        servAddr.sin_addr.s_addr = inet_addr(ip.c_str());
        servAddr.sin_port = htons(port);

        // TODO Domic a mis tout un truc pour vérifier la validité d'une adresse, il s'agirait de faire ça >:)

        if (bind(serveur, (SOCKADDR*) &servAddr, sizeof(servAddr)) == SOCKET_ERROR)
            throw Erreur("Impossible de lier le serveur à l'adresse souhaitée");

        if (listen(serveur, SOMAXCONN) == SOCKET_ERROR)
            throw Erreur("Impossible de listen");

        const int MAXCLIENTS = 100;
        Interlocuteur clients[MAXCLIENTS];
        thread threads[MAXCLIENTS];
        int id = 0;

        cout << "Serveur démarré sur " << ip << ":" << port << endl;

        while (true)
        {
            SOCKET c;
            if ((c = accept(serveur, NULL, NULL)) == INVALID_SOCKET)
                throw Erreur("Socket client invalide, crash entier du serveur !!!");

            cout << "Nouveau socket d'id " << id << endl;

            clients[id] = Interlocuteur(c);
            threads[id] = thread(clients[id]);
            threads[id].detach(); // Nécessaire pour synchro?

            id++;
        }
    }
};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        Serveur s = Serveur();
        s.ecouter("127.0.0.1", 9111);
    }
    catch (Erreur& e)
    {
        cerr << e.msg << endl;
    }

    return 0;
}