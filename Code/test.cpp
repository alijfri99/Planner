#include<iostream>
#include "Model/Object.h"
#include "Model/Predicate.h"
#include "Model/State.h"
#include "Model/Action.h"
#include "Utils/SetUtils.h"

int main()
{
    Object obj1("obj1");
    Object obj2("obj2");
    Object obj3("obj3");
    Object obj4("d");

    Predicate pr("mypredicate1", {obj1, obj2, obj3, obj4});
    Predicate pr2("stack", {obj2, obj4});
    Predicate pr3("attach", {obj1, obj3, obj2});
    Action a(pr, {}, {pr2}, {pr, pr3}, {pr3});
    State state(NULL, a.get_action_predicate(), {pr}, {pr3});
    std::set<Predicate> first = {pr3, pr2, pr};
    std::set<Predicate> second = {pr2};
    std::set<Predicate> difference = SetUtils::difference(first, second);
    std::set<Predicate> myunion = SetUtils::set_union(first, second);
    State result = a.regress(&state);
    bool hmm = a.is_relevant(state);
    std::cout << "DONE!" << std::endl;
}