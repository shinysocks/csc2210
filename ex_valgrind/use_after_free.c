#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 5; // use BEFORE free
    free(ptr);
    return 0;
}
