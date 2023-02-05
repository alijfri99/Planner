#include "BackwardPlanner.h"
#include<iostream>

BackwardPlanner::BackwardPlanner(Problem *problem) : Planner(problem) {}

std::vector<std::string> BackwardPlanner::search()
{
    int counter = 0;
    std::vector<std::string> result;
    std::queue<State*> frontier;
    std::unordered_set<State> reached;
    
    if(goal_test(problem->get_goal_state()))
    {
        return result;
    }
    
    frontier.push(problem->get_goal_state());
    reached.insert(problem->get_goal_state());


    while(!frontier.empty())
    {
        State *current = frontier.front();
        frontier.pop();
        std::cout << counter++ << std::endl;

        std::vector<State> successor_states = successor(&current);

        for(State successor_state : successor_states)
        {
            if(goal_test(successor_state))
            {
                result = build_solution(&successor_state);
                return result;
            }
            if(reached.find(successor_state) == reached.end())
            {
                frontier.push(successor_state);
                reached.insert(successor_state);
            }
        }
    }

    return result;
}

std::vector<State> BackwardPlanner::successor(State * const state)
{
    std::vector<State> result;

    Domain *domain = problem->get_domain();
    std::vector<Action> actions = domain->get_actions();

    for(Action action : actions)
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

std::vector<std::string> BackwardPlanner::build_solution(State *state)
{
    std::cout << "DONE PLANNING!" << std::endl;
}