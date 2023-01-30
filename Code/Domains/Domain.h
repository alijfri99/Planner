#ifndef DOMAIN_H
#define DOMAIN_H
#include<list>
#include "../Model/Predicate.h"
#include "../Model/Action.h"

class Domain
{
protected:
    std::string name;
    std::list<Action> actions;
};

#endif