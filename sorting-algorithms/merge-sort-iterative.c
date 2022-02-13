/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#define MAX 100

void mergeSort(int a[], int n);
void sortPass(int a[], int temp[], int size, int n);
void merge(int a[], int temp[],int low1, int up1, int low2, int up2);
void copy(int a[], int temp[], int n);

main()
{
	int a[MAX],i,n;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	
	mergeSort(a,n);

	printf("Sorted list is :\n");
	for(i=0; i<n ; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void mergeSort(int a[], int n)
{
	int temp[MAX];
	int size=1;
	while(size<=n-1)
	{
		sortPass(a,temp,size,n);
		size=size*2;
	}
}

void sortPass(int a[], int temp[], int size, int n)
{
	int i,low1,up1,low2,up2;
	
	low1=0;
	
	while( low1+size <= n-1 )
	{
		up1=low1+size-1;
		low2=low1+size;
		up2=low2+size-1;
		
		if(up2>=n)/*if length of last sublist is less than size*/ 						
			up2=n-1;
		
		merge(a,temp,low1,up1,low2,up2);
		
		low1=up2+1;	/*Take next two sublists for merging*/
	}
	
	for(i=low1; i<=n-1; i++)
		temp[i]=a[i];	/*If any sublist is left alone*/
	
	copy(a, temp, n); 
}

/* a[low1]...a[up1] and a[low2]...a[up2] merged to temp[low1]...temp[up2] */
void merge(int a[], int temp[],int low1, int up1, int low2, int up2 )
{
	int i=low1;
	int j=low2;
	int k=low1;

	while(i<=up1 && j<=up2 )
	{
		if( a[i] <= a[j] )
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	
	while(i<=up1)
		temp[k++]=a[i++];
	
	while(j<=up2)
		temp[k++]=a[j++];
}

/*copies temp[low]....temp[up] to a[low]...a[up]*/
void copy(int a[], int temp[], int n)
{
	int i;
	for(i=0;i<n;i++)
		a[i]=temp[i];
}

/*
void mergeSort(int a[], int n)
{
	int temp[MAX];
	int size=1;
	while(size<n)
	{
		sortPass(a,temp,size,n);
		size=size*2;
		sortPass(temp,a,size,n);
		size=size*2;
	}
}
*/
