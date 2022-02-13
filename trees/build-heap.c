/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include <stdio.h>
#define LARGE_VALUE 99999   

void restoreUp(int a[],int loc);
void restoreDown(int a[],int i,int size);
void display(int a[],int n);
void buildHeap_TopDown(int a[], int n);
void buildHeap_BottomUp(int a[], int n);

main()
{
	int a1[]={LARGE_VALUE,20,33,15,6,40,60,45,16,75,10,80,12}; 
	int a2[]={LARGE_VALUE,20,33,15,6,40,60,45,16,75,10,80,12}; 
	
	int n=12;  
	
	buildHeap_TopDown(a1,n);
	buildHeap_BottomUp(a2,n);

	display(a1,n);
	display(a2,n);
}

void buildHeap_TopDown(int a[], int n)
{
	int i;
	for(i=2; i<=n; i++)
		restoreUp(a,i);
}

void buildHeap_BottomUp(int a[], int n)
{
	int i;
	for(i=n/2; i>=1; i--)
		restoreDown(a,i,n);
}

void restoreUp(int a[], int i)
{
	int k=a[i];  
	int iparent=i/2;
	
	while(a[iparent]<k)      
	{
		a[i]=a[iparent];
		i=iparent;
		iparent=i/2;
	}
	a[i]=k; 
}

void restoreDown(int a[], int i, int n)
{
	int k=a[i];
	int lchild=2*i, rchild=lchild+1;
		
	while(rchild<=n)
	{
		if( k>=a[lchild] && k>=a[rchild] )  
		{
			a[i]=k;
			return;
		}
		else if(a[lchild] > a[rchild])
		{
			a[i]=a[lchild]; 
			i=lchild;
		}
		else
		{
			a[i]=a[rchild];
			i=rchild;
		}
		lchild=2*i;
		rchild=lchild+1;
	}

	/*If number of nodes is even*/	
	if(lchild==n && k<a[lchild]) 
	{
		a[i]=a[lchild];
		i=lchild;
	}
	a[i]=k;
}

void display(int a[],int n)
{       
	int i;
	if(n==0)
	{
		printf("Heap is empty\n");
		return;
	}
	printf("Heap size = %d\n",n);
	for(i=1; i<=n; i++)
		printf("%d ",a[i]);
	printf("\n");
}


