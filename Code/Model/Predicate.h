#ifndef PREDICATE_H
#define PREDICATE_H
#include<list>
#include "../Utils/Constants.h"

class Predicate
{
private:
    int name;
    std::list<int> objects;
    std::size_t prehash;
    std::size_t compute_prehash();
public:
    Predicate(int name, std::list<int> objects);
    ~Predicate();
    int get_name() const;
    std::list<int> get_objects() const;
    std::size_t get_prehash() const;
    bool operator == (const Predicate &other) const;
    bool operator != (const Predicate &other) const;
    bool operator < (const Predicate &other) const;
    bool operator > (const Predicate &other) const;
};

#endif