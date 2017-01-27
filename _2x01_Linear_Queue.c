/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.26
// File        : _2x01_Linear_Queue.c
// Description : Example code for a linear queue data structure.
//             : Menu presented to Add, Delete and Display queue items.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Linear Queue Characteristics:
// 1. Direct access.
//    Front points to first item in the queue.
//    Rear points to the last item in the queue.
// 2. Code uses an array to store items in the queue.
//    The queue size is limited. Static.
//    Better to use a linked list.
// 3. Homogeneous data - all 1 char.
// 4. Linear data - array.
// 5. FIFO list.
//
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Include files
/////////////////////////////////////////////////////////////////////////////////////
#include "1x02 Data Structures in C.h"
#include "_2x00_Queues.h"

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// Structures & Typedefs
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes
/////////////////////////////////////////////////////////////////////////////////////
void Use_Add_Linear_Queue(LinearQueue* queue);

void TestCode_D_Linear_Queue();
void TestCode_E_Linear_Queue();
void TestCode_F_Linear_Queue();
void TestCode_G_Linear_Queue();
void TestCode_H_Linear_Queue();

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _2x01_Linear_Queue() {

	char Choice;
	LinearQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Queue Data Structure                                                     *\n");
		printf("*                                                                            *\n");
		printf("*   Type Character + Enter                                                   *\n");
		printf("*                                                                            *\n");
		printf("*   A - Add Item                                                             *\n");
		printf("*   B - Delete Item                                                          *\n");
		printf("*   C - Display                                                              *\n");
		printf("*                                                                            *\n");
		#define DEBUG_201
		#ifdef DEBUG_201
		printf("*                                                                            *\n");
		printf("*   D - Unit Testing - Add Items To The Queue                                *\n");
		printf("*   E - Unit Testing - Add Item To Full Queue                                *\n");
		printf("*   F - Unit Testing - Delete Item From Queue                                *\n");
		printf("*   G - Unit Testing - Delete Item From Empty Queue                          *\n");
		printf("*   H - Unit Testing - Move Front Forward (Add, Delete, Repeat)              *\n");
		#endif
		#undef DEBUG_201
		printf("*                                                                            *\n");
		printf("*   X - Exit                                                                 *\n");
		printf("*   Z - Return To The Queue Menu                                             *\n");
		printf("*                                                                            *\n");
		printf("******************************************************************************\n");
		printf("\n");

		printf("Enter choice: ");
		char Inputs[MAX_INPUT_CHARS];
		scanf("%s", Inputs);
		Choice = tolower(Inputs[0]);
		printf("\n");

		if (Choice == 'a')
			Use_Add_Linear_Queue(&Queue);
		else if (Choice == 'b') {
			Delete_Linear_Queue(&Queue);
			system("pause");
		} else if (Choice == 'c') {
			Display_Linear_Queue(&Queue);
			system("pause");
		} else if (Choice == 'd')
			TestCode_D_Linear_Queue();
		else if (Choice == 'e')
			TestCode_E_Linear_Queue();
		else if (Choice == 'f')
			TestCode_F_Linear_Queue();
		else if (Choice == 'g')
			TestCode_G_Linear_Queue();
		else if (Choice == 'h')
			TestCode_H_Linear_Queue();
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
void Use_Add_Linear_Queue(LinearQueue* queue) {

	char Item;
	printf("Input the element: ");
	fflush(stdin);
	scanf("%c", &Item);
	if (Item != NULL)
		Add_Linear_Queue(queue, Item);

}

void Add_Linear_Queue(LinearQueue* queue, char item) {

	// Queue is full.
	if ((queue->front == 0) && (queue->rear == SIZE_OF_LINEAR_QUEUE)) {
		printf("***** The queue is full *****\n");
		printf("***** Item '%c' not added *****\n", item);
	} else {
		if (queue->rear == SIZE_OF_LINEAR_QUEUE) {
			// Shift items to start of the array.
			for (int i = queue->front; i < queue->rear; i++) {
				queue->item[i - queue->front] = queue->item[i];
				queue->rear = queue->rear - queue->front;
				queue->front=0;
			}
		}

		// Add item.
		queue->item[queue->rear++] = item;
		printf("Item added to the queue: '%c'\n", item);
		printf("Front : %d\n", queue->front);
		printf("Rear  : %d\n", queue->rear);
		printf("\n");
	}
}

void Display_Linear_Queue(LinearQueue* queue) {

	printf("------------------------------------------------------------------------------\n");
	printf("List of Items In The Queue\n");
	printf("------------------------------------------------------------------------------\n");

	printf("Front : %d\n", queue->front);
	printf("Rear  : %d\n", queue->rear);
	printf("\n");

	if (queue->front == queue->rear)
		printf("The queue is empty.\n");
	else {
		for (int i = queue->front; i < queue->rear; i++) {
			printf("Item  : '%c'\n", queue->item[i]);
		}
	}

	printf("------------------------------------------------------------------------------\n");

}

void Delete_Linear_Queue(LinearQueue* queue) {

	printf("------------------------------------------------------------------------------\n");
	printf("Delete Item In The Queue (FIFO)\n");
	printf("------------------------------------------------------------------------------\n");

	printf("Front : %d\n", queue->front);

	if (queue->front == queue->rear)
		printf("***** The queue is empty. *****\n");
	else
		printf("Item  : '%c' deleted\n", queue->item[queue->front++]);

	printf("Front : %d\n", queue->front);

	printf("------------------------------------------------------------------------------\n");

}
/////////////////////////////////////////////////////////////////////////////////////
// Unit testing for this file.
/////////////////////////////////////////////////////////////////////////////////////
void TestCode_D_Linear_Queue() {

	printf("==============================================================================\n");
	printf("D - Unit Testing - Add Items To The Queue\n");
	printf("==============================================================================\n");
	printf("\n");

	LinearQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;

	printf("Items Added.\n");
	printf("------------------------------------------------------------------------------\n");
	char Item = 'a';
	Add_Linear_Queue(&Queue, Item);

	Item = 'z';
	Add_Linear_Queue(&Queue, Item);

	Item = '1';
	Add_Linear_Queue(&Queue, Item);

	Item = 245;
	Add_Linear_Queue(&Queue, Item);

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	Display_Linear_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_E_Linear_Queue() {

	printf("==============================================================================\n");
	printf("E - Unit Testing - Add Item To Full Queue\n");
	printf("==============================================================================\n");
	printf("\n");

	LinearQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;

	printf("Items Added.\n");
	printf("------------------------------------------------------------------------------\n");
	char Item = 'a';
	Add_Linear_Queue(&Queue, Item);

	Item = 'z';
	Add_Linear_Queue(&Queue, Item);

	Item = '1';
	Add_Linear_Queue(&Queue, Item);

	Item = 245;
	Add_Linear_Queue(&Queue, Item);

	Item = '+';
	Add_Linear_Queue(&Queue, Item);

	Item = '!';
	Add_Linear_Queue(&Queue, Item);

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	Display_Linear_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_F_Linear_Queue() {

	printf("==============================================================================\n");
	printf("F - Unit Testing - Delete Item From Queue\n");
	printf("==============================================================================\n");
	printf("\n");

	LinearQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;

	printf("Items Added.\n");
	printf("------------------------------------------------------------------------------\n");
	char Item = 'a';
	Add_Linear_Queue(&Queue, Item);

	Item = 'z';
	Add_Linear_Queue(&Queue, Item);

	Item = '1';
	Add_Linear_Queue(&Queue, Item);

	Item = 245;
	Add_Linear_Queue(&Queue, Item);

	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	Delete_Linear_Queue(&Queue);

	printf("\n");
	Display_Linear_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_G_Linear_Queue() {

	printf("==============================================================================\n");
	printf("G - Unit Testing - Delete Item From Empty Queue \n");
	printf("==============================================================================\n");
	printf("\n");
	LinearQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Delete_Linear_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_H_Linear_Queue() {

	printf("==============================================================================\n");
	printf("H - Unit Testing - Move Front Forward (Add, Delete, Repeat)\n");
	printf("==============================================================================\n");
	printf("\n");

	LinearQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;

	char Item = 'a';
	Add_Linear_Queue(&Queue, Item);
	Delete_Linear_Queue(&Queue);
	printf("\n");

	Item = 'b';
	Add_Linear_Queue(&Queue, Item);
	Delete_Linear_Queue(&Queue);
	printf("\n");

	Item = 'c';
	Add_Linear_Queue(&Queue, Item);
	Delete_Linear_Queue(&Queue);
	printf("\n");

	Item = 'd';
	Add_Linear_Queue(&Queue, Item);
	Delete_Linear_Queue(&Queue);
	printf("\n");

	Display_Linear_Queue(&Queue);
	printf("\n");

	Item = 'e';
	Add_Linear_Queue(&Queue, Item);
	Item = 'f';
	Add_Linear_Queue(&Queue, Item);
	Item = 'g';
	Add_Linear_Queue(&Queue, Item);

	Display_Linear_Queue(&Queue);

	printf("\n");
	system("pause");

}
