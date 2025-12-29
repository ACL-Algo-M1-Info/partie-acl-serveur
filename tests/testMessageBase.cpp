//
// Created by remik on 29/12/2025.
//

#include <iostream>
#include <map>

#include "types/messagesReseau/base/messageBaseRecu/messageBaseRecu.h"
#include "types/messagesReseau/base/messageBaseReponse/messageBaseReponse.h"

using namespace std;

int main()
{
    serv::MessageBaseReponse<string> m("api", "je suis une limace");
    serv::MessageBaseReponse<map<string, int>> m2("api", map<string, int> {{"hey", 1}, {"hi", 2}});

    cout << m << endl;
    cout << m2 << endl;

    serv::MessageBaseRecu<string> r = serv::MessageBaseRecu<string>("{\"data\":\"hi I'm Maxence\",\"type\":\"api\"}");

    cout << r << endl;
    cout << m2.type << endl << m2.data << endl;
}