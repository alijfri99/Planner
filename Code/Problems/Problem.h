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
    Problem(Domain *domain);
    ~Problem();
    State get_initial_state() const;
    State get_goal_state() const;
    Domain* get_domain() const;
};

#endif