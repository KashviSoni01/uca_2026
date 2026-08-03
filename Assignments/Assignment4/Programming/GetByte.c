#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {

    int x, n;

    printf("Enter x (decimal): ");
    scanf("%d", &x);

    printf("Enter byte number n (0-3): ");
    scanf("%d", &n);

    int result = getByte(x, n);

    printf("getByte(%d, %d) = 0x%x\n", x, n, result);

    return 0;
}

