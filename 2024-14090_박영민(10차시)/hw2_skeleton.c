#include <stdio.h>

// TODO : Fix the macros
#define SQUARE(x) x * x 
#define MIN(a, b) a < b ? a : b 
#define MULTIPLY(x, y) x * y 

int main() {
    int num = 1;
    int a = 20, b = 10;

    printf("num = %d, a = %d, b = %d\n", num, a, b);
    printf("Square of (num + num): %d\n", SQUARE(num + num)); 
    printf("Twice the minimum of (a + 5) and (b - 5): %d\n", 2 * MIN(a + 5, b - 5)); 
    printf("Multiply (a + 1) and (b - 1): %d\n", MULTIPLY(a + 1, b - 1));
    return 0;
}

