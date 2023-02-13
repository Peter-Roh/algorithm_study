#include <cassert>
#include <iostream>
#include "Queue.h"

Queue::Queue()
    : mCount(0)
    , mFront(0)
    , mBack(0)
{}

// 평균 시간복잡도 O(1)
void Queue::Enqueue(const int n) {
    assert(mCount < CAPACITY);

    mNums[mBack] = n;

    mBack = (mBack + 1) % CAPACITY;
    ++mCount;
}

// 평균 시간복잡도 O(1)
int Queue::Dequeue() {
    assert(mCount > 0);

    int ret = mNums[mFront];

    mFront = (mFront + 1) % CAPACITY;
    --mCount;

    return ret;
}

// 평균 시간복잡도 O(n)
bool Queue::SearchValue(const int n) {
    assert(mCount > 0);

    Queue temp = Queue();
    bool isFound = false;
    size_t cnt = mCount;

    for(size_t i = 0; i < cnt; ++i) {
        int val = Queue::Dequeue();
        temp.Enqueue(val);
        if(val == n) {
            isFound = true;
        }
    }

    // recover
    size_t temp_cnt = temp.GetCount();

    for(size_t i = 0; i < temp_cnt; ++i) {
        int val = temp.Dequeue();
        Queue::Enqueue(val);
    }

    return isFound;
}

bool Queue::IsEmpty() const {
    return mCount == 0;
}

size_t Queue::GetCapacity() const {
    return CAPACITY;
}

size_t Queue::GetCount() const {
    return mCount;
}

size_t Queue::GetFront() const {
    return mFront;
}

size_t Queue::GetBack() const {
    return mBack;
}

void Queue::PrintQueue() const {
    std::cout << "Result: " ;
    size_t i = mFront;

    for(size_t j = 0; j < mCount; ++j) {
        std::cout << mNums[i++ % CAPACITY] << ' ';
    }

    std::cout << std::endl;
}
