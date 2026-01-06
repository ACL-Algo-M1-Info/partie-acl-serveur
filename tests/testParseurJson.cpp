//
// Created by remik on 06/01/2026.
//

// INCLUSIONS

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "utils/json.h"

// NAMESPACES

using namespace std;
using json = nlohmann::json;

class classeTest
{
public:

    int id;

    string nom;

    vector<int> idVoitures;
    map<string, classeTest> conversion;

    classeTest() = default;

    classeTest(int id, const string& nom, const vector<int>& idVoitures, const map<string, classeTest>& conversion)
        : id(id), nom(nom), idVoitures(idVoitures), conversion(conversion)
    {}

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(classeTest, id, nom, idVoitures, conversion);

    operator string() const
    {
        ostringstream s;

        s << "classeTest[id = " << id << ", nom = " << nom << ", idVoitures = [ ";

        for (auto i : idVoitures)
            s << i << " ";
        s << "], conversion = { ";

        map<string, classeTest>::const_iterator it;
        for (it = conversion.begin(); it != conversion.end(); ++it)
            s << "[" << it->first << "] = " << it->second << "\n";
        s << "}]";

        return s.str();
    }

    friend ostream& operator<<(ostream& s, const classeTest& t)
    {
        return s << (string)t;
    }
};

template <class T>
T depuisJson(json& j)
{
    return j;
}

int main()
{
    classeTest test(5, "Rémi", {1, 2, 3}, {{"hi", classeTest()}});
    vector<classeTest> tests = {test, test, test, test};

    json j = tests;

    cout << j << endl;

    vector<classeTest> res = depuisJson<vector<classeTest>>(j);

    for (auto test : res)
        cout << test << endl;

    return 0;
}