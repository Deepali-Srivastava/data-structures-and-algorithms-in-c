/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int a[MAX];
int front,rear;

void initializeQueue();
void insertFront(int x);
void insertRear(int x);
int deleteFront();
int deleteRear();
void display();
int isEmpty();
int isFull();

main()
{
	int choice,x;
	
	initializeQueue();

	while(1)
	{
		printf("1.Insert at the front end\n");
		printf("2.Insert at the rear end\n");
		printf("3.Delete from front end\n");
		printf("4.Delete from rear end\n");
		printf("5.Display all elements of deque\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		if(choice==6)
			break;

		switch(choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&x);
			insertFront(x);
			break;
		case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&x);
			insertRear(x);
			break;
		 case 3:
			printf("Element deleted from front end is : %d\n",deleteFront());
			break;
		 case 4:
			printf("Element deleted from rear end is : %d\n",deleteRear());
			break;
		 case 5:
			display();
			break;
		 default:
			printf("Wrong choice\n");
		}
	}
}

void initializeQueue()
{
	front=-1;
	rear=-1;
}

void insertFront(int x)
{
	if(isFull())
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)
	{	
		front=0;
		rear=0;
	}
	else if(front==0)
		front=MAX-1;
	else
		front=front-1;
	a[front]=x;
}

void insertRear(int x)
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

int deleteFront()
{
	int x;
	if( isEmpty() )
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	x=a[front];
	if(front==rear) 
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

int deleteRear()
{
	int x;
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	x=a[rear];
	
	if(front==rear) 
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
		rear=MAX-1;
	else
		rear=rear-1;
	return x;
}

int isFull()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

void display()
{
	int i;
	
	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}
	
	printf("Queue is : \n");
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


