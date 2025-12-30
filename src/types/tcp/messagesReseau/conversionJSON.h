//
// Created by remik on 30/12/2025.
//

#ifndef SERVEURCPP_CONVERSIONJSON_H
#define SERVEURCPP_CONVERSIONJSON_H
#include <string>

// NAMESPACES

using namespace std;

namespace serv
{

class ConversionJSON
{
public:
    
    virtual ~ConversionJSON() = default;

    /**
     * Méthode de conversion en JSON.
     * @return Le JSON représenté par l'objet.
     */
    virtual string enJson() const = 0;
};

} // serv

#endif //SERVEURCPP_CONVERSIONJSON_H