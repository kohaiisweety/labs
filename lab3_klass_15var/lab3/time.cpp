#include "Header.h"

Pair Pair::operator-(const Pair& t) {
    Pair res;
    res.one = one - t.one;
    res.two = two - t.two;
    return res;
}

Pair Pair::operator+(const double& d) {
    Pair res;
    res.one = one + (int)d;
    res.two = two + (d - (int)d);
    return res;
}

Pair Pair::operator+(const int& n) {
    Pair res;
    res.one = one + n;
    res.two = two;
    return res;
}

istream& operator>>(istream& in, Pair& t) {
    cout << "one: "; in >> t.one;
    cout << "two: "; in >> t.two;
    return in;
}

ostream& operator<<(ostream& out, const Pair& t) {
    return (out << t.one << " : " << t.two);
}
