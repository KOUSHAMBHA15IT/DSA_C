#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}node;
node *front,*rear,*temp,*ptr;
void Insert()
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(rear==NULL)
	 {
	 	front=temp;
	 	rear=temp;
	 }
	else
	{
		rear->link=temp;
		rear=temp;
	}
}
void Delete()
{
	if(front==NULL)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",front->data);
		front=front->link;
	}
}
void display()
{
	if(front==NULL)
	 printf("\n List empty ");
	else
	{
		ptr=front;
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->link;
		}
	}
}
int main()
{
	int ch;
	front=NULL;
	rear=NULL;
	while(1)
	{
		printf("\n 1 for INSERT ");
		printf("\n 2 for DELETE ");
		printf("\n 3 for DISPLAY ");
		printf("\n 4 for EXIT ");
		printf("\n enter the choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			Insert();
			display();
			break;
			
			case 2:
			Delete();
			display();
			break;
			
			case 3:
			display();
			break;
			
			case 4:
			exit(1);
			
			default:
			printf("\n Wrong choice ");
		}
	}
}
