#ifndef OBJECT_H
#define OBJECT_H
#include<string>

class Object
{
private:
    std::string name;
public:
    Object(std::string name);
    Object() = default;
    std::string get_name() const;
};

#endif