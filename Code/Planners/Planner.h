#ifndef PLANNER_H
#define PLANNER_H
#include<vector>
#include<string>
#include "../Problems/Problem.h"
#include "../Model/Action.h"
#include "../Model/State.h"

class Planner
{
protected:
    Problem *problem;
    virtual std::vector<State> successor(const State &state, const int &state_index) = 0;
    virtual bool goal_test(const State &state) = 0;
    virtual std::vector<std::string> build_solution(State &state) = 0;
public:
    Planner(Problem *problem);
    ~Planner();
    virtual std::vector<std::string> search() = 0;
};

#endif