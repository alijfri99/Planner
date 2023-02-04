#include "BackwardPlanner.h"

BackwardPlanner::BackwardPlanner(Problem *problem) : Planner(problem) {}

std::list<std::string> BackwardPlanner::search()
{
    std::list<std::string> result;
    std::queue<State> frontier;
    std::map<int, std::list<State>> explored;
    
    if(goal_test(problem->get_initial_state()))
    {
        return result;
    }
    
    frontier.push(problem->get_initial_state());

    while(!frontier.empty())
    {
        State current = frontier.front();
        frontier.pop();

        if(explored.find(current.get_prehash()) != explored.end())
        {
            std::list<State> successor_states = successor(&current);

            for(State successor_state : successor_states)
            {
                if(explored.find(successor_state.get_prehash()) == explored.end())
                {
                    
                }
            }
        }
    }
}

std::list<State> BackwardPlanner::successor(State * const state)
{
    std::list<State> result;

    for(Action action : problem->get_domain()->get_actions())
    {
        if(action.is_relevant(*state))
        {
            State successor_state = action.regress(state);
            result.push_back(successor_state);
        }
    }

    return result;
}

bool BackwardPlanner::goal_test(const State &state)
{
    return(SetUtils::is_subset(state.get_positive_literals(), problem->get_initial_state().get_positive_literals()) 
    && !SetUtils::is_intersected(state.get_negative_literals(), problem->get_initial_state().get_positive_literals()));
}