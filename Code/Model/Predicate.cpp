#include "Predicate.h"

Predicate::Predicate(const int &name, const std::set<int> &objects)
{
    this->name = name;
    this->objects = objects;
}

int Predicate::get_name() const
{
    return this->name;
}

std::set<int> Predicate::get_objects() const
{
    return this->objects;
}

bool Predicate::operator == (const Predicate &other) const
{
    if(this->name != other.get_name())
    {
        return false;
    }

    if(this->objects.size() != other.get_objects().size())
    {
        return false;
    }

    std::set<int>::const_iterator current_iterator = this->objects.begin();
    std::set<int>::const_iterator other_iterator = other.get_objects().begin();

    while(current_iterator != this->objects.end())
    {
        if(*current_iterator != *other_iterator)
        {
            return false;
        }
        current_iterator++;
        other_iterator++;
    }

    return true;
}

bool Predicate::operator < (const Predicate &other) const
{
    if(this->name != other.get_name())
    {
        return this->name < other.get_name();
    }

    std::set<int>::const_iterator current_iterator = this->objects.begin();
    std::set<int>::const_iterator other_iterator = other.get_objects().begin();

    while(current_iterator != this->objects.end() && other_iterator != other.get_objects().end())
    {
        if(*current_iterator < *other_iterator)
        {
            return true;
        }
        else if(*current_iterator > *other_iterator)
        {
            return false;
        }
        else
        {
            current_iterator++;
            other_iterator++;
        }
    }
    
    if(current_iterator == this->objects.end())
    {
        return true;
    }

    return false;
}