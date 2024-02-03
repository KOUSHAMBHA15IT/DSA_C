#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top; //point top most element of the stack
void push(int stk[])
{
	int num;
	if(top==MAX-1)
	 printf("\n O V E R F L O W");
	else
	{
		printf("\n Enter the number ");
		scanf("%d",&num);
		
		stk[++top]=num;// place the number at stack top
	}
}
void pop(int stk[])
{
	if(top==-1)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",stk[top--]);
	}
}
void peep(int stk[])
{
	if(top==-1)
	 printf("\n No Element ");
	else
	{
		printf("\n Element %d",stk[top]);
	}
}
void display(int stk[])
{
	int i;
	if(top==-1)
	 printf("\n Stack is Empty ");
	else
	{
		for(i=top;i>=0;i--)
		 printf("\n %d",stk[i]);
	}
}
int main()
{
	int stack[MAX];
	int ch;
	top=-1;// initialize
	while(1)
	{
		printf("\n\n 1 for PUSH ");
		printf("\n 2 for POP ");
		printf("\n 3 for PEEP ");
		printf("\n 4 for DISPLAY ");
		printf("\n 5 for EXIT ");
		printf("\n\n Enter the choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			push(stack);
			break;
			
			case 2:
			pop(stack);
			break;
			
			case 3:
			peep(stack);
			break;
			
			case 4:
			display(stack);
			break;
			
			case 5:
			exit(1);
			
			default:
			printf("\n Oops! Wrong choice ");
			
			
		}
	}
}
