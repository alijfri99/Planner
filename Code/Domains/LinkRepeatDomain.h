#ifndef LINKREPEATDOMAIN_H
#define LINKREPEATDOMAIN_H
#include "Domain.h"

class LinkRepeatDomain : public Domain
{
private:
    int size;
    void define_predicate_names();
    void define_objects();
    void define_actions();
public:
    LinkRepeatDomain(int size);
    int get_size() const;
};

#endif