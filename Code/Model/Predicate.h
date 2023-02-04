#ifndef PREDICATE_H
#define PREDICATE_H
#include<vector>
#include "../Utils/Constants.h"

class Predicate
{
private:
    int name;
    std::vector<int> objects;
    std::size_t prehash;
    std::size_t compute_prehash();
public:
    Predicate(int name, std::vector<int> objects);
    ~Predicate();
    int get_name() const;
    std::vector<int> get_objects() const;
    std::size_t get_prehash() const;
    bool operator == (const Predicate &other) const;
    bool operator != (const Predicate &other) const;
    bool operator < (const Predicate &other) const;
    bool operator > (const Predicate &other) const;
};

#endif