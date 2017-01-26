/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.17
// File        : _0x00_MainMenu.c
// Description : Terminal style main menu for user.
//             : Starting point for the user.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _0x00_MainMenu() {

	char Choice;

	do
	{
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Beginning Data Structures in C                                           *\n");
		printf("*   Main Menu                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Stack (Fixed array)                                                  *\n");
		printf("*   B - Infix to Postfix Notation                                            *\n");
		printf("*   C - Evalaute Postfix Expression                                          *\n");
		printf("*                                                                            *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("Enter choice: ");

		// Input user action.
		char Inputs[MAX_INPUT_CHARS];
		GetUserInputs(Inputs, CHOICE_LENGTH);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			_0x01_Stacks();
		else if (Choice == 'b')
			_0x02_Infix_Postfix_Notation();
		else if (Choice == 'c')
			_0x03_Evaluate_PostFix_Expression();
		else if (Choice == 'd')
			Choice = 'd';
		else if (Choice == 'q')
			Choice = 'q';
		else if (Choice != 'x')
			printf("*** Select a choice from those listed. ****\n\n");

	} while (Choice != 'x');

}
