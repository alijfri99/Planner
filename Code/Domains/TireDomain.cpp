#include "TireDomain.h"

TireDomain::TireDomain()
{
    this->name = "Tire Domain";

    Object spare("Spare");
    Object flat("Flat");
    Object axle("Axle");
    Object trunk("Trunk");
    Object ground("Ground");
    std::list<Object> tires = {spare, flat};
    std::list<Object> locations = {axle, trunk, ground};

    for(Object tire : tires)
    {
        Predicate at_tire_ground("At", {tire, ground});
        Predicate at_flat_axle("At", {flat, axle});
        Predicate at_tire_axle("At", {tire, axle});

        Predicate put_on_tire_axle_predicate("PutOn", {tire, axle});
        Action put_on_tire_axle(put_on_tire_axle_predicate, 
        {at_tire_ground}, {at_flat_axle}, {at_tire_axle}, {at_tire_ground});

        this->actions[put_on_tire_axle_predicate.get_prehash()] = put_on_tire_axle;

        for(Object location : locations)
        {
            Predicate at_tire_location("At", {tire, location});

            Predicate remove_tire_location_predicate("Remove", {tire, location});
            Action remove_tire_location(remove_tire_location_predicate,
            {at_tire_location}, {}, {at_tire_ground}, {at_tire_location});

            this->actions[remove_tire_location_predicate.get_prehash()] = remove_tire_location;
        }
    }

}

std::string TireDomain::get_name() const
{
    return this->name;
}

std::unordered_map<std::string, Action> TireDomain::get_actions() const
{
    return this->actions;
}