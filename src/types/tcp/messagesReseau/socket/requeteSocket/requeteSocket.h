//
// Created by remik on 29/12/2025.
//

#ifndef SERVEURCPP_MESSAGEBASERECU_H
#define SERVEURCPP_MESSAGEBASERECU_H

// INCLUSIONS

#include "exceptions/ErreurFormat/erreurFormat.h"
#include "types/tcp/messagesReseau/codeTypeRequete.h"
#include "utils/json.h"

using json = nlohmann::json;

namespace serv
{

class RequeteSocket
{
public:

    // CONSTANTES

    /** Segment JSON pour le champ du type. */
    static const string SEGMENT_TYPE;

    /** Segment JSON pour le champ de la data. */
    static const string SEGMENT_DATA;

    // VARIABLES

    /** Contenu JSON du jsonMessage initial. */
    string contenuInitial;

    /** JSON obtenu. */
    json jsonMessage;

    /** Type de la requête reçue. */
    CodeTypeRequete type;

    /** Segment de données reçu, au format json. */
    json data;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Construit un jsonMessage reçu et parse le contenu. Doit être un json valide.
     * @param contenuInitial Contenu json en string.
     * @throws json::parse_error Erreur de parsing : json invalide.
     */
    RequeteSocket(const string& contenuInitial)
        : contenuInitial(contenuInitial)
    {
        // Throws un json::parse_error si invalide.
        jsonMessage = json::parse(contenuInitial);

        // Structure incorrecte
        if (!messageRespecteStructure())
            throw ErreurFormat("Message au format invalide");

        this->type = jsonMessage[ SEGMENT_TYPE ].get<CodeTypeRequete>();
        this->data = jsonMessage[ SEGMENT_DATA ];
    }

    // METHODES

    /**
     * Décrit si le json obtenu est un dictionnaire.
     * @return Si le json parsé est un dictionnaire.
     */
    bool messageEstDictionnaire() const
    {
        return jsonMessage.is_object(); // Est un dico <=> est un objet
    }

    /**
     * Détermine si le json obtenu respect a minima la structure attendue {type: string, data: DATA}.
     * @return Si le json parsé respecte la structure minimale.
     */
    bool messageRespecteStructure() const
    {
        return messageEstDictionnaire()
            && jsonMessage.contains(SEGMENT_TYPE)
            && jsonMessage.contains(SEGMENT_DATA);
    }

    // OPERATEURS

    /**
     * Opérateur string
     */
    operator string() const
    {
        return "Message recu : " + this->contenuInitial;
    }

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const RequeteSocket& m)
    {
        return s << (string)m;
    }
};

} // serv

#endif //SERVEURCPP_MESSAGEBASERECU_H