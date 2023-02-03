#ifndef BACKWARDPLANNER_H
#define BACKWARDPLANNER_H
#include<queue>
#include<unordered_map>
#include "Planner.h"
#include "../Utils/SetUtils.h"

class BackwardPlanner : public Planner
{
public:
    BackwardPlanner(Problem *problem);
    std::list<std::string> search();
    std::list<State> successor(State * const state);
    bool goal_test(const State &state);
};

#endif