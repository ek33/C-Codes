#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

//Node declaration that will be used to store data in a stack
struct Node
{
	int val;
	struct Node *next;
};

//Declaration of a stack node
typedef struct Node StackRecord;
typedef StackRecord *Stack;

//Function signatures
Stack CreateStack();
void MakeEmptyStack(Stack);
void PushStack(int, Stack);
int PopStack(Stack);
int TopOfStack(Stack);
int IsEmptyStack(Stack);
void DisplayStack(Stack);

int main()
{
	Stack myStack;
	int exit, val;
	char command;

	myStack = CreateStack();

	exit = FALSE;

	while (!exit)
	{
		fflush(stdin);
		printf("Enter command i)nitialize p)ush r)emove (pop) t)op of stack e)xit: ");
		scanf("%c", &command);
		fflush(stdin);
		switch (command)
		{
		case 'i':
			MakeEmptyStack(myStack);
			break;
		case 'p':
			printf("enter value: ");
			scanf("%d", &val);
			fflush(stdin);
			PushStack(val, myStack);
			break;
		case 'r':
			
			if (IsEmptyStack(myStack))
				printf("The stack is empty!\n");
			else
				val = PopStack(myStack);
			printf("Pop value from stack = %d\n", val);
			break;
		case 't':
			val = TopOfStack(myStack);
			if (val != -1)
				printf("top element is %d\n", val);
			break;
		case 'e':
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
		DisplayStack(myStack);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

//This function initialises a stack with a dummy node
Stack CreateStack()
{
	Stack s;
	s=(Stack)malloc(sizeof(struct Node));
	if(s==NULL){
		printf("Error while allocating");
		exit(1);
	}s->next=NULL;
	return s;
}

//This function empties the content of a stack
void MakeEmptyStack(Stack s)
{
	while(s->next!=NULL)
		PopStack(s);
}

//This function checks if a stack is empty or not
int IsEmptyStack(Stack s)
{
	if(s->next==NULL)
		return 1;
	else
		return 0;
}

//This function checks if a stack is full
int IsFullStack(Stack s)
{
	return FALSE;
}

//This function creates a new node, adds the value of x to this node
//and then pushes this new node to the given stack
void PushStack(int x, Stack s)
{
	Stack temp;
	temp=(Stack)malloc(sizeof(struct Node));
	if(temp==NULL){
		printf("Error while allocating");
		exit(1);
	}
	temp->val=x;
	temp->next=s->next;
	s->next=temp;
}

//This function pops the top node from the stack frees the memory location 
//of that node and returns the value stored in that top node
int PopStack(Stack s)
{
	Stack temp=s->next;
	int t=temp->val;
	temp=temp->next;
	free(s->next);
	s->next=temp;
	return t;
}

//This function returns the value stored at the top node
int TopOfStack(Stack s)
{
	return s->next->val;

}

//This function displays the content of a stack
void DisplayStack(Stack s)
{
	struct Node *p;
	printf("Stack content:\n");
	if (IsEmptyStack(s))
		printf("The stack is empty!\n");
	else{
		p = s->next;
		while (p != NULL)
		{
			printf("\t--> %d\n", p->val);
			p = p->next;
		}
	}
}
