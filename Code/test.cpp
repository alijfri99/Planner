#include<iostream>
#include "Model/Object.h"

int main()
{
    Object obj("object1");
    std::cout << obj.get_name() << std::endl;
}