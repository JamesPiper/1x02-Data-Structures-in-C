/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.19
// File        : _0x01_Stacks.h
// Description : Stack data structure header file.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 99.)
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
// from _0x01_Stacks
int Push(Stack*, int);
int Pop(Stack*);
int Peek(Stack*);
Boolean IsEmpty(Stack*);
Boolean IsFull(Stack*);
void Display(Stack*);
// end _0x01_Stacks

// from _0x02_InfixPostfixNotation
void Convert_Infix_To_Postfix(char*, CharStack*, CharStack*);
int Priority(char);
Boolean IsHigherOrEqual(int, int);
int PushChar(CharStack*, char);
char PopChar(CharStack*);
char PeekChar(CharStack*);
Boolean IsDigit(char);
// end _0x02_InfixPostfixNotation

#endif // STACKS_FILE

