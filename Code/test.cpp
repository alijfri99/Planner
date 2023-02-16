#include<iostream>
#include<unordered_set>
#include "Model/Predicate.h"
#include "Utils/Constants.h"
#include "Model/State.h"
#include "Utils/SetUtils.h"
#include "Model/Action.h"
#include "Domains/DepotsDomain.h"
#include "Problems/TireProblem.h"
#include "Problems/LinkRepeatProblem.h"
#include "Planners/BackwardPlanner.h"

int main()
{
    BackwardPlanner back(new LinkRepeatProblem(new LinkRepeatDomain(100)));
    std::vector<std::string> actions = back.search();
    int a = 2;
}