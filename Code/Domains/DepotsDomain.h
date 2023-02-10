#ifndef DEPOTSDOMAIN_H
#define DEPOTSDOMAIN_H
#include "Domain.h"

class DepotsDomain : public Domain
{
private:
    std::vector<Predicate> facts;
    int number_of_crates;
    int number_of_locations;
    int number_of_trucks;
    void define_predicate_names();
    void define_objects();
    void define_actions();
    void define_drive_actions();
public:
    DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks);
    //std::vector<Predicate> get_facts();
};

#endif