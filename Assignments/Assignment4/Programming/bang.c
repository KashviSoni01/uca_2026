#include <stdio.h>

int bang(int x) {
    int negX = ~x + 1;
    int sign = (x | negX) >> 31;
    return sign + 1;
}

int main() {

    int x;

    printf("Enter x: ");
    scanf("%d", &x);

    int result = bang(x);

    printf("bang(%d) = %d\n", x, result);

    return 0;
}
