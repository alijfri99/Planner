#ifndef PLANNER_H
#define PLANNER_H
#include<list>
#include<string>
#include "../Problems/Problem.h"
#include "../Model/Action.h"
#include "../Model/State.h"

class Planner
{
protected:
    Problem *problem;
    virtual std::list<State> successor(State * const state) = 0;
    virtual bool goal_test(const State &state) = 0;
    virtual std::list<std::string> build_solution(State *state) = 0;
public:
    Planner(Problem *problem);
    ~Planner();
    virtual std::list<std::string> search() = 0;
};

#endif