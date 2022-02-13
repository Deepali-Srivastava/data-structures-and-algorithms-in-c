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
struct node *mergeSort(struct node *p);
struct node *divideList(struct node *p);
struct node *merge(struct node *p,struct node *q);

main()
{
	struct node *start=NULL;
	start = createList(start);
	start = mergeSort(start);
	displayList(start);
}

struct node *mergeSort(struct node *start)
{
	struct node *start1, *start2, *startM;
	
	if( start==NULL || start->link==NULL )/*if list empty has or one element*/
		return start;

	/*if more than one element*/
	start1 = start;
	start2 = divideList(start);
	start1 = mergeSort(start1);
	start2 = mergeSort(start2);
	startM = merge(start1, start2);
	return startM;
}

struct node *divideList(struct node *p)
{
	struct node *q, *start2;
	
	q=p->link->link;
	while(q!=NULL && q->link!=NULL)
	{
		p=p->link;
		q=q->link->link;
	}
	start2 = p->link;
	p->link = NULL;
	return start2;
}

struct node *merge(struct node *p1,struct node *p2)
{
	struct node *startM,*pM;
	
	if(p1->info <= p2->info)
	{
		startM = p1;
		p1 = p1->link;
	}
	else
	{
		startM = p2;
		p2 = p2->link;
	}
	
	pM = startM;
	while( p1!=NULL && p2!=NULL )
	{
		if( p1->info <= p2->info )
		{
			pM->link = p1;
			pM = pM->link;
			p1 = p1->link;
		}
		else
		{
			pM->link = p2;
			pM = pM->link;
			p2 = p2->link;
		}
	}
	
	if(p1==NULL)
		pM->link=p2;
	else
		pM->link=p1;
	return startM;
}

struct node *createList(struct node *start)
{
	int i,n,data;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	if(n<=0)
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




