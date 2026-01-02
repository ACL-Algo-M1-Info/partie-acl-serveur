//
// Created by remik on 29/12/2025.
//

#ifndef SERVEURCPP_MESSAGEBASEREPONSE_H
#define SERVEURCPP_MESSAGEBASEREPONSE_H

// INCLUSIONS

#include <string>

#include "types/tcp/messagesReseau/codeStatutReponse.h"
#include "types/tcp/messagesReseau/conversionJSON.h"
#include "utils/json.h"

// NAMESPACES

using json = nlohmann::json;
using namespace std;

namespace serv
{

template <class T>
class ReponseSocket : public ConversionJSON
{
public:

    // CONSTANTES

    /** Segment du code statut de la requête. */
    inline static const string SEGMENT_STATUT = "statut";

    /** Segment de la réponse de la requête. */
    inline static const string SEGMENT_REPONSE = "reponse";

    /** Segment de l'id de conversation de la requête. */
    inline static const string SEGMENT_IDCONVERSATION = "idConversation";

    // VARIABLES

    /** Code de statut. */
    CodeStatutReponse statut;

    /** Données à jsonifier. */
    T reponse;

    /** ID de la conversation. */
    int idConversation;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Construit une réponse à envoyer sur le réseau ayant un statut et un segment réponse.
     * @param
     * @param
     */
    ReponseSocket(CodeStatutReponse statut, int idConversation, const T& reponse)
        : statut(statut), reponse(reponse), idConversation(idConversation)
    {}

    // METHODES

    /**
     * Transforme le jsonMessage au format JSON.
     * @return Message au format JSON.
     */
    string enJson() const
    {
        // Mise en place du json.
        json j;

        j[ SEGMENT_STATUT ] = this->statut;
        j[ SEGMENT_REPONSE ] = this->reponse;
        j[ SEGMENT_IDCONVERSATION ] = this->idConversation;

        // Renvoie au format string. Provoque une erreur si le type T n'est pas sérialisable. Devrait être un type de base comme dictionnaire, ...
        return j.dump();
    }

    // OPERATEURS

    /**
     * Opérateur string.
     */
    operator string() const
    {
        return "Reponse generee : " + this->enJson();
    }

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const ReponseSocket& m)
    {
        return s << (string)m;
    }
};

} // namespace serv

#endif  // SERVEURCPP_MESSAGEBASEREPONSE_H
