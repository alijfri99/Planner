#ifndef DOMAIN_H
#define DOMAIN_H
#include<vector>
#include<unordered_map>
#include<string>
#include "../Model/Predicate.h"
#include "../Model/Action.h"

class Domain
{
protected:
    std::string name;
    std::vector<Action> actions;
    std::unordered_map<std::string, int> codes;
    std::unordered_map<std::string, std::vector<std::string>> object_containers;
    void add_word(const std::string &word);
    virtual void define_predicate_names() = 0;
    virtual void define_objects() = 0;
    virtual void define_actions() = 0;
public:
    std::string get_name() const;
    std::vector<Action> get_actions();
    int get_word_code(const std::string &word);
};

#endif