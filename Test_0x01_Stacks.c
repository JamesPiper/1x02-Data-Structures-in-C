/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.21
// File        : Test_0x01_Stacks.c
// Description : Unit testing of _0x01_Stacks.c
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (Compiling to ISO 99.)
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
#include "_0x01_Stacks.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
#define DEBUG

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
/////////////////////////////////////////////////////////////////////////////////////
//static void Display(Stack*);

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////

void Test_0x01_Stacks() {

    /////////////////////////////////////////////////////////////////////////////////////
    // Create exmaples of infix strings and check postfix result.
    /////////////////////////////////////////////////////////////////////////////////////

	Stack TheStack;
	TheStack.Top = -1;
    int Item;

	printf("==============================================================================\n");
	printf("Unit Testing Code - Stacks\n");
	printf("==============================================================================\n");
	printf("\n");
	printf("Push Items Onto The Stack\n");
	printf("------------------------------------------------------------------------------\n");
	Item = 10;
    Push(&TheStack, Item);
    printf("Added at element %d: %d\n", TheStack.Top, Item);
	Item = -10;
    Push(&TheStack, Item);
    printf("Added at element %d: %d\n", TheStack.Top, Item);
	Item = 100000;
    Push(&TheStack, Item);
    printf("Added at element %d: %d\n", TheStack.Top, Item);
	Item = 123456789;
    Push(&TheStack, Item);
    printf("Added at element %d: %d\n", TheStack.Top, Item);

	printf("\n");
    printf("Display The Stack\n");
	printf("------------------------------------------------------------------------------\n");
    Display(&TheStack);
	printf("\n");
    system("pause");

    printf("Peek\n");
	printf("------------------------------------------------------------------------------\n");
    Item = Peek(&TheStack);
    printf("Peek of element: %d \n", Item);
    printf("No of elements: %d \n", TheStack.Top + 1);
    Item = Peek(&TheStack);
    printf("Peek of element: %d \n", Item);
    printf("No of elements: %d \n", TheStack.Top + 1);

	printf("\n");
    printf("Pop Items From The Stack\n");
	printf("------------------------------------------------------------------------------\n");
    Item = Pop(&TheStack);
    printf("Popped element: %d \n", Item);
    printf("No of elements left: %d \n", TheStack.Top + 1);
    Item = Pop(&TheStack);
    printf("Popped element: %d \n", Item);
    printf("No of elements left: %d \n", TheStack.Top + 1);
    Item = Pop(&TheStack);
    printf("Popped element: %d \n", Item);
    printf("No of elements left: %d \n", TheStack.Top + 1);
    Item = Pop(&TheStack);
    printf("Popped element: %d \n", Item);
    printf("No of elements left: %d \n", TheStack.Top + 1);

	printf("\n");
    printf("Display The Stack\n");
	printf("------------------------------------------------------------------------------\n");
    Display(&TheStack);

	printf("\n");
	printf("Stress Test\n");
	printf("------------------------------------------------------------------------------\n");
	printf("Push %d items to the stack.\n", SIZE_OF_ARRAY_STACK);
	TheStack.Top=-1;
    for (int i = 0; i < SIZE_OF_ARRAY_STACK; i++) {
        Push(&TheStack, i);
    }

    Item = Peek(&TheStack);
    printf("Peek of element: %d \n", Item);
    printf("No of elements: %d \n", TheStack.Top + 1);

	printf("Pop %d items from the stack.\n", SIZE_OF_ARRAY_STACK);
    for (int i = 0; i < SIZE_OF_ARRAY_STACK; i++) {
        Item = Pop(&TheStack);
    }

	printf("\n");
    printf("Display The Stack\n");
	printf("------------------------------------------------------------------------------\n");
    Display(&TheStack);

	printf("\n");
	printf("\n");
	printf("==============================================================================\n");
    system("pause");

}
