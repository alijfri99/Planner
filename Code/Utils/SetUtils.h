#ifndef SETUTILS_H
#define SETUTILS_H
#include<set>
#include "../Model/Predicate.h"

namespace SetUtils
{
    bool is_intersected(const std::set<Predicate> &first, const std::set<Predicate> &second);
}

#endif