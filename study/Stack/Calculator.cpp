#include <cassert>
#include <iostream>
#include "Stack.h"

int main(void) {
    // 후위표기법 stack 이용 계산 테스트
    const char expression[] = "245+*33/-"; // 17

    Stack stack = Stack();

    for(int i = 0; expression[i] != '\0'; ++i) {
        char token = expression[i];
        int res = 0;

        if(token >= '0' && token <= '9') {
            stack.Push(token - '0');
        } else {
            int num1 = stack.Pop();
            int num2 = stack.Pop();

            switch (token) {
            case '+':
                res = num2 + num1;
                break;
            case '-':
                res = num2 - num1;
                break;
            case '*':
                res = num2 * num1;
                break;
            case '/':
                res = num2 / num1;
                break;
            default:
                assert(0);
                break;
            }

            stack.Push(res);
        }
    }

    int ans = stack.Pop();

    std::cout << "Answer: " << ans << std::endl;

    return 0;
}
