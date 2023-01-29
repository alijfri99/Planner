#include<iostream>
#include "Model/Predicate.h"
#include "Utils/SetUtils.h"
#include "Model/State.h"

int main()
{
    Object obj("object1");
    Object obj2("object2");
    Predicate pr1("mypredicate", {obj, obj2});
    Predicate pr2("mypredicate2", {obj});
    Predicate pr3("mypredicate3", {obj2});
    std::cout << pr1.get_prehash() << " " << pr1.print() << std::endl;
    std::cout << SetUtils::is_intersected({pr1, pr2}, {pr2, pr3}) << " " << std::endl;
    std::cout << SetUtils::is_intersected({pr1}, {pr2, pr3}) << " " << std::endl;
    std::cout << SetUtils::is_intersected({pr1}, {pr3, pr1}) << " " << std::endl;
    State state(NULL, pr1, {pr2}, {pr3});
    std::cout << state.get_prehash() << std::endl;
}