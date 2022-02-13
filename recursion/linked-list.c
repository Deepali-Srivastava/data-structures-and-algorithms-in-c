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
void displayList(struct node *p);
void displayListR(struct node *p);
int countNodes(struct node *p);
int sum(struct node *p);
int search(struct node *p, int x);
struct node *insertLast(struct node *p, int value);
struct node *deleteLast(struct node *p);

main()
{
	struct node *start=NULL;	
	int choice,x;
	start=createList(start);
		
	while(1)
	{
		printf("1.Display List\n");
		printf("2.Display List in reverse order\n");
		printf("3.Count nodes\n");
		printf("4.Sum of elements of the list\n");
		printf("5.Search for an element\n");
		printf("6.Insert at the end of the list\n");
		printf("7.Delete the last node of the list\n");
		printf("8.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		if(choice==8)
			break;

		printf("\n");
		switch(choice)
		{
		 case 1:
			displayList(start);
			printf("\n\n");
			break;
		 case 2:
			displayListR(start);
			printf("\n\n");
			break;
		 case 3:
			printf("Number of nodes=%d\n\n",countNodes(start));
			break;
		 case 4:
			printf("Sum of elements = %d\n\n",sum(start));
			break;		
		 case 5:
			printf("Enter the element to be searched : ");
			scanf("%d",&x);
			if(search(start,x)==1)
				printf("%d present in list\n\n",x);
			else
				printf("%d not present in the list\n\n",x);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&x);
			start=insertLast(start,x);
			break;
		 case 7:
			start=delLast(start);	
			printf("Last node deleted......\n");
			break;
		 default:
			 printf("Wrong choice\n");
		}
	}
}

struct node *createList(struct node *start)
{
	int i,n,data;
	struct node *p,*temp;
	
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);

		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=NULL;

		if(start==NULL) /*If list is empty */
			start=temp;
		else /*Inserted at the end*/
		{   
			p=start;
			while(p->link!=NULL)
				p=p->link;
			p->link=temp;
		}
	}
	return start;
}

void displayList(struct node *p)
{
	if(p==NULL)
		return;
	printf("%d ",p->info);
	displayList(p->link);
}

void displayListR(struct node *p)
{
	if(p==NULL)
		return;
	displayListR(p->link);
	printf("%d ",p->info);
}

int countNodes(struct node *p)
{
	if(p==NULL)
		return 0;
	return 1 + countNodes(p->link);
}

int sum(struct node *p)
{
	if(p==NULL)
		return 0;
	return p->info + sum(p->link);
}

int search(struct node *p,int x)
{
	if(p==NULL)
		return 0;
	if(p->info==x)
		return 1;
	return search(p->link,x);
}

struct node *insertLast(struct node *p, int x)
{
	struct node *temp;
	if(p==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=x;
		temp->link=NULL;	
		return temp;
	}
	p->link=insertLast(p->link, x);
    return p;
}

struct node *delLast(struct node *p)
{
	if(p->link==NULL)
	{
		free(p);
		return NULL;
	}	
	p->link=delLast(p->link);
	return p;
}

