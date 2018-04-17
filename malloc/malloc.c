#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    int length = string_length(src);
    char *dup_str = malloc(length + 1);
    while (*src != '\0') {
        *dup_str = *src;
        dup_str++;
        src++;
    }
    *dup_str = '\0';
    return dup_str - length;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. 
*/
void *mem_copy(void *dest, const void *src, int n)
{
    char *src_new = (char *)src;
    char *dest_new = (char *)dest;
    // *dest_new = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        dest_new[i] = src_new[i];
    }
    dest_new[n] = '\0';
    return dest_new;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif