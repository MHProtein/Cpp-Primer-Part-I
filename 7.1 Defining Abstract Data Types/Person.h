#pragma once
#include <string>

class Person
{
public:
    Person();
    Person(std::string NAME, std::string ADDRESS) :name(&NAME), address(&ADDRESS){}
    ~Person();
    auto get_name() const;
    auto get_address() const;
    void set_name(const std::string& Name) const;
    void set_address(const std::string& Address) const;

private:
    std::string* name;
    std::string* address;
};

//Only when the constructors finishes to initialize an object, the object can get a real "constness", thus, we can't define a constructor as a const member function

//