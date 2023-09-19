#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void push(int stk[], int *top1, int num)
{
		*top1=*top1+1;
		stk[*top1]=num;
}

void push2(int tstk[], int *top2, int num)
{
	*top2=*top2+1;
	tstk[*top2]=num;
}
int pop(int s[], int *t)
{
	int num=s[*t];
	*t=*t-1;
	return num;
}
void display(int stk[], int top)
{
	int i;
	for(i=0;i<=top;i++)
	 printf("\n %d",stk[i]);
}
int main()
{
	int top1=-1;
	int top2=-1;
	int ch,num,cpy,i;
	int stk[MAX],tstk[MAX];
	while(1)
	{
		printf("\n 1 for PUSH ");
		printf("\n 2 for POP ");
		printf("\n 3 for DISPLAY ");
		printf("\n 4 for EXIT ");
		printf("\n Enter Choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1:
			if(top1==MAX-1)
			 printf("\n O V E R F L O W ");
			else
			{
				printf("\n Enter number ");
				scanf("%d",&num);
				push(stk,&top1,num);
			}
			break;
			
			
			case 2:
			if(top1==-1)
			 printf("\n U N D E R F L O W");
			else
			{
				cpy=top1;
				for(i=1;i<=cpy;i++)
				{
					num=pop(stk,&top1);
					push2(tstk,&top2,num);
				}
				display(tstk,top2);
				printf("\n Delete Element %d",stk[top1]);
				top1--;
				cpy=top2;
				for(i=0;i<=cpy;i++)
				{
					num=pop(tstk,&top2);
					push(stk,&top1,num);
				}
			}
			break;
			case 3:
			display(stk,top1);
			break;
			
			case 4:
			exit(1);
			
			default:
			printf("\n Wrong choice ");
		}
	}
}
