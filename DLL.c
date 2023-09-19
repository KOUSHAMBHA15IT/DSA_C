#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}node;

node *start, *temp,*ptr;
void insertFirst()
{
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	if(start==NULL)
	 start=temp;
	else
	{
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
}
void insertLast()
{
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	if(start==NULL)
	 start=temp;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		 ptr=ptr->next;
		 
		ptr->next=temp;
		temp->prev=ptr;
	}
}
void deleteFirst()
{
	if(start==NULL)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",start->data);
		start=start->next;
		start->prev=NULL;
	}
}
void deleteLast()
{
	if(start==NULL)
	 printf("\n U N D E R F L O W");
	else if(start->next==NULL)
	{
		printf("\n Deleted %d",start->data);
		start=NULL;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		 ptr=ptr->next;
		 
		ptr=ptr->prev;
		ptr->next->prev=NULL;
		ptr->next=NULL;
	}
}
void display()
{
	if(start==NULL)
	 printf("\n List is Empty ");
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
	}
}
int main()
{
	int ch;
	start=NULL;
	while(1)
	{
		printf("\n 1 for Insert First ");
		printf("\n 2 for Insert Last ");
		printf("\n 3 for Delete First ");
		printf("\n 4 for Delete Last ");
		printf("\n 5 for Display ");
		printf("\n 6 for Exit ");
		printf("\n Enter choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			insertFirst();
			display();
			break;
			
			case 2:
			insertLast();
			display();
			break;
			
			case 3:
			deleteFirst();
			display();
			break;
			
			case 4:
			deleteLast();
			display();
			break;
			
			
			case 5:
			display();
			break;
			
			
			case 6:
			exit(1);
			
			default:
			printf("\n Bapi bari ja ");
			
							
		}
	}
}
