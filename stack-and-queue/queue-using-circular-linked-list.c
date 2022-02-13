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

struct node *rear;

void initializeQueue();
int isEmpty();
int peek();
int size();
void insert(int x);
int Delete();
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
	rear=NULL;
}

int isEmpty()
{
	if(rear==NULL)
		return 1;
	else
		return 0;
}

void insert(int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=x;
	if(temp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	
	if(isEmpty()) 
	{
		rear=temp;
		rear->link=rear;
	}
	else
	{
		temp->link=rear->link;
		rear->link=temp;
		rear=temp;
	}
}

int Delete()
{
	int x;
	struct node *temp;
	if(isEmpty())
	{
		printf("Queue underflow\n");
		exit(1);
	}
	if(rear->link==rear)  /*If only one element*/
	{
		temp=rear;
		rear=NULL;
	}
	else
	{
		temp=rear->link;
		rear->link=temp->link;
	}
	x=temp->info;
	free(temp);
	return x;
}

int peek()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		exit(1);
	}
	return rear->link->info;
}

void display()
{
	struct node *p;
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	
	printf("Queue is :\n");
	p=rear->link;
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=rear->link);
	printf("\n");
}

int size()
{
	struct node *p;
	int s=0;
	if(isEmpty())
		return 0;
	
	p=rear->link;
	do
	{
		s++;
		p=p->link;
	}while(p!=rear->link);
	return s;	
}
