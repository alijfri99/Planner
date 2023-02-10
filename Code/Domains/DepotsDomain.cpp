#include "DepotsDomain.h"

DepotsDomain::DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks)
{
    std::vector<std::string> crates;
    std::vector<std::string> locations;
    std::vector<std::string> hoists;
    std::vector<std::string> pallets;
    std::vector<std::string> trucks;


    for(int i = 1; i <= number_of_crates; i++)
    {
        std::string crate_string = "Crate" + std::to_string(i);
        add_word(crate_string);
        crates.push_back(crate_string);
    }

    for(int i = 1; i <= number_of_locations; i++)
    {
        std::string location_string = "Location" + std::to_string(i);
        std::string hoist_string = "Hoist" + std::to_string(i);
        std::string pallet_string = "Pallet" + std::to_string(i);

        add_word(location_string);
        add_word(hoist_string);
        add_word(pallet_string);

        locations.push_back(location_string);
        hoists.push_back(hoist_string);
        pallets.push_back(pallet_string);
    }

    for(int i = 1; i <= number_of_trucks; i++)
    {
        std::string truck_string = "Truck" + std::to_string(i);
        add_word(truck_string);
        trucks.push_back(truck_string);
    }
}