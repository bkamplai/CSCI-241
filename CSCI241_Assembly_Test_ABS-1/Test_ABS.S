;Author: (Put your name here)
;Description: ATMega2560 AVR assembly language "Test_ABS" program.

#define __SFR_OFFSET 0
#include "avr/io.h"   // AVR processor I/O definitions.

;Internal symbols referenced from external code.

.global Setup_Test_ABS
.global Test_ABS

;External symbols referenced from internal code.

.global AVR_SetupLedPort
.global AVR_SetupBuzzer
.global AVR_SetupButtonA
.global AVR_DisplayR18
.global AVR_Display16BitR18

;-----------------------------------------------------------------
; Setup code called once at start up.

Setup_Test_ABS:
  call  AVR_SetupLedPort    ;Call utility routine to do the work
  call  AVR_SetupBuzzer     ;Call utility routine to do the work
  call  AVR_SetupButtonA    ;Call utility routine to do the work
  ret                       ;Return to our caller

;-----------------------------------------------------------------
; Test_ABS function.  Equivalent to the C-language function:
;
; int Test_ABS(int value);
;
; which takes the signed 16-bit integer passed into the function
; (in R25:R24) and returns its absolute value (in R25:R24).
;
; IMPORTANT: You are limited to modifying r0, r18 through 27, r30, r31.
;            Do NOT modify registers r1 through r17 or r28, r29!

Test_ABS:

;********************* Start of Your Code ***********************

 

;********************** End of Your Code ************************

  ret                 ;Done. Return to our caller  
