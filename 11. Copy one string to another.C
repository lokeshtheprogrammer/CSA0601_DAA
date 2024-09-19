#include <stdio.h>
#include <string.h>

void copy_string(char src[], char dest[]) {
    strcpy(dest, src);
}

int main() {
    char src[100], dest[100];
    printf("Enter a string: ");
    scanf("%s", src);
    copy_string(src, dest);
    printf("Copied string: %s\n", dest);
    return 0;
}
