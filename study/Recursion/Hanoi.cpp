#include <iostream>

void HanoiRecursive(int n, int from, int by, int dest) {
    if(n == 1) {
        std::cout << from << " -> " << dest << std::endl;
    } else {
        HanoiRecursive(n - 1, from, dest, by);
        std::cout << from << " -> " << dest << std::endl;
        HanoiRecursive(n - 1, by, from, dest);
    }
}

int main() {
    int n; // 원판 개수

    std::cin >> n;

    int step = pow(2, n) - 1;

    std::cout << "Number of steps: " << step << std::endl;

    HanoiRecursive(n, 1, 2, 3);

    return 0;
}
