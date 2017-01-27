/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.19
// File        : _0x03_Evaluate_PostFix_Expression.c
// Description : Code to evaluate a postfix expression.
//             : e.g., '2 2 +' evaluates to 4.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
/////////////////////////////////////////////////////////////////////////////////////
//
// Using stack functions from _1x00_Stacks.h instead of typing in here.
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
#include "_1x00_Stacks.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
// see _1x00_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////
// see _1x00_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
/////////////////////////////////////////////////////////////////////////////////////
// see _1x00_Stacks.h
void Process_Postfix_Evaluation();
int Evaluate_PostFix_Expression(char*, Boolean*);
void GetNumber(char*, int, char*);

void TestCode_B_Evaluate_PostFix_Expression();
void TestCode_C_Evaluate_PostFix_Expression();
void TestCode_D_Evaluate_PostFix_Expression();
void TestCode_E_Evaluate_PostFix_Expression();

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _1x03_Evaluate_PostFix_Expression() {

	char Choice;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Evaluation of Postfix Notation                                           *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Enter Postfix Notation To Evaluate                                   *\n");
		printf("*                                                                            *\n");
		#define DEBUG_103
		#ifdef DEBUG_103
		printf("*                                                                            *\n");
		printf("*   B - Unit Testing - Two Opperands                                         *\n");
		printf("*   C - Unit Testing - Two Bracketed Items                                   *\n");
		printf("*   D - Unit Testing - Three Opperands                                       *\n");
		printf("*   E - Unit Testing - Invalid Expressions                                   *\n");
		#endif
		#undef DEBUG_103
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
			Process_Postfix_Evaluation();
		else if (Choice == 'b')
			TestCode_B_Evaluate_PostFix_Expression();
		else if (Choice == 'c')
			TestCode_C_Evaluate_PostFix_Expression();
		else if (Choice == 'd')
			TestCode_D_Evaluate_PostFix_Expression();
		else if (Choice == 'e')
			TestCode_E_Evaluate_PostFix_Expression();
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
void Process_Postfix_Evaluation() {

	CharStack Stack;
	CharStack Postfix;
	Stack.top = Postfix.top = -1;

	printf("\n");
	printf("Example\n");
	printf("-------\n");
	printf("Infix   : 2 + 3\n");
	printf("Postfix : 2 3 +\n");
	printf("\n");
	printf("Input the infix expression: ");
	char Infix[SIZE_OF_ARRAY_STACK];
	GetUserInputs(Infix, SIZE_OF_ARRAY_STACK);

	printf("\n");
	printf("Infix   Notation  : '%s'\n", Infix);
	Boolean Success = False;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		int result = 0;
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		if (Success)
			printf("Evaluated To      :  %d \n", result);
		else
			printf("***** Problem with postfix expression of '%s' *****\n", Postfix.expression);
	} else {
			printf("***** Problem with infix expression of '%s' *****\n", Infix);
	}
	printf("\n");

	system("pause");

}

int Evaluate_PostFix_Expression(char* postfix, Boolean* success) {

	Stack Stack;
	int number = 0;
	int result = 0;
	int op1 = 0;
	int op2 = 0;

	// Assume true.
	*success = True;

	char NumberInString[SIZE_OF_ARRAY_STACK];
	Stack.top = -1;
	//#define DEBUG_103
	#ifdef DEBUG_103
	printf("Expression to evaluate in function: '%s'\n", postfix);
	#endif

	for (int i = 0; postfix[i] != 0; i++) {
		#ifdef DEBUG_103
		printf("For loop #%d: %c\n", i, postfix[i]);
		#endif
		if ((postfix[i] == ' ') ||
			(postfix[i] == ',') ||
			(postfix[i] == '(') ||
			(postfix[i] == ')')) {
			#ifdef DEBUG_103
			printf("Ignoring certain characters.\n");
			#endif
		} else if (IsDigit(postfix[i])) {
			GetNumber(postfix, i, NumberInString);
			i += strlen(NumberInString);
			number = atoi(NumberInString);
			Push(&Stack, number);
			#ifdef DEBUG_103
			printf("Number pushed to stack: %d\n", number);
			#endif
			i--;
		} else {
			op2 = Pop(&Stack);
			op1 = Pop(&Stack);
			if ((postfix[i]) == '+')
				result = op1 + op2;
			else if ((postfix[i]) == '-')
				result = op1 - op2;
			else if ((postfix[i]) == '/')
				// No error checking if op2 is zero.
				result = op1 / op2;
			else if ((postfix[i]) == '*')
				result = op1 * op2;
			else if ((postfix[i]) == '^')
				// op1, op2 declared as ints, pow takes double
				// Is there automatic type casting?
				result = pow(op1, op2);
			else {
				#ifdef DEBUG_103
				printf("***** Unrecognizable operation *****\n");
				#endif
				result = 0;
				*success = False;
			}
		Push(&Stack, result);
		}
	}

	result = Pop(&Stack);
	return result;
	#undef DEBUG_103

}

void GetNumber(char* postfix, int index, char* numbers) {

	// Create a string of a number from individual chars.
	int j = 0;
	while (IsDigit(postfix[index])) {
		numbers[j++] = postfix[index++];
	}
	numbers[j] = '\0';
}

void TestCode_B_Evaluate_PostFix_Expression() {

	printf("==============================================================================\n");
	printf("B - Unit Testing - Two Opperands\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;

	char Infix[SIZE_OF_ARRAY_STACK];
	int result;
	Boolean Success;

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "22 + 33");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "55 - 33");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "100 / 5");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "20 * 5");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("Example 5\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 ^ 20");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}

void TestCode_C_Evaluate_PostFix_Expression() {

	printf("==============================================================================\n");
	printf("C - Unit Testing - Two Bracketed Items\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;

	char Infix[SIZE_OF_ARRAY_STACK];
	int result;
	Boolean Success;

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(22 + 33) + (44 + 55)");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(2 * 3) + (4 - 5)");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(200 / 100) ^ (4 * 5)");
	Stack.top = -1;
	Postfix.top = -1;
	Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
	printf("Infix   Notation  : '%s'\n", Infix);
	printf("Postfix Notation  : '%s'\n", Postfix.expression);
	printf("Evaluated To      :  %d \n", result);
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}

void TestCode_D_Evaluate_PostFix_Expression() {

	printf("==============================================================================\n");
	printf("D - Unit Testing - Three Opperands\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;

	char Infix[SIZE_OF_ARRAY_STACK];
	int result;
	Boolean Success;

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 + 3 + 4");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 - 3 + 4");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "100 / 5 + 10");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 * 3 + 4");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 5\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 ^ 3 + 4");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}

void TestCode_E_Evaluate_PostFix_Expression() {

	printf("==============================================================================\n");
	printf("E - Unit Testing - Invalid Expressions\n");
	printf("==============================================================================\n");
	printf("\n");

	CharStack Stack;
	CharStack Postfix;

	char Infix[SIZE_OF_ARRAY_STACK];
	int result;
	Boolean Success;

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "  ");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "a +  ");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 4\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 + a ");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 5\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "2 +  ");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("Example 6\n");
	printf("------------------------------------------------------------------------------\n");
	strcpy(Infix, "(2 + ) ");
	printf("Infix   Notation  : '%s'\n", Infix);
	Stack.top = -1;
	Postfix.top = -1;
	Success = Convert_Infix_To_Postfix(Infix, &Stack, &Postfix);
	if (Success) {
		result = Evaluate_PostFix_Expression(Postfix.expression, &Success);
		printf("Postfix Notation  : '%s'\n", Postfix.expression);
		printf("Evaluated To      :  %d \n", result);
	} else
		printf("***** Unable to create postfix notation ***** \n");
	printf("\n");

	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}
