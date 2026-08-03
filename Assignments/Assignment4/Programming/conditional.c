#include <stdio.h>

int conditional(int x, int y, int z) {
    int mask = !!x;
    mask = ~mask + 1;

    return (mask & y) | (~mask & z);
}

int main() {

    int x, y, z;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter y: ");
    scanf("%d", &y);

    printf("Enter z: ");
    scanf("%d", &z);

    int result = conditional(x, y, z);

    printf("conditional(%d, %d, %d) = %d\n", x, y, z, result);

    return 0;
}
