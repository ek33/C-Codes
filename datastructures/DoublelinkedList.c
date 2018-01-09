#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
};

struct ListRecord
{
	struct Node *head;
	struct Node *tail;
	int length;
};
typedef struct ListRecord *DoubleList;

DoubleList CreateList(int);
void MakeEmptyList(DoubleList);
void InsertListAtPosition(DoubleList, int, int);
void DisplayList(DoubleList);

int main()
{
	DoubleList myList;
	int exit, val, pos;
	char command;
	exit = FALSE;

	myList = CreateList(0);

	while (!exit)
	{
		fflush(stdin);
		printf("\nMenu: \n i)nitialize\n n)ew element\n e(x)it\nEnter command: ");
		scanf("%c", &command);
		fflush(stdin);

		switch (command)
		{
		case 'i':
			MakeEmptyList(myList);
			break;
		case 'n':
			printf("enter value: ");
			scanf("%d", &val);
			printf("enter position: ");
			scanf("%d", &pos);
			InsertListAtPosition(myList, pos, val);
			break;
		case 'x':
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
		printf("\n");
		DisplayList(myList);

	}

	printf("\n");
	system("PAUSE");
	return 0;
}

DoubleList CreateList(int size)
{
	DoubleList l;

	l = (struct ListRecord *) malloc(sizeof(struct ListRecord));
	if (l == NULL){
		printf("Out of memory!\n");
		return NULL;
	}
	else{
		MakeEmptyList(l);
		return l;
	}
}

void MakeEmptyList(DoubleList l)
{
	l->head=(struct Node*)malloc(sizeof(struct Node));
	if(l->head==NULL){
		printf("Error while allocating memory!!");
		return;
	}
	l->tail=(struct Node*)malloc(sizeof(struct Node));
	if(l->tail==NULL){
		printf("Error while allocating memory!!");
		return;
	}
	l->head->next=NULL;
	l->head->prev=NULL;
	l->tail=l->head;
	l->length=0;
}

void InsertListAtPosition(DoubleList l, int pos, int val)
{
	struct Node *Pos;
	struct Node *temp;
	if(pos>l->length+1||pos<1){
		printf("Cannot insert that position!!");
		return;
	}else{
		temp=(struct Node *)malloc(sizeof(struct Node));
		if(temp==NULL){
			printf("Error while allocating memory!!");
			return;
		}
		temp->val=val;
		Pos=l->head;
		if(pos==1&&l->length==0){
			temp->next=NULL;
			temp->prev=NULL;
			l->tail=temp;
			l->head=temp;
		}else if(pos==1){
			temp->next=Pos;
			temp->prev=NULL;
			l->head=temp;
			Pos->prev=temp;
		}else{
			pos--;//iki kere ilk pos a eleman almadan ikinciye almiyor!!
			if(pos<l->length/2){
				
				for(;pos>1;pos--){
					Pos=Pos->next;
				}
				temp->next=Pos;
				temp->prev=Pos->prev;
				Pos->prev=temp;
				Pos->next=temp;
			}else{
				Pos=l->head;
				for(;pos>1;pos--){
					Pos=Pos->next;
				}
				temp->next=Pos->next;
				temp->prev=Pos;
				Pos->next->prev=temp;
				Pos->next=temp;
			}
		}
		
		l->length++;
	}
}

void DisplayList(DoubleList l)
{
	struct Node *p;

	p = l->head;
	printf("List content:\n");

	while (p != NULL)
	{
		printf("--> %d\t", p->val);
		p = p->next;
	}
}
