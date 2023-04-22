#include "Header.h"
#include <iostream>

int main() {
    List list1, list2;
    std::cout << "Enter values for list1: ";
    std::cin >> list1;
    std::cout << "Enter values for list2: ";
    std::cin >> list2;

    std::cout << "list1: " << list1 << std::endl;
    std::cout << "list2: " << list2 << std::endl;

    List list3 = list1 * list2;
    std::cout << "list3 = list1 * list2: " << list3 << std::endl;

    std::cout << "Enter index for list1: ";
    int index;
    std::cin >> index;
    std::cout << "list1[" << index << "] = " << list1[index] << std::endl;

    std::cout << "Enter n for list1: ";
    int n;
    std::cin >> n;
    List::Iterator it = list1.begin() + n;
    if (it != list1.end()) {
        std::cout << "list1[" << n << "] = " << *it << std::endl;
    }
    else {
        std::cout << "Invalid index\n";
    }

    return 0;
}
