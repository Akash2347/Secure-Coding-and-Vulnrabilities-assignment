#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = NULL;
    size_t size = 5;

    /* malloc */
    ptr = malloc(size * sizeof(int));

    if (ptr == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        return EXIT_FAILURE;
    }

    /* Initialize allocated memory */
    for (size_t i = 0; i < size; i++)
    {
        ptr[i] = 0;
    }

    printf("After malloc:\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n",
           size * sizeof(int));

    /* realloc safely using a temporary pointer */
    size_t new_size = 10;
    int *temp = realloc(ptr, new_size * sizeof(int));

    if (temp == NULL)
    {
        fprintf(stderr, "realloc failed\n");
        free(ptr);
        ptr = NULL;
        return EXIT_FAILURE;
    }

    ptr = temp;

    /* Initialize newly allocated elements */
    for (size_t i = size; i < new_size; i++)
    {
        ptr[i] = 0;
    }

    size = new_size;

    printf("\nAfter realloc:\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n",
           size * sizeof(int));

    /* Free safely */
    free(ptr);
    ptr = NULL;

    printf("\nAfter free:\n");
    printf("Pointer: %p\n", (void *)ptr);

    if (ptr == NULL)
    {
        printf("Pointer is NULL. "
               "Use-after-free prevented.\n");
    }

    return EXIT_SUCCESS;
}
