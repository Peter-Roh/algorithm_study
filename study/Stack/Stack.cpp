#include <cassert>
#include <iostream>
#include "Stack.h"

Stack::Stack()
    : mCount(0)
{}

// 평균 시간복잡도 O(1)
void Stack::Push(const int n) {
    assert(mCount < CAPACITY);
    mNums[mCount++] = n;
}

// 평균 시간복잡도 O(1)
int Stack::Pop() {
    assert(mCount > 0);
    return mNums[--mCount];
}

// 평균 시간복잡도 O(n)
bool Stack::SearchValue(const int n) {
    assert(mCount > 0);
    Stack temp = Stack();
    bool isFound = false;

    for(size_t i = 0; i < mCount; ++i) {
        int val = Stack::Pop();
        temp.Push(val);
        if(val == n) {
            isFound = true;
            break;
        }
    }

    if(isFound) {
        size_t temp_len = temp.GetCount();
        for(size_t j = 0; j < temp_len; ++j) {
            int val = temp.Pop();
            Stack::Push(val);
        }
    }

    return isFound;
}

int Stack::GetTop() const {
    assert(mCount > 0);
    return mNums[mCount - 1];
}

bool Stack::IsEmpty() const {
    return mCount == 0;
}

size_t Stack::GetCapacity() const {
    return CAPACITY;
}

size_t Stack::GetCount() const {
    return mCount;
}

void Stack::PrintStack() const {
    std::cout << "Result: " ;

    for(size_t i = 0; i < mCount; ++i) {
        std::cout << mNums[i] << ' ';
    }

    std::cout << std::endl;
}
