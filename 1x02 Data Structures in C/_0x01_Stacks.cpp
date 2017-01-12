//==============================================================================
//
// January 9, 2017
// From book on Data Structures in C by Yogish Sachdeva
// Working through the example,s but not doing so verbatim
// Typing the code out, not simply 'copy and paste'
// and changing for style etc.
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
//==============================================================================

#include "stdafx.h"
#include "1x02 Data Structures in C.h"
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#define MAX_01 100

typedef enum Boolean { False, True } Boolean;

typedef struct _Stack
{
	int top;
	int S[MAX_01];
} Stack;

// Function prototypes
static void Push(Stack*, int);
static void Display(Stack*);
static int Pop(Stack*);
static int Peek(Stack*);
static Boolean IsEmpty(Stack*);
static Boolean IsFull(Stack*);


void _0x01_Stacks() {
	
	char Inputs[MAX_01];
	char Choice;

	int Item;
	Stack TheStack;

	// Initialize top 
	TheStack.top = -1;

	do {
		
		printf("==============================================================================\n");
		printf("Stack\n");
		printf("==============================================================================\n");
		printf("\n");
		printf("Type number + Enter\n");
		printf("\n");
		printf("A. Push\n");
		printf("B. Pop\n");
		printf("C. Peek\n");
		printf("D. Display\n");
		printf("X. Exit\n");
		printf("\n");
		printf("==============================================================================\n");
		printf("\n");

		printf("\n");
		printf("Enter choice: ");
		scanf("%s", &Inputs);
		Choice = Inputs[0];

		// Push
		if (Choice == 'A' || Choice == 'a') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsFull(&TheStack)) {
				printf("Stack overflow.\n");
			}
			else {
				printf("Input the data: ");
				scanf("%d", &Item);
				Push(&TheStack, Item);
				printf("%d added at element %d\n", Item, TheStack.top);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
			continue;
		}

		// Pop
		if (Choice == 'B' || Choice == 'b') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsEmpty(&TheStack)) {
				printf("Stack underflow. The stack is empty.\n");
			}
			else {
				Item = Pop(&TheStack);
				printf("Popped element: %d \n", Item);
				printf("No of elements left: %d \n", TheStack.top + 1);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
			continue;
		}

		// Peek
		if (Choice == 'C' || Choice == 'c') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsEmpty(&TheStack)) {
				printf("The stack is empty.\n");
			}
			else {
				Item = Peek(&TheStack);
				printf("Peek of element: %d \n", Item);
				printf("No of elements left: %d \n", TheStack.top + 1);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
			continue;
		}

		// Display
		if (Choice == 'D' || Choice == 'd') {
			printf("\n");
			printf("------------------------------------------------------------------------------\n");
			if (IsEmpty(&TheStack)) {
				printf("The stack is empty.\n");
			}
			else {
				Display(&TheStack);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("\n");
			continue;
		}

		// Exit
		if (Choice == 'X' || Choice == 'x') {
			return;
		}
		

	} while (Choice != 'X' && Choice != 'x');  
}

static void Push(Stack* Stack, int item) {
	Stack->S[++Stack->top] = item;
}

static void Display(Stack* Stack) {
	for (int i = Stack->top; i >= 0; i--)
		printf("  The %d element is %d\n", i, Stack->S[i]);
}

static int Pop(Stack* Stack) {
	//int Item;
	//Item = Stack->S[Stack->top--];
	//return Item;

	//printf("Stack->top is %d\n ", Stack->top);
	return Stack->S[Stack->top--];
}

static int Peek(Stack* Stack) {
	return Stack->S[Stack->top];
}

static Boolean IsEmpty(Stack* Stack) {
	if (Stack->top == -1)
		return True;
	else
		return False;
}

static Boolean IsFull(Stack* Stack) {
	if (Stack->top == MAX_01 - 1) 
		return True;
	else
 		return False;
}


