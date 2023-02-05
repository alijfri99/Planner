#ifndef BACKWARDPLANNER_H
#define BACKWARDPLANNER_H
#include<queue>
#include<unordered_set>
#include "Planner.h"
#include "../Utils/SetUtils.h"

class BackwardPlanner : public Planner
{
protected:
    std::vector<State> successor(const State & state, const int &state_index);
    bool goal_test(const State &state);
    std::vector<std::string> build_solution(State &state);
public:
    BackwardPlanner(Problem *problem);
    std::vector<std::string> search();
};

#endif