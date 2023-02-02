#include "Problem.h"

Problem::Problem(Domain *domain)
{
    this->domain = domain;
}

Problem::~Problem()
{
    delete domain;
}

State Problem::get_initial_state() const
{
    return this->initial_state;
}

State Problem::get_goal_state() const
{
    return this->goal_state;
}

Domain* Problem::get_domain() const
{
    return this->domain;
}