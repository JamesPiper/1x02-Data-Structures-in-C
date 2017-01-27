/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.10
// File        : _0x02_Infix_Postfix_Notation.c
// Description : Convert infix notation (2 + 2) into postfix notation (2 2 +)
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
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
// 4. The code in _1x00_Stacks creates an int stack.
//    This code uses a char stack.
//    C isn't designed for overloading so need to distinguish
//    between a char stack and int stack.
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
#include "_1x00_Stacks.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
// Moved to main header file (1x02 Data Structures in C.h).
// see _1x00_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////
// see _1x00_Stacks.h

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

void Process_Infix_To_Postfix();

void TestCode_B_Infix_Postfix_Notation();
void TestCode_C_Infix_Postfix_Notation();
void TestCode_D_Infix_Postfix_Notation();
void TestCode_E_Infix_Postfix_Notation();

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _1x02_Infix_Postfix_Notation() {

	char Choice;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Postfix Notation                                                         *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Enter Infix And Convert To Postfix                                   *\n");
		printf("*                                                                            *\n");
		#define DEBUG_102
		#ifdef DEBUG_102
		printf("*                                                                            *\n");
		printf("*   B - Unit Testing - Two Opperands                                         *\n");
		printf("*   C - Unit Testing - Two Bracketed Items                                   *\n");
		printf("*   D - Unit Testing - Three Opperands                                       *\n");
		printf("*   E - Unit Testing - Invalid Expressions                                   *\n");
		#endif
		#undef DEBUG_102
		printf("*                                                                            *\n");
		printf("*   Z - Return to Stacks Menu                                                *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");
		printf("\n");

		printf("Enter choice: ");
		char Inputs[MAX_INPUT_CHARS];
		scanf("%s", Inputs);
		Choice = tolower(Inputs[0]);

		if (Choice == 'a')
			Process_Infix_To_Postfix();
		else if (Choice == 'b')
			TestCode_B_Infix_Postfix_Notation();
		else if (Choice == 'c')
			TestCode_C_Infix_Postfix_Notation();
		else if (Choice == 'd')
			TestCode_D_Infix_Postfix_Notation();
		else if (Choice == 'e')
			TestCode_E_Infix_Postfix_Notation();
		else if (Choice == 'f')
			Choice = 'i';
		else if (Choice == 'g')
			Choice = 'i';
		else if (Choice == 'h')
			Choice = 'i';
		else if (Choice == 'i')
			Choice = 'i';
		else if (Choice == 'z')
			return;
		else if (Choice == 'x')
			exit(0);
		else if (Choice != 'x') {
			printf("*** Select a choice from those listed. ****\n\n");
			system("pause");
		}

	} while (Choice != 'x');

}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions
/////////////////////////////////////////////////////////////////////////////////////
void Process_Infix_To_Postfix() {

	CharStack Stack;
	CharStack Postfix;
	Stack.top = Postfix.top = -1;

	printf("Input the infix expression: ");
	char Infix[SIZE_OF_ARRAY_STACK];
	GetUserInputs(Infix, SIZE_OF_ARRAY_STACK);

	Boolean Result;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	system("pause");

}

Boolean Convert_Infix_To_Postfix(char infix[], CharStack* stack, CharStack* postfix) {

	char Item;
	int Length = strlen(infix);
	Boolean Success = True;

	// Insert ')' at the end.
	infix[Length++] = ')';
	// End with null char.
	infix[Length] = '\0';

	// Start with '('
	PushChar(stack, '(');

	#define DEBUG_102
	#ifdef DEBUG_102
	#endif

	for (int i = 0; infix[i] != '\0'; i++) {

		if (infix[i] != ' ') {
			if ((infix[i] == '+') ||
				(infix[i] == '-') ||
				(infix[i] == '*') ||
				(infix[i] == '/') ||
				(infix[i] == '^')) {

				// Pop all the operatos from the stack with prioirty
				// higher than or equal to infix[i]
				while (IsHigherOrEqual(Priority(PeekChar(stack)), Priority(infix[i]))) {
					Item = PopChar(stack);
					PushChar(postfix, Item);
					PushChar(postfix, ' ');
				}
				PushChar(stack, infix[i]);

			} else if (infix[i] == '(') {
				PushChar(stack, infix[i]);
			} else if (infix[i] == ')') {
				while ((Item = PopChar(stack)) !='(') {
					PushChar(postfix, Item);
					PushChar(postfix, ' ');
				}
			} else {
				if(IsDigit(infix[i])) {
					while (IsDigit(infix[i]))
					{
						PushChar(postfix, infix[i]);
						i++;
					}
					PushChar(postfix, ' ');
					i--;
				} else {
					printf("***** Incorrect character (%c %X) encountered in infix. *****\n", infix[i], infix[i]);
					Success = False;
				}
			}
		}
	}

	PushChar(postfix, '\0');
	infix[--Length] = '\0';

	if (strlen(postfix->expression) == 0)
		Success = False;

	return Success;

	#ifdef DEBUG_102
	#endif
	#undef DEBUG_102

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

int PushChar(CharStack* stack, char item) {
	if (stack->top < SIZE_OF_ARRAY_STACK - 1) {
		stack->expression[++stack->top] = item;
		return 1;
	} else
		return 0;
}

char PopChar(CharStack* stack) {
	if (stack->top >= 0)
		return stack->expression[stack->top--];
	else
		return 0;
}

char PeekChar(CharStack* stack) {
	if (stack->top >= 0)
		return stack->expression[stack->top];
	else
		return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// Unit testing for this file.
/////////////////////////////////////////////////////////////////////////////////////
void TestCode_B_Infix_Postfix_Notation() {

	printf("==============================================================================\n");
	printf("B - Unit Testing - Two Opperands\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;
	Stack.top = -1;
	Postfix.top = -1;
	char Infix[SIZE_OF_ARRAY_STACK];

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 + 3");
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(12 + 13)");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "22 - 23");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "122 * 323");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 5\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "122 / 323");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 6\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 * 64");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}

void TestCode_C_Infix_Postfix_Notation() {


	printf("==============================================================================\n");
	printf("C - Unit Testing - Two Bracketed Items\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;
	Stack.top = -1;
	Postfix.top = -1;
	char Infix[SIZE_OF_ARRAY_STACK];

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(2 + 3) + (4 + 5)");
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(2 * 3) + (4 - 5)");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(2 / 3) ^ (4 * 5)");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}

void TestCode_D_Infix_Postfix_Notation() {

	printf("==============================================================================\n");
	printf("D - Unit Testing - Three Opperands\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;
	Stack.top = -1;
	Postfix.top = -1;
	char Infix[SIZE_OF_ARRAY_STACK];

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 + 3 + 4");
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 - 3 + 4");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 / 3 + 4");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 - 3 * 4");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 ^ 3 + 4");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	printf("Infix    : '%s'\n", Infix);
	printf("Postfix  : '%s'\n", Postfix.expression);
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}

void TestCode_E_Infix_Postfix_Notation() {

	printf("==============================================================================\n");
	printf("E - Unit Testing - Invalid Expressions\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;
	char Infix[SIZE_OF_ARRAY_STACK];
	Boolean Result;

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "");
	printf("Infix    : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "   ");
	printf("Infix    : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "a + b");
	printf("Infix    : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 + b");
	printf("Infix    : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 5\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 + ");
	printf("Infix    : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 6\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(2 + 3");
	printf("Infix    : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Result = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Result)
		printf("Postfix  : '%s'\n", Postfix.expression);
	else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}
