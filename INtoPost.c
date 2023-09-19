#include<stdio.h>
#include<string.h>
#define MAX 100
int check(char ch)
{
	if(ch=='^')
	 return 4;
	else if(ch=='/' || ch=='*' || ch=='%')
	 return 3;
	else if(ch=='+' || ch=='-')
	 return 2;
	else //(
	 return 1;
}
void push(char stk[], char ch, int  *top)
{
	*top=*top+1;
	stk[*top]=ch;
}
char pop(char stk[], int *top)
{
	char t=stk[*top];
	*top=*top-1;
	return t;
}
int main()
{
	int top=-1,i, ind=0;
	char infix[MAX],postfix[MAX],stack[MAX];
	printf("Enter the expression ");
	scanf("%s",infix);
	strupr(infix);
	for(i=0;i<strlen(infix);i++)
	{
		if(infix[i]=='(')
		 push(stack,infix[i],&top);
		
		else if(infix[i]>='A' && infix[i]<='Z')
		 postfix[ind++]=infix[i];
		
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			 postfix[ind++]=pop(stack,&top);
			 
			top--;//remove ( from stack top
		}
		else//operator
		{
			if(check(infix[i])>check(stack[top]))
			 push(stack,infix[i],&top);
			else
			{
				while(check(infix[i])<=check(stack[top]))
				 postfix[ind++]=pop(stack,&top);
				 
				push(stack,infix[i],&top);
			}
		}
		postfix[ind]='\0';
		stack[++top]='\0';
		printf("\n %c\t %s \t%s",infix[i],stack,postfix) ;
		top--;
		 
	}
}
