/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.10
// File        : _0x02_InfixPostfixNotation.c
// Description : Convert infix notation (2 + 2) into postfix notation (2 2 +)
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 99.)
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Infix     :  A + B or C * D or E - F
// Prefix    :  + A B, * C D, - E F         (aka Polish notation)
// Postfix   :  A B +, C D *, E F -         (aka Reverse Polish Notation)
//
//
// Five operations to focus on
// 1. + addition
// 2. - subtraction
// 3. * multiplication
// 4. / division
// 5. ^ exponential
//
// Examples of Infix to Postfix
// A + B                              -->  A B +
// A + B - C                          -->  A B + C -
// (A + B) * (C - D)                  -->  A B + C D - *
// ((A + B) * C - (D - E)) ^ (F + G)  -->  A B + C * D E - - F G - ^
//
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
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
#include "_0x01_Stacks.h"
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
//void ConvertInfixToPostfix(char*, CharStack*, CharStack*);
//int Priority(char);
//Boolean IsHigherOrEqual(int, int);
//void PushChar(CharStack*, char item);
//char PopChar(CharStack*);
//char PeekChar(CharStack*);
//Boolean IsDigit(char);


/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _0x02_InfixPostfixNotation() {

	CharStack Stack, Postfix;
	Stack.Top = Postfix.Top = -1;

	printf("Input the infix expression: ");
	char Infix[SIZE_OF_ARRAY_STACK];
	GetUserInputs(Infix, SIZE_OF_ARRAY_STACK);
	ConvertInfixToPostfix(Infix, &Stack, &Postfix);
	printf("Infix    : %s\n", Infix);
	printf("Postfix  : %s\n", Postfix.String);
//	printf("The Postfix expression is: %s\n\n", Postfix.String);
    system("pause");

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions
/////////////////////////////////////////////////////////////////////////////////////
void ConvertInfixToPostfix(char infix[], CharStack* stack, CharStack* postfix) {

	char Item;
	int Length = strlen(infix);

	// Insert ')' at the end.
	infix[Length++] = ')';
	// End with null char.
	infix[Length] = '\0';

	// Start with '('
	PushChar(stack, '(');

	for (int i = 0; infix[i] != '\0'; i++) {
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
				Item = PopChar(stack);
				PushChar(postfix, Item);
				PushChar(postfix, ' ');
			}
			PushChar(stack, infix[i]);
			break;
		case '(':
			PushChar(stack, infix[i]);
			break;
		case ')':
			while ((Item = PopChar(stack)) !='(') {
				PushChar(postfix, Item);
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
				i--;
			}
			else
			{
				printf("Incorrect character encountered in infix.\n");
				break;
			}
		}
	}
	PushChar(postfix, '\0');
    infix[--Length] = '\0';

}

int Priority(char item) {
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

Boolean IsHigherOrEqual(int A, int B) {
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
	stack->String[++stack->Top] = item;
}

char PopChar(CharStack* stack) {
	return stack->String[stack->Top--];
}

char PeekChar(CharStack* stack) {
	return stack->String[stack->Top];
}


