    .arch armv8-a
    .text
    .align 2
    .global main
    .type main, %function

    // This is a simple ARM assembly language test skeleton
    // It behaves like a C-language "main" function.
    // Place your ARM assembly code between the dashed lines.
main:
    // main function entry point.

    stp x29, x30, [sp, -16]!    // Store x29, x30 on stack
    mov x29, sp                 // Stack pointer becomes frame pointer
//----------------------------------------------------
    ldr x0, =msg_1              // Load address of message into x0
    bl  outstr                  // Display message
    bl  outhexprefix            // Display hexadecimal prefix
    ldr x0, =value              // Move address of value into x0
    ldr x0, [x0]                // Move value into x0
    bl  outhex16                // Display 64-bit value in hex
    bl  newline                 // Advance to next line

    ldr x0, =msg_2              // Load address of message into x0
    bl  outstr                  // Display message
    bl  outhexprefix            // Display hexadecimal prefix
    ldr x9, =value              // Move address of value into x9
    ldr x9, [x9]                // Move value into x9
    ngc x0, x9                  // Take the two's complement of x9 and store it in x0
    bl  outhex16                // Display 64-bit value in hex
    bl newline                  // Advance to next line

    ldr x0, =msg_3              // Load address of message into x0
    bl  outstr                  // Display message
    bl  outhexprefix            // Display hexadecimal prefix
    ldr x10, =value             // Move address of value into x10
    ldr x10, [x10]              // Move value into x10
    ngc x9, x10                 // Take the two's complement of x9 and store it in x0
    add x0, x10, x9             // Add x10 and x9 together and store it in x0
    bl  outhex16                // Display 64-bit value in hex
    bl newline                  // Advance to next line
//----------------------------------------------------
value:  .quad   0x0123456789ABCDEF
msg_1:  .asciz  "Original value     = "
msg_2:  .asciz  "Negative of value  = "
msg_3:  .asciz  "Sum                = "