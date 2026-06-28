#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 6
#define TITLE_MAX_SIZE 59

// Queue : The data structure having FIFO(First-In, First-Out) structure
// Queue is divided by two kinds
// 1. linear queue
// >> Linear queue has critical limitation which is called fake saturation condition
// Because every points(front, rear) go to back side

// 2. circular queue
// >> This queue is implemented by logical way
// => So, I would implement circular way in this script
typedef struct Queue {
	int data[MAX_SIZE];
	
	// Pointers to point first and last values
	int front;
	int rear;
}CircularQueue;

// It's two way in Queue's core action
// Circular queue use the %(mod) operator to return 0 index
bool isQueueFull(CircularQueue * q)
{
	// in Circular queue, When to add 1 in index aspect, if it becomes 0 index (First index)
	// That means that queue is full
	return (q->rear + 1) % MAX_SIZE == q->front; 
}

bool isQueueEmpty(CircularQueue * q)
{	
	return q->front == q->rear;
}

// 1. Enqueue
// >> The job to add data in rear of queue
void Enqueue(CircularQueue * q, int value)
{
	if (isQueueFull(q) == true)
	{
		printf("\n\n");
		printf("! Because Queue is full, you can't enqueue value !\n");
		printf("! Please retry after making empty location that value can be put !\n");
		getch();
		return;
	}
	else
	{
		q->data[q->rear] = value;
		q->rear = (q->rear + 1) % MAX_SIZE;
	}
}

// 2. Dequeue
// >> The job to remove data in front of queue
// >> As like Stack, you can only delete value in one direction 
int Dequeue(CircularQueue * q)
{
	int returnValue = -1;
	if (isQueueEmpty(q) == true)
	{
		printf("\n\n");
		printf("! There aren't any data !\n");
		printf("! Plase retry after enqueueing any values !\n");
		getch();
		returnValue;
	}
	else
	{
		returnValue = q->data[q->front];
		q->data[q->front] = 0;
		q->front = (q->front + 1) % MAX_SIZE;
	}
	return returnValue;
}

void Display (CircularQueue * q)
{
	int i;
	
	// include front words
	int frontPadding = ((13 - 8) / 2) + (9 * q->front);
	int rearPadding = ((13 - 7) / 2) + (9 * q->rear);
	// formatting
	// One queue format size 13
	// Arrow size 3 (¡è/¡é)
	// Therefore, the criteria is 5((13 - 3) / 2) * (index + 1)
	// At least, need five blank in front of words
	
	printf("\n\n");
	
	for (i = 0; i < frontPadding; i++)
			printf(" ");
		printf("%s\n", "FRONT¡é");
	
	printf("||");
	for (i = 0; i < MAX_SIZE; i++)
	{
		printf(" %05d ||", q->data[i]);
	}
	
	printf("\n");
	for (i = 0; i < rearPadding; i++)
			printf(" ");
		printf("%s\n", "REAR¡è");
	getch();
}

int main()
{
	// The part to initialize Queue
	CircularQueue cq;
	cq.front = 0;
	cq.rear = 0;
	
	int i;
	for(i = 0; i < MAX_SIZE; i++)
		cq.data[i] = 0;
		
	// The most important fact is that in the circular queue, there aren't front and back
	int input = 3;
	int value = 0;
	
	// The history of delete process
	int dequeueHistory[15] = {0,};
	int dequeueCnt = 0;
	
	// The part to put title to center
	char * Title = "CIRCULAR QUEUE";
	int padding = (TITLE_MAX_SIZE - strlen(Title)) / 2;
	
	// Repeat until a stop command is received
	while (input != -1)
	{
		for (i = 0; i < padding; i++)
			printf(" ");
		printf("%s\n", Title);
		
		printf("===========================================================\n");
		printf("|| 0 : Enqueue || 1 : Dequeue || 2 : Display || -1 : End ||\n");
		printf("===========================================================\n");
		printf("INPUT : ");
		scanf("%d", &input);
		
		if (input == 0)
		{
			printf("VALUE : ");
			scanf("%d", &value);
		}
		
		if (input != -1)
			switch (input)
			{
				case 0 :	{
					Enqueue(&cq, value);
					break;
				}
				case 1 : {
					dequeueHistory[dequeueCnt] = Dequeue(&cq);
					dequeueCnt++;
					break;
				}	
				case 2 : {
					Display(&cq);
					break;
				}
				// exception processing
				default :
					printf("\n\n! This is worng input !\n");
					printf("! Try other input !\n");
					getch();
					break;	
			} 
		
		system("cls");	// clear the terminal screen (Window version)
	}
	
	printf("- Dequeue History -\n\n");
	for (i = 0; i < dequeueCnt; i++)
		printf("%d : %d\n", i + 1, dequeueHistory[i]);
	printf("\n------------------\n");
	return 0;
}
