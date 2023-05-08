#include "List.h"
#include "Error.h"
#include <iostream>
#include <exception>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        List a(5);
        List b(6);
        cout << "a: " << a;
        cout << a[5]; 
        cout << "b: " << b;
        List c = a * b; 
        cout << b + 6 << endl;
        cout << b + 7;  
    }
    catch (Error& e) {
        e.what();
    }
    catch (...) {
        cout << "Unknown exception occurred" << endl;
    }
    return 0;
}