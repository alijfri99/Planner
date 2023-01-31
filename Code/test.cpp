#include<iostream>
#include "Model/Predicate.h"
#include "Utils/Constants.h"
#include "Model/State.h"
#include "Utils/SetUtils.h"

int main()
{
    Predicate p1(1, {1, 2, 3});
    Predicate p2(2, {3, 4, 5});
    Predicate p3(3, {7, 5, 2});
    Predicate p4(1, {1, 2, 3});

    bool a = (p4 < p3);

    State s(NULL, "Stack(A, B)", {p1, p2}, {p3});
    int sa = 2;
}