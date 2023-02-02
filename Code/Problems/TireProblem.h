#ifndef TIREPROBLEM_H
#define TIREPROBLEM_H
#include "Problem.h"
#include "../Domains/TireDomain.h"
#include "../Model/Predicate.h"
#include "../Model/State.h"

class TireProblem : public Problem
{
public:
    TireProblem(Domain *domain);
};

#endif