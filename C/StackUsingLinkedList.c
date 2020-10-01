#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int val;
struct node *next;
}*top=NULL;

int PUSH()
{
	int value;
	struct node *current=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data : ");
	scanf("%d", &value);
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
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\nStack is empty!\n");
		return 0;
	}
	else
	{
		top=top->next;
	}
	printf("\n The value to be deleted is %d \n",temp->val);
	free(temp);
}

void Traverse()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\nStack is empty!\n");
	}
	else
	{
		printf("\nStack displayed is:\n");
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
		
		printf("\nEnter 1 for PUSH\nEnter 2 for POP\nEnter 3 for TRAVERSE\nEnter 4 for EXIT ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: PUSH();
			break;
			case 2: POP();
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
