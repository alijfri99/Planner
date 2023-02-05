#include "BackwardPlanner.h"
#include<iostream>

BackwardPlanner::BackwardPlanner(Problem *problem) : Planner(problem) {}

std::vector<std::string> BackwardPlanner::search()
{
    int total_state_index = 0;
    std::vector<std::string> result;
    std::queue<int> frontier;
    std::unordered_set<State> reached;
    std::vector<State> all_states;
    
    if(goal_test(problem->get_goal_state()))
    {
        return result;
    }
    
    frontier.push(total_state_index);
    reached.insert(problem->get_goal_state());
    all_states.push_back(problem->get_goal_state());


    while(!frontier.empty())
    {
        int current_state_index = frontier.front();
        frontier.pop();
        State current_state = all_states[current_state_index];

        std::vector<State> successor_states = successor(current_state, current_state_index);

        for(State successor_state : successor_states)
        {
            if(goal_test(successor_state))
            {
                result = build_solution(successor_state, all_states);
                return result;
            }
            if(reached.find(successor_state) == reached.end())
            {
                total_state_index++;
                frontier.push(total_state_index);
                reached.insert(successor_state);
                all_states.push_back(successor_state);
            }
        }
    }

    return result;
}

std::vector<State> BackwardPlanner::successor(const State &state, const int &current_state_index)
{
    std::vector<State> result;

    for(Action action : problem->get_domain()->get_actions())
    {
        if(action.is_relevant(state))
        {
            State successor_state = action.regress(state);
            successor_state.set_parent_index(current_state_index);
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

std::vector<std::string> BackwardPlanner::build_solution(State &state, const std::vector<State> &all_states)
{
    std::cout << "DONE PLANNING!" << std::endl;
}