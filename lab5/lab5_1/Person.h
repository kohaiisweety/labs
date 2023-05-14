#pragma once
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual void set_name(string n) { name = n; }
    virtual void set_age(int a) { age = a; }
    virtual string get_name() const { return name; }
    virtual int get_age() const { return age; }
    virtual void print_info() const = 0;
};