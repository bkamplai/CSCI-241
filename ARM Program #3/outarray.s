        .arch armv8-a
        .text
        .align 2    

        .global outarray

        // Routine to output an array of 64-bit integers. Upon entry:
        // x0 should contain the base address of the array.
        // x1 should contain the number of integers in the array.
        //
        // Upon return, x0 contains the number of elements actaully output.
        // Note: This routine only outputs negative array values.
outarray:
        stp x29, x30, [sp, -16]!        // Store x29, x30 on stack
        mov x29, sp                     // Stack pointer becomes frame pointer

        // Store x19, x20, x21, x22 contents on stack, so these
        // four registers can be used in this routine. By convention,
        // their values will be preserved across subroutine calls.

        stp x19, x20, [sp, -16]!
        stp x21, x22, [sp, -16]!

//-------------------------------------------------------------------------
        mov x20, x0                     // Array base addr
        mov x21, x1                     // Number of elements
        mov x19, 0                      // Array subscript into register
        mov x22, 0                      // Init count of values output
.outi:  ldr x0, =fmt_1                  // Addr of printf format string
        mov x1, x19                     // Subscript value is next parameter
        ldr x2, [x20, x19, lsl 3]       // Array element contents next parameter
        cmp x2, 0                       // Compare the array element with 0
        bge pos                         // Branch if element is positive
        bl  printf                      // Call "printf" to display results
        add x22, x22, 1                 // Increment value output counter
pos:
        add x19, x19, 1                 // Increment subscript
        cmp x19, x21                    // Processed all array elements?
        bne .outi                       // Branch if not.
        mov x0, x22                     // Set return value of function
//-------------------------------------------------------------------------

        // Restore original x19, x20, x21, x22 contents
        // before returning from this routine.

        ldp x21, x22, [sp], 16
        ldp x19, x20, [sp], 16

        ldp x29, x30, [sp], 16          // Restore x29, x30 from stack
        ret

fmt_1:  .asciz  "Array[%ld] = %ld\n"    // Printf format string