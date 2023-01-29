#include "State.h"

State::State(State *parent, Predicate action_predicate, std::set<Predicate> positive_literals, std::set<Predicate> negative_literals)
{
    this->parent = parent;
    this->action_predicate = action_predicate;
    this->positive_literals = positive_literals;
    this->negative_literals = negative_literals;
    this->prehash = this->compute_prehash();
}

Predicate State::get_action_predicate() const
{
    return this->action_predicate;
}

std::set<Predicate> State::get_positive_literals() const
{
    return this->positive_literals;
}

std::set<Predicate> State::get_negative_literals() const
{
    return this->negative_literals;
}

std::string State::compute_prehash() const
{
    std::string result = "";
    std::set<Predicate>::iterator positive_literal = positive_literals.begin();
    std::set<Predicate>::iterator negative_literal = negative_literals.begin();

    while(positive_literal != positive_literals.end() && negative_literal != negative_literals.end())
    {
        std::string positive_literal_prehash = positive_literal->get_prehash();
        std::string negative_literal_prehash = negative_literal->get_prehash();

        if(positive_literal_prehash <= negative_literal_prehash)
        {
            result += positive_literal_prehash;
            positive_literal++;
        }
        else
        {
            result += negative_literal_prehash;
            negative_literal++;
        }
    }

    while(positive_literal != positive_literals.end())
    {
        result += positive_literal->get_prehash();
        positive_literal++;
    }
    while(negative_literal != negative_literals.end())
    {
        result += negative_literal->get_prehash();
        negative_literal++;
    }

    return result;
}

std::string State::get_prehash() const
{
    return this->prehash;
}