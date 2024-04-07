#include<stdio.h>
#define MAX 10
int main()
{
	int a[MAX][MAX],color[MAX];
	int i,j,n,p;
	printf("Enter the no. of vertex ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Neighbour of %c : ",i+65);
		for(j=0;j<n;j++)
		 scanf("%d",&a[i][j]);
	}
	printf("\n matrix form \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	 color[i]=0; //initialize
	 
	color[0]=1; // initialize first node
	p=1;
	while(p<n)  //  5
	{
		color[p]=1;
		for(j=0;j<p;j++)//  <5
		{
			if(a[p][j]==1 && color[j]==color[p])	
			{
				color[p]++;
			}
		}
		p++;
	}
	for(i=0;i<n;i++)
	{
		printf("\n Vertex %c = color %d",i+65,color[i]);
	}
}
