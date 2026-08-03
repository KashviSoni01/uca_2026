#include <stdio.h>

int isPower2(int x) {
    int positive = !(x >> 31);
    int nonZero = !!x;
    int oneBit = !(x & (x + ~0));

    return positive & nonZero & oneBit;
}

int main() {

    int x;

    printf("Enter x: ");
    scanf("%d", &x);

    int result = isPower2(x);

    printf("isPower2(%d) = %d\n", x, result);

    return 0;
}
