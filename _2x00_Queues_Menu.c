/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.17
// File        : _2x00_Queues_Menu.c
// Description : Submenu of queues related code.
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
void _2x00_Queues_Menu() {

	char Choice;

	do
	{
		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Queue Data Structures in C                                               *\n");
		printf("*   Main Menu                                                                *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Linear Queue (Fixed array)                                           *\n");
		printf("*   B - Circular Queue (Fixed array)                                         *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Return to Main Menu                                                  *\n");
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
			_2x01_Linear_Queue();
		else if (Choice == 'b')
			_2x02_Circular_Queue();
		else if (Choice == 'c')
			Choice = 'd';
		else if (Choice == 'd')
			Choice = 'd';
		else if (Choice == 'z')
			return;
		else if (Choice != 'x') {
			printf("*** Select a choice from those listed. ****\n\n");
			system("pause");
		}

	} while (Choice != 'x');

}
