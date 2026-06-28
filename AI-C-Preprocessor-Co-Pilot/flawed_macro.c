#include <stdio.h>

#define MAX(a, b) a > b ? a : b

int main() {
    int x = 3, y = 5;
    int result = 1 + MAX(x, y);  // Bug 1: precedence

    int a = 2, b = 1;
    int r2 = MAX(a++, b);        // Bug 2: side effect

    printf("result = %d\n", result);
    printf("a = %d\n", a);
    return 0;
}