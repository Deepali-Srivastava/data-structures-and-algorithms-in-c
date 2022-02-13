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

struct node *createSortedList(struct node *start);
struct node *insertInOrder(struct node *start,int data);
void displayList(struct node *start);
struct node *merge(struct node *p1,struct node *p2);

main()
{
	struct node *start1=NULL,*start2=NULL, *startM;	

	start1=createSortedList(start1);
	start2=createSortedList(start2);
	
	printf("List1 : ");	
	displayList(start1);

	printf("List2 : "); 
	displayList(start2);
	
	startM = merge(start1, start2);
	displayList(startM);

}/*End of main()*/


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

struct node *createSortedList(struct node *start )
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;

	for(i=1; i<=n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=insertInOrder(start, data);
	}
	return start;
}/*End of createSortedList()*/

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
	else
	{
		p=start;
		while(p->link!=NULL && p->link->info < data)
			p=p->link;
		temp->link=p->link;
		p->link=temp;
	}
	return start;
}/*End of insertInOrder()*/


void displayList(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}/*End of displayList()*/

