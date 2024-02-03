#include<stdio.h>
void main()
{
	int n;
	printf("Enter the limit of array:\n");
	scanf("%d",&n);
	int a[n]; int b=0,e=n;
	int mid=0;int s,f=0;
	printf("\nEnter the elements of array in ascending order:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to be searched:");
	scanf("%d",&s);
	while(b<e)
	  {
		mid=(b+e)/2;
		
		if(a[mid]==s)
		{ f=1;
		 break;
		}
		else if(a[mid]>s)
		{
			e=mid-1;
		}
		else
		b=mid+1;
	  }
 if(f==1)
 printf("\n The searched number is present");
 else
 printf("\n The searched number is not present");
}
