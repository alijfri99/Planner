#ifndef PLANNER_H
#define PLANNER_H
#include<list>
#include "../Problems/Problem.h"
#include "../Model/Action.h"

class Planner
{
protected:
    Problem *problem;
public:
    Planner(Problem *problem);
    ~Planner();
    virtual std::list<Action> search() = 0;
};

#endif