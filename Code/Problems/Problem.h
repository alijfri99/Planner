#ifndef PROBLEM_H
#define PROBLEM_H
#include "../Model/State.h"
#include "../Domains/Domain.h"

class Problem
{
protected:
    Domain *domain;
    State initial_state;
    State goal_state;
public:
    ~Problem();
};

#endif