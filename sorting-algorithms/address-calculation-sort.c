/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
	int info ;
	struct node *link;
};
struct node *start[6];

void addrCalSort(int a[], int n);
void insertInList(int num,int addr);
int hash_fn(int x, int large);

main()
{
	int i,a[MAX],n;

	printf("Enter the number of elements in the list : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	
	addrCalSort(a,n);

	printf("Sorted list is :\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
}

void addrCalSort(int a[], int n)
{
	int i,j,addr,large=0;
	struct node *p;
	
	for(i=0; i<=5; i++)
		start[i]=NULL;
	
	for(i=0; i<n; i++)
	{
		if(a[i] > large)
			large = a[i];
	}
	
	for(i=0; i<n; i++)
	{
		addr=hashFn(a[i],large);
		insertInList(a[i],addr);
	}
	
	/*Elements of linked lists are copied to array*/
	i=0;
	for(j=0; j<=5; j++)
	{
		p=start[j];
		while(p!=NULL)
		{
			a[i++]=p->info;
			p=p->link;
		}
	}
}/*End of addrCalSort()*/

int hashFn(int x, int large)
{
	int addr;
	float temp;
	temp=(float)x/large;
	addr=temp*5;
	return addr;
}

/*Insertion in sorted linked list*/
void insertInList(int num,int addr)
{
	struct node *q,*temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = num;

	/*list is empty or item to be added in beginning */
	if(start[addr] == NULL || num < start[addr]->info)
	{
		temp->link=start[addr];
		start[addr]=temp;
		return;
	}
	else
	{
		q=start[addr];
		while(q->link != NULL && q->link->info < num)
			q=q->link;
		temp->link=q->link;
		q->link=temp;
	}
}



