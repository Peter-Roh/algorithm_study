#include <iostream>
#include <limits>
#include <string>
#include "Hash.h"

HashTable::HashTable()
    : mSize(0)
{}

unsigned long HashTable::DJB2(const char* str) const {
    unsigned long hash = 5381;
    int c;

    while(c != '\0') {
        c = *str++;
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

void HashTable::Add(const char* key, int value) {
    unsigned long hashValue = HashTable::DJB2(key);

    Node* newNode = new Node();
    std::strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = nullptr;

    if(mTable[hashValue % MAX_TABLE] == nullptr) {
        mTable[hashValue % MAX_TABLE] = newNode;
    } else {
        Node* p = mTable[hashValue % MAX_TABLE];

        while(p->next != nullptr) {
            p = p->next;
        }

        p->next = newNode;
    }

    ++mSize;
}

void HashTable::Delete(const char* key) {
    unsigned long hashValue = HashTable::DJB2(key);
    int index = 0;

    if(mTable[hashValue % MAX_TABLE] != nullptr) {
        Node* p = mTable[hashValue % MAX_TABLE];

        while(p != nullptr) {
            if(std::strcmp(p->key, key) == 0) {
                Node* next = p->next;
                delete p;

                if(index == 0) {
                    mTable[hashValue % MAX_TABLE] = next;
                } else {
                    p = p->next;
                }

                break;
            }

            p = p->next;
            ++index;
        }
    }
}

bool HashTable::Find(const char* key) const {
    bool isFound = false;
    unsigned long hashValue = HashTable::DJB2(key);

    if(mTable[hashValue % MAX_TABLE] != nullptr) {
        Node* p = mTable[hashValue % MAX_TABLE];

        while(p != nullptr) {
            if(std::strcmp(p->key, key) == 0) {
                isFound = true;
                std::cout << "Value found - Key: " << p->key << ", Value: " << p->value << std::endl;
                break;
            }

            p = p->next;
        }
    }

    return isFound;
}

void HashTable::PrintHashTable() {
    std::cout <<"-------------------- Results -------------------- " << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < MAX_TABLE; ++i) {
        Node* p = mTable[i];

        std::cout << "Index " << i << ":" << std::endl;
        std::cout << std::endl;

        while(p != nullptr) {
            std::cout << "    Key: " << p->key << ", Value: " << p->value << std::endl;
            std::cout << std::endl;
            p = p->next;
        }
    }
    std::cout <<"------------------------------------------------- " << std::endl;
}

HashTable::~HashTable() noexcept {
    for(int i = 0; i < MAX_TABLE; ++i) {
        Node* p = mTable[i];

        while(p != nullptr) {
            Node* next = p->next;
            delete p;
            p = next;
        }
    }
}
