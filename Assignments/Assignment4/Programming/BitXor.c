#include <stdio.h>

int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}

int main() {

    int x, y;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    int result = bitXor(x, y);

    printf("bitXor(%d, %d) = %d\n", x, y, result);

    return 0;
}
