/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *front,*rear;

void initializeQueue();
int size();
void insert(int x);
int Delete();
int peek();
int isEmpty();
void display();

main()
{
	int choice,x;
	
	initializeQueue();
	
	while(1)
	{       
		printf("1.Insert an element in the queue\n");
		printf("2.Delete an element from the queue\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Display size of the queue\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		if(choice==6)
			break;

		switch(choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&x);
			insert(x);
			break;
		case 2:
			x=Delete();
			printf("Element Deleted is : %d\n",x);
			break;
		case 3:
			printf("Element at the front is : %d\n",peek());
			break;
		case 4:
			display();
			break;
		case 5:
			printf("Size of the queue is %d\n",size());
			break;
		default :
			printf("Wrong choice\n");
		}
		printf("\n");
	}
}

void initializeQueue()
{
	front=NULL;
	rear=NULL;
}

int size()
{
	int s=0;
	struct node *p=front;
	while(p!=NULL)
	{
		s++;
		p=p->link;
	}
	return s;
}

void insert(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	temp->info=x;
	temp->link=NULL;

	if(front==NULL)		 /*If Queue is empty*/
		front=temp;
	else
		rear->link=temp;
	rear=temp;
}

int Delete()
{
	struct node *temp;
	int x;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	temp=front;
	x=temp->info;
	front=front->link;
	free(temp);
	return x;
}

int peek()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front->info;
}

int isEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void display()
{
	struct node *p;
	p=front;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Queue is :\n\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}
