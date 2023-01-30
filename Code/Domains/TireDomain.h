#ifndef TIREDOMAIN_H
#define TIREDOMAIN_H
#include "Domain.h"

class TireDomain : private Domain
{
public:
    TireDomain();
    std::string get_name() const;
    std::unordered_map<std::string, Action> get_actions() const;
};

#endif