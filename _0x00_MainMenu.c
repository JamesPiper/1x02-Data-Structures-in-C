/////////////////////////////////////////////////////////////////////////////////////
// 2017.01.13 by James Piper, james@jamespiper.com
//
// Based on book "Data Structures in C" by Yogish Sachdeva
// I am working through the examples, but not doing so verbatim
// I am typing the code out, not simply 'copy and paste'
// and changing for style etc.
//
/////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include "1x02 Data Structures in C.h"

void _0x00_MainMenu() {

	char Inputs[MAX_INPUT_CHARS];
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
		printf("*   Q - Linked List (mine)                                                   *\n");
		printf("*   X - Exit the program.                                                    *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");

		printf("\n");
		printf("\n");
		printf("Enter choice: ");

		// Input user action.
		// Because of buffering, getchar or getc processes hold more than one character.
		// Use scanf because less chance of problems.
		// Using "%c" causes the loop to process for each char enter, need "%s"
		// MS wants me to use scanf_s instead of scanf b/c of buffer overflow.
		//
		// fscanf(stdin, "%s", Inputs, sizeof(Inputs));
		// fscanf is getting overlow as well, ugh.
		scanf("%s", &Inputs);
		printf("User input: %s\n", Inputs);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			_0x01_Stacks();
		else if (Choice == 'b')
			_0x02_InfixPostfixNotation();
		else if (Choice == 'c')
			_0x03_EvaluatePostFixExpression();
		else if (Choice == 'q')
			_0x0Z_MyLinkedList();
		else if (Choice == 'x')
			return;
		else
			printf("*** Select a choice from those listed. ****\n\n");

	} while (Choice != 'x');

}
