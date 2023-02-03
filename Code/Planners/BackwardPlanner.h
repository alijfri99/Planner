#ifndef BACKWARDPLANNER_H
#define BACKWARDPLANNER_H
#include "Planner.h"

class BackwardPlanner : public Planner
{
public:
    BackwardPlanner(Problem *problem);
    std::list<Action> search();
};

#endif