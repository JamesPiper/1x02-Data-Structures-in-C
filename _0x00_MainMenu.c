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
		printf("*   A - Stacks                                                               *\n");
		printf("*   B - Queues                                                               *\n");
		printf("*   C - Recursion                                                            *\n");
		printf("*   D - Linked Lists                                                         *\n");
		printf("*   E - Queues and Stacks with Linked Lists                                  *\n");
		printf("*   F - Trees                                                                *\n");
		printf("*   G - Graphs                                                               *\n");
		printf("*   H - Searching                                                            *\n");
		printf("*   I - Sorting                                                              *\n");
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
			_1x00_Stacks_Menu();
		else if (Choice == 'b')
			_2x00_Queues_Menu();
		else if (Choice == 'c')
			Choice = 'c';
		else if (Choice == 'd')
			Choice = 'd';
		else if (Choice == 'e')
			Choice = 'e';
		else if (Choice == 'f')
			Choice = 'f';
		else if (Choice == 'g')
			Choice = 'g';
		else if (Choice == 'h')
			Choice = 'h';
		else if (Choice == 'i')
			Choice = 'i';
		else if (Choice != 'x') {
			printf("*** Select a choice from those listed. ****\n\n");
			system("pause");
		}

	} while (Choice != 'x');

}
