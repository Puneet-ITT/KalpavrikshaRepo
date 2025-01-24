#include <stdio.h>

long long modularFun(long long base, long long expo, long long mod) {
    long long result = 1;
    if (base == 0) 
        return 0;
    base = base % mod;
    while (expo > 0) {
        if (expo % 2 == 1) {
            result = (result * base) % mod;
        }
        expo = expo / 2;
        base = (base * base) % mod;
    }

    return result;
}

int main() {
    long long base, expo, mod;

    printf("Enter base: ");
    if (scanf("%lld", &base) != 1 || base < 0) {
        printf("Enter a non-negative integer.\n");
        return 1;
    }

    printf("Enter exponent: ");
    if (scanf("%lld", &expo) != 1 || expo < 0) {
        printf("Enter a non-negative integer exponent.\n");
        return 1;
    }

    printf("Enter modulus: ");
    if (scanf("%lld", &mod) != 1 || mod <= 0) {
        printf("Enter positive integer.\n");
        return 1;
    }

    long long result = modularFun(base, expo, mod);
    printf("Result: %lld\n", result);

    return 0;
}