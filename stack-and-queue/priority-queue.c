/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int priority;
	int info;
	struct node *link;
};

struct node *front;

void initializeQueue();
void insert(int element, int elementPriority);
int Delete();
void display();
int isEmpty();

main()
{
	int choice,element,elementPriority;
	
	initializeQueue();
	
	while(1)
	{
		printf("1.Insert a new element\n");
		printf("2.Delete an element\n");
		printf("3.Display the queue\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		if(choice==4)
			break;

		switch(choice)
		{
		 case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&element);
			printf("Enter its priority : ");
			scanf("%d",&elementPriority);
			insert(element, elementPriority);
			break;
		 case 2:
			printf("Deleted element is %d\n",Delete());			
			break;
		 case 3:
			display();
			break;
		 default :
			printf("Wrong choice\n");
		}
	}
}

void initializeQueue()
{
	front=NULL;
}

void insert(int element,int elementPriority)
{
	struct node *temp,*p;
	
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	temp->info=element;
	temp->priority=elementPriority;

	/*Queue is empty or element to be added has priority more than first element*/
	if( isEmpty() || elementPriority < front->priority )
	{
		temp->link=front;
		front=temp;
	}
	else
	{
		p=front;
		while( p->link!=NULL && p->link->priority<=elementPriority )
			p=p->link;
		temp->link=p->link;
		p->link=temp;
	}
}

int Delete()
{
	struct node *temp;
	int element;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		temp=front;
		element=temp->info;
		front=front->link;
		free(temp);
	}
	return element;
}

int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;

}/*End of isEmpty()*/


void display()
{
	struct node *ptr;
	ptr=front;
	if(isEmpty())
		printf("Queue is empty\n");
	else
	{	
		printf("Queue is :\n");
		printf("Priority       element\n");
		while(ptr!=NULL)
		{
			printf("%5d        %5d\n",ptr->priority,ptr->info);
			ptr=ptr->link;
		}
	}
}




