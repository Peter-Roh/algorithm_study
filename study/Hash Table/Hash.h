#pragma once
#include <cstddef>
#include <string>

class HashTable {
    public:
        HashTable();
        void Add(const std::string& key, int value);
        void Delete(const std::string& key);
        bool Find(const std::string& key) const;
        void PrintHashTable();
        ~HashTable() noexcept;
    private:
        enum { MAX_TABLE = 23 };
        struct Node {
            std::string key;
            int value;
            Node* next;
        };
        Node* mTable[MAX_TABLE];
        size_t mSize = 0;
        unsigned long DJB2(const std::string& str) const;
};
