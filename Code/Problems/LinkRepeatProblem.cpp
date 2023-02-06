#include "LinkRepeatProblem.h"

LinkRepeatProblem::LinkRepeatProblem(Domain *domain) : Problem(domain)
{
    Predicate g_0(((LinkRepeatDomain *) domain)->get_size() + 1, {0});
    Predicate g_n(((LinkRepeatDomain *) domain)->get_size() + 1, {((LinkRepeatDomain *) domain)->get_size()});
    Predicate g_star(((LinkRepeatDomain *) domain)->get_size() + 1, {((LinkRepeatDomain *) domain)->get_size() + 2});
    
    State temp_initial_state("", {g_star, g_0}, {});
    State temp_goal_state("", {g_star, g_n}, {});

    temp_initial_state.set_parent_index(-1);
    temp_goal_state.set_parent_index(-1);
    
    this->initial_state = temp_initial_state;
    this->goal_state = temp_goal_state; 
}