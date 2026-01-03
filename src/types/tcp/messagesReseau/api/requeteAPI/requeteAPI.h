//
// Created by remik on 30/12/2025.
//

#ifndef SERVEURCPP_REQUETEAPI_H
#define SERVEURCPP_REQUETEAPI_H

// INCLUSIONS

#include <string>

#include "types/tcp/messagesReseau/socket/requeteSocket/requeteSocket.h"
#include "utils/json.h"

// NAMESPACES

using namespace std;
using json = nlohmann::json;

namespace serv
{

class RequeteAPI : public MessageBase
{
public:

    // CONSTANTES

    /** Segment de commande. */
    inline static const string SEGMENT_COMMANDE = "cmd";

    /** Segment d'arguments. */
    inline static const string SEGMENT_ARGUMENTS = "args";

    // VARIABLES

    /** Requête obtenue (précédemment). */
    const RequeteSocket& precedent;

    /** jsonMessage du contenu data. */
    json jsonAPIMessage;

    /** Nom de la commande invoquée. */
    string commande;

    /** Arguments au format json. La désérialisation et le typage se fait dans chaque commande. */
    vector<json> args;

    // CONSTRUCTEUR / DESTRUCTEUR

    RequeteAPI(const RequeteSocket& requeteInitiale)
        : precedent(requeteInitiale), jsonAPIMessage(requeteInitiale.data)
    {
        if (!messageRespecteStructure())
            throw ErreurFormat("Format commande API invalide");

        this->commande = jsonAPIMessage[ SEGMENT_COMMANDE ].get<string>();

        for (const json& arg : jsonAPIMessage[ SEGMENT_ARGUMENTS ])
            this->args.push_back(arg);
    }

    // GETTER / SETTER

    int getIdConversation() const override
    {
        return this->precedent.getIdConversation();
    }

    // METHODES

    /**
     * Détermine si le json obtenu respect a minima la structure attendue {type: string, data: DATA}.
     * @return Si le json parsé respecte la structure minimale.
     */
    bool messageRespecteStructure() const
    {
        return precedent.messageRespecteStructure()
            && jsonAPIMessage.contains(SEGMENT_COMMANDE)
            && jsonAPIMessage.contains(SEGMENT_ARGUMENTS);
    }

    // OPERATEURS

    /**
     * Opérateur string
     */
    operator string() const
    {
        return this->precedent;
    }

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const RequeteAPI& m)
    {
        return s << (string)m;
    }
};

} // serv

#endif //SERVEURCPP_REQUETEAPI_H