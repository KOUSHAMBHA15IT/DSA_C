//DFS(Depth First Search)
#include<stdio.h>
void push(char stk[], int *top, char num)
{
	*top=*top+1;
	stk[*top]=num;
}
char pop(char stk[], int *top)
{
	char ch=stk[*top];
	*top=*top-1;
	return ch;
}
int main()
{
	int n,i,j,p=1,pos=0;
	char k;
	int top=-1;
	printf("\n Enter the number of Vertex ");
	scanf("%d",&n);
	int a[n][n],status[n];
	char stk[n];
	for(i=0;i<n;i++)
	{
		printf("\n Neighbour of %c : ",i+65);
		for(j=0;j<n;j++)
		 scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	 status[i]=1;// before stack
	
	printf(" A ");
	status[0]=3;
	
	while(p<n)
	{
		for(j=0;j<n;j++)
		{
			if(a[pos][j]==1 && status[j]==1)
			{
				push(stk,&top,(char)(j+65));
				status[j]=2;
			}
		}
		k=pop(stk,&top);
		printf("%c ",k);
		pos=(int)k-65;
		status[pos]=3;//outside stack
		p++;
	}
}
