#pragma once
#include <cstddef>

class HashTable {
    public:
        HashTable();
        unsigned long DJB2(const char* str) const;
        void Add(const char* key, int value);
        void Delete(const char* key);
        bool Find(const char* key) const;
        void PrintHashTable();
        ~HashTable() noexcept;
    private:
        enum { MAX_TABLE = 23 };
        enum { MAX_KEY = 8};
        struct Node {
            char key[MAX_KEY];
            int value;
            Node* next;
        };
        Node* mTable[MAX_TABLE];
        size_t mSize = 0;
};
