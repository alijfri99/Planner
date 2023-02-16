#include "LinkRepeatDomain.h"

LinkRepeatDomain::LinkRepeatDomain(int size)
{
    this->name = "Link-repeat Domain";
    this->size = size;

    Predicate g_star(size + 1, {size + 2});
    Action a_star("A*", {}, {}, {g_star}, {});
    actions.push_back(a_star);

    std::vector<Predicate> predicates;

    for(int i = 0; i <= size; i++)
    {
        Predicate g_i(size + 1, {i});
        predicates.push_back(g_i);
    }

    for(int i = 1; i <= size; i++)
    {
        Action a_i("A" + std::to_string(i), {g_star, predicates[i - 1]}, {}, {predicates[i]}, {g_star});
        actions.push_back(a_i);
    }
}

int LinkRepeatDomain::get_size() const
{
    return this->size;
}

void LinkRepeatDomain::define_predicate_names() {}
void LinkRepeatDomain::define_objects() {}
void LinkRepeatDomain::define_actions() {}
