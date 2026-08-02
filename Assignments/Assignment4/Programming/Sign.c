#include <stdio.h>

int sign(int x) {
    int signBit = x >> 31;
    return signBit | !!x;
}

int main() {

    int x;

    printf("Enter x: ");
    scanf("%d", &x);

    int result = sign(x);

    printf("sign(%d) = %d\n", x, result);

    return 0;
}
