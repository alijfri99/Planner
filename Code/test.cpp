#include<iostream>
#include "Model/Predicate.h"

int main()
{
    Object obj("object1");
    Object obj2("object2");
    Predicate pr1("mypredicate", {obj, obj2});
    std::cout << pr1.get_prehash() << " " << pr1.print() << std::endl;
}