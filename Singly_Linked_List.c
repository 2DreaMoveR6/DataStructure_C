#include <stdio.h>
// Necessary header to include malloc function
#include <stdlib.h>
#include <string.h> 

#define TITLE_MAX_SIZE 57

// Singly Linked List : The data structure to connect nodes that contain datas

// Two basic elements 
/*
1. Data : the value to really store
2. Next pointer : the pointer to point next node location in memory
*/

typedef struct Node {
	int data;	// Data part to store
	struct Node * nextNode;		// Pointer to point next location
}Node;

// Features to implement
// >> Bring first location from parameter is called header
//    then, touring nodes, process the command 

// 1. Insert 
// >> There needs four functions(insert from empty/to front/to last/to mid)
Node * InsertNode(Node * head, Node * newNode)
{
	// If there aren't any nodes
	if (head == NULL)
	{
		head = newNode;
		newNode->nextNode = NULL;
	}
	else
	{
		newNode->nextNode = NULL;
		
		// The criteria to insert node is the size of data
		// A method of inserting data at the front, the smaller data size
		
		// If there are same value, the priority is the older one
		
		// if new Node's data is smallest, insert it at the front
		if (head->data >= newNode->data)
		{
			newNode->nextNode = head;
			head = newNode;
		}
		else
		{
			Node * curNode = head->nextNode;
			Node * prevNode = head;
			
			while (curNode != NULL)
			{
				if (curNode->data >= newNode->data)
				{
					newNode->nextNode = curNode;
					break;
				}

				// two pointers are touring between nodes, find the location for new node
				prevNode = curNode;
				curNode = curNode->nextNode;
			}
			
			// The important point is how to classify last and mid location
			// by assigning NULL to nextNode, I classify last and mid
			
			// When newNode is placed to behind of last node
			// newNode->nextNode = NULL;
			// prevNode->nextNode = newNode;
			
			// When newNode is placed to mid of nodes
			// newNode->nextNode = curNode;
			prevNode->nextNode = newNode;
			
			// Because the part(prevNode->nextNode = newNode) is always same
			// between last and mid
		}
	}
	
	return head;
}	

// 2. Delete
Node * DeleteNode(Node * head, int value)
{
	// If value is -1, Delete every nodes
	// If value is certain integer, Delete some nodes that have same value
		
	if (head == NULL)
	{
		printf("\n\n"); 
		printf("! There aren't any nodes !\n");
		printf("! Plase retry after creating any nodes !\n");
		getch();
	}
	else
	{
		Node * curNode = head->nextNode;
		Node * prevNode = head;
	
		// According to value parameter, the tool to free memory become different
		while (curNode != NULL)
		{
			if (value == -1)
			{
				free(prevNode);
			}
			else
			{
				if (curNode->data == value)
				{
					prevNode->nextNode = curNode->nextNode;
					free(curNode);
					curNode = prevNode;
				}
			}
			
			prevNode = curNode;
			curNode = curNode->nextNode;
		}
		
		// Because all deleting function use prevNode for free tool
		// Additionally, should free memory one more
		if (value == -1)
		{
			head = NULL;
			free(prevNode);	
		}
	}
	
	return head;
}

// 3. Display
Node * DisplayNode(Node * head)
{
	printf("\n\n");
	// If there aren't any nodes
	if (head == NULL)
	{
		printf("! There aren't any nodes !\n");
		printf("! Plase retry after creating any nodes !\n");
		getch();
	}
	else
	{
		Node * curNode = head;
		
		int i = 1;
		printf("HEAD");
		// The part to show data in nodes
		while (curNode != NULL)
		{
			printf(" -> | %05d |", curNode->data);
			
			// The part to change line in every three nodes
			if (i % 4 == 0)
			{
				printf("\n");
				i = 1;
			}
			
			curNode = curNode->nextNode;
			i++;
		}
		printf(" -> NULL\n");
	}
	
	getch();
	return head;
}

int main() {
	// Head : The pointer to point the first node
	Node * head = NULL;
	// Tail : The pointer to point the last node
	
	int input = 3;	
	int value = 0;	// The value to insert or delete 
	
	// The part to put title to center
	int i;
	char * Title = "SINGLY LINKED LIST";
	int padding = (TITLE_MAX_SIZE - strlen(Title)) / 2;
	
	// Repeat until a stop command is received
	while (input != -1)
	{
		for (i = 0; i < padding; i++)
			printf(" ");
		printf("%s\n", Title);
		
		printf("=========================================================\n");
		printf("|| 0 : Insert || 1 : Delete || 2 : Display || -1 : End ||\n");
		printf("=========================================================\n");
		printf("INPUT : ");
		scanf("%d", &input);
		
		// When adding or deleting data, receive value from user
		if (input == 0 || input == 1)
		{
			if (input == 1)
				printf("IF. you want to delete all nodes, input -1\n");
			printf("VALUE : ");
			scanf("%d", &value);
		}
		
		switch (input)
		{
			case -1 :
				return 0;
				break;
			case 0 :	{
				Node * newNode = (Node *)malloc(sizeof(Node));
				newNode->data = value;
				head = InsertNode(head, newNode);
				break;
			}
			case 1 : {
				head = DeleteNode(head, value);
				break;
			}	
			case 2 : {
				head = DisplayNode(head);
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
	
	// for preventing memory leak, free all memory locations 
	if (head != NULL)
		DeleteNode(head, -1);
	
	return 0;
}

