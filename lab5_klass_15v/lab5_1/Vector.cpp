#include "Vector.h"

void Vector::print_all() const {
    for (auto p : v) {
        p->print_info();
    }
}