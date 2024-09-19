#include <stdio.h>

void fibonacci(int n) {
    if (n <= 1) {
        printf("%d ", n);
    } else {
        fibonacci(n-1);
        fibonacci(n-2);
        printf("%d ", n);
    }
}
int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
