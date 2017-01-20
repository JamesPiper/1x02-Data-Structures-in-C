/////////////////////////////////////////////////////////////////////////////////////
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
// 4. The code in _0x01_Stacks creates an int stack.
//    This code uses a char stack.
//    C isn't designed for overloading so need to distinguish
//    between a char stack and int stack.
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
#include "_0x01_Stacks.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
// Moved to main header file (1x02 Data Structures in C.h).
// see _0x01_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////
// see _0x01_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
/////////////////////////////////////////////////////////////////////////////////////
static int Priority(char);
static void ConvertInfixToPostfix(char*, CharStack*, CharStack*);
static Boolean IsHigherOrEqual(int, int);
//void PushChar(CharStack*, char item);
//char PopChar(CharStack*);
//char PeekChar(CharStack*);
//Boolean IsDigit(char);


/////////////////////////////////////////////////////////////////////////////////////
// Main functions
/////////////////////////////////////////////////////////////////////////////////////
void _0x02_InfixPostfixNotation() {

	CharStack Stack, Postfix;
	Stack.Top = Postfix.Top = -1;

	printf("Input the infix expression: ");
	char Infix[SIZE_OF_ARRAY_STACK];
	GetUserInputs(Infix, SIZE_OF_ARRAY_STACK);
	ConvertInfixToPostfix(Infix, &aStack, &Postfix);
	printf("The Postfix expression is: %s\n\n", Postfix.S);

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions
/////////////////////////////////////////////////////////////////////////////////////
static void ConvertInfixToPostfix(char infix[], CharStack *stack, CharStack *postfix) {

	int length;
	char item;
	length = strlen(infix);

	// Insert ')' at the end
	infix[length] = ')';
	// End with null char
	infix[length + 1] = '\0';

	// Start with '('
	PushChar(stack, '(');

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
			while (IsHigherOrEqual(Priority(PeekChar(stack)), Priority(infix[i]))) {
				item = PopChar(stack);
				PushChar(postfix, item);
				PushChar(postfix, ' ');
			}
			PushChar(stack, infix[i]);
			break;
		case '(':
			PushChar(stack, infix[i]);
			break;
		case ')':
			while ((item = PopChar(stack)) !=')') {
				PushChar(postfix, item);
				PushChar(postfix, ' ');
			}
			break;
		default:
			if(IsDigit(infix[i]))
			{
				while (IsDigit(infix[i]))
				{
					PushChar(postfix,infix[i]);
					i++;
				}
				PushChar(postfix, ' ');
			}
			else
			{
				printf("Incorrect character encountered in infix.\n");
				break;
			}
		}
	}
	PushChar(postfix, 0);
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

static Boolean IsHigherOrEqual(int A, int B) {
	if (A >= B)
		return True;
	else
		return False;
}

Boolean IsDigit(char item) {
	if (item >= '0' && item <= '9')
		return True;
	else
		return False;
}

void PushChar(CharStack* stack, char item) {
	stack->S[++stack->Top] = item;
}

char PopChar(CharStack* stack) {
	return stack->S[stack->Top--];
}

char PeekChar(CharStack* stack) {
	return stack->S[stack->Top];
}


