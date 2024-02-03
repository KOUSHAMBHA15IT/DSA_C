#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int front,rear;
void Insert(int Q[])//insert
{
	int num;
	if(rear==MAX-1)
	 printf("\n O V E R F L O W");
	else
	{
		printf("\n Enter the number ");
		scanf("%d",&num);
		
		if(rear==-1)
		{
			front=0;
			rear=0;
			Q[rear]=num;
		}
		else
		 Q[++rear]=num;
		}
}
void Delete(int Q[])//delete
{
	if(front==-1)	
	 printf("\n U N D E R F L O W");
	else
	{
	 	printf("\n Delete Element %d",Q[front]);
	 	if(front==rear)
	 	{
	 		front=-1;
	 		rear=-1;
		 }
		 else
		  front++;
	}
	
}
void display(int Q[])
{
	int i;
	if(front==-1)
	 printf("\n Queue is Empty ");
	else
	{
		printf("\n Elements are \n");
		for(i=front;i<=rear;i++)
	 		printf("\n %d",Q[i]);
	}
}
int main()
{
	int queue[MAX];
	int ch;
	front=-1; rear=-1;// initialize
	while(1)
	{
		printf("\n 1 for INSERT ");
		printf("\n 2 for DELETE ");
		printf("\n 3 for DISPLAY ");
		printf("\n 4 for EXIT ");
		printf("\n\n Enter the Choice ");
		scanf("%d",&ch);
		
		
		switch(ch)
		{
			case 1:
			Insert(queue);
			break;
			
			case 2:
			Delete(queue);
			break;
			
			case 3:
			display(queue);
			break;
			
			case 4:
			exit(1);
			
			default:
			printf("\n Wrong choice ");
		}
	}
}
