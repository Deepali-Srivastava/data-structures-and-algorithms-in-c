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
struct node *insertInBeginning(struct node *last,int data);
struct node *insertAtEnd(struct node *last,int data);
struct node *insertAfter(struct node *last,int data,int item);
struct node *deleteNode(struct node *last,int data);

main( )
{
	int choice,data,item;
	struct node	*last=NULL;
	
	last=createList(last);
		
	while(1)
	{
		printf("1.Display List\n");
		printf("2.Insert in  empty list\n");
		printf("3.Insert in the beginning\n");
		printf("4.Insert at the end\n");
		printf("5.Insert after a node\n");
		printf("6.Delete a node\n");
		printf("7.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		if(choice==7)
			break;
		switch(choice)
		{
		 case 1:
			displayList(last);
			break;
		 case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=insertInEmptyList(last,data);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=insertInBeginning(last,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=insertAtEnd(last,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			last=insertAfter(last,data,item);
			break;
		 case 6:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			last=deleteNode(last,data);
			break;
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main( )*/

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
}/*End of displayList()*/

struct node *insertInBeginning(struct node *last,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	
	temp->link=last->link;
	last->link=temp;
	return last;
}/*End of insertInBeginning( )*/

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

struct node *insertAfter(struct node *last,int data,int x)
{
	struct node *temp,*p;
	p=last->link;
	do
	{
		if(p->info==x)
			break;
		p=p->link;
	}while(p!=last->link);

	if(p==last->link && p->info!=x)  
		printf("%d not present in the list\n",x);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;

		temp->link=p->link;
		p->link=temp;
		if(p==last)
			last=temp;
	}
	return last;
}/*End of insertAfter()*/

struct node *deleteNode(struct node *last,int x)
{
	struct node *temp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	/*Deletion of only node*/
	if(last->link==last && last->info==x)  
	{
		temp=last;
		last=NULL;
		free(temp);
		return last;
	}
	/*Deletion of first node*/
	if(last->link->info==x)    
	{
		temp=last->link;
		last->link=temp->link;
		free(temp);
		return last;
	}
	
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==x)     
			break;
		p=p->link;
	}
	
	if(p->link!=last) /*Node to be deleted is in between*/
	{
		temp=p->link;
		p->link=temp->link;
		free(temp);
	}
	else     
	{
		if(last->info==x) /*Node to be deleted is last node*/
		{
			temp=last;
			p->link=last->link;
			last=p;
			free(temp);
		}
		else
			printf("Element %d not found\n",x);
	}
	return last;
}/*End of deleteNode()*/




