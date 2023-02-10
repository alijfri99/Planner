#include "DepotsDomain.h"

DepotsDomain::DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks)
{
    this->number_of_crates = number_of_crates;
    this->number_of_locations = number_of_locations;
    this->number_of_trucks = number_of_trucks;

    std::unordered_map<std::string, std::vector<std::string>> object_containers;
    object_containers["crates"];
    object_containers["locations"];
    object_containers["hoists"];
    object_containers["pallets"];
    object_containers["trucks"];

    define_predicate_names();
    define_objects(object_containers);
}

void DepotsDomain::define_predicate_names()
{
    add_word("At");
    add_word("On");
    add_word("In");
    add_word("Lifting");
    add_word("Available");
    add_word("Clear");
}

void DepotsDomain::define_objects(std::unordered_map<std::string, std::vector<std::string>> &object_containers)
{
    for(int i = 1; i <= number_of_crates; i++)
    {
        std::string crate_string = "Crate" + std::to_string(i);
        add_word(crate_string);
        object_containers["crates"].push_back(crate_string);
    }

    for(int i = 1; i <= number_of_locations; i++)
    {
        std::string location_string = "Location" + std::to_string(i);
        std::string hoist_string = "Hoist" + std::to_string(i);
        std::string pallet_string = "Pallet" + std::to_string(i);

        add_word(location_string);
        add_word(hoist_string);
        add_word(pallet_string);

        object_containers["locations"].push_back(location_string);
        object_containers["hoists"].push_back(hoist_string);
        object_containers["pallets"].push_back(pallet_string);

        Predicate at_hoist_location(this->codes["At"], {this->codes[hoist_string], this->codes[location_string]});
        Predicate at_pallet_location(this->codes["At"], {this->codes[pallet_string], this->codes[location_string]});

        this->facts.push_back(at_hoist_location);
        this->facts.push_back(at_pallet_location);
    }

    for(int i = 1; i <= number_of_trucks; i++)
    {
        std::string truck_string = "Truck" + std::to_string(i);
        add_word(truck_string);
        object_containers["trucks"].push_back(truck_string);
    }
}

void DepotsDomain::define_actions(std::unordered_map<std::string, std::vector<std::string>> &object_containers)
{
    
}