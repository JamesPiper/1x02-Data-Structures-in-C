#include "stdafx.h"
#include <cstdio>

#include "1x02 Data Structures in C.h"
#define _CRT_SECURE_NO_WARNINGS

void MainMenu() {

	char Inputs[80];
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
		printf("*   B - Infix to Postfix Notation                                            *\n");
		printf("*                                                                            *\n");
		printf("*   Z - Linked List (mine)                                                   *\n");
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
		scanf("%s", &Inputs);

		Choice = Inputs[0];
		printf("\n");

		if (Choice == 'A' || Choice == 'a')
			_0x01_Stacks();
		else if (Choice == 'B' || Choice == 'b') 
			_0x02_InfixPostfixNotation();
		else if (Choice == 'Z' || Choice == 'z') 
			_0x0Z_MyLinkedList();
		else if (Choice == 'X' || Choice == 'x') 
			return;

	} while (Choice != 'X' && Choice != 'x'); 

}
