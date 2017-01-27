/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.09
// File        : _1x01_Stacks.c
// Description : Example code on a stack data structure.
//             : Menu presented to Push, Pop, Peek and Display stack items.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
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
// 6. No index bound testing on the stack array. Unreal.
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
#include "_1x00_Stacks.h"
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
void Use_Push(Stack* Stack);
void Use_Pop(Stack* stack);
void Use_Peek(Stack* stack);

// Part of header file for use by other files.
//void Display_Stack(Stack*);
//int Push(Stack*, int);
//int Pop(Stack*);
//int Peek(Stack*);
//Boolean IsEmpty(Stack*);
//Boolean IsFull(Stack*);

void TestCode_E_Stack();
void TestCode_F_Stack();
void TestCode_G_Stack();
void TestCode_H_Stack();

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _1x01_Stacks() {

	char Choice;

	Stack TheStack;
	TheStack.top = -1;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Stack Data Structure                                                     *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Push                                                                 *\n");
		printf("*   B - Pop                                                                  *\n");
		printf("*   C - Peek                                                                 *\n");
		printf("*   D - Display                                                              *\n");
		printf("*                                                                            *\n");
		#define DEBUG_101
		#ifdef DEBUG_101
		printf("*                                                                            *\n");
		printf("*   E - Unit Testing - Push Items To Empty Stack                             *\n");
		printf("*   F - Unit Testing - Pop Items From The Stack                              *\n");
		printf("*   G - Unit Testing - Push Max Number Of Items To The Stack                 *\n");
		printf("*   H - Unit Testing - Push Item Onto A Full Stack                           *\n");
		#endif
		#undef DEBUG_101
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
			Use_Push(&TheStack);
		else if (Choice == 'b')
			Use_Pop(&TheStack);
		else if (Choice == 'c')
			Use_Peek(&TheStack);
		else if (Choice == 'd') {
			Display_Stack(&TheStack);
			system("pause");
		} else if (Choice == 'e')
			TestCode_E_Stack();
		else if (Choice == 'f')
			TestCode_F_Stack();
		else if (Choice == 'g')
			TestCode_G_Stack();
		else if (Choice == 'h')
			TestCode_H_Stack();
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
void Use_Push(Stack* stack) {

	int Item;
	int Result;

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Push Item To The Stack\n");
	printf("------------------------------------------------------------------------------\n");
	if (IsFull(stack)) {
		printf("Stack overflow.\n");
	} else {
		printf("Input the data: ");
		scanf("%d", &Item);
		Result = Push(stack, Item);
		if (Result)
			printf("Item, %d, added at index %d\n", Item, stack->top);
		else
			printf("***** Item not added to the stack *****\n");
	}

   printf("------------------------------------------------------------------------------\n");
   printf("\n");
   system("pause");

}

void Use_Pop(Stack* stack) {

	int Item;

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Pop Item From The Stack\n");
	printf("------------------------------------------------------------------------------\n");

	if (IsEmpty(stack)) {
		printf("Stack underflow. The stack is empty.\n");
	} else {
		Item = Pop(stack);
		printf("Popped item : %d \n", Item);
		printf("Stack count : %d \n", stack->top + 1);
	}

	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

void Use_Peek(Stack* stack) {

	int Item;

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Peek At Top Item From The Stack\n");
	printf("------------------------------------------------------------------------------\n");

	if (IsEmpty(stack)) {
		printf("The stack is empty.\n");
	} else {
		Item = Peek(stack);
		printf("Peek of item : %9d \n", Item);
		printf("Stack count  : %9d \n", stack->top + 1);
	}

	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	system("pause");

}

int Push(Stack* stack, int item) {
	if (stack->top < SIZE_OF_ARRAY_STACK - 1) {
		stack->value[++stack->top] = item;
		return True;
	} else
		return False;
}

int Pop(Stack* stack) {
	if (stack->top >= 0)
		return stack->value[stack->top--];
	else
		return 0;
}

int Peek(Stack* stack) {
	if (stack->top >= 0)
		return stack->value[stack->top];
	else
		return 0;
}

Boolean IsEmpty(Stack* stack) {
	if (stack->top == -1)
		return True;
	else
		return False;
}

Boolean IsFull(Stack* stack) {
	if (stack->top == SIZE_OF_ARRAY_STACK - 1)
		return True;
	else
 		return False;
}

void Display_Stack(Stack* stack) {

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Stack Content\n");
	printf("------------------------------------------------------------------------------\n");

	if (IsEmpty(stack))
		printf("The stack is empty.\n");
	else {
		for (int i = stack->top; i >= 0; i--)
			printf("Item at index %d is %9d\n", i, stack->value[i]);
	}

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

}

/////////////////////////////////////////////////////////////////////////////////////
// Unit testing for this file.
/////////////////////////////////////////////////////////////////////////////////////
void TestCode_E_Stack() {

	Stack TheStack;
	TheStack.top = -1;
	int Item;

	printf("==============================================================================\n");
	printf("E - Unit Testing - Push Items To Empty Stack\n");
	printf("==============================================================================\n");
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Push Items Onto Stack\n");
	printf("------------------------------------------------------------------------------\n");

	Item = 10;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);
	Item = -10;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);
	Item = 100000;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);
	Item = 123456789;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);

	Display_Stack(&TheStack);
	system("pause");

}

void TestCode_F_Stack() {

	Stack TheStack;
	TheStack.top = -1;
	int Item;

	printf("==============================================================================\n");
	printf("F - Unit Testing - Pop Items From The Stack\n");
	printf("==============================================================================\n");
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Push Items Onto Stack\n");
	printf("------------------------------------------------------------------------------\n");
	Item = 10;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);
	Item = -10;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);
	Item = 100000;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);
	Item = 123456789;
	Push(&TheStack, Item);
	printf("Item added at index %d: %9d\n", TheStack.top, Item);

	Display_Stack(&TheStack);

	printf("------------------------------------------------------------------------------\n");
	printf("Pop Items From The Stack\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Stack count : %9d \n", TheStack.top + 1);
	Item = Pop(&TheStack);
	printf("Popped item : %9d \n", Item);
	printf("Stack count : %9d \n", TheStack.top + 1);
	Item = Pop(&TheStack);
	printf("Popped item : %9d \n", Item);
	printf("Stack count : %9d \n", TheStack.top + 1);
	Item = Pop(&TheStack);
	printf("Popped item : %9d \n", Item);
	printf("Stack count : %9d \n", TheStack.top + 1);
	Item = Pop(&TheStack);
	printf("Popped item : %9d \n", Item);
	printf("Stack count : %9d \n", TheStack.top + 1);

	Display_Stack(&TheStack);
	system("pause");

}

void TestCode_G_Stack() {

	Stack TheStack;
	TheStack.top = -1;
	int Item;
	int Result;

	printf("==============================================================================\n");
	printf("G - Unit Testing - Push Max Number Of Items To The Stack\n");
	printf("==============================================================================\n");
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Push %d items to the stack.\n", SIZE_OF_ARRAY_STACK);
	printf("------------------------------------------------------------------------------\n");
	printf("Items added at: ");
	for (int i = 0; i < SIZE_OF_ARRAY_STACK; i++) {
		Result = Push(&TheStack, i);
		if (Result)
			printf("%d ", i);
		else {
			printf("\n");
			printf("\n***** Item, %d, not added to the stack *****\n", i);
		}
	}
	printf("\n");
	printf("\n");
	if (Result)
		printf("Items 0 to %d pushed onto the stack.\n", SIZE_OF_ARRAY_STACK - 1);
	else
		printf("***** Problem adding all the items to the stack *****\n");
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Peek Top Item On The Stack.\n");
	printf("------------------------------------------------------------------------------\n");
	Item = Peek(&TheStack);
	printf("Peek of item : %9d \n", Item);
	printf("Stack count  : %9d \n", TheStack.top + 1);
	printf("\n");

	system("pause");

}

void TestCode_H_Stack() {

	Stack TheStack;
	TheStack.top = -1;
	int Item;
	int Result;

	printf("==============================================================================\n");
	printf("H - Unit Testing - Push Item Onto A Full Stack\n");
	printf("==============================================================================\n");
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Fill the stack with %d items.\n", SIZE_OF_ARRAY_STACK);
	printf("------------------------------------------------------------------------------\n");
	for (int i = 0; i < SIZE_OF_ARRAY_STACK; i++) {
			Result = Push(&TheStack, i);
		if (Result)
			printf("%d ", i);
		else
			printf("\n***** Item, %d, not added to the stack *****\n", i);
	}
	printf("\n");
	printf("\n");
	if (Result) {
		printf("Items 0 to %d pushed onto the stack.\n", SIZE_OF_ARRAY_STACK - 1);
		printf("\n");
		printf("The stack is full.\n");
	} else
		printf("***** Problem adding all the items to the stack *****\n");
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Peek Top Item On The Stack.\n");
	printf("------------------------------------------------------------------------------\n");
	Item = Peek(&TheStack);
	printf("Peek of item : %9d \n", Item);
	printf("Stack count  : %9d \n", TheStack.top + 1);
	printf("\n");

	printf("------------------------------------------------------------------------------\n");
	printf("Push Item Onto The Stack.\n");
	printf("------------------------------------------------------------------------------\n");
	Result = Push(&TheStack, 1000);
	if (Result)
		printf("Item added at index %d: %9d\n", TheStack.top, Item);
	else
		printf("***** Problem adding the item to the stack *****\n");
	printf("\n");

	system("pause");

}
