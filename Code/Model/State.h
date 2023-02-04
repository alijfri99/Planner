#ifndef STATE_H
#define STATE_H
#include<set>
#include<string>
#include "Predicate.h"
#include "../Utils/Constants.h"

class State
{
private:
    State *parent;
    std::string action_name;
    std::set<Predicate> positive_literals;
    std::set<Predicate> negative_literals;
    std::size_t prehash;
    std::size_t compute_prehash();
public:
    State(State *parent, std::string action_name, std::set<Predicate> positive_literals, std::set<Predicate> negative_literals);
    State() = default;
    ~State();
    std::string get_action_name() const;
    std::set<Predicate> get_positive_literals() const;
    std::set<Predicate> get_negative_literals() const;
    std::size_t get_prehash() const;
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