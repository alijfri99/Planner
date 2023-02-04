#ifndef BACKWARDPLANNER_H
#define BACKWARDPLANNER_H
#include<queue>
#include<unordered_set>
#include "Planner.h"
#include "../Utils/SetUtils.h"

class BackwardPlanner : public Planner
{
protected:
    std::list<State> successor(State * const state);
    bool goal_test(const State &state);
    std::list<std::string> build_solution(State *state);
public:
    BackwardPlanner(Problem *problem);
    std::list<std::string> search();
};

#endif