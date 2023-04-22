#include <iostream>
#include "Student.h"
using namespace std;

void Student::print_info() const {
    cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << ", Grade: " << grade << endl;
}

void Student::check_grade() const {
    if (grade < 60) {
        cout << "Warning: Unsatisfactory grade!" << endl;
    }
}