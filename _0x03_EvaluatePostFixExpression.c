/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.19
// File        : _0x02_InfixPostfixNotation.c
// Description : Code to evaluate a postfix expression.
//             : e.g., '2 2 +' evaluates to 4.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 99.)
/////////////////////////////////////////////////////////////////////////////////////
//
// Using stack functions from _0x01_Stacks.h instead of typing in here.
// Except there are based on int data and this code requires char.
//
// Running into problems getting postfix expression.
// 'gets' or 'scanf' are breaking up input based on whitespace
// yet need to include whitespace (e.g., 2 3 +).
// Creating GetUserInput function that should work to overcome this.
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
#include "_0x01_Stacks.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
// see _0x01_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////
// see _0x01_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
/////////////////////////////////////////////////////////////////////////////////////
// see _0x01_Stacks.h
static int EvaluatePostFixExpression(char*);
static void GetNumber(char*, int*, char*);

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _0x03_EvaluatePostFixExpression() {

    //>>char PostFix[MAX];
    char PostFix[SIZE_OF_ARRAY_STACK];
    int result;

    printf("Enter the postfix expression: ");
	char Inputs[MAX_INPUT_CHARS];
    GetUserInputs(Inputs, CHOICE_LENGTH);
    printf("\n");
    printf("User inputs: '%s'\n", Inputs);

    strncpy(PostFix, Inputs, SIZE_OF_ARRAY_STACK);
    //printf("Expression to evaluate: '%s'", PostFix);

    result = EvaluatePostFixExpression(PostFix);
    printf("Result: %d\n", result);

    system("pause");

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions
/////////////////////////////////////////////////////////////////////////////////////

static int EvaluatePostFixExpression(char* postfix) {

    CharStack St;
    int number, result, op1, op2;
    char StrNumber[SIZE_OF_ARRAY_STACK];
    St.Top = -1;
    printf("Expression to evaluate in function: '%s'\n", postfix);

    for (int i = 0; postfix[i] != 0; i++) {
        printf("For loop #%d\n", i);
        if (postfix[i] == ' ' || postfix[i] == ',') {
            printf("Ignoring space:\n");
            continue;
        }
        if (IsDigit(postfix[i])) {
            GetNumber(postfix, &i, StrNumber);
            number = atoi(StrNumber);
            PushChar(&St, number);
            printf("Number pushed to stack: %d\n", number);
            i--;
        } else {
            op2 = PopChar(&St);
            op1 = PopChar(&St);
            switch (postfix[i]) {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '/':
                // No error checking if op2 is zero.
                result = op1 / op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '^':
                // op1, op2 declared as ints, pow takes double
                // Is there automatic type casting?
                result = pow(op1, op2);
                break;
            default:
                printf("Unrecognizable operation.\n");
                exit(1);
            }
            PushChar(&St, result);
        }
    }

    result = PopChar(&St);
    return result;
}

//>>static void GetNumber(char* postfix[SIZE_OF_ARRAY_STACK], int* index, char* numbers[SIZE_OF_ARRAY_STACK]) {
static void GetNumber(char* postfix, int* index, char* numbers) {

    printf("In GetNumber function.\n");
    printf("Using this expression: '%s'\n", postfix);
    printf("Starting index is %d\n", *index);

    int j = 0;
    while (IsDigit(postfix[*index])) {
        printf("A digit (%d) is a number.\n", postfix[*index]);
        numbers[j++] = postfix[*index++];
        printf("The string of numbers is: %s\n", numbers);
    }
    numbers[j] = '\0';
}

