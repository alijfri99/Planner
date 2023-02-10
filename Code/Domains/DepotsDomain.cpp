#include "DepotsDomain.h"

DepotsDomain::DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks)
{
    this->number_of_crates = number_of_crates;
    this->number_of_locations = number_of_locations;
    this->number_of_trucks = number_of_trucks;

    this->object_containers["crates"];
    this->object_containers["locations"];
    this->object_containers["hoists"];
    this->object_containers["pallets"];
    this->object_containers["trucks"];

    define_predicate_names();
    define_objects();
    define_actions();
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

void DepotsDomain::define_objects()
{
    for(int i = 1; i <= number_of_crates; i++)
    {
        std::string crate_string = "Crate" + std::to_string(i);
        add_word(crate_string);
        this->object_containers["crates"].push_back(crate_string);
    }

    for(int i = 1; i <= number_of_locations; i++)
    {
        std::string location_string = "Location" + std::to_string(i);
        std::string hoist_string = "Hoist" + std::to_string(i);
        std::string pallet_string = "Pallet" + std::to_string(i);

        add_word(location_string);
        add_word(hoist_string);
        add_word(pallet_string);

        this->object_containers["locations"].push_back(location_string);
        this->object_containers["hoists"].push_back(hoist_string);
        this->object_containers["pallets"].push_back(pallet_string);

        Predicate at_hoist_location(this->codes["At"], {this->codes[hoist_string], this->codes[location_string]});
        Predicate at_pallet_location(this->codes["At"], {this->codes[pallet_string], this->codes[location_string]});

        this->facts.push_back(at_hoist_location);
        this->facts.push_back(at_pallet_location);
    }

    for(int i = 1; i <= number_of_trucks; i++)
    {
        std::string truck_string = "Truck" + std::to_string(i);
        add_word(truck_string);
        this->object_containers["trucks"].push_back(truck_string);
    }
}

void DepotsDomain::define_actions()
{
    define_drive_actions();
}

void DepotsDomain::define_drive_actions()
{
    for(std::string truck : this->object_containers["trucks"])
    {
        for(std::string location_1 : this->object_containers["locations"])
        {
            for(std::string location_2 : this->object_containers["locations"])
            {
                if(location_1 != location_2)
                {
                    std::string drive_action_name = "Drive(" + truck + ", " + location_1 + ", " + location_2 + ")";
                    Predicate at_truck_location_1(this->codes["At"], {this->codes[truck], this->codes[location_1]});
                    Predicate at_truck_location_2(this->codes["At"], {this->codes[truck], this->codes[location_2]});
                    Action drive_action(drive_action_name, {at_truck_location_1}, {}, {at_truck_location_2}, {at_truck_location_1});
                    this->actions.push_back(drive_action);
                }
            }
        }
    }
}