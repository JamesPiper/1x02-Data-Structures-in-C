/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.17
// File        : 1x02 Data Structures in C.h
// Description : Main header file.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
/////////////////////////////////////////////////////////////////////////////////////
//
// https://en.wikipedia.org/wiki/C_preprocessor
// http://www.cprogramming.com/tutorial/cpreprocessor.html
//
/////////////////////////////////////////////////////////////////////////////////////

//#pragma once

#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
#define MAX_INPUT_CHARS 255
#define CHOICE_LENGTH 2

/////////////////////////////////////////////////////////////////////////////////////
// Common typedefs
/////////////////////////////////////////////////////////////////////////////////////
typedef enum Boolean { False, True } Boolean;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
void _0x00_MainMenu();

void _1x00_Stacks_Menu();
void _1x01_Stacks();
void _1x02_Infix_Postfix_Notation();
void _1x03_Evaluate_PostFix_Expression();

/////////////////////////////////////////////////////////////////////////////////////
// Library function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
void GetUserInputs(char*, int);

#endif // HEADER_FILE
