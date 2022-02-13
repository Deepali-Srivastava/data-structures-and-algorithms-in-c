/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX];
int front,rear;

void initializeQueue();
int size();
int isFull();
int isEmpty();
void insert(int x);
int Delete();
int peek();
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
		scanf("%d",&choice);
		if(choice==6)
			break;
		
		switch(choice)
		{
		case 1 :
			printf("Enter the element to be inserted : ");
			scanf("%d",&x);
			insert(x);
			break;
		case 2 :
			printf("Element deleted is : %d\n",Delete());
			break;
		case 3:
			printf("Element at the front is  : %d\n",peek());
			break;
		case 4:
			display();
			break;
		case 5:
			printf("Size of queue is %d\n",size());
			break;
		default:
			printf("Wrong choice\n");
		}
		printf("\n");
	}
}
void initializeQueue()
{
	rear=-1;
	front=-1;
}

int isEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}
int isFull()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
		return 0;
}

void insert(int x)
{
	if(isFull())
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)  
		front=0;
	
	if(rear==MAX-1)
		rear=0;
	else
		rear=rear+1;
	a[rear]=x;
}

int Delete()
{
	int x;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	x=a[front];

	if(front==rear) /*queue has only one element*/
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else
		front=front+1;
	return x;
}

int peek()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return a[front];
}

void display()
{
	int i;
	printf("front = %d, rear = %d\n",front,rear);

	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Queue is :\n");

	i=front;
	if(front<=rear)
	{
		while(i<=rear)
			printf("%d ",a[i++]);
	}
	else
	{
		while(i<=MAX-1)
			printf("%d ",a[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",a[i++]);
	}
	printf("\n");
}

int size()
{
	int i,sz;
	
	if(isEmpty())
		return 0;
	if(isFull())
		return MAX;
	
	i=front;
	sz=0;
	if(front<=rear)
		while(i<=rear)
		{	
			sz++; 
			i++;
		}
	else
	{
		while(i<=MAX-1)
		{
			sz++;
			i++;
		}
		i=0;
		while(i<=rear)
		{
			sz++;
			i++;
		}
	}
	return sz;
}
