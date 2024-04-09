#include<stdio.h>
#define INF 9999
int main()
{
	int n,i,j,s=0,r,c,p=0,min;
	printf("Enter NUmber of Vertex ");
	scanf("%d",&n);
	int g[n][n];
	int status[n];
	for(i=0;i<n;i++)
	{
		printf("\n Enter Neighbour of %c = ",i+65);
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
			if(g[i][j]==0)
			 g[i][j]=INF;
		}
	}
	for(i=0;i<n;i++)
	 status[i]=0;
	status[0]=1;// starting node
	while(p<n-1)
	{
		for(i=0;i<n;i++)
		{
			if(status[i]==1)//process row
			{
				min=INF;
				for(j=0;j<n;j++)
				{
					if(status[j]==0 && g[i][j]<min)
					{
						min=g[i][j];
						r=i;
						c=j;
					}
				}
			}
		}//outer for
		printf("\n %c --> %c = %d",r+65,c+65,min);
		s=s+min;
		status[c]=1;
		p++;
	}
	printf("\n Value %d",s);
}