/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>

struct  node
{
	int info ;
	struct node *link;
}*start=NULL;

void radixSort();
int digitsInLargest();
int digit(int number, int k);

main()
{
	struct node *temp,*p;
	int i,n,item;

	printf("Enter number of elements in the list : ");
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&item);

		/*Inserting elements in linked list*/
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info=item;
		temp->link=NULL;

		if(start==NULL) /*Inserting first element */
			start=temp;
		else
		{
			p=start;
			while(p->link!=NULL)
				p=p->link;
			p->link=temp;
		}
	}

	radixSort();

	printf("Sorted list is :\n");
	
	p=start;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n");
}/*End of main()*/

void radixSort()
{
	int i,k,dig,leastSigPos,mostSigPos;
	struct node *p, *rear[10], *front[10];

	leastSigPos=1;
	mostSigPos=digitsInLargest();

	for(k=leastSigPos; k<=mostSigPos; k++) 
	{
		/*Making all the queues empty at the beginning of each pass*/
		for(i=0; i<=9 ; i++)
		{
			rear[i] = NULL;
			front[i] = NULL;
		}
		
		for(p=start; p!=NULL; p=p->link)
		{
			/*Find kth digit from right in the number*/
			dig = digit(p->info,k);
		
			/*Insert the node in Queue(dig) */
			if(front[dig] == NULL)			
				front[dig]=p;
			else
				rear[dig]->link=p;
			rear[dig]=p;
		}
		
		/*Join all queues to form new linked list*/
		i=0;
		while(front[i] == NULL)  /*Finding first non empty queue*/
			i++;
		start = front[i]; 	
		while(i<=8) 
		{
			if(rear[i+1]!=NULL) /*if next queue (i+1)th  is not empty*/
				rear[i]->link=front[i+1]; /*join end of ith queue to start of (i+1)th queue*/
			else							
				rear[i+1]=rear[i]; /*continue with rear[i]*/
			i++;
		}
		rear[9]->link=NULL;  
	}/*End of for*/
}/*End of radixSort*/

/*Returns number of digits in the largest element of the list */
int digitsInLargest()
{
	struct node *p=start;
	int large=0,ndigits=0;

	/*Find largest element*/
	while(p!=NULL)
	{
		if(p->info > large)
			large = p->info;
		p=p->link;
	}
	/*Find number of digits in largest element*/
	while(large!=0)
	{
		ndigits++;
		large/=10;
	}
	return ndigits;
} 

/*Returns kth digit from right in n*/
int digit(int n, int k)
{
	int d, i ;
	for(i=1; i<=k; i++)
	{
		d=n%10 ;
		n/=10 ;
	}
	return d;
}


