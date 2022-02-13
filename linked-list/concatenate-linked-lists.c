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

struct node *createList(struct node *start);
void displayList(struct node *start);
struct node *insertInBeginning(struct node *start,int data);
void insertAtEnd(struct node *start,int data);
struct node *concatenate( struct node *start1,struct node *start2);

main()
{
	struct node *start1=NULL,*start2=NULL;

	start1=createList(start1);
	start2=createList(start2);

	printf("First list is  : ");	displayList(start1);
	printf("Second list is  : ");	displayList(start2);
    
	start1=concatenate(start1, start2);

	printf("Concatenated list is  : ");	displayList(start1);
}

struct node *concatenate( struct node *start1,struct node *start2)
{
	struct node *p;
	
	if(start1==NULL)
	{
		start1=start2;
		return start1;
	}
	
	if(start2==NULL)   
		return start1;

	p=start1;
	while(p->link!=NULL)
		p=p->link;
	
	p->link=start2;	
	
	return start1;
}

struct node *createList(struct node *start)
{
	int i,n,data;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	if(n==0)
		return start;

	printf("Enter the first element to be inserted : ");
	scanf("%d",&data);
	start=insertInBeginning(start,data);

	for(i=2; i<=n; i++)
	{
		printf("Enter the next element to be inserted : ");
		scanf("%d",&data);
		insertAtEnd(start,data);	
	}
	return start;
}/*End of createList()*/

struct node *insertInBeginning(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;

	temp->link=start;
	start=temp;
	
	return start;
}

void insertAtEnd(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;

	p=start;
	while(p->link!=NULL)
		p=p->link;
	
	p->link=temp;
	temp->link=NULL;
}

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
	printf("\n");
}/*End of displayList() */

