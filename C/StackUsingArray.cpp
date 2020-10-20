#include<stdio.h>
#include<stdlib.h>
# define N 5
int stack[N],top=-1;
void push()
{
	int x;
	printf("Enter the number\n");
	scanf("%d",&x);
	if(top==N-1)
	{
		printf("Stack is Overflow\n");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack is Underflow\n");
	}
	else
	{
		printf("Popped Value is %d \n",stack[top]);
		top--;
	}
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}
void exit()
{
	exit(0);
}
int main()
{
	int choice;
	while(1)
	{
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Exit \n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit();
				break;
		}
	}
}
