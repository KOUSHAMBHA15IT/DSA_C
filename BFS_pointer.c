//BFS(Depth First Search)-queue
#include<stdio.h>
void Insert(char Q[], int *f,int *r, char num)
{
	if(*r==-1)
	{
		*r=0;
		*f=0;
		Q[*r]=num;
	}
	else
	{
	*r=*r+1;
	Q[*r]=num;
    }
}
char Delete(char Q[], int *f,int *r)
{
	char ch=Q[*f];
	if(*f==*r)
	{
		*f=-1;
		*r=-1;
	}
	else
	*f=*f+1;
	return ch;
}
int main()
{
	int n,i,j,p=1,pos=0;
	char k;
	int f=-1,r=-1;
	printf("\n Enter the number of Vertex ");
	scanf("%d",&n);
	int a[n][n],status[n];
	char Q[n];
	for(i=0;i<n;i++)
	{
		printf("\n Neighbour of %c : ",i+65);
		for(j=0;j<n;j++)
		 scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	 status[i]=1;// before queue
	
	printf(" A ");
	status[0]=3;
	
	while(p<n)
	{
		for(j=0;j<n;j++)
		{
			if(a[pos][j]==1 && status[j]==1)
			{
				Insert(Q,&f,&r,(char)(j+65));
				status[j]=2;
			}
		}
		k=Delete(Q,&f,&r);
		printf("%c ",k);
		pos=(int)k-65;
		status[pos]=3;//outside queue
		p++;
	}
}
