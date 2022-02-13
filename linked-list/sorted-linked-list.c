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

void displayList(struct node *start);
void search(struct node *start,int x);
struct node *insertInOrder(struct node *start,int data);

main()
{
	int choice,data;
	struct node *start=NULL;

	while(1)
	{
		printf("1.Display List\n");
		printf("2.Insert a new node\n");
		printf("3.Search\n");
		printf("4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		if(choice==4)
			 break;
		
		switch(choice)
		{
		 case 1:
			displayList(start);
			break;
		 case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insertInOrder(start,data);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(start,data);
			break;
		  default:
			printf("Wrong choice\n");
		}
	}/*End of while*/
} /*End of main */

struct node *insertInOrder(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	
	/*List empty or new node to be inserted before first node*/
	if(start==NULL || data<start->info)
	{
		temp->link=start;
		start=temp;
		return start;
	}

	p=start;
	while(p->link!=NULL && p->link->info <= data)
		p=p->link;

	temp->link=p->link;
	p->link=temp;
	return start;
}/*End of insertInOrder()*/


void search(struct node *start,int x)
{
	struct node *p;
	int position;
	
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}

	p=start;
	position=1;
	while(p!=NULL && p->info<=x)
	{
		if(p->info==x)
			break;
		position++;
		p=p->link;
	}
	if(p==NULL || p->info!=x)
		printf("%d not found in list\n",x);
	else
		printf("%d is at position %d\n",x,position);	
}/*End of search()*/

void displayList(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("List is :   ");
	p=start;
	while(p!=NULL)
	{
		printf("%d  ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of displayList() */


