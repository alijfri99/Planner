#ifndef OBJECT_H
#define OBJECT_H
#include<string>

class Object
{
private:
    std::string name;
public:
    Object(std::string name);
    std::string get_name() const;
};

#endif