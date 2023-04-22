#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Student : public Person {
private:
    string subject;
    int grade;
public:
    Student(string n = "", int a = 0, string sub = "", int g = 0) : Person(n, a), subject(sub), grade(g) {}
    void set_subject(string sub) { subject = sub; }
    void set_grade(int g) { grade = g; }
    string get_subject() const { return subject; }
    int get_grade() const { return grade; }
    void print_info() const;
    void check_grade() const;
};