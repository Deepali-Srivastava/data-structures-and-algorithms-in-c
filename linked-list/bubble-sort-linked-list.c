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
void SortByExchangingData(struct node *start);
struct node *SortByExchangingLinks(struct node *start);

main()
{
	struct node *start1=NULL, *start2=NULL;	
	
	printf("Create first list \n");
	start1 = createList(start1);
	SortByExchangingData(start1);
	displayList(start1);


	printf("Create second list \n");
	start2 = createList(start2);
	start2 = SortByExchangingLinks(start2);
	displayList(start2);

}/*End of main()*/

void SortByExchangingData(struct node *start)
{
	struct node *end,*p,*q;
	int temp;

	for(end=NULL; end!=start->link; end=p)
	{
  		for(p=start; p->link!=end; p=p->link)
		{
			q=p->link;
			if(p->info > q->info)
			{
				temp=p->info;
				p->info=q->info;
				q->info=temp;
			}
		}
	}
}/*End of SortByExchangingData( )*/		

struct node *SortByExchangingLinks(struct node *start)
{
	struct node *end,*r,*p,*q,*temp;
		
	for(end=NULL; end!=start->link; end=p)
	{
  		for(r=p=start; p->link!=end; r=p,p=p->link)
		{
			q=p->link;
			if(p->info > q->info)
			{
				p->link=q->link;
				q->link=p;
				if(p!=start)
                    r->link=q;
				else
					start=q;
				temp=p;
				p=q;
				q=temp;
			}
		}
		
	}
	return start;
}/*End of SortByExchangingLinks()*/

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

