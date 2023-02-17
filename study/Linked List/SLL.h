#pragma once
#include <iostream>

template<typename T>
class SLL {
    public:
        SLL();
        void AddNode(const T value);
        void InsertFront(const T value);
        bool Insert(const int index, const T value);
        void Remove(const T value);
        void PrintNodes() const;
        bool Search(const T value) const;
        bool IsEmpty() const;
        int GetSize() const;
        ~SLL() noexcept;
    private:
        struct Node {
            T value;
            Node* next = nullptr;
        };
        Node* mHead;
        int mSize = 0;
};

template<typename T>
SLL<T>::SLL()
    : mHead(nullptr)
{}

template<typename T>
void SLL<T>::AddNode(const T value) {
    Node* node = new Node();
    node->value = value;
    node->next = nullptr;

    ++mSize;

    if(mHead == nullptr) {
        mHead = node;
    } else {
        Node* p = mHead;

        while(p->next != nullptr) {
            p = p->next;
        }

        p->next = node;
    }
}

template<typename T>
void SLL<T>::InsertFront(const T value) {
    Node* NewNode = new Node();
    NewNode->value = value;
    NewNode->next = mHead;

    mHead = NewNode;
    ++mSize;
}

template<typename T>
bool SLL<T>::Insert(const int index, const T value) {
    Node* NewNode = new Node();
    NewNode->value = value;
    bool isFound = true;
    
    Node* p = mHead;
    int i = 0;

    while(i < index - 1) {
        if(p->next == nullptr) {
            isFound = false;
            break;
        }

        p = p->next;
        ++i;
    }

    if(index == 0) {
        NewNode->next = mHead;
        mHead = NewNode;
    } else if(index > 0) {
        NewNode->next = p->next;
        p->next = NewNode;
    }

    return isFound;
}

template<typename T>
void SLL<T>::Remove(const T value) {
    Node** pp = &mHead;

    while(*pp != nullptr) {
        if((*pp)->value == value) {
            Node* temp = *pp;
            *pp = (*pp)->next;
            delete temp;
            --mSize;
            break;
        }

        pp = &(*pp)->next;
    }
}

template<typename T>
void SLL<T>::PrintNodes() const {
    Node* p = mHead;

    std::cout << "Result: ";

    while(p != nullptr) {
        std::cout << p->value;

        if(p->next != nullptr) {
            std::cout << " -> ";
        }

        p = p->next;
    }

    std::cout << std::endl;
}

template<typename T>
bool SLL<T>::Search(const T value) const {
    Node* p = mHead;
    int index = 0;
    bool isFound = false;

    while(p != nullptr) {
        if(p->value == value) {
            isFound = true;
            std::cout << "Value " << value << " found on index: " << index << std::endl;
            break;
        }

        ++index;
        p = p->next;
    }

    if(isFound == false) {
        std::cout << "Could not find " << value << "..." << std::endl;
    }

    return isFound;
}

template<typename T>
bool SLL<T>::IsEmpty() const {
    return mSize == 0;
}

template<typename T>
int SLL<T>::GetSize() const {
    return mSize;
}

template<typename T>
SLL<T>::~SLL() noexcept {
    Node* p = mHead;

    while(p != nullptr) {
        Node* next = p->next;
        delete p;
        p = next;
    }
}
