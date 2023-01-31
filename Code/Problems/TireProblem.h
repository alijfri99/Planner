#ifndef TIREPROBLEM_H
#define TIREPROBLEM_H
#include "Problem.h"
#include "../Domains/TireDomain.h"
#include "../Model/Predicate.h"
#include "../Model/State.h"

class TireProblem : private Problem
{
    TireProblem(Domain *domain, State initial_state, State goal_state);
};

#endif