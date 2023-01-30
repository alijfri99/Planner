#ifndef ACTION_H
#define ACTION_H
#include "State.h"
#include "Predicate.h"
#include "../Utils/SetUtils.h"

class Action
{
private:
    Predicate action_predicate;
    std::set<Predicate> positive_preconditions;
    std::set<Predicate> negative_preconditions;
    std::set<Predicate> add_list;
    std::set<Predicate> delete_list;
    bool is_unified(const State &state) const;
    bool is_conflicting(const State &state) const;
public:
    Action(Predicate action_predicate, std::set<Predicate> positive_preconditions, std::set<Predicate> negative_preconditions, std::set<Predicate> add_list, std::set<Predicate> delete_list);
    Predicate get_action_predicate() const;
    bool is_relevant(const State &state) const;
    State regress(State * const state) const;
};

#endif