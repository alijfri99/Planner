#include "State.h"

State::State(State *parent, std::string action_name, std::set<Predicate> positive_literals, std::set<Predicate> negative_literals)
{
    this->parent = parent;
    this->action_name = action_name;
    this->positive_literals = positive_literals;
    this->negative_literals = negative_literals;
    this->prehash = this->compute_prehash();
}

State::~State()
{
    positive_literals.clear();
    negative_literals.clear();
}

std::string State::get_action_name() const
{
    return this->action_name;
}

std::set<Predicate> State::get_positive_literals() const
{
    return this->positive_literals;
}

std::set<Predicate> State::get_negative_literals() const
{
    return this->negative_literals;
}

int State::compute_prehash()
{
    int result = 0;

    for(Predicate positive_literal : this->positive_literals)
    {
        result = (result + (positive_literal.get_prehash() % Constants::prime)) % Constants::prime;
    }

    for(Predicate negative_literal : this->negative_literals)
    {
        result = (result + (negative_literal.get_prehash() % Constants::prime)) % Constants::prime;
    }

    return result;
}

int State::get_prehash() const
{
    return this->prehash;
}