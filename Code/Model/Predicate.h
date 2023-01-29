#ifndef PREDICATE_H
#define PREDICATE_H
#include<list>
#include "Object.h"

class Predicate
{
private:
    std::string name;
    std::list<Object> objects;
    std::string prehash;
    std::string compute_prehash() const;
public:
    Predicate(const std::string &name, const std::list<Object> &objects);
    Predicate() = default;
    std::string get_prehash() const;
    std::string print() const;
    bool operator < (const Predicate &other) const;
    bool operator == (const Predicate &other) const;
};

#endif