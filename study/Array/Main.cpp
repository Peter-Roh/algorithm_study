#include <iostream>
#include "Array.h"

int main() {
    Array array = Array();

    std::cout << "Capacity of array: " << array.GetCapacity() << std::endl;

    std::cout << "Inserting values..." << std::endl;

    array.InsertAt(0, 0);
    array.InsertAt(1, 1);
    array.InsertAt(2, 2);
    array.InsertAt(3, 3);
    array.InsertAt(4, 4);
    array.InsertAt(5, 5);

    array.PrintArray(); // 0 1 2 3 4 5

    array.RemoveAt(1);

    array.PrintArray(); // 0 2 3 4 5

    size_t cnt = array.GetCount(); // 5
    std::cout << "Number of datas in array: " << cnt << std::endl;

    std::cout << "Value of array[2]: " << array.GetValue(2) << std::endl;

    array.RemoveAtUnordered(1);

    array.PrintArray(); // 0 5 3 4

    return 0;
}
