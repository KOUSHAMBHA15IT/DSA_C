#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;// actual data
	struct linklist *link;// address of next node
}node;
node *start,*temp,*ptr;
void insertFirst()
{
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	
	if(start==NULL)
	 start=temp;
	else
	{
		temp->link=start;
		start=temp;
	}
}
void insertLast()
{
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	
	if(start==NULL)
	 start=temp;
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
		
		  ptr=ptr->link;
	    }
		 
		ptr->link=temp;
	}
}
void deleteFirst()
{
	if(start==NULL)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",start->data);
		start=start->link;
	}
}
void deleteLast()
{
	if(start==NULL)
	 printf("\n U N D E R F L O W");
	else if(start->link==NULL)
	 {
	 	printf("\n Deleted %d",start->data);
	 	start=NULL;
	 }
	 else
	 {
	 	ptr=start;
	 	while(ptr->link->link!=NULL)
	 	 ptr=ptr->link;
	 	 
	 	printf("\n Deleted %d",ptr->link->data); 
	 	ptr->link=NULL;
	 	
	 }
}
void deleteany(int pos){
	int i=1;
	if(start==NULL)
	 printf("\n List is Empty ");
	 else{
	 	ptr=start;
	 	while(i!=pos-1){
	 		ptr=ptr->link;
	 		i++;
		 }
		 printf("\n Deleted %d",ptr->link->data);
		 ptr->link=ptr->link->link;
		 
	 	
	 }
}
void insertany(int pos){
	int i=1;
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	ptr=start;
	
	if(start==NULL)
	 start=temp;
	else
	{
		while(i!=pos-1){
			ptr=ptr->link;
	 		i++;
		}
		temp->link=ptr->link;
		ptr->link=temp;
		
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
			ptr=ptr->link;
		}
	}
}
int main()
{
	int ch;
	start=NULL;
	while(1)
	{
		printf("\n\n 1 for Insert First ");
		printf("\n 2 for Insert Last ");
		printf("\n 3 for Delete First ");
		printf("\n 4 for Delete Last ");
		printf("\n 5 for Delete any ");
		printf("\n 6 for Insert any ");
		printf("\n 7 for Exit ");
		printf("\n Enter choice : ");
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
			deleteany(3);
			display();
			break;
			
			case 6:
			insertany(3);// give the position inside the brackets
			display();
			break;
						
			case 7:
			exit(1);
			
			default:
			printf("\n Oops! Wrong choice ");
		}
	}
}
