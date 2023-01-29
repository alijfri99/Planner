#include "SetUtils.h"

bool SetUtils::is_intersected(const std::set<Predicate> &first, const std::set<Predicate> &second)
{
    std::set<Predicate>::const_iterator first_iterator = first.begin();
    std::set<Predicate>::const_iterator second_iterator = second.begin();

    while(first_iterator != first.end() && second_iterator != second.end())
    {
        if(*first_iterator == *second_iterator)
        {
            return true;
        }
        else if(*first_iterator < *second_iterator)
        {
            first_iterator++;
        }
        else
        {
            second_iterator++;
        }
    }
    return false;
}