#pragma once
#include <cstddef>

class Stack {
    public:
        Stack();
        void Push(const int n);
        int Pop();
        bool SearchValue(const int n);
        int GetTop() const;
        bool IsEmpty() const;
        size_t GetCapacity() const;
        size_t GetCount() const;
        void PrintStack() const;
        ~Stack() = default;
    private:
        enum { CAPACITY = 8 };
        size_t mCount;
        int mNums[CAPACITY];
};
