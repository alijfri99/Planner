#include "State.h"

State::State(State *parent, std::string action_name, std::set<Predicate*> positive_literals, std::set<Predicate*> negative_literals)
{
    this->parent = parent;
    this->action_name = action_name;
    this->positive_literals = positive_literals;
    this->negative_literals = negative_literals;
    this->prehash = this->compute_prehash();
}

State::~State()
{
    std::set<Predicate*>::iterator positive_literals_iterator = positive_literals.begin();
    std::set<Predicate*>::iterator negative_literals_iterator = negative_literals.begin();

    while(positive_literals_iterator != positive_literals.end())
    {
        std::set<Predicate*>::iterator current = positive_literals_iterator;
        positive_literals.erase(positive_literals_iterator++);
        delete *current;
    }

    while(negative_literals_iterator != negative_literals.end())
    {
        std::set<Predicate*>::iterator current = negative_literals_iterator;
        negative_literals.erase(negative_literals_iterator++);
        delete *current;
    }
}

std::string State::get_action_name() const
{
    return this->action_name;
}

std::set<Predicate*> State::get_positive_literals() const
{
    return this->positive_literals;
}

std::set<Predicate*> State::get_negative_literals() const
{
    return this->negative_literals;
}

int State::compute_prehash()
{
    int result = 0;

    for(Predicate *positive_literal : this->positive_literals)
    {
        result = (result + (positive_literal->get_prehash() % Constants::prime)) % Constants::prime;
    }

    for(Predicate *negative_literal : this->negative_literals)
    {
        result = (result + (negative_literal->get_prehash() % Constants::prime)) % Constants::prime;
    }
}

int State::get_prehash() const
{
    return this->prehash;
}