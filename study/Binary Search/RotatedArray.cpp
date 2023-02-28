#include <iostream>

int IndexOfRotatedArray(int* num, int l, int r, int val) {
    if(l > r) {
        return -1;
    }

    int m = (l + r) / 2;

    if(num[m] == val) {
        return m;
    }

    if(num[l] <= num[m]) {
        if(val >= num[l] && val <= num[m]) {
            return IndexOfRotatedArray(num, l, m - 1, val);
        }

        return IndexOfRotatedArray(num, m + 1, r, val);
    }

    if(val >= num[m] && val <= num[r]) {
        return IndexOfRotatedArray(num, m + 1, r, val);
    }

    return IndexOfRotatedArray(num, l, m - 1, val);
}

int main() {
    int num[] = {20, 25, 26, 28, 32, 33, 1, 3, 5, 7, 10, 11, 19};
    int index;

    index = IndexOfRotatedArray(num, 0, 12, 28);

    std::cout << "Index of value: " << index << std::endl;

    index = IndexOfRotatedArray(num, 0, 12, 3);

    std::cout << "Index of value: " << index << std::endl;

    index = IndexOfRotatedArray(num, 0, 12, 4);

    std::cout << "Index of value: " << index << std::endl;

    return 0;
}
