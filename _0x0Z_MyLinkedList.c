//==============================================================================
//
// 2017.01.11 by James Piper, james@jamespiper.com
//
// My attempt of creating a single linked list.
// It is a dynamic linked list.
// It's working and so cool.
//
// Can add and display nodes.
//
// TO DO
// Move chunck of code in AddNode to NewNode function.
// Code to insert, delete node.
//
//
//==============================================================================

#include "1x02 Data Structures in C.h"

#include <stdlib.h>
#include <stdio.h>

// Moved to main header file (1x02 Data Structures in C.h).
//typedef enum Boolean { False, True } Boolean;

typedef struct sllist {
  int value;
  struct sllist* next;
} sllist;

static void A();
static void B();
static void C();
static void D();
//static void E();
static void AddNode(int value);

sllist* ListHead;

void _0x0Z_MyLinkedList() {

	char Inputs[MAX_INPUT_CHARS];
	char Choice;

	// Initialize
	ListHead = NULL;

	do {

		printf("==============================================================================\n");
		printf("Single Linked List\n");
		printf("==============================================================================\n");
		printf("\n");
		printf("Type number + Enter\n");
		printf("\n");
		printf("A. Add\n");
		printf("B. Remove\n");
		printf("C. Insert\n");
		printf("D. Display\n");
		printf("X. Exit\n");
		printf("\n");
		printf("==============================================================================\n");
		printf("\n");

		printf("\n");
		printf("Enter choice: ");
		scanf("%s", &Inputs);
		Choice = Inputs[0];

		if (Choice == 'A' || Choice == 'a')
			A();
		else if (Choice == 'B' || Choice == 'b')
			B();
		else if (Choice == 'C' || Choice == 'c')
			C();
		else if (Choice == 'D' || Choice == 'd')
			D();
		else if (Choice == 'X' || Choice == 'x') {
			return;
		}

	} while (Choice != 'X' && Choice != 'x');
}

static void A() {

	int Item;
	printf("------------------------------------------------------------------------------\n");
	printf("Add Node To The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Value to add to node: ");
	scanf("%d", &Item);
	printf("\n");
	AddNode(Item);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
}

static void AddNode(int value) {

	// Create a new node.
	sllist* node = (sllist*) malloc(sizeof(sllist));
	// Test if not null
	if (node != NULL) {
		node->value = value;
		node->next = NULL;
		printf("Node added to the list with value %d.\n", value);
	}
	else {
		printf("Problem allocating memory for new node.\n");
		return;
	}

	// Add new node to the end.
	sllist* Traverser;
	if (ListHead != NULL) {
		Traverser = ListHead;
		while (Traverser->next !=NULL) {
			Traverser = Traverser->next;
		}
		Traverser->next = node;
	}
	else {
		ListHead = node;
	}

}

static void B() {

	printf("------------------------------------------------------------------------------\n");
	printf("Remove Node In The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
}

static void C() {

	printf("------------------------------------------------------------------------------\n");
	printf("Insert Node Into The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
}

static void D() {

	printf("------------------------------------------------------------------------------\n");
	printf("Display Nodes In The List\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");

	sllist* Traverser;
	if (ListHead != NULL) {
		printf("The ListHead is at %X\n", ListHead);
		Traverser = ListHead;
		do {
			printf("List item with value %d at memory location %X and next at %X\n", Traverser->value, Traverser, Traverser->next);
			Traverser = Traverser->next;
		} while (Traverser !=NULL);
	}
	else
		printf("The list empty.\n");

	printf("\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
}
