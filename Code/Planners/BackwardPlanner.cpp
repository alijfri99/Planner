#include "BackwardPlanner.h"

BackwardPlanner::BackwardPlanner(Problem *problem) : Planner(problem) {}

std::list<Action> BackwardPlanner::search()
{
    std::list<Action> result;
    std::queue<State> frontier;
    std::unordered_map<int, State> explored;
    return result;
}

bool BackwardPlanner::goal_test(const State &state)
{
    return(SetUtils::is_subset(state.get_positive_literals(), problem->get_initial_state().get_positive_literals()) 
    && !SetUtils::is_intersected(state.get_negative_literals(), problem->get_initial_state().get_positive_literals())));
}