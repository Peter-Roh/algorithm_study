#include <iostream>
#include "Stack.h"

int main() {
    Stack stack = Stack();

    std::cout << "Capacity of stack: " << stack.GetCapacity() << std::endl;

    std::cout << "Inserting values..." << std::endl;

    stack.Push(0);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    stack.PrintStack(); // 0, 1, 2, 3, 4, 5

    stack.Pop();

    stack.PrintStack(); // 0, 1, 2, 3, 4

    std::cout << "Searching for 2 in the stack..." << std::endl;
    bool isNumExist = stack.SearchValue(2);

    if(isNumExist) {
        std::cout << "Number 2 exists in the stack!" << std::endl;
    }

    stack.PrintStack(); // 0, 1, 2, 3, 4

    int top = stack.GetTop(); // 4
    std::cout << "Top value: " << top << std::endl;

    size_t cnt = stack.GetCount(); // 5
    std::cout << "Number of datas in stack: " << cnt << std::endl;

    return 0;
}
