#include "Object.h"

Object::Object(std::string name)
{
    this->name = name;
}

std::string Object::get_name() const
{
    return this->name;
}