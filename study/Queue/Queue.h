#pragma once
#include <cstddef>

class Queue {
    public:
        Queue();
        void Enqueue(const int n);
        int Dequeue();
        bool SearchValue(const int n);
        bool IsEmpty() const;
        size_t GetCapacity() const;
        size_t GetCount() const;
        void PrintQueue() const;
        ~Queue() = default;
    private:
        size_t GetFront() const;
        size_t GetBack() const;
        enum { CAPACITY = 8 };
        size_t mCount;
        size_t mFront;
        size_t mBack;
        int mNums[CAPACITY];
};
