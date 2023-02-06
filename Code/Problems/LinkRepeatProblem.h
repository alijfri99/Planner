#ifndef LINKREPEATPROBLEM_H
#define LINKREPEATPROBLEM_H
#include "Problem.h"
#include "../Domains/LinkRepeatDomain.h"

class LinkRepeatProblem : public Problem
{
public:
    LinkRepeatProblem(Domain *domain);
};

#endif