//
// Created by MEGACHEESEKEBAB on 22/12/2025.
//

#ifndef TPACL_ERREUR_H
#define TPACL_ERREUR_H
#include <string>
using namespace std;

class Erreur
{
private:
    string message;

public:
    Erreur(const string& message) : message(message)
    {
    }

    string getMessage() const
    {
        return message;
    }
};


#endif //TPACL_ERREUR_H
