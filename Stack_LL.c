#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *top,*temp,*ptr;
void push()
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(top==NULL)
	 top=temp;
	else
	{
		temp->link=top;
		top=temp;
	}
}
void pop()
{
	if(top==NULL)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",top->data);
		top=top->link;
	}
}
void display()
{
	if(top==NULL)
	 printf("\n List empty ");
	 
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->link;
		}
	}
}
int main()
{
	int ch;
	top=NULL;
	while(1)
	{
		printf("\n 1 for PUSH ");
		printf("\n 2 for POP ");
		printf("\n 3 for DISPLAY ");
		printf("\n 4 for EXIT ");
		printf("\n enter the choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			push();
			display();
			break;
			
			case 2:
			pop();
			display();
			break;
			
			case 3:
			display();
			break;
			
			case 4:
			exit(1);
			
			default:
			printf("\n Wrong choice ");
		}
	}
}
