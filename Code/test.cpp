#include<iostream>
#include<unordered_set>
#include "Model/Predicate.h"
#include "Utils/Constants.h"
#include "Model/State.h"
#include "Utils/SetUtils.h"
#include "Model/Action.h"
#include "Domains/DepotsDomain.h"

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
    std::unordered_set<State> uset = {s, s2};
    std::set<Predicate> s1 = {p1};
    std::set<Predicate> s2 = {p3, p5};
    bool sub = SetUtils::is_subset(s1, s2);
    TireProblem *tire_problem = new TireProblem(new TireDomain());
    Planner *back = new BackwardPlanner(tire_problem);
    std::list<std::string> result = back->search();
    delete back;
    int b = 3;*/

    Predicate p2(2, {3, 4, 5});
    Predicate p3(3, {7, 5, 2});
    Predicate p4(4, {7, 9, 3});
    Predicate p5(1, {1, 2, 3});
    std::cout << "GO!" << std::endl;
    Domain *depots = new DepotsDomain(10, 10, 10);
    std::cout << "DONE!" << std::endl;
    int sdf = 2;
}