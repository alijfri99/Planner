#include "BackwardPlanner.h"

BackwardPlanner::BackwardPlanner(Problem *problem) : Planner(problem) {}

std::list<std::string> BackwardPlanner::search()
{
    std::list<std::string> result;
    std::queue<State> frontier;
    std::unordered_map<int, State> explored;
    
    if(goal_test(problem->get_initial_state()))
    {
        return result;
    }
}

bool BackwardPlanner::goal_test(const State &state)
{
    return(SetUtils::is_subset(state.get_positive_literals(), problem->get_initial_state().get_positive_literals()) 
    && !SetUtils::is_intersected(state.get_negative_literals(), problem->get_initial_state().get_positive_literals()));
}