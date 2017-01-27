/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.26
// File        : _2x02_Circular_Queue.c
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
// Circular version is similar to linear except the queue can wrap around to the
// beginning to use empty elements.
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
void Use_Add_Circular_Queue(CircularQueue* queue);

void TestCode_D_Circular_Queue();
void TestCode_E_Circular_Queue();
void TestCode_F_Circular_Queue();
void TestCode_G_Circular_Queue();
void TestCode_H_Circular_Queue();

/////////////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////////////
void _2x02_Circular_Queue() {

	char Choice;
	CircularQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Queue.count = 0;

	do {

		printf("******************************************************************************\n");
		printf("*                                                                            *\n");
		printf("*   Circular Queue Data Structure                                            *\n");
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
			Use_Add_Circular_Queue(&Queue);
		else if (Choice == 'b') {
			Delete_Circular_Queue(&Queue);
			system("pause");
		} else if (Choice == 'c') {
			Display_Circular_Queue(&Queue);
			system("pause");
		} else if (Choice == 'd')
			TestCode_D_Circular_Queue();
		else if (Choice == 'e')
			TestCode_E_Circular_Queue();
		else if (Choice == 'f')
			TestCode_F_Circular_Queue();
		else if (Choice == 'g')
			TestCode_G_Circular_Queue();
		else if (Choice == 'h')
			TestCode_H_Circular_Queue();
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
void Use_Add_Circular_Queue(CircularQueue* queue) {

	char Item;
	printf("Input the element: ");
	fflush(stdin);
	scanf("%c", &Item);
	if (Item != NULL)
		Add_Circular_Queue(queue, Item);

}

void Add_Circular_Queue(CircularQueue* queue, char item) {

	// Queue is full.
	if (queue->count == SIZE_OF_ARRAY_QUEUE) {
		printf("***** The queue is full *****\n");
		printf("***** Item '%c' not added *****\n", item);
	} else {
		// Adjust rear to front of array.
		if (queue->rear == SIZE_OF_ARRAY_QUEUE)
			queue->rear = 0;

		// Add item.
		queue->item[queue->rear++] = item;
		queue->count++;
		printf("Item added to the queue: '%c'\n", item);
	}

	printf("Front  : %d\n", queue->front);
	printf("Rear   : %d\n", queue->rear);
	printf("Count  : %d\n", queue->count);
	printf("\n");

}

void Display_Circular_Queue(CircularQueue* queue) {

	printf("------------------------------------------------------------------------------\n");
	printf("List of Items In The Queue\n");
	printf("------------------------------------------------------------------------------\n");

	printf("Front  : %d\n", queue->front);
	printf("Rear   : %d\n", queue->rear);
	printf("Count  : %d\n", queue->count);
	printf("\n");

	if (queue->front == queue->rear)
		printf("The queue is empty.\n");
	else {
		for (int i = 0; i < queue->count; i++) {
			if ((queue->front + i) >= SIZE_OF_ARRAY_QUEUE)
				printf("Item  : '%c'\n", queue->item[queue->front + i - SIZE_OF_ARRAY_QUEUE]);
			else
				printf("Item  : '%c'\n", queue->item[queue->front + i]);
		}

	}

	printf("------------------------------------------------------------------------------\n");

}

void Delete_Circular_Queue(CircularQueue* queue) {

	printf("------------------------------------------------------------------------------\n");
	printf("Delete Item In The Queue (FIFO)\n");
	printf("------------------------------------------------------------------------------\n");

	printf("Front  : %d\n", queue->front);
	printf("Count  : %d\n", queue->count);

	if (queue->front == queue->rear)
		printf("***** The queue is empty. *****\n");
	else {
		printf("Item  : '%c' deleted\n", queue->item[queue->front++]);
		queue->count--;
		printf("Front  : %d\n", queue->front);
		printf("Count  : %d\n", queue->count);
	}

	printf("------------------------------------------------------------------------------\n");

}

/////////////////////////////////////////////////////////////////////////////////////
// Unit testing for this file.
/////////////////////////////////////////////////////////////////////////////////////
void TestCode_D_Circular_Queue() {

	printf("==============================================================================\n");
	printf("D - Unit Testing - Add Items To The Queue\n");
	printf("==============================================================================\n");
	printf("\n");

	CircularQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Queue.count = 0;

	printf("Items Added.\n");
	printf("------------------------------------------------------------------------------\n");
	char Item = 'a';
	Add_Circular_Queue(&Queue, Item);

	Item = 'b';
	Add_Circular_Queue(&Queue, Item);

	Item = 'c';
	Add_Circular_Queue(&Queue, Item);

	Item = 'd';
	Add_Circular_Queue(&Queue, Item);

	Item = 'e';
	Add_Circular_Queue(&Queue, Item);

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	Display_Circular_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_E_Circular_Queue() {

	printf("==============================================================================\n");
	printf("E - Unit Testing - Add Item To Full Queue\n");
	printf("==============================================================================\n");
	printf("\n");

	CircularQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Queue.count = 0;

	printf("Items Added.\n");
	printf("------------------------------------------------------------------------------\n");
	char Item = 'a';
	Add_Circular_Queue(&Queue, Item);

	Item = 'b';
	Add_Circular_Queue(&Queue, Item);

	Item = 'c';
	Add_Circular_Queue(&Queue, Item);

	Item = 'd';
	Add_Circular_Queue(&Queue, Item);

	Item = 'e';
	Add_Circular_Queue(&Queue, Item);

	Item = '!';
	Add_Circular_Queue(&Queue, Item);

	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	Display_Circular_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_F_Circular_Queue() {

	printf("==============================================================================\n");
	printf("F - Unit Testing - Delete Item From Queue\n");
	printf("==============================================================================\n");
	printf("\n");

	CircularQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Queue.count = 0;

	printf("Items Added.\n");
	printf("------------------------------------------------------------------------------\n");
	char Item = 'a';
	Add_Circular_Queue(&Queue, Item);

	Item = 'b';
	Add_Circular_Queue(&Queue, Item);

	Item = 'c';
	Add_Circular_Queue(&Queue, Item);

	Item = 'd';
	Add_Circular_Queue(&Queue, Item);

	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	Delete_Circular_Queue(&Queue);

	printf("\n");
	Display_Circular_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_G_Circular_Queue() {

	printf("==============================================================================\n");
	printf("G - Unit Testing - Delete Item From Empty Queue \n");
	printf("==============================================================================\n");
	printf("\n");

	CircularQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Queue.count = 0;

	Delete_Circular_Queue(&Queue);

	printf("\n");
	system("pause");

}

void TestCode_H_Circular_Queue() {

	printf("==============================================================================\n");
	printf("H - Unit Testing - Move Front Forward (Add, Delete, Repeat)\n");
	printf("==============================================================================\n");
	printf("\n");

	CircularQueue Queue;
	Queue.front = 0;
	Queue.rear = 0;
	Queue.count = 0;

	char Item = 'a';
	Add_Circular_Queue(&Queue, Item);
	Delete_Circular_Queue(&Queue);
	printf("\n");

	Item = 'b';
	Add_Circular_Queue(&Queue, Item);
	Delete_Circular_Queue(&Queue);
	printf("\n");
	system("pause");

	Item = 'c';
	Add_Circular_Queue(&Queue, Item);
	Delete_Circular_Queue(&Queue);
	printf("\n");

	Item = 'd';
	Add_Circular_Queue(&Queue, Item);
	Delete_Circular_Queue(&Queue);
	printf("\n");

	Display_Circular_Queue(&Queue);
	printf("\n");
	system("pause");

	Item = 'e';
	Add_Circular_Queue(&Queue, Item);
	Item = 'f';
	Add_Circular_Queue(&Queue, Item);
	Item = 'g';
	Add_Circular_Queue(&Queue, Item);

	Display_Circular_Queue(&Queue);

	printf("\n");
	system("pause");

}
