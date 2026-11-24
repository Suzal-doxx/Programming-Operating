
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int global_var = 150;  // Data segment
int bss_var;           // BSS segment

int main() {

    int local_var = 30;          // Stack segment
    static int local_static = 20; // Data segment

    int *heap_var = malloc(sizeof(int)); // Heap allocation

    if (heap_var == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *heap_var = 500;

    printf("===== MEMORY SEGMENT ADDRESSES =====\n\n");

    printf("Global variable (Data):  %p\n", (void *)&global_var);

    printf("BSS variable:             %p\n", (void *)&bss_var);

    printf("Local variable (Stack):   %p\n", (void *)&local_var);

    printf("Static variable (Data):   %p\n", (void *)&local_static);

    printf("Heap allocated memory:    %p\n", (void *)heap_var);

    printf("\n===== VARIABLE VALUES =====\n");

    printf("Global variable: %d\n", global_var);
    printf("BSS variable: %d\n", bss_var);
    printf("Local variable: %d\n", local_var);
    printf("Static variable: %d\n", local_static);
    printf("Heap variable: %d\n", *heap_var);

    uintptr_t stack_address = (uintptr_t)&local_var;
    uintptr_t heap_address = (uintptr_t)heap_var;

    uintptr_t difference;

    if (stack_address > heap_address) {
        difference = stack_address - heap_address;
    } else {
        difference = heap_address - stack_address;
    }

    printf("\n===== ADDRESS COMPARISON =====\n");

    printf("Stack address:  %p\n", (void *)&local_var);
    printf("Heap address:   %p\n", (void *)heap_var);

    printf("Address difference: %" PRIuPTR " bytes\n", difference);

    free(heap_var);

    return 0;
}
