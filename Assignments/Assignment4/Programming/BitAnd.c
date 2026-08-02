#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {

    int x, y;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    int result = bitAnd(x, y);

    printf("bitAnd(%d, %d) = %d\n", x, y, result);

    return 0;
}
