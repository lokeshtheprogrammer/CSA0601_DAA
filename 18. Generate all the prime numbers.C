#include <stdio.h>

void generate_primes(int n) {
    int primes[n];
    int count = 0;
    for (int i = 2; i <= n; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            primes[count++] = i;
        }
    }
    printf("Prime numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}
