/*AUTHOR - Sayantan Banerjee (2018IMT-093) */

#include<stdio.h>
int queue[100],front=-1,rear=-1,size=-1;
void Insert()
{
	int value;
	if(front==(rear+1)%size)
	{
		printf("\nCircular Queue overflow\n");
		return;
	}
	if(rear==-1)
	{
		front=0;
		rear=0;
	}
	else{
		rear=(rear+1)%size;
	}
	printf("\nEnter the value to be Inserted ");
	scanf("%d",&value);
	queue[rear]=value;
}
void Delete()
{
	int temp;
	if(front==-1)
	{
		printf("\nCircular Queue underflow");
		return;
	}
	temp=front;
	if(rear==front)
	{
		front=-1;
		rear=-1;
	}
	else{
		front=(front+1)%size;
	}
	printf("\nThe deleated value is %d \n",queue[temp]);
}
void Traverse()
{
	int i;
	if(front==-1)
	{
		printf("\nCircular Queue underflow");
		return;
	}
	printf("\nCircular Queue data as follows: \n");
	if(front<=rear)
	{
	
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
	else
	{
		
		for(i=front;i<=size-1;i++)
		{
			printf("%d ",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
int main()
{
	int option;
	printf("\nEnter for the size of the Circular Queue ");
	scanf("%d",&size);
	while(1)
	{
	
		printf("\nEnter 1 for Insert \nEnter 2 for Delete \nEnter 3 for Traverse \nEnter 4 for Exit ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: Insert();
					break;
			case 2: Delete();
					break;
			case 3: Traverse();
					break;
			case 4: return 0;	
			default:
					printf("\nInvalid Input\n");
		}
	}
}
