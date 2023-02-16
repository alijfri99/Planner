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
    void define_lift_actions();
    void define_drop_actions();
    void define_load_actions();
    void define_unload_actions();
    void add_drive_action(std::string &truck, std::string &location_1, std::string &location_2);
    void add_lift_action(std::string &hoist, std::string &crate, std::string &surface, std::string &location);
    void add_drop_action(std::string &hoist, std::string &crate, std::string &surface, std::string &location);
    void add_load_action(std::string &hoist, std::string &crate, std::string &truck, std::string &location);
    void add_unload_action(std::string &hoist, std::string &crate, std::string &truck, std::string &location);
public:
    DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks);
    //std::vector<Predicate> get_facts();
};

#endif