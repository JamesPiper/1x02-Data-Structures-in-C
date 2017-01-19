//==============================================================================
//
// 2017.01.10 by James Piper, james@jamespiper.com
//
// Infix: A + B or C * D or E - F
// Prefix: + A B, * C D, - E F
// Reverse Prefix or Postfix or Suffix: A B +, C D *, E F -
//
// AKA Polish Notation and Reverse Polish Notation
//
// Five operations to focus on
// 1. + addition
// 2. - subtraction
// 3. * multiplication
// 4. / division
// 5. ^ exponential
//
// Examples of Infix to Postfix
// A + B --> A B +
// A + B - C --> A B + C -
// (A + B) * (C - D) --> A B + C D - *
// ((A + B) * C - (D - E)) ^ (F + G) --> A B + C * D E - - F G - ^
//
// I am confused by the process and the related code.
//
// Comments on the code.
// 1. Why create IsDigit function when ctype.h has one?
// 2. I have the code working but it seems to be a useless bit of code.
//    There is no error checking of inputs so it easily crashes.
// 3. Uses switch statement. Not structured programming b/c of break;
//    I should change to use if...else.
//
//==============================================================================

#include "1x02 Data Structures in C.h"
//#include "_0x01_Stacks.h"

#include <stdio.h>
#include <string.h>

// Moved to main header file (1x02 Data Structures in C.h).
//typedef enum Boolean { False, True } Boolean;

// Moved to _0x01_Stacks.h
typedef struct Stack {
	int Top;
	char S[SIZE_OF_ARRAY_STACK];
} Stack;


// Function prototypes
static void ConvertInfixToPostfix(char*, Stack*, Stack*);
static void Push(Stack*, char item);
static char Pop(Stack*);
static char Peek(Stack*);
static int Priority(char);
static Boolean IsDigit(char);
static Boolean IsHigherOrEqual(int, int);


void _0x02_InfixPostfixNotation() {

	char Infix[SIZE_OF_ARRAY_STACK];
	Stack aStack, Postfix;
	aStack.Top = Postfix.Top = -1;

	printf("Input the infix expression: ");
	//gets(Infix);
	scanf("%s", &Infix);
	ConvertInfixToPostfix(Infix, &aStack, &Postfix);
	printf("The Postfix expression is: %s\n\n", Postfix.S);

}

static void ConvertInfixToPostfix(char infix[], Stack *stack, Stack *postfix) {

	int length;
	char item;
	length = strlen(infix);

	// Insert ')' at the end
	infix[length] = ')';
	// End with null char
	infix[length + 1] = '\0';

	// Start with '('
	Push(stack, '(');

	for (int i = 0; infix[i] != 0; i++) {
		switch (infix[i])
		{
		case ' ':
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			// Pop all the operatos from the stack with prioirty
			// higher than or equal to infix[i]
			while (IsHigherOrEqual(Priority(Peek(stack)), Priority(infix[i]))) {
				item = Pop(stack);
				Push(postfix, item);
				Push(postfix, ' ');
			}
			Push(stack, infix[i]);
			break;
		case '(':
			Push(stack, infix[i]);
			break;
		case ')':
			while ((item = Pop(stack)) !=')') {
				Push(postfix, item);
				Push(postfix, ' ');
			}
			break;
		default:
			if(IsDigit(infix[i]))
			{
				while (IsDigit(infix[i]))
				{
					Push(postfix,infix[i]);
					i++;
				}
				Push(postfix, ' ');
			}
			else
			{
				printf("Incorrect character encountered in infix.\n");
				break;
			}
		}
	}
	Push(postfix, 0);
}

static void Push(Stack* Stack, char item) {
	Stack->S[++Stack->Top] = item;
}

static char Pop(Stack* Stack) {
	return Stack->S[Stack->Top--];
}

static char Peek(Stack* Stack) {
	return Stack->S[Stack->Top];
}

static int Priority(char item) {
	switch (item) {
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

static Boolean IsDigit(char item) {
	if (item >= '0' && item <= '9')
		return True;
	else
		return False;
}

static Boolean IsHigherOrEqual(int A, int B) {
	if (A >= B)
		return True;
	else
		return False;
}
