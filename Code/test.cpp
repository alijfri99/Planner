#include<iostream>
#include "Model/Predicate.h"
#include "Utils/Constants.h"
#include "Model/State.h"

int main()
{
    {
        State *s = new State(NULL, "Stack(A, B)", {new Predicate(1, {1, 2, 3}), new Predicate(2, {1, 3, 4})}, {new Predicate(1, {3, 5, 8}), new Predicate(2, {8, 7, 11})});
        int a = 2;
    }
    
    
    std::cout << "DONE!" << std::endl;
}