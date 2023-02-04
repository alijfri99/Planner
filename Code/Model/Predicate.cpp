#include "Predicate.h"

Predicate::Predicate(int name, std::list<int> objects)
{
    this->name = name;
    this->objects = objects;
    this->prehash = this->compute_prehash();
}

Predicate::~Predicate()
{
    this->objects.clear();
}

int Predicate::get_name() const
{
    return this->name;
}

std::list<int> Predicate::get_objects() const
{
    return this->objects;
}

std::size_t Predicate::get_prehash() const
{
    return this->prehash;
}

std::size_t Predicate::compute_prehash()
{
    std::size_t result = 0;
    result += this->name % Constants::prime;

    for(int object : this->objects)
    {
        result = (result + (object % Constants::prime)) % Constants::prime;
    }

    return result;
}

bool Predicate::operator == (const Predicate &other) const
{
    if(this->name != other.get_name())
    {
        return false;
    }

    if(this->prehash != other.get_prehash())
    {
        return false;
    }

    std::list<int> other_objects = other.get_objects();

    if(this->objects.size() != other_objects.size())
    {
        return false;
    }

    std::list<int>::const_iterator current_iterator = this->objects.begin();
    std::list<int>::const_iterator other_iterator = other_objects.begin();

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

bool Predicate::operator != (const Predicate &other) const
{
    return !(*this == other);
}

bool Predicate::operator < (const Predicate &other) const
{
    if(this->name != other.get_name())
    {
        return this->name < other.get_name();
    }

    std::list<int> other_objects = other.get_objects();
    std::list<int>::const_iterator current_iterator = this->objects.begin();
    std::list<int>::const_iterator other_iterator = other_objects.begin();

    while(current_iterator != this->objects.end() && other_iterator != other_objects.end())
    {
        if(*current_iterator < *other_iterator)
        {
            return true;
        }
        else if(*current_iterator > *other_iterator)
        {
            return false;
        }
        current_iterator++;
        other_iterator++;
    }
    
    if(current_iterator == this->objects.end() && other_iterator != other_objects.end())
    {
        return true;
    }

    return false;
}

bool Predicate::operator > (const Predicate &other) const
{
    return !(*this < other);
}