#include "Domain.h"

std::string Domain::get_name() const
{
    return this->name;
}

std::list<Action> Domain::get_actions() const
{
    return this->actions;
}