#include<stdio.h>

void sort(int p[], int w[], int n)
{
	int i,j,t;
	float r[n],temp;
	for(i=0;i<n;i++)
	 r[i]=(float)p[i]/w[i];
	 
	 
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(r[j]<r[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
				
				t=w[j];
				w[j]=w[j+1];
				w[j+1]=t;
				
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
				
			}
		}
	}
}
int main()
{
	int n,cap,i;
	float s=0.0,t;
	printf("Enter Number of Elements ");
	scanf("%d",&n);
	
	int p[n];
	int w[n];
	for(i=0;i<n;i++)
	{
		printf("Enter Profit & Weight of Item %d:  ",i+1);
		scanf("%d%d",&p[i],&w[i]);
	}
	printf("\n Enter the capacity ");
	scanf("%d",&cap);
	
	sort(p,w,n);// function call
	for(i=0;i<n;i++)
	{
		if(cap==0)
		 break;
		 
		else if(w[i]<=cap)
		{
			printf("\n %d",p[i]);
			s=s+p[i];
			cap=cap-w[i];
		}
		else
		{
			t=p[i]*((float)cap/w[i]);
			s=s+t;
			printf("\n %.2f",t);
			break;
		}
	}
	printf("\n Total Profit %.2f",s);
	return 0;
}
