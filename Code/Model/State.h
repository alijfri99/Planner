#ifndef STATE_H
#define STATE_H
#include<set>
#include<string>
#include "Predicate.h"
#include "../Utils/Constants.h"

class State
{
private:
    int parent_index;
    std::string action_name;
    std::set<Predicate> positive_literals;
    std::set<Predicate> negative_literals;
    std::size_t prehash;
    std::size_t compute_prehash();
public:
    State(std::string action_name, std::set<Predicate> positive_literals, std::set<Predicate> negative_literals);
    State() = default;
    ~State();
    void set_parent_index(int parent_index);
    int get_parent_index() const;
    std::string get_action_name() const;
    std::set<Predicate> get_positive_literals() const;
    std::set<Predicate> get_negative_literals() const;
    std::size_t get_prehash() const;
    bool operator== (const State &other) const;
};

namespace std
{
    template <>
    struct hash<State>
    {
        std::size_t operator() (const State &state) const;
    };
}
#endif