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

struct node *createList(struct node *last);
void displayList(struct node *last);
struct node *insertInEmptyList(struct node *last,int data);
struct node *insertAtEnd(struct node *last,int data);
struct node *concatenate(struct node *last1,struct node *last2);

main()
{
	struct node *last1=NULL,*last2=NULL;
	
	last1=createList(last1);
	last2=createList(last2);

	printf("First list is :  ");	displayList(last1);
	printf("Second list is :  ");	displayList(last2);
    
	last1=concatenate(last1, last2);

	printf("Concatenated list is  : "); 	displayList(last1);
}

struct node *concatenate(struct node *last1,struct node *last2)
{
	struct node *p;
	
	if(last1==NULL)
	{
		last1=last2;
		return last1;
	}
	
	if(last2==NULL)   
		return last1;
	
	p=last1->link;
	last1->link=last2->link;
	last2->link=p;
	last1=last2;
	
	return last1;
}

struct node *createList(struct node *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=insertInEmptyList(last,data);
			
	for(i=2; i<=n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=insertAtEnd(last,data);	
	}
	return last;
}/*End of createList()*/

struct node *insertInEmptyList(struct node *last,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	
	last=temp;
	last->link=last;
	return last;
}/*End of insertInEmptyList()*/

struct node *insertAtEnd(struct node *last,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	
	temp->link=last->link;
	last->link=temp;
	last=temp;
	return last;
}/*End of insertAtEnd( )*/

void displayList(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	
	p=last->link;
	do 
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}/*End of displayList( )*/

