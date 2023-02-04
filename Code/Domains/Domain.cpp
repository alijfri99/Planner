#include "Domain.h"

std::string Domain::get_name() const
{
    return this->name;
}

std::list<Action>& Domain::get_actions()
{
    return this->actions;
}

int Domain::get_word_code(const std::string &word)
{
    return this->codes[word];
}

void Domain::add_word(const std::string &word)
{
    this->codes[word] = this->codes.size() + 1;
}