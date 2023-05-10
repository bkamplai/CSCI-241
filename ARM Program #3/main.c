// Program to populate an array of 64-bit integers, than call the "outarray"
// function to display the values on the console.

#include <stdio.h>

// Pass function the array base address and the number of elements.
// Function returns the number of elements actually output.

unsigned long outarray(long *array, unsigned long numelements);

int main()
{
    long values[] = { 10, -9, 8, -7, 6, -5, 4, -3, 2, -1 };
    unsigned long numelements = sizeof(values) / sizeof(values[0]);

    // Call subroutine to do the work.

    unsigned long numoutpout = outarray(values, numelements);

    printf("Number of elements output = %lu\n", numoutpout);

    return 0;
}