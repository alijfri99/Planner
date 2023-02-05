#include "TireProblem.h"

TireProblem::TireProblem(Domain *domain) : Problem(domain)
{
    Predicate at_flat_axle(domain->get_word_code("At"), 
    {domain->get_word_code("Flat"), domain->get_word_code("Axle")});

    Predicate at_spare_trunk(domain->get_word_code("At"),
    {domain->get_word_code("Spare"), domain->get_word_code("Trunk")});

    Predicate at_spare_axle(domain->get_word_code("At"),
    {domain->get_word_code("Spare"), domain->get_word_code("Axle")});

    Predicate at_flat_trunk(domain->get_word_code("At"),
    {domain->get_word_code("Flat"), domain->get_word_code("Trunk")});

    State temp_initial_state("", {at_flat_axle, at_spare_trunk}, {});
    State temp_goal_state("", {at_spare_axle, at_flat_trunk}, {});

    temp_initial_state.set_parent_index(-1);
    temp_goal_state.set_parent_index(-1);

    this->initial_state = temp_initial_state;
    this->goal_state = temp_goal_state;
}