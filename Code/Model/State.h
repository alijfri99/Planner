#ifndef STATE_H
#define STATE_H
#include<set>
#include "Predicate.h"

class State
{
private:
    State *parent;
    Predicate action_predicate;
    std::set<Predicate> positive_literals;
    std::set<Predicate> negative_literals;
    std::string prehash;
    std::string compute_prehash() const;
public:
    State(State *parent, Predicate action_predicate, std::set<Predicate> positive_literals, std::set<Predicate> negative_literals);
    Predicate get_action_predicate() const;
    std::set<Predicate> get_positive_literals() const;
    std::set<Predicate> get_negative_literals() const;
    std::string get_prehash() const;
};

#endif