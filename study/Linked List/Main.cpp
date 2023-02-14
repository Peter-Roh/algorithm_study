#include <iostream>
#include <memory>
#include "SLL.h"

int main() {
    std::unique_ptr<SLL<int>> list = std::make_unique<SLL<int>>();

    list->AddNode(2);
    list->AddNode(3);
    list->AddNode(5);
    list->AddNode(8);

    list->PrintNodes(); // 2 -> 3 -> 5 -> 8
    list->Search(3);

    list->Remove(3);
    list->PrintNodes(); // 2 -> 5 -> 8

    int size = list->GetSize(); // 3
    std::cout << "Size of the list: " << size << std::endl;

    list->InsertFront(1);
    list->PrintNodes(); // 1 -> 2 -> 5 -> 8

    return 0;
}
