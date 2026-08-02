#include <stdio.h>

int fitsBits(int x, int n) {
    int shift = 32 + ~n + 1;
    return !(((x << shift) >> shift) ^ x);
}

int main() {

    int x, n;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    int result = fitsBits(x, n);

    printf("fitsBits(%d, %d) = %d\n", x, n, result);

    return 0;
}
