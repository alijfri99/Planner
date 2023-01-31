#ifndef PREDICATE_H
#define PREDICATE_H
#include<set>


class Predicate
{
private:
    int name;
    std::set<int> objects;
public:
    Predicate(const int &name, const std::set<int> &objects);
    int get_name() const;
    std::set<int> get_objects() const;
    bool operator == (const Predicate &other) const;
    bool operator < (const Predicate &other) const;
};

#endif