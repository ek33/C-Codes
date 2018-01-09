#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

/*A Node declaration to store a value and a link*/
struct Node
{
	int val;
	struct Node *next;
};

/*Queue Record that will store the following:
size: total number of elements stored in the list
front: it shows the front node of the queue (front of the queue)
rear: it shows the rare node of the queue (rear of the queue)*/
struct QueueRecord
{
	struct Node *front;   /* pointer to front of queue */
	struct Node *rear;    /* pointer to rear of queue */
	int size;             /* number of items in queue */
};
typedef struct QueueRecord *Queue;

Queue CreateQueue(int);
void MakeEmptyQueue(Queue);
int QueueSize(Queue);
void Enqueue(int, Queue);
int Dequeue(Queue);
int FrontOfQueue(Queue);
int RearOfQueue(Queue);
int IsEmptyQueue(Queue);
void DisplayQueue(Queue);

int main()
{
	int queueSize;
	Queue myQueue;
	int exit, val;
	char command;

	myQueue = CreateQueue(0);

	exit = FALSE;

	while (!exit)
	{
		fflush(stdin);
		printf("Enter command i)nitialize e)nqueue d)equeue f)ront queue r)ear queue t)erminate: ");
		scanf("%c", &command);
		fflush(stdin);

		switch (command)
		{
		case 'i':
			MakeEmptyQueue(myQueue);
			break;
		case 'e':
			printf("enter value: ");
			scanf("%d", &val);
			Enqueue(val, myQueue);
			break;
		case 'd':
			val = Dequeue(myQueue);
			break;
		case 'f':
			val = FrontOfQueue(myQueue);
			if (val != -1)
				printf("front element is %d\n", val);
			break;
		case 'r':
			val = RearOfQueue(myQueue);
			if (val != -1)
				printf("rear element is %d\n", val);
			break;
		case 't':
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
		DisplayQueue(myQueue);
	}
	printf("\n");
	system("PAUSE");
	return 0;
}

/*This function initialises the queue*/
Queue CreateQueue(int maxElements)
{
	//TO BE COMPLETED
}

/*This function sets the queue size to 0, and creates a dummy element
and sets the front and rear point to this dummy element*/
void MakeEmptyQueue(Queue q)
{
	//TO BE COMPLETED
}

/*Shows if the queue is empty*/
int IsEmptyQueue(Queue q)
{
	//TO BE COMPLETED
}

/*Returns the queue size*/
int QueueSize(Queue q)
{
	//TO BE COMPLETED 
}

/*Enqueue - Adds a new element to the queue, simly creates a node and 
adds it to the rear of the queue*/
void Enqueue(int x, Queue q)
{
	//TO BE COMPLETED
}

/*Dequeue - Removes a node from the queue, basically removes a node from 
the front of the queue*/
int Dequeue(Queue q)
{
	//TO BE COMPLETED
}

/*Returns the value stored in the front of the queue*/
int FrontOfQueue(Queue q)
{
	if (!IsEmptyQueue(q))
		return q->front->next->val;
	else
	{
		printf("The queue is empty\n");
		return -1;
	}
}

/*Returns the value stored in the rear of the queue*/
int RearOfQueue(Queue q)
{
	if (!IsEmptyQueue(q))
		return q->rear->val;
	else
	{
		printf("The queue is empty\n");
		return -1;
	}
}

/*Displays the content of the queue*/
void DisplayQueue(Queue q)
{
	struct Node *print;

	print = q->front->next;

	while (print != NULL)
	{
		printf("--> %d  ", print->val);
		print = print->next;
	}
	printf("\n");
}
