#include <stdio.h>

void strcpy_recursive(char *dest, char *src) {
    if (*src == '\0') {
        *dest = '\0';
        return;
    }
    *dest = *src;
    strcpy_recursive(dest + 1, src + 1);
}

int main() {
    char src[] = "Hello, World!";
    char dest[20];
    strcpy_recursive(dest, src);
    printf("Copied string: %s\n", dest);
    return 0;
}
