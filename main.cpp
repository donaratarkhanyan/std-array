#include <iostream>
#include "array.h"  // Include your array class definition

int main() {
    // Testing the default constructor
    array<int, 5> arr1 {1, 3, 4, 5, 5};

    // Testing the constructor with initializer list
    array<int, 5> arr2{10, 20, 30, 40, 50};

    // Testing the copy constructor
    array<int, 5> arr3 = arr2;

    // Testing the move constructor
    array<int, 5> arr4 = std::move(arr3);

    // Testing element access
    std::cout << "arr2[2] = " << arr2[2] << std::endl;           // Output: 30
    std::cout << "arr2.at(3) = " << arr2.at(3) << std::endl;     // Output: 40
    std::cout << "arr2.front() = " << arr2.front() << std::endl; // Output: 10
    std::cout << "arr2.back() = " << arr2.back() << std::endl;   // Output: 50

    // Testing data()
    int* dataPtr = arr2.data();
    std::cout << "arr2.data() = " << *dataPtr << std::endl;      // Output: 10

    // Testing size(), max_size(), empty()
    std::cout << "arr2.size() = " << arr2.size() << std::endl;       // Output: 5
    std::cout << "arr2.max_size() = " << arr2.max_size() << std::endl; // Output: 5
    std::cout << "arr2.empty() = " << (arr2.empty() ? "true" : "false") << std::endl; // Output: false

    // Testing fill()
    arr1.fill(100);
    std::cout << "arr1 after fill(100): ";
    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i] << " ";  // Output: 100 100 100 100 100
    }
    std::cout << std::endl;

    // Testing swap()
    std::cout << "Before swap:" << std::endl;
    std::cout << "arr2: ";
    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";  // Output: 10 20 30 40 50
    }
    std::cout << std::endl;

    std::cout << "arr4: ";
    for (size_t i = 0; i < arr4.size(); ++i) {
        std::cout << arr4[i] << " ";  // Output: 10 20 30 40 50
    }
    std::cout << std::endl;

    arr2.swap(arr4);

    std::cout << "After swap:" << std::endl;
    std::cout << "arr2: ";
    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";  // Output: 10 20 30 40 50
    }
    std::cout << std::endl;

    std::cout << "arr4: ";
    for (size_t i = 0; i < arr4.size(); ++i) {
        std::cout << arr4[i] << " ";  // Output: 10 20 30 40 50
    }
    std::cout << std::endl;

    // Testing iterators
    std::cout << "Iterating through arr2 with iterators: ";
    for (auto it = arr2.begin(); it != arr2.end(); ++it) {
        std::cout << *it << " ";  // Output: 10 20 30 40 50
    }
    std::cout << std::endl;

    std::cout << "Iterating through arr2 with reverse iterators: ";
    for (auto rit = arr2.rbegin(); rit != arr2.rend(); ++rit) {
        std::cout << *rit << " ";  // Output: 50 40 30 20 10
    }
    std::cout << std::endl;

    return 0;
}
