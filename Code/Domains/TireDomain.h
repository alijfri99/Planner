#ifndef TIREDOMAIN_H
#define TIREDOMAIN_H
#include "Domain.h"

class TireDomain : public Domain
{
public:
    TireDomain();
    std::string get_name() const;
    std::list<Action> get_actions() const;
};

#endif