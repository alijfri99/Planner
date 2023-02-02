#ifndef DOMAIN_H
#define DOMAIN_H
#include<list>
#include<unordered_map>
#include<string>
#include "../Model/Predicate.h"
#include "../Model/Action.h"

class Domain
{
protected:
    std::string name;
    std::list<Action> actions;
    std::unordered_map<std::string, int> codes;
public:
    std::string get_name() const;
    std::list<Action> get_actions() const;
    int lookup_word(const std::string &word);
    void add_word(const std::string &word);
};

#endif