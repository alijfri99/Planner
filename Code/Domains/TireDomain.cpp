#include "TireDomain.h"

TireDomain::TireDomain()
{
    this->name = "Tire Domain";

    std::list<std::string> tires = {"flat", "spare"};
    std::list<std::string> locations = {"axle", "trunk"};
    if(lookup_word("ground") == -1)
    {
        add_word("ground");
    }
}