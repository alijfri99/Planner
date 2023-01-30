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

std::set<Predicate> SetUtils::difference(std::set<Predicate> first, const std::set<Predicate> &second)
{
    std::set<Predicate>::iterator first_iterator = first.begin();
    std::set<Predicate>::const_iterator second_iterator = second.begin();

    while(first_iterator != first.end() && second_iterator != second.end())
    {
        if(*first_iterator == *second_iterator)
        {
            first.erase(first_iterator++);
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
    return first;
}

std::set<Predicate> SetUtils::set_union(const std::set<Predicate> &first, const std::set<Predicate> &second)
{
    std::set<Predicate> result;
    std::set<Predicate>::const_iterator first_iterator = first.begin();
    std::set<Predicate>::const_iterator second_iterator = second.begin();
    std::set<Predicate>::const_iterator result_iterator = result.begin();

    while(first_iterator != first.end() && second_iterator != second.end())
    {
        if(*first_iterator < *second_iterator)
        {
            result.insert(result_iterator, *first_iterator);
            first_iterator++;
            result_iterator++;
        }
        else if(*second_iterator < *first_iterator)
        {
            result.insert(result_iterator, *second_iterator);
            second_iterator++;
            result_iterator++;
        }
        else
        {
            result.insert(result_iterator, *first_iterator);
            first_iterator++;
            second_iterator++;
            result_iterator++;
        }
    }

    while(first_iterator != first.end())
    {
        result.insert(result_iterator, *first_iterator);
        first_iterator++;
        result_iterator++;
    }

    while(second_iterator != second.end())
    {
        result.insert(result_iterator, *second_iterator);
        second_iterator++;
        result_iterator++;
    }

    return result;
}