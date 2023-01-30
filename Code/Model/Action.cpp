#include "Action.h"

Action::Action(Predicate action_predicate, std::set<Predicate> positive_preconditions, std::set<Predicate> negative_preconditions, std::set<Predicate> add_list, std::set<Predicate> delete_list)
{
    this->action_predicate = action_predicate;
    this->positive_preconditions = positive_preconditions;
    this->negative_preconditions = negative_preconditions;
    this->add_list = add_list;
    this->delete_list = delete_list;
}

Predicate Action::get_action_predicate() const
{
    return this->action_predicate;
}

bool Action::is_unified(const State &state) const
{
    return(SetUtils::is_intersected(this->add_list, state.get_positive_literals())
        || SetUtils::is_intersected(this->delete_list, state.get_negative_literals()));
}

bool Action::is_conflicting(const State &state) const
{
    return(SetUtils::is_intersected(this->add_list, state.get_negative_literals())
        || SetUtils::is_intersected(this->delete_list, state.get_positive_literals()));
}

bool Action::is_relevant(const State &state) const
{
    return((this->is_unified(state)) && !(this->is_conflicting(state)));
}

State Action::regress(State *const state) const
{
    std::set<Predicate> result_positive_literals = SetUtils::set_union(
        SetUtils::difference(state->get_positive_literals(), this->add_list), this->positive_preconditions
    );
    
    std::set<Predicate> result_negative_literals = SetUtils::set_union(
        SetUtils::difference(state->get_negative_literals(), this->delete_list), this->negative_preconditions
    );

    State result(state, this->get_action_predicate(), result_positive_literals, result_negative_literals);
    return result;
}