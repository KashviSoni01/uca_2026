#include <stdio.h>

// Brute Force Approach
long long evenFibSumBrute(int n) {
    long long sum = 0;

    int a = 1, b = 1;

    while (a <= n) {
        if (a % 2 == 0)
            sum += a;

        int next = a + b;
        a = b;
        b = next;
    }

    return sum;
}

// Optimized Approach
long long evenFibSumOptimized(int n) {
    long long sum = 0;

    long long a = 2;
    long long b = 8;

    while (a <= n) {
        sum += a;

        long long next = 4 * b + a;

        a = b;
        b = next;
    }

    return sum;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nBrute Force Approach\n");
    printf("Sum of even Fibonacci numbers = %lld\n", evenFibSumBrute(n));

    printf("\nOptimized Approach\n");
    printf("Sum of even Fibonacci numbers = %lld\n", evenFibSumOptimized(n));

    return 0;
}
