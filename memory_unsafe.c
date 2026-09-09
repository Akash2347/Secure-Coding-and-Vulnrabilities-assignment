#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(5 * sizeof(int));

    printf("After malloc:\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", 5 * sizeof(int));

    if (ptr == NULL)
        return 1;

    /* Reallocate */
    ptr = realloc(ptr, 10 * sizeof(int));

    printf("\nAfter realloc:\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", 10 * sizeof(int));

    /* Free memory */
    free(ptr);

    printf("\nAfter free:\n");
    printf("Pointer: %p\n", (void *)ptr);

    /* DELIBERATE ERROR: use-after-free */
    ptr[0] = 100;

    printf("Value: %d\n", ptr[0]);

    return 0;
}
