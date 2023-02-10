#ifndef TIREDOMAIN_H
#define TIREDOMAIN_H
#include "Domain.h"

class TireDomain : public Domain
{
private:
    void define_predicate_names();
    void define_objects();
    void define_actions();
public:
    TireDomain();
};

#endif