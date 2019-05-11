#ifndef MYDATA_H
#define MYDATA_H

#include <string>
#include <iosfwd>

namespace MyProject
{
class MyData
{
public:
    MyData(int age, const std::string &name, const std::string &secondName);
    int getAge() const;
    std::string getName() const;
    std::string getSecondName() const;
    std::string getFullName() const;

private:
    int _age{18};
    std::string _name;
    std::string _secondName;
};

std::ostream &operator << (std::ostream &os, const MyData &myData);

}

#endif // MYDATA_H
