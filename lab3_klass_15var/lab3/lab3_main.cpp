#include "Header.h"

int main() {
    Pair p1(1, 2.5);
    Pair p2(3, 4.7);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    Pair p3 = p1 - p2;
    cout << "p1 - p2: " << p3 << endl;

    Pair p4 = p1 + 2;
    cout << "p1 + 2: " << p4 << endl;

    Pair p5 = p1 + 2.5;
    cout << "p1 + 2.5: " << p5 << endl;

    return 0;
}