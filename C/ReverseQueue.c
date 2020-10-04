/*AUTHOR : Sayantan Banerjee (2018 IMT - 093)*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
}*front=NULL,*rear=NULL;

struct node2{
int val;
struct node2 *next;
}*top=NULL;

int PUSH(int value)
{
	
	struct node2 *current=(struct node2*)malloc(sizeof(struct node2));
	current->val=value;
	
	if(top==NULL)
	{
		top=current;
		current->next=NULL;
	}
	else
	{
		current->next=top;
		top=current;
	}
	
	return 0;
}

int POP()
{
	struct node2 *temp=top;
	if(top==NULL)
	{
		return 0;
	}
	else
	{
		top=top->next;
	}
	int a= temp->val;
	free(temp);
	return a;
}

int insert(int value)
{
	struct node *current=(struct node*)malloc(sizeof(struct node));
	
	current->val=value;
	current->next=NULL;
	
	if(rear==NULL)
	{
		front=current;
		rear=current;
	}
	else
	{
		rear->next=current;
		rear=current;
	}
	
	return 0;
}

int Delete()
{
	struct node *temp=front;
	if(front==NULL)
	{
		printf("\nQueue is empty!\n");
		return 0;
	}
	else if(rear==front)
	{
		rear=NULL;
		front=NULL;
	}
	else
	{
		front=front->next;
	}
	free(temp);
}

void Traverse()
{
	struct node *temp=front;
	if(front==NULL)
	{
		printf("\nQueue is empty!\n");
	}
	else
	{
		printf("\nQueue displayed is:\n");
		while(temp!=NULL)
		{
			printf(" %d -> ",temp->val);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

void REVERSE()
{
	struct node *temp=front;
	if(front==NULL)
	{
		printf("\nQueue is empty!\n");
	}
	else
	{
		printf("\nQueue is reversed!\n");
		while(temp!=NULL)
		{
			PUSH(temp->val);
			Delete();
			temp=front;
		}
		struct node2 *temp2=top;
		while(temp2!=NULL)
		{
			int a=POP();
			insert(a);
			temp2=top;
		}
		
	}
}

int main()
{
	int n,value;
	while(1)
	{
		
		printf("\nEnter 1 for insertion\nEnter 2 for delete\nEnter 3 for traverse\nEnter 4 for reverse queue\nEnter 5 for exit ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: 
					printf("\nEnter data : ");
					scanf("%d", &value);
					insert(value);
					break;
			case 2: Delete();
			break;
			case 3: Traverse();
			break;
			case 4: REVERSE();
			break;
			case 5: exit(0);
			break;
			default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}
