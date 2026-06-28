#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10
#define TITLE_MAX_SIZE 52

// Stack : The data structure in the form of a stack
// >> The most important features is LIFO(Last-In, First-Out)

// There are two ways to implement
// first way is using Array
// >> This way is less flexible than second way 

// second way is using List
// >> This way is harder to make than first way
// => So, I would use first way in this script

// Functions to implement 
// >> for implementing two functions, There needs isEmpty(Check whether to be empty)/isFull(Check whether to be full) functions

// The part to define stack structure
typedef struct Stack {
	int data[MAX_SIZE];	// In this array, The data are stored  
	int top;	// This pointer point the value using index
}Stack;

// The functions to check condition of stack(Full or Empty)
bool isFull (Stack * s)
{
	// Because top index is counted like array index
	// starting to count from 0
	return s->top == MAX_SIZE - 1;
}

bool isEmpty (Stack * s)
{
	return s->top == -1;
}

// 1. Push
void Push(Stack * s, int value)
{
	// In the case, There aren't any place where the data can be stored
	if (isFull(s) == true)
	{
		printf("\n\n! Because Stack is full, you can't push value !\n");
		printf("! Please retry after making empty location that value can be put !\n");
		getch();
		return;
	}
	else
	{
		s->top++;
		s->data[s->top] = value;
	}
}

// 2. Pop
// >> This function returns the value that is deleted
int Pop(Stack * s)
{
	int returnValue = -1;
	
	// In the case, There aren't any data that can be deleted
	if (isEmpty(s) == true)
	{
		printf("\n\n! Because Stack is empty, you can't delete value !\n");
		printf("! Please retry after creating data can be deleted !\n");
		getch();
	}
	else
	{
		returnValue = s->data[s->top];
		// Logical remove
		s->top--;
	}
	// -1 means wrong end process (error code)
	return returnValue;
}

// 3. Display
void Display(Stack * s)
{
	int topCursor = s->top;
	
	printf("\n\n");
	// Touring every values, print the values using index 
	while (topCursor >= 0)
	{
		printf("|| %05d ||\n", s->data[topCursor]);
		topCursor--;
	}
	printf("===========\n");
	getch();
}

int main()
{
	Stack stack;
	// The part of Initializing stack
	// >> top that value is -1 means empty condition
	// But, We have to put value in 0 index not -1 
	stack.top = -1;
	
	int input = 3;
	// This value is used only when push function is used
	// Because in Stack deleting process, the value that will be deleted should be on the top of every values
	int value = 0;
	
	// The part to put title to center
	int i;
	char * Title = "STACK";
	int padding = (TITLE_MAX_SIZE - strlen(Title)) / 2;
	
	// Repeat until a stop command is received
	while (input != -1)
	{
		for (i = 0; i < padding; i++)
			printf(" ");
		printf("%s\n", Title);
		
		printf("====================================================\n");
		printf("|| 0 : Push || 1 : Pop || 2 : Display || -1 : End ||\n");
		printf("====================================================\n");
		printf("INPUT : ");
		scanf("%d", &input);
		
		// When adding or deleting data, receive value from user
		if (input == 0)
		{
			printf("VALUE : ");
			scanf("%d", &value);
		}
		
		if (input != -1)
			switch (input)
			{
				case 0 :	{
					Push(&stack, value);
					break;
				}
				case 1 : {
					Pop(&stack);
					break;
				}	
				case 2 : {
					Display(&stack);
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
	return 0;
}
