#include "DepotsDomain.h"

DepotsDomain::DepotsDomain(int number_of_crates, int number_of_locations, int number_of_trucks)
{
    this->number_of_crates = number_of_crates;
    this->number_of_locations = number_of_locations;
    this->number_of_trucks = number_of_trucks;

    this->object_containers["crates"];
    this->object_containers["locations"];
    this->object_containers["hoists"];
    this->object_containers["trucks"];
    this->object_containers["pallets"];

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
    define_lift_actions();
    define_drop_actions();
    define_load_actions();
    define_unload_actions();
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
                    add_drive_action(truck, location_1, location_2);
                }
            }
        }
    }
}

void DepotsDomain::define_lift_actions()
{
    for(std::string hoist : this->object_containers["hoists"])
    {
        for(std::string crate : this->object_containers["crates"])
        {
            for(std::string surface : this->object_containers["crates"])
            {
                if(crate == surface)
                {
                    continue;
                }
                for(std::string location : this->object_containers["locations"])
                {
                    add_lift_action(hoist, crate, surface, location);
                }
            }
            for(std::string surface : this->object_containers["pallets"])
            {
                for(std::string location : this->object_containers["locations"])
                {
                    add_lift_action(hoist, crate, surface, location);
                }
            }
        }
    }
}

void DepotsDomain::define_drop_actions()
{
    for(std::string hoist : this->object_containers["hoists"])
    {
        for(std::string crate : this->object_containers["crates"])
        {
            for(std::string surface : this->object_containers["crates"])
            {
                if(crate == surface)
                {
                    continue;
                }
                for(std::string location : this->object_containers["locations"])
                {
                    add_drop_action(hoist, crate, surface, location);
                }
            }
            for(std::string surface : this->object_containers["pallets"])
            {
                for(std::string location : this->object_containers["locations"])
                {
                    add_drop_action(hoist, crate, surface, location);
                }
            }
        }
    }
}

void DepotsDomain::define_load_actions()
{
    for(std::string hoist : this->object_containers["hoists"])
    {
        for(std::string crate : this->object_containers["crates"])
        {
            for(std::string truck : this->object_containers["trucks"])
            {
                for(std::string location : this->object_containers["locations"])
                {
                    add_load_action(hoist, crate, truck, location);
                }
            }
        }
    }
}

void DepotsDomain::define_unload_actions()
{
    for(std::string hoist : this->object_containers["hoists"])
    {
        for(std::string crate : this->object_containers["crates"])
        {
            for(std::string truck : this->object_containers["trucks"])
            {
                for(std::string location : this->object_containers["locations"])
                {
                    add_unload_action(hoist, crate, truck, location);
                }
            }
        }
    }
}

void DepotsDomain::add_drive_action(std::string &truck, std::string &location_1, std::string &location_2)
{
    std::string drive_action_name = "Drive(" + truck + ", " + location_1 + ", " + location_2 + ")";
    Predicate at_truck_location_1(this->codes["At"], {this->codes[truck], this->codes[location_1]});
    Predicate at_truck_location_2(this->codes["At"], {this->codes[truck], this->codes[location_2]});
    Action drive_action(drive_action_name, {at_truck_location_1}, {}, {at_truck_location_2}, {at_truck_location_1});
    this->actions.push_back(drive_action);
}

void DepotsDomain::add_lift_action(std::string &hoist, std::string &crate, std::string &surface, std::string &location)
{
    std::string lift_action_name = "Lift(" + hoist + ", " + crate + ", " + surface + ", " + location + ")";
                    
    Predicate at_hoist_location(this->codes["At"], {this->codes[hoist], this->codes[location]});
    Predicate available_hoist(this->codes["Available"], {this->codes[hoist]});
    Predicate at_crate_location(this->codes["At"], {this->codes[crate], this->codes[location]});
    Predicate on_crate_surface(this->codes["On"], {this->codes[crate], this->codes[surface]});
    Predicate clear_crate(this->codes["Clear"], {this->codes[crate]});
    Predicate clear_surface(this->codes["Clear"], {this->codes[surface]});
    Predicate lifting_hoist_crate(this->codes["Lifting"], {this->codes[hoist], this->codes[crate]});

    Action lift_action(lift_action_name, {at_hoist_location, available_hoist, at_crate_location, clear_crate}, {},
    {lifting_hoist_crate, clear_surface}, {at_crate_location, clear_crate, available_hoist, on_crate_surface});
    
    this->actions.push_back(lift_action);
}

void DepotsDomain::add_drop_action(std::string &hoist, std::string &crate, std::string &surface, std::string &location)
{
    std::string drop_action_name = "Drop(" + hoist + ", " + crate + ", " + surface + ", " + location + ")";

    Predicate at_hoist_location(this->codes["At"], {this->codes[hoist], this->codes[location]});
    Predicate at_surface_location(this->codes["At"], {this->codes[surface], this->codes[location]});
    Predicate clear_surface(this->codes["Clear"], {this->codes[surface]});
    Predicate lifting_hoist_crate(this->codes["Lifting"], {this->codes[hoist], this->codes[crate]});
    Predicate available_hoist(this->codes["Available"], {this->codes[hoist]});
    Predicate at_crate_location(this->codes["At"], {this->codes[crate], this->codes[location]});
    Predicate clear_crate(this->codes["Clear"], {this->codes[crate]});
    Predicate on_crate_surface(this->codes["On"], {this->codes[crate], this->codes[surface]});

    Action drop_action(drop_action_name, {at_hoist_location, at_surface_location, clear_surface, lifting_hoist_crate}, {},
    {available_hoist, at_crate_location, clear_crate, on_crate_surface}, {lifting_hoist_crate, clear_surface});

    this->actions.push_back(drop_action);
}

void DepotsDomain::add_load_action(std::string &hoist, std::string &crate, std::string &truck, std::string &location)
{
    std::string load_action_name = "Load(" + hoist + ", " + crate + ", " + truck + ", " + location + ")";

    Predicate at_hoist_location(this->codes["At"], {this->codes[hoist], this->codes[location]});
    Predicate at_truck_location(this->codes["At"], {this->codes[truck], this->codes[location]});
    Predicate lifting_hoist_crate(this->codes["Lifting"], {this->codes[hoist], this->codes[crate]});
    Predicate in_crate_truck(this->codes["In"], {this->codes[crate], this->codes[truck]});
    Predicate available_hoist(this->codes["Available"], {this->codes[hoist]});

    Action load_action(load_action_name, {at_hoist_location, at_truck_location, lifting_hoist_crate}, {}, 
    {in_crate_truck, available_hoist}, {lifting_hoist_crate});

    this->actions.push_back(load_action);
}

void DepotsDomain::add_unload_action(std::string &hoist, std::string &crate, std::string &truck, std::string &location)
{
    std::string unload_action_name = "Unload(" + hoist + ", " + crate + ", " + truck + ", " + location + ")";

    Predicate at_hoist_location(this->codes["At"], {this->codes[hoist], this->codes[location]});
    Predicate at_truck_location(this->codes["At"], {this->codes[truck], this->codes[location]});
    Predicate available_hoist(this->codes["Available"], {this->codes[hoist]});
    Predicate in_crate_truck(this->codes["In"], {this->codes[crate], this->codes[truck]});
    Predicate lifting_hoist_crate(this->codes["Lifting"], {this->codes[hoist], this->codes[crate]});

    Action unload_action(unload_action_name, {at_hoist_location, at_truck_location, available_hoist, in_crate_truck}, {},
    {lifting_hoist_crate}, {in_crate_truck, available_hoist});

    this->actions.push_back(unload_action);
}