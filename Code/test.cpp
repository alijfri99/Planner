#include<iostream>
#include "Model/Predicate.h"
#include "Utils/Constants.h"
#include "Model/State.h"
#include "Utils/SetUtils.h"
#include "Model/Action.h"
#include "Domains/TireDomain.h"
#include "Problems/TireProblem.h"
#include "Planners/BackwardPlanner.h"

int main()
{
    /*Predicate p1(1, {1, 2, 3});
    Predicate p2(2, {3, 4, 5});
    Predicate p3(3, {7, 5, 2});
    Predicate p4(4, {7, 9, 3});
    Predicate p5(1, {1, 2, 3});
    std::cout << (p1 == p1) << " " << (p1 == p5) << " " << (p1 < p2) << " " << (p3 < p2) << std::endl;
    std::cout << (p2 == p3) << std::endl;
    State s(NULL, "", {p2}, {p3, p4});
    Action a("Attach(B, C)", {p1, p3}, {}, {p1, p2}, {});
    std::cout << a.is_relevant(s) << std::endl;
    State s2 = a.regress(&s);
    int sfsd = 2;*/
    TireProblem *tire_problem = new TireProblem(new TireDomain());
    Planner *back = new BackwardPlanner(tire_problem);
    std::list<Action> result = back->search();
    int a = 2;
    delete back;
    int b = 3;
}