#include <iostream>
#include "Header.h"

int main() {
    List list1, list2;
    // Input lists
    std::cout << "Enter values for list 1: ";
    std::cin >> list1;
    std::cout << "Enter values for list 2: ";
    std::cin >> list2;

    // Output lists
    std::cout << "List 1: " << list1 << std::endl;
    std::cout << "List 2: " << list2 << std::endl;

    // Access elements by index
    std::cout << "List 1 element at index 2: " << list1[2] << std::endl;
    std::cout << "List 2 element at index 0: " << list2[0] << std::endl;

    // Multiply lists
    try {
        int result = list1 * list2;
        std::cout << "List 1 * List 2 = " << result << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Iterate through list 1
    std::cout << "List 1 elements: ";
    for (List::Iterator it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate through list 2
    std::cout << "List 2 elements: ";
    for (List::Iterator it = list2.begin() + 2; it != list2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}