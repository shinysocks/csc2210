#include <stdlib.h>

int main() {
    int *ptr = malloc(10 * sizeof(int));
    free(ptr);
    return 0;
}
