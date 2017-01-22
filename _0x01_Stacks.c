/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.09
// File        : _0x01_Stacks.c
// Description : Example code on a stack data structure.
//             : Menu presented to Push, Pop, Peek and Display stack items.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 99.)
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// I'm finding flaws in the code.
// 1. Getting numbers for the menu items causes problems if non-digits entered
//    I switched it to a alpha base to avoid this problem.
// 2. The functions could have been simplified by simply returning the result
//    instead of creating variable, storing it and return it.
// 3. I don't like the names of variables he used. 'I' as a counter instead of 'i'
// 4. He used too many comments.
// 5. Not sure why he needs functions for Push or Pop.
//    Code called from only one spot and the code in the function is one line.
//
// Stack Characteristics:
// 1. Terms of Push and Pop
// 2. LIFO
// 3. Linear
// 4. Homogenious data - all the same type
// 5. Static - the stack is a fixed size and he's using an array hence fixed
//    yet he says it's dynamic. Odd.
// 6. Sequential access - can only access the top of the stack.
//
// Not sure where I'd use it.
// 1. Microprocessor emulator for sure.
// 2. Could be used in parsing HTML or calculator arguments.
//
// TO DO
// Modify to allow char as data value in stack instead of int.
// Create a dynamic stack. This one is fixed array stack.
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
// Rename as SIZE_OF_ARRAY_STACK
// #define MAX 100

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////

// Moved to main header file (1x02 Data Structures in C.h).
//typedef enum Boolean { False, True } Boolean;

//typedef struct _Stack {
//	int Top;
//	int S[SIZE_OF_ARRAY_STACK];
//} Stack;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
/////////////////////////////////////////////////////////////////////////////////////
//void Display(Stack*);
//void Push(Stack*, int);
//int Pop(Stack*);
//int Peek(Stack*);
//Boolean IsEmpty(Stack*);
//Boolean IsFull(Stack*);

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _0x01_Stacks() {

	char Choice;

	int Item;
	Stack TheStack;
	TheStack.Top = -1;

	do {

		printf("==============================================================================\n");
		printf("Stack\n");
		printf("==============================================================================\n");
		printf("\n");
		printf("Type number + Enter\n");
		printf("\n");
		printf("A - Push\n");
		printf("B - Pop\n");
		printf("C - Peek\n");
		printf("D - Display\n");
		printf("\n");
		printf("X - Exit\n");
		printf("Z - Return\n");
		printf("\n");
		printf("==============================================================================\n");
		printf("\n");

		printf("\n");
		printf("Enter choice: ");
        char Inputs[MAX_INPUT_CHARS];
		scanf("%s", Inputs);
		Choice = tolower(Inputs[0]);

		// Push
		if (Choice == 'a') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsFull(&TheStack)) {
				printf("Stack overflow.\n");
			}
			else {
				printf("Input the data: ");
				scanf("%d", &Item);
				Push(&TheStack, Item);
				printf("%d added at element %d\n", Item, TheStack.Top);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
            system("pause");
			continue;
		}

		// Pop
		if (Choice == 'b') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsEmpty(&TheStack)) {
				printf("Stack underflow. The stack is empty.\n");
			}
			else {
				Item = Pop(&TheStack);
				printf("Popped element: %d \n", Item);
				printf("No of elements left: %d \n", TheStack.Top + 1);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
            system("pause");
			continue;
		}

		// Peek
		if (Choice == 'c') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsEmpty(&TheStack)) {
				printf("The stack is empty.\n");
			}
			else {
				Item = Peek(&TheStack);
				printf("Peek of element: %d \n", Item);
				printf("No of elements: %d \n", TheStack.Top + 1);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
            system("pause");
			continue;
		}

		// Display
		if (Choice == 'd') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
            Display(&TheStack);
//			if (IsEmpty(&TheStack)) {
//				printf("The stack is empty.\n");
//			}
//			else {
//				Display(&TheStack);
//			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
            system("pause");
			continue;
		}

		// Return to main menu.
		if (Choice == 'z') {
			return;
		}

		// Exit
		if (Choice == 'x') {
			exit(0);
		}

	} while (Choice != 'x');
}

/////////////////////////////////////////////////////////////////////////////////////
// Subfunctions
/////////////////////////////////////////////////////////////////////////////////////
void Push(Stack* Stack, int item) {
	Stack->S[++Stack->Top] = item;
}

int Pop(Stack* Stack) {
	//int Item;
	//Item = Stack->S[Stack->top--];
	//return Item;

	//printf("Stack->top is %d\n ", Stack->top);
	return Stack->S[Stack->Top--];
}

int Peek(Stack* Stack) {
	return Stack->S[Stack->Top];
}

Boolean IsEmpty(Stack* Stack) {
	if (Stack->Top == -1)
		return True;
	else
		return False;
}

Boolean IsFull(Stack* Stack) {
	if (Stack->Top == SIZE_OF_ARRAY_STACK - 1)
		return True;
	else
 		return False;
}
void Display(Stack* Stack) {
    if (IsEmpty(Stack))
        printf("The stack is empty.\n");
    else {
        for (int i = Stack->Top; i >= 0; i--)
            printf("Element at %d is %d\n", i, Stack->S[i]);
    }
}

