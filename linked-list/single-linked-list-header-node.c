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

void createList(struct node *head);
void displayList(struct node *head);
void insertAtEnd(struct node *head,int data);
void insertBefore(struct node *head,int data,int x);
void insertAtPosition(struct node *head,int data,int k);
void deleteNode(struct node *head,int data);
void reverse(struct node *head);

main()
{
	int choice,data,x,k;
	struct node *head;	
	
	head=(struct node *)malloc(sizeof(struct node));
	head->info=0;	
	head->link=NULL;
	
	createList(head);
	
	while(1)
	{
		printf("1.Display list\n");
		printf("2.Insert a node at the end of the list\n");
		printf("3.Insert a new node before a node\n");
		printf("4.Insert at a given position\n");
		printf("5.Delete a node\n");
		printf("6.Reverse the list\n");
		printf("7.Quit\n\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		if(choice==7)
			break;

		switch(choice)
		{
		 case 1:
			displayList(head);
			break;
		 case 2:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			insertAtEnd(head,data);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&x);
			insertBefore(head,data,x);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&k);
			insertAtPosition(head,data,k);
			break;
		 case 5:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			deleteNode(head,data);	
			break;
		 case 6:
			reverse(head);
			break;
		 default:
			printf("Wrong choice\n\n");
		}
	}/*End of while */
}/*End of main()*/

void displayList(struct node *head)
{
	struct node *p;
	if(head->link==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head->link;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}/*End of displayList()*/

void insertAtEnd(struct node *head,int data)
{
	struct node *p,*temp;
	temp= (struct node *)malloc(sizeof(struct node));
	temp->info=data;

	p=head;
	while(p->link!=NULL)
		p=p->link;
	
	p->link=temp;
	temp->link=NULL;
}/*End of insertAtEnd()*/

void createList(struct node *head)
{
	int i,n,data;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		insertAtEnd(head,data);	
	}
}/*End of createList()*/

void insertBefore(struct node *head,int data,int x)
{
	struct node *temp,*p;
	
	/*Find pointer to predecessor of node containing x*/
	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==x)
			break;
		p=p->link;
	}
	
	if(p->link==NULL)
		printf("%d not present in the list\n",x);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
}/*End of insertBefore()*/		

void insertAtPosition(struct node *head,int data,int k)
{
	struct node *temp,*p;
	int i;
	
	p=head;
	for(i=1; i<=k-1 && p!=NULL; i++)
		p=p->link;
	
	if(p==NULL)
		printf("You can insert only upto %dth position\n\n",i-1);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}	
}/*End of insertAtPosition()*/

void deleteNode(struct node *head, int data)
{
	struct node *temp,*p;

	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==data)   
			break;
		p=p->link;
	}

	if(p->link==NULL)
		printf("Element %d not found\n",data);
	else
	{
		temp=p->link;
		p->link=temp->link;
		free(temp);
	}
}/*End of deleteNode()*/

void reverse(struct node *head)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
	ptr=head->link;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head->link=prev;
}/*End of reverse()*/

