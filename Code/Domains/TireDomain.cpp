#include "TireDomain.h"

TireDomain::TireDomain()
{
    this->name = "Tire Domain";

    std::list<std::string> tires = {"Flat", "Spare"};
    std::list<std::string> locations = {"Axle", "Trunk"};
    add_word("Ground");
    add_word("Flat");
    add_word("Spare");
    add_word("Axle");
    add_word("Trunk");
    add_word("At");
    add_word("Empty");

    for(std::string tire : tires)
    {
        Predicate at_tire_ground(this->codes["At"], {this->codes[tire], this->codes["Ground"]});
        for(std::string location : locations)
        {
            std::string remove_action_name = "Remove(" + tire + ", " + location + ")";
            std::string put_action_name = "Put(" + tire + ", " + location + ")";        

            Predicate at_tire_location(this->codes["At"], {this->codes[tire], this->codes[location]});
            Predicate empty_location(this->codes["Empty"], {this->codes[location]});

            Action remove_action(remove_action_name, {at_tire_location}, {}, {at_tire_ground, empty_location}, {});
            Action put_action(put_action_name, {at_tire_ground, empty_location}, {}, {at_tire_location}, {at_tire_ground, empty_location});
            
            this->actions.push_back(remove_action);
            this->actions.push_back(put_action);
        }
    }
}