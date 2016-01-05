/* Topic 15 = Boost Serialization
   for ITSE 34669 advanced C++
   William Bowen w1702335
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// This example serializes a vector<Soldier> using XML archives.
//
// XML requires tags identifying the elements.  XML serialization
// is greatly simplified using the BOOST_SERIALIZATION_NVP macro
// (NVP = name-value pair).  There's ways to control the markup
// tags yourself, but this is by far easier.

#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/nvp.hpp>

class Soldier
{
public:
    string name;
    int rank;
    Soldier(string name, int rank)
    {
        this->name = name;
        this->rank = rank;
    }

    Soldier() {}

    template<typename Archive>
    void serialize(Archive &ar, const unsigned version)
    {
        ar & BOOST_SERIALIZATION_NVP(name) & BOOST_SERIALIZATION_NVP(rank);
    }
};

int main()
{
    vector<Soldier> outVec, inVec;

    outVec.push_back(Soldier("Bart", 9));
    outVec.push_back(Soldier("Lisa", 11));
    outVec.push_back(Soldier("Maggie", 1));
    outVec.push_back(Soldier("Kirk", 35));
    outVec.push_back(Soldier("Scottie", 46));

    cout << "outVec holds " << outVec.size() << " Soldiers:\n\n";

    for (auto it = outVec.begin();	it != outVec.end(); ++it)
        cout << it->name << " is " << it->rank << endl;

    cout << "\nNow serializing outVec to /home/silver/boostSer.xml ...";

    ofstream output("/home/silver/boostSer.xml");
    boost::archive::xml_oarchive xmloarch(output);

    xmloarch & BOOST_SERIALIZATION_NVP(outVec);
    output.close();

    cout << "\n\nNow deserializing /home/silver/boostSer.xml to inVec ...";

    ifstream input("/home/silver/boostSer.xml");
    boost::archive::xml_iarchive xmliarch(input);

    xmliarch & BOOST_SERIALIZATION_NVP(inVec);
    input.close();

    cout << "\n\ninVec holds " << inVec.size() << " Soldiers:\n\n";

    for (auto it = inVec.begin();	it != inVec.end(); ++it)
        cout << it->name << " is " << it->rank << endl;

    return 0;
}
