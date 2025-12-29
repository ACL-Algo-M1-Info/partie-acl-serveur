//
// Created by remik on 29/12/2025.
//

#ifndef SERVEURCPP_MESSAGEBASE_H
#define SERVEURCPP_MESSAGEBASE_H

// INCLUSIONS

#include <string>

// NAMESPACES

using namespace std;

namespace serv
{

template <class DATA>
class MessageBase
{
public:

    // CONSTANTES

    /** Le segment décrivant le type de requête. */
    const string SEGMENT_TYPE = "type";

    /** Le segment décrivant les données. */
    const string SEGMENT_DATA = "data";

    // VARIABLES

    /** Type de requête. */
    string type;

    /** Données à stocker. */
    DATA data; //TODO prendre un string ici, peux pas préparser dès le début

    // CONSTRUCTEUR

    /**
     * Constructeur par défaut.
     */
    MessageBase() = default;

    /**
     * Construit un message de base avec le type de requête et les données.
     * @param type Type de requête.
     * @param data Données accompagnées.
     */
    MessageBase(const string& type, const DATA& data): type(type), data(data) {}

    /**
     * Opérateur <<
     */
    friend ostream& operator<<(ostream& s, const MessageBase<DATA>& m)
    {
        return s << (string)m;
    }
};

}  // namespace serv

#endif  // SERVEURCPP_MESSAGEBASE_H
