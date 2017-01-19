/////////////////////////////////////////////////////////////////////////////////////
// 2017.01.19 by James Piper, james@jamespiper.com
//
// Code to evaluate a PostFix expression.
//
// Using //>> to indicate original code I've replaced.
// Using stack functions from _0x01_Stacks.h instead of typing in here.
//
// Running into problems getting postfix expression.
// 'gets' or 'scanf' are breaking up input based on whitespace
// yet need to include whitespace (e.g., 2 3 +).
// Creating GetUserInput function that should work to overcome this.
//
/////////////////////////////////////////////////////////////////////////////////////

#include "1x02 Data Structures in C.h"
#include "_0x01_Stacks.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

// Macros
//>>#define MAX 100

// User-defined types
//>>typedef struct Stack {
//>>    int Top;
//>>    int S[MAX];
//>>    int S[SIZE_OF_ARRAY_STACK];
//>>} Stack;

//typedef enum Boolean { False, True } Boolean;

// Function prototypes
static void GetUserInput(char*);
//static void Push(Stack*, int);
//static int Pop (Stack*);
//static Boolean IsDigit(char);
static int EvaluatePostFixExpression(char*);
static void GetNumber(char*, int*, char*);

void _0x03_EvaluatePostFixExpression() {

    //>>char PostFix[MAX];
    char PostFix[SIZE_OF_ARRAY_STACK];
    int result;

    printf("Enter the postfix expression: ");
    //>>gets(PostFix);
	char Inputs[MAX_INPUT_CHARS];
    GetUserInput(Inputs);
    printf("\n");
    printf("User inputs: '%s'\n", Inputs);

    strncpy(PostFix, Inputs, SIZE_OF_ARRAY_STACK);
    //printf("Expression to evaluate: '%s'", PostFix);

    result = EvaluatePostFixExpression(PostFix);
    printf("Result: %d\n", result);

    system("pause");

}

static void GetUserInput(char* input) {

    // Code to store string expression with spaces in one char array.
    // Example: '2 3 +' + '\n'

    scanf("%s", input);
    char c;
    int i = strlen(input);

    do {
        scanf("%c", &c);
        if (i < MAX_INPUT_CHARS)
            input[i++] = c;
    } while (c != '\n');

    input[i - 1] = '\0';

}

static int EvaluatePostFixExpression(char* postfix) {

    Stack St;
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
            Push(&St, number);
            printf("Number pushed to stack: %d\n", number);
            i--;
        } else {
            op2 = Pop(&St);
            op1 = Pop(&St);
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
            Push(&St, result);
        }
    }

    result = Pop(&St);
    return result;
}

// Using stack functions from _0x01_Stacks.h instead of typing in here.

//static void Push(Stack* stack, int value) {
//
//}

//static int Pop (Stack* stack) {
//    return 0;
//}

//static Boolean IsDigit(char value) {
//    return 0;
//}

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

