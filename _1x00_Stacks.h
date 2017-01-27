/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.19
// File        : _1x00_Stacks.h
// Description : Stack data structure header file.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
/////////////////////////////////////////////////////////////////////////////////////

//#pragma once

#ifndef STACKS_FILE
#define STACKS_FILE

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
#define SIZE_OF_ARRAY_STACK 100

/////////////////////////////////////////////////////////////////////////////////////
// User types.
/////////////////////////////////////////////////////////////////////////////////////
typedef struct _Stack {
	int top;
	int value[SIZE_OF_ARRAY_STACK];
} Stack;

typedef struct _CharStack {
	int top;
	char expression[SIZE_OF_ARRAY_STACK];
} CharStack;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
// from _1x01_Stacks
int Push(Stack*, int);
int Pop(Stack*);
int Peek(Stack*);
Boolean IsEmpty(Stack*);
Boolean IsFull(Stack*);
void Display_Stack(Stack*);
// end _1x01_Stacks

// from _1x02_Infix_Postfix_Notation
Boolean Convert_Infix_To_Postfix(char*, CharStack*, CharStack*);
int Priority(char);
Boolean IsHigherOrEqual(int, int);
int PushChar(CharStack*, char);
char PopChar(CharStack*);
char PeekChar(CharStack*);
Boolean IsDigit(char);
// end _1x02_Infix_Postfix_Notation

#endif // STACKS_FILE

