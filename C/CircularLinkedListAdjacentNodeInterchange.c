/*AUTHOR - Sayantan Banerjee (2018IMT-093) */

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next;
}*head=NULL;

int count()
{	
		struct node *temp=head;
		int count=1;
		while(temp->next!=head)
		{
			count++;
			temp=temp->next;
		}
		return count;
}

void insert()
{
	struct node *current=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value");
	scanf("%d",&current->val);
	if(head==NULL)
	{
		head=current;
		
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=current;
	}
	current->next=head;
}
void Delete()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("\nLinked List is Empty");
	}
	else if(temp==head && temp->next==head)
	{
		head=NULL;
		printf("\nValue deleted is %d ",temp->val);
		free(temp);
	}
	else
	{
		struct node *temp2=head;
		temp2=temp->next;
		while(temp2->next!=head)
		{
			temp=temp->next;
			temp2=temp2->next;
		}
		temp->next=temp2->next;
		printf("\nValue deleted is %d ",temp2->val);
		free(temp2);
			
		
	}

}
void Traverse()
{
	struct node *temp=head;
	if(head==NULL)
		printf("\nLINKED LIST IS EMPTY");
	else
	{
		printf("\nCIRCULAR LIST: \n");
		printf("\n%d ->",temp->val);
		temp=temp->next;
	
		while(temp!=head)
		{
			printf("%d -> ",temp->val);
			temp=temp->next;
		}
		printf("%d",head->val);
	}
}
int AdjacentChange()
{
	
	if(head==NULL)
		printf("\nLINKED LIST IS EMPTY");
	else
	{
		int pos,TEMP;
		printf("\nEnter the position to be interchanged with its adjacent");
		scanf("%d",&pos);
		
		int no_of_nodes=count();
		if(no_of_nodes<pos)
		{
			printf("Invalid Position");
			return 0;
		}
		int trav=pos-1;
		struct node *temp=head;
		struct node *temp2=head;
		temp2=temp->next;
		while(trav--)
		{
			temp=temp->next;
			temp2=temp2->next;
			
		}
		TEMP=temp->val;
		temp->val=temp2->val;
		temp2->val=TEMP;
	}
}


int main()
{
	int n;
	while(1)
	{
		
		printf("\nEnter 1 for insertion\nEnter 2 for delete\nEnter 3 for traverse\nEnter 4 for Exchanging adjacent nodes\nEnter 5 for exit ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: insert();
			break;
			case 2: Delete();
			break;
			case 3: Traverse();
			break;
			case 4: AdjacentChange();
			break;
			case 5: exit(0);
			break;
			default:
			printf("\nINVALID INPUT!");
		}
	}
	return 0;
}
