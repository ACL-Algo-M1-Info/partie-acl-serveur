//
// Created by remik on 29/12/2025.
//

#include <iostream>
#include <map>

#include "types/tcp/messagesReseau/api/requeteAPI/requeteAPI.h"
#include "types/tcp/messagesReseau/socket/requeteSocket/requeteSocket.h"
#include "types/tcp/messagesReseau/socket/reponseSocket/reponseSocket.h"

using namespace std;

int main()
{
    serv::ReponseSocket<string> m(serv::CodeStatutReponse::OK, "je suis une limace", 2);
    serv::ReponseSocket<map<string, int>> m2(serv::CodeStatutReponse::OK, map<string, int> {{"hey", 1}, {"hi", 2}});

    cout << m << endl;
    cout << m2 << endl;

    serv::RequeteSocket r("{\"data\":{\"cmd\":\"test\",\"args\":[1,2,3]},\"type\":10,\"idConversation\":5}");

    cout << r << endl;

    serv::RequeteAPI api(r);

    cout << api << endl;
    cout << api.commande << endl << api.args << endl;
}