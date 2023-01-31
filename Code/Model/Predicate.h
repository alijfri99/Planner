#ifndef PREDICATE_H
#define PREDICATE_H
#include<set>
#include "../Utils/Constants.h"

class Predicate
{
private:
    int name;
    std::set<int> objects;
    int prehash;
    int compute_prehash();
public:
    Predicate(int name, std::set<int> objects);
    ~Predicate();
    int get_name() const;
    std::set<int> get_objects() const;
    int get_prehash() const;
    bool operator == (const Predicate &other) const;
    bool operator < (const Predicate &other) const;
};

#endif