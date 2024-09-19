#include <stdio.h>

int reverse_number(int n) {
    int rev = 0;
    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int rev = reverse_number(n);
    printf("Reverse of the number: %d\n", rev);
    return 0;
}
