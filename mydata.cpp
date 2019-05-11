#include "mydata.h"
#include <iostream>

namespace MyProject
{

MyData::MyData(int age, const std::string &name, const std::string &secondName)
    : _age(age), _name(name), _secondName(secondName)
{
}

int MyData::getAge() const
{
    return _age;
}

std::string MyData::getName() const
{
    return _name;
}

std::string MyData::getSecondName() const
{
    return _secondName;
}

std::string MyData::getFullName() const
{
    return _name + " " + _secondName;
}

std::ostream &operator <<(std::ostream &os, const MyData &myData)
{
    return os << "[" << "Age: " << myData.getAge() << ", FullName: " <<  myData.getName() << "]";
}

}
