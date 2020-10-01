/* AUTHOR - Sayantan Banerjee (2018IMT-093) IIITM Gwalior */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
}*front=NULL,*rear=NULL;

int insert()
{
	int value;
	struct node *current=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data : ");
	scanf("%d", &value);
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
	printf("\n The value to be deleted is %d \n",temp->val);
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

int main()
{
	int n;
	while(1)
	{
		
		printf("\nEnter 1 for insertion\nEnter 2 for delete\nEnter 3 for traverse\nEnter 4 for exit ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: insert();
			break;
			case 2: Delete();
			break;
			case 3: Traverse();
			break;
			case 4: exit(0);
			break;
			default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}
