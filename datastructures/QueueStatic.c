#include <stdio.h>
#include <stdlib.h>

//Minimum queue size - minimum number of elements that 
//can be stored in a queue
#define MIN_QUEUE_SIZE 5
//Maximum queue size - maximum number of elements that
//can be stored in a queue
#define MAX_QUEUE_SIZE 100

#define FALSE 0
#define TRUE 1

//Queue record that holds the following data:
//capacity: the capacity of the queue, 
//front: index of the front element
//rear: index of the rear element
//size: size of the queue
//array: the array to hold the data in the stack
struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};
typedef struct QueueRecord *Queue;

//Function signatures
Queue CreateQueue(int);
void MakeEmptyQueue(Queue);
int Succ(int, Queue);
void Enqueue(int, Queue);
int Dequeue(Queue);
int FrontOfQueue(Queue);
int RearOfQueue(Queue);
int IsFullQueue(Queue);
int IsEmptyQueue(Queue);
void DisplayQueue(Queue);

int main()
{
    int queueSize;
    Queue myQueue;
    int exit, val;
    char command;
        
        printf("Enter queue size: ");
        scanf("%d", &queueSize);
        myQueue = CreateQueue(queueSize);
        
        exit = FALSE;
        
        while (!exit)
        {
               fflush(stdin);
               printf("Enter command i)nitialize e)nqueue d)equeue f)ront queue r)ear queue t)erminate: ");
               scanf("%c", &command);  
               fflush(stdin);
               
	              switch(command) 
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
	                        if (val != -1)
	                            printf("Dequed value is %d\n",val);
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
     
        printf("\n\n");              
        system("PAUSE");	
        return 0;
}


/*Creates a queue*/
Queue CreateQueue(int maxElements)
{
	if(maxElements<MIN_QUEUE_SIZE){
		printf("Size isn't proper");
		exit(1);
	}
	Queue Q;
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    if(Q==NULL){
    	printf("Error while memory allocating!!");
    	exit(1);
	}
    /* Initialise its properties */
    Q->array = (int *)malloc(sizeof(int)*maxElements);
    if(Q->array==NULL){
    	printf("Error while memory allocating!!");
    	exit(1);
	}
    Q->capacity = maxElements;
    MakeEmptyQueue(Q);
    /* Return the pointer */
    return Q;


}

/*Makes an empty queue*/
void MakeEmptyQueue(Queue Q)
{
	Q->size=0;
	Q->front=1;
	Q->rear=0;
	
}

/*Checks if a queue is empty*/
int IsEmptyQueue(Queue Q)
{
	if(!Q->size)
		return TRUE;
	return FALSE;
}


/*Checks if a queue is full*/
int IsFullQueue(Queue Q)
{
	if(Q->capacity==Q->size)
		return TRUE;
	return FALSE;
}

/*Moves the given value by one, if it is the end of the array,
 it makes the index 0*/
int Succ(int val, Queue q)
{
	val++;
	/* As we fill the queue in circular fashion */
	if(val == q->capacity)
	   val = 0;
	return val;
}

/*Adds a new value to the rear of the queue*/
void Enqueue(int x, Queue Q)
{
	//TO BE COMPLETED 
	/* If the Queue is full, we cannot push an element into it as there is no space for it.*/
        if(IsFullQueue(Q))
        {
                printf("Queue is Full\n");
        }
        else
        {
                Q->size++;
                /* Insert the element in its rear side */ 
                Q->rear=Succ(Q->rear,Q);
                Q->array[Q->rear] = x;
        }
        return;

}

/*Removes a value from the front of the queue*/
int Dequeue(Queue Q)
{
	/* If Queue size is zero then it is empty. So we cannot pop */
	if(IsEmptyQueue(Q)){
		printf("Queue is empty!!");
		return -1;
	}else{
		int x;
		x=Q->array[Q->front];
		Q->size--;
		Q->front=Succ(Q->front,Q);
		return x;
	}
		
}

/*Gives the front element in the queue*/
int FrontOfQueue(Queue Q)
{ 
	if(IsEmptyQueue(Q)){
		printf("Queue is Empty\n");
        return -1;
	}
    /* Return the element which is at the front*/
    return Q->array[Q->front];

}

/*Gives the rear element in the queue*/
int RearOfQueue(Queue Q)
{
	if(IsEmptyQueue(Q)){
		printf("Queue is Empty\n");
        return -1;
	}
	return Q->array[Q->rear];
}

/*Displays the content of the queue*/
void DisplayQueue(Queue q)
{
    int i, pos;
    printf("Front: %d",q->front);
    printf("Rear: %d",q->rear);
    pos=q->front;
    printf("Queue content:\n");
    
    for (i=0; i<q->size; i++)
    {
        printf("\t--> %d\n", q->array[pos]);
        pos = Succ(pos, q);
    }
}
