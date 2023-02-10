#include <cstddef>

class Array {
    public:
        Array();
        void InsertAt(const size_t index, const int n);
        size_t FindIndex(const int n) const;
        void RemoveAt(const size_t index);
        void RemoveAtUnordered(const size_t index);
        int GetValue(const size_t index) const;
        size_t GetCapacity() const;
        size_t GetCount() const;
        void PrintArray() const;
        ~Array() = default;

    private:
        enum { CAPACITY = 8 };
        size_t mCount;
        int mNums[CAPACITY];
};
