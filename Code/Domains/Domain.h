#ifndef DOMAIN_H
#define DOMAIN_H
#include<unordered_map>
#include "../Model/Predicate.h"
#include "../Model/Action.h"

class Domain
{
protected:
    std::string name;
    std::unordered_map<std::string, Action> actions;
};

#endif