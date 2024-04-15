#include<stdio.h>
struct Job
{
	char ID;
	int dead;
	int profit;	
}J[10];
void sort(struct Job J[], int n)
{
	int i,j;
	struct Job temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(J[j].profit<J[j+1].profit)
			{
				temp=J[j];
				J[j]=J[j+1];
				J[j+1]=temp;
			}
		}
	}
	
}
int main()
{
	int n,sum=0,i,d;

	printf("\n Enter the number of JOBS ");
	scanf("%d",&n);
	int status[n];
	char pros[n];
	for(i=0;i<n;i++)
	{
		printf("\n Enter ID Deadline and Profit ");
		fflush(stdin);
		scanf("%c%d%d",&J[i].ID,&J[i].dead,&J[i].profit);
	}
	for(i=0;i<n;i++)
	 status[i]=0;
	
	sort(J,n);
	for(i=0;i<n;i++)
	 printf(" %c\n",J[i].ID);
	for(i=0;i<n;i++)
	{
		d=J[i].dead-1;
		while(d>=0)
		{
			if(status[d]==0)
			{
				sum=sum+J[i].profit;
				status[d]=1;
				pros[d]=J[i].ID;
				break;
			}
			d--;
		}
	}
	printf("\n Total Profit : %d\n",sum);
	for(i=0;i<n;i++)
	{
		if(status[i]==1)
		 printf("%c ",pros[i]);
	}
}
