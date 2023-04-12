// Author: Wayne Wall
// Description: Test ATMega2560 Assembly Language absolute value function.

// CSCI Library includes

#include <CSCI_Console.h>   // Console input/output routines.
#include <CSCI_SysUtils.h>  // System utility routines.


// Place your assembly language code in one or more *.S files in the same
// folder as this program.  For example, assume you have some assembly code
// you place in the file "Test_ABS.S".  Here are some conventions:
//
// 1. It's assumed your assembly language code has a "Setup_Test_ABS" subroutine
//    which performs any setup at the assembly language level.  This subroutine
//    is passed nothing and returns nothing.
//
// 2. It's assumed your assembly language code has a "Test_ABS" function which
//    takes a signed integer value passed in and returns the absolute value.

extern "C"
{
  // External assembly language subroutines called from C code.

  void Setup_Test_ABS();    // Setup code for assembly language portion.
  int Test_ABS(int value);  // Function to return the absolute value.

};

// Put your setup code here.  Runs once at power up or reset.

void setup()
{
  ConsoleSetup();     // Setup the console routines.
  Setup_Test_ABS();   // Setup the assembly language test routines.
}

// Put your main code here, which is run repeatedly.

void loop()
{
  // Calculate and display the absolute values of several test numbers.

  DisplayABSValue(-1776);
  DisplayABSValue(1776);

  DisplayABSValue(-1);
  DisplayABSValue(1);

  DisplayABSValue(-0);
  DisplayABSValue(0);

  DisplayABSValue(-32767);
  DisplayABSValue(32767);

  HaltProgram();  // Halt the program. Do not return.
}

// Routine to display the passed value and its absolute value.

void DisplayABSValue(int value)
{
  // Call assembly language function to return the absolute value of the
  // signed value passed into it.
  
  int abs_value = Test_ABS(value);

  DisplayNewline();
  DisplayString("Absolute value of ");
  DisplayInteger(value);
  DisplayString(" = ");
  DisplayInteger(abs_value);
  DisplayNewline();  
}
