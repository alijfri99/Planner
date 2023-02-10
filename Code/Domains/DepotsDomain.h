#ifndef DEPOTSDOMAIN_H
#define DEPOTSDOMAIN_H
#include "Domain.h"

class DepotsDomain : public Domain
{
public:
    DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks);
};

#endif