#pragma once
#include <vector>
#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

class Vector {
private:
    vector<Person*> v;
public:
    void add_person(Person* p) { v.push_back(p); }
    void print_all() const;
};
