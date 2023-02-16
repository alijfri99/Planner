#include "TireDomain.h"

TireDomain::TireDomain()
{
    this->name = "Tire Domain";

    this->object_containers["tires"];
    this->object_containers["locations"];

    define_predicate_names();
    define_objects();
    define_actions();
}

void TireDomain::define_predicate_names()
{
    add_word("Ground");
    add_word("Flat");
    add_word("Spare");
    add_word("Axle");
    add_word("Trunk");
    add_word("At");
}

void TireDomain::define_objects()
{
    this->object_containers["tires"].push_back("Flat");
    this->object_containers["tires"].push_back("Spare");
    this->object_containers["locations"].push_back("Axle");
    this->object_containers["locations"].push_back("Trunk");
}

void TireDomain::define_actions()
{
    std::unordered_map<std::string, std::string> other;
    other["Flat"] = "Spare";
    other["Spare"] = "Flat";

    for(std::string tire : this->object_containers["tires"])
    {
        Predicate at_tire_ground(this->codes["At"], {this->codes[tire], this->codes["Ground"]});
        for(std::string location : this->object_containers["locations"])
        {
            std::string remove_action_name = "Remove(" + tire + ", " + location + ")";
            std::string put_action_name = "Put(" + tire + ", " + location + ")";        

            Predicate at_tire_location(this->codes["At"], {this->codes[tire], this->codes[location]});
            Predicate at_other_location(this->codes["At"], {this->codes[other[tire]], this->codes[location]});

            Action remove_action(remove_action_name, {at_tire_location}, {}, {at_tire_ground}, {at_tire_location});
            Action put_action(put_action_name, {at_tire_ground}, {at_other_location}, {at_tire_location}, {at_tire_ground});
            
            this->actions.push_back(remove_action);
            this->actions.push_back(put_action);
        }
    }
}