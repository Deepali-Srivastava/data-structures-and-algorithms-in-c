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
struct node *insertAtEnd(struct node *start,int data);
void insertCycle(struct node *start, int x);
struct node *findCycle(struct node *start);
void removeCycle(struct node *start, struct node *pC);

main()
{
	struct node *start=NULL;	
	struct node *ptr;		
	int x;

	start=createList(start);
	
	if(start==NULL)
		exit(1);
  	
	x=40;
	insertCycle(start,x);
	
	ptr=findCycle(start);
	
	if(ptr==NULL)
		printf("List is NULL terminated\n");
	else
	{
		printf("Cycle found in the list\n");	
		removeCycle(start, ptr);	
		printf("Cycle Removed, now list is NULL terminated\n");
	}
	displayList(start);
}/*End of main()*/


/*Insert a cycle at node containing x*/
void insertCycle(struct node *start, int x)
{
	struct node *p,*px=NULL, *prev, *ptr;		
	
	p=start;
	while(p!=NULL)
	{
		if(p->info==x)
			px=p;
		prev=p;
		p=p->link;
	}
	if(px!=NULL)
		prev->link=px;
}

/*Returns NULL if the list is NULL terminated otherwise returns 
pointer to node where both slow and fast pointers meet*/
struct node *findCycle(struct node *start)
{
	struct node *slowP, *fastP;
	
	if(start->link==NULL) /*only one element*/
		return NULL;

	slowP=fastP=start;

	while(fastP!=NULL && fastP->link!=NULL) 
	{
		slowP=slowP->link;
		fastP=fastP->link->link;
		if( slowP==fastP )
			return slowP;
	}
	return NULL;
}/*End of findCycle()*/

void removeCycle(struct node *start, struct node *pC)
{
	struct node *p, *q;
	int i, lenCycle, lenRemList, lengthList;
		
	printf("Node at which the cycle was detected is %d\n",pC->info);
	
	p=q=pC;	
	lenCycle=0;
	do
	{
		lenCycle++;
		q=q->link;
	}while(p!=q);
	printf("Length of cycle is : %d\n",lenCycle);
	
	lenRemList=0;
	p=start;
	while(p!=q)
	{
		lenRemList++;
		p=p->link;
		q=q->link;
	}
	
	printf("Number of nodes not included in the cycle are : %d\n",lenRemList);
	
	lengthList = lenCycle + lenRemList;
	printf("Length of the list is : %d\n",lengthList);
	
	p=start;
	for(i=1; i<=lengthList-1; i++)
		p=p->link;
	p->link=NULL;
}

struct node *createList(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=insertInBeginning(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=insertAtEnd(start,data);	
	}
	return start;
}/*End of createList()*/

void displayList(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}/*End of displayList() */

struct node *insertInBeginning(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}/*End of insertInBeginning()*/

struct node *insertAtEnd(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}/*End of addAtEnd()*/

