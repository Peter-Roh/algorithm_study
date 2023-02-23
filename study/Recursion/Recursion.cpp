#include <iostream>
#include <time.h>

unsigned long long Factorial(unsigned long long n) {
    if(n <= 1ull) {
        return 1ull;
    }

    return n * Factorial(n - 1);
}

unsigned long long FactorialTailRecursive(unsigned long long n, unsigned long long fact) {
    if(n <= 1) {
        return fact;
    }

    return FactorialTailRecursive(n - 1, n * fact);
}

unsigned long long FactorialLoop(unsigned long long n) {
    unsigned long long fact = 1ull;

    for(unsigned long long i = 1ull; i <= n; ++i) {
        fact *= i;
    }

    return fact;
}

void PrintResult(double result, unsigned long long value) {
    std::cout << "수행 시간: " << result << " millisec, " << "결과: " << value << std::endl;
}

int main() {
    clock_t start;
    clock_t end;
    double result;
    unsigned long long fact;

    start = clock();
    fact = Factorial(20);
    end = clock();

    result = (double)(end - start);
    PrintResult(result, fact);

    start = clock();
    fact = FactorialTailRecursive(20, 1);
    end = clock();

    result = (double)(end - start);
    PrintResult(result, fact);

    start = clock();
    fact = FactorialLoop(20);
    end = clock();

    result = (double)(end - start);
    PrintResult(result, fact);
}
