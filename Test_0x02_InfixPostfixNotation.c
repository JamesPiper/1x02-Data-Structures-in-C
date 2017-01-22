/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.20
// File        : Test_0x02_InfixPostfixNotation.h
// Description : Unit testing of _0x02_InfixPostfixNotation.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 99.)
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
// See 1x02 Data Structures in C.h
// see _0x01_Stacks.h

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////
// see _0x01_Stacks.h


void Test_0x02_InfixPostfixNotation() {

    /////////////////////////////////////////////////////////////////////////////////////
    // Create exmaples of infix strings and check postfix result.
    /////////////////////////////////////////////////////////////////////////////////////

	printf("==============================================================================\n");
	printf("Unit Testing Code - Infix Notation to Postfix\n");
	printf("==============================================================================\n");
	printf("\n");

    CharStack Stack;
    CharStack Postfix;
	Stack.Top = -1;
	Postfix.Top = -1;
    char Infix[SIZE_OF_ARRAY_STACK];

	printf("Example 1\n");
	printf("------------------------------------------------------------------------------\n");
    strcpy(Infix, "2 + 2");
    ConvertInfixToPostfix(Infix, &Stack, &Postfix);
	printf("Infix    : %s\n", Infix);
	printf("Postfix  : %s\n", Postfix.String);
	printf("\n");

	printf("Example 2\n");
	printf("------------------------------------------------------------------------------\n");
    strcpy(Infix, "(2 + 2)");
	Stack.Top = -1;
	Postfix.Top = -1;
//    Stack.String[0] = "\0";
//    Postfix.String[0] = "\0";
    ConvertInfixToPostfix(Infix, &Stack, &Postfix);
	printf("Infix    : %s\n", Infix);
	printf("Postfix  : %s\n", Postfix.String);
	printf("\n");

	printf("Example 3\n");
	printf("------------------------------------------------------------------------------\n");
    strcpy(Infix, "(2 + )");
    strcpy(Infix, "(2 + ");
	Stack.Top = -1;
	Postfix.Top = -1;
    ConvertInfixToPostfix(Infix, &Stack, &Postfix);
	printf("Infix    : %s\n", Infix);
	printf("Postfix  : %s\n", Postfix.String);
	printf("\n");


	printf("==============================================================================\n");
	printf("\n");
	system("pause");

}


