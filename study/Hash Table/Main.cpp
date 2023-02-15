#include <iostream>
#include "Hash.h"

int main() {
    std::unique_ptr<HashTable> table = std::make_unique<HashTable>();

    table->Add("John", 70);
    table->Add("Peter", 90);
    table->Add("Kate", 50);
    table->Add("Kate", 80);
    table->Add("Luke", 20);
    table->Add("Tom", 50);
    table->Add("Adrianna", 10);

    table->Delete("Kate");
    table->PrintHashTable();

    table->Find("Peter");

    return 0;
}
