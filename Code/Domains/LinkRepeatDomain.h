#ifndef LINKREPEATDOMAIN_H
#define LINKREPEATDOMAIN_H
#include "Domain.h"

class LinkRepeatDomain : public Domain
{
private:
    int size;
public:
    LinkRepeatDomain(int size);
    int get_size() const;
};

#endif