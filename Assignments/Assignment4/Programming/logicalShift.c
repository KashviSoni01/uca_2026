#include <stdio.h>

int logicalShift(int x, int n) {

    int shifted = x >> n;

    int mask = ~(((1 << 31) >> n) << 1);

    return shifted & mask;
}

int main() {

    int x, n;

    printf("Enter x: ");
    scanf("%i", &x);

    printf("Enter shift amount n: ");
    scanf("%d", &n);

    int result = logicalShift(x, n);

    printf("logicalShift(%d, %d) = 0x%x\n", x, n, result);

    return 0;
}
