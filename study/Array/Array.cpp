#include <cassert>
#include <iostream>
#include "Array.h"

Array::Array()
    : mCount(0)
{}

void Array::InsertAt(const size_t index, const int n) {
    assert(index <= mCount);
    assert(mCount < CAPACITY);

    for(size_t i = mCount; i > index; --i) {
        mNums[i] = mNums[i - 1];
    }

    mNums[index] = n;
    ++mCount;
}

// 찾지 못한 경우 -1 반환
size_t Array::FindIndex(const int n) const {
    for(size_t i = 0; i < mCount; ++i) {
        if(mNums[i] == n) {
            return i;
        }
    }

    return -1; // invalid index
}

// 평균 시간복잡도 O(n)
void Array::RemoveAt(const size_t index) {
    assert(index < mCount);
    --mCount;

    for(size_t i = index; i < mCount; ++i) {
        mNums[i] = mNums[i + 1];
    }
}

/*
    순서 보장되지 않음
    평균 시간복잡도 O(1)
*/
void Array::RemoveAtUnordered(const size_t index) {
    assert(index < mCount);
    mNums[index] = mNums[--mCount];
}

int Array::GetValue(const size_t index) const {
    return mNums[index];
}

size_t Array::GetCapacity() const {
    return CAPACITY;
}

size_t Array::GetCount() const {
    return mCount;
}

void Array::PrintArray() const {
    std::cout << "Result: " ;

    for(size_t i = 0; i < mCount; ++i) {
        std::cout << mNums[i] << ' ';
    }

    std::cout << std::endl;
}
