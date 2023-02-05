#ifndef ACTION_H
#define ACTION_H
#include "State.h"
#include "Predicate.h"
#include "../Utils/SetUtils.h"

class Action
{
private:
    std::string action_name;
    std::set<Predicate> positive_preconditions;
    std::set<Predicate> negative_preconditions;
    std::set<Predicate> add_list;
    std::set<Predicate> delete_list;
    bool is_unified(const State &state) const;
    bool is_conflicting(const State &state) const;
public:
    Action(std::string action_name, std::set<Predicate> positive_preconditions, std::set<Predicate> negative_preconditions, std::set<Predicate> add_list, std::set<Predicate> delete_list);
    Action() = default;
    std::string get_action_name() const;
    bool is_relevant(const State &state) const;
    State regress(const State &state) const;
};

#endif