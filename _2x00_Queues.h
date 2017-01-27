/////////////////////////////////////////////////////////////////////////////////////
// Project     : 1x02 Data Structures in C
// Author      : James Piper, james@jamespiper.com
// Date        : 2017.01.26
// File        : _2x00_Queues.h
// Description : Queue data structure header file.
// IDE         : Code::Blocks 16.01
// Compiler    : GCC
// Language    : C (ISO 11)
/////////////////////////////////////////////////////////////////////////////////////

//#pragma once
#include "1x02 Data Structures in C.h"

#ifndef QUEUE_FILE
#define QUEUE_FILE

/////////////////////////////////////////////////////////////////////////////////////
// Macros
/////////////////////////////////////////////////////////////////////////////////////
#define SIZE_OF_ARRAY_QUEUE 5

/////////////////////////////////////////////////////////////////////////////////////
// User types.
/////////////////////////////////////////////////////////////////////////////////////
typedef struct LinearQueue
{
  int front;
  char item[SIZE_OF_ARRAY_QUEUE];
  int rear;
} LinearQueue;

typedef struct CircularQueue {
	int count;
	int front;
	char item[SIZE_OF_ARRAY_QUEUE];
	int rear;
} CircularQueue;

/////////////////////////////////////////////////////////////////////////////////////
// Function prototypes.
/////////////////////////////////////////////////////////////////////////////////////
// _2x01_Linear_Queue.cpp
void Add_Linear_Queue(LinearQueue*, char);
void Display_Linear_Queue(LinearQueue* queue);
void Delete_Linear_Queue(LinearQueue* queue);
// _2x01_Linear_Queue.cpp

// _2x02_Circular_Queue.cpp
void Add_Circular_Queue(CircularQueue*, char);
void Display_Circular_Queue(CircularQueue* queue);
void Delete_Circular_Queue(CircularQueue* queue);
// _2x02_Circular_Queue.cpp

#endif // QUEUE_FILE
