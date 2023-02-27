#include <iostream>

int BinarySearchRecursive(int nums[], int l, int r, int value) {
    int m = (l + r) / 2;

    if(l <= r) {
        if(nums[m] < value) {
            return BinarySearchRecursive(nums, m + 1, r, value);
        } else if(nums[m] > value) {
            return BinarySearchRecursive(nums, l, m - 1, value);
        } else {
            return m;
        }
    } else {
        return -1;
    }
}

int main() {
    int nums[] = { 1, 2, 3, 5, 7, 8, 10, 11, 15, 21, 33, 42, 69, 85, 99};

    int index = BinarySearchRecursive(nums, 0, 14, 42);

    std::cout << "Index of the value: " << index << std::endl;

    index = BinarySearchRecursive(nums, 0, 14, 45);

    std::cout << "Index of the value: " << index << std::endl;

    return 0;
}
