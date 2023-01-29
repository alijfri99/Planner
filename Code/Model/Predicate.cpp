#include "Predicate.h"

Predicate::Predicate(const std::string &name, const std::list<Object> &objects)
{
    this->name = name;
    this->objects = objects;
    this->prehash = this->compute_prehash();
}

std::string Predicate::compute_prehash() const
{
    std::string result = this->name;
    for(Object object : this->objects)
    {
        result += object.get_name();
    }
    return result;
}

std::string Predicate::get_prehash() const
{
    return this->prehash;
}

std::string Predicate::print() const
{
    std::string result = this->name;
    result += "(";
    std::list<Object>::const_iterator objects_iterator = this->objects.begin();
    while(objects_iterator != this->objects.end())
    {
        result += objects_iterator->get_name();
        objects_iterator++;
        if(objects_iterator != objects.end())
        {
            result += ", ";
        }
    }
    result += ")";
    return result;
}

bool Predicate::operator < (const Predicate &other) const
{
    return this->prehash < other.get_prehash();
}

bool Predicate::operator == (const Predicate &other) const
{
    return this->prehash == other.get_prehash();
}