#include "Predicate.h"

Predicate::Predicate(int name, std::vector<int> objects)
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

std::vector<int> Predicate::get_objects() const
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

    return(this->objects == other.get_objects());
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

    return(this->objects < other.get_objects());
}

bool Predicate::operator > (const Predicate &other) const
{
    if(this->name != other.get_name())
    {
        return this->name > other.get_name();
    }

    return(this->objects > other.get_objects());
}