#include "Domain.h"

std::string Domain::get_name() const
{
    return this->name;
}

std::list<Action> Domain::get_actions() const
{
    return this->actions;
}

int Domain::lookup_word(const std::string &word)
{
    if(this->codes.find(word) != this->codes.end())
    {
        return this->codes[word];
    }
    return -1;
}

void Domain::add_word(const std::string &word)
{
    this->codes[word] = this->codes.size() + 1;
}