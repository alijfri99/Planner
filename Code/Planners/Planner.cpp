#include "Planner.h"

Planner::Planner(Problem *problem)
{
    this->problem = problem;
}

Planner::~Planner()
{
    delete problem;
}