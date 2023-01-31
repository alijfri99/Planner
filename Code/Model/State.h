#ifndef STATE_H
#define STATE_H
#include<set>
#include<string>
#include "Predicate.h"
#include "../Utils/Constants.h"

class State
{
private:
    State *parent;
    std::string action_name;
    std::set<Predicate*> positive_literals;
    std::set<Predicate*> negative_literals;
    int prehash;
    int compute_prehash();
public:
    State(State *parent, std::string action_name, std::set<Predicate*> positive_literals, std::set<Predicate*> negative_literals);
    State() = default;
    ~State();
    std::string get_action_name() const;
    std::set<Predicate*> get_positive_literals() const;
    std::set<Predicate*> get_negative_literals() const;
    int get_prehash() const;
};

#endif