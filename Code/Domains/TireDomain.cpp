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
    std::list<Object> locations = {axle, trunk};

    for(Object tire : tires)
    {
        Predicate at_tire_ground("At", {tire, ground});

        for(Object location : locations)
        {
            Predicate at_tire_location("At", {tire, location});
            Predicate empty_location("Empty", {location});

            Predicate put_tire_location_predicate("Put", {tire, location});
            Action put_tire_location(put_tire_location_predicate, 
            {at_tire_ground, empty_location}, {}, {at_tire_location}, {at_tire_ground, empty_location});

            this->actions.push_back(put_tire_location);

            Predicate remove_tire_location_predicate("Remove", {tire, location});
            Action remove_tire_location(remove_tire_location_predicate,
            {at_tire_location}, {}, {at_tire_ground, empty_location}, {at_tire_location});

            this->actions.push_back(remove_tire_location);
        }
    }

}