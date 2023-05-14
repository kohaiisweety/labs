#include "Vector.h"

int main() {
    Person* p1 = new Student("John", 20, "Math", 85);
    Person* p2 = new Student("Mary", 19, "English", 72);
    Person* p3 = new Student("Tom", 21, "Physics", 58);
    Vector vec;
    vec.add_person(p1);
    vec.add_person(p2);
    vec.add_person(p3);
    vec.print_all();
    return 0;
}