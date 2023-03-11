#include "Person.h"

Person::Person()
{
    this->address = new std::string;
    this->name = new std::string;
    *address = " ";
    *name = "Not Named";
}

Person::~Person()
{
    delete this->name;
    delete this->address;
}

void Person::set_name(const std::string& Name) const
{
    *this->name = Name;
}

void Person::set_address(const std::string& Address) const
{
    *this->address = Address;
}

auto Person::get_address() const
{
    return *this->address;
    //though this points to a const Person class, you can still change the value of the string that address points to by dereferencing the address pointer
    //since the const mark only makes this pointer a const
}

auto Person::get_name() const
{
    return *this->name;
}
