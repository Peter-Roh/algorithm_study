#include <iostream>
#include "Queue.h"

int main() {
    Queue queue = Queue();

    std::cout << "Capacity of queue: " << queue.GetCapacity() << std::endl;
    std::cout << "Inserting values..." << std::endl;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.Enqueue(60);

    queue.PrintQueue(); // 10 20 30 40 50 60

    queue.Dequeue();

    queue.PrintQueue(); // 20 30 40 50 60

    std::cout << "Searching for 50 in the queue..." << std::endl;
    bool isNumExist = queue.SearchValue(50);

    if(isNumExist) {
        std::cout << "Number 50 exists in the stack!" << std::endl;
    }

    queue.PrintQueue(); // 20 30 40 50 60

    size_t cnt = queue.GetCount(); // 
    std::cout << "Number of datas in queue: " << cnt << std::endl;

    return 0;
}
