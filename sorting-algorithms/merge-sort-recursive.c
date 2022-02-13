/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#define MAX 100

void mergeSort( int a[], int low, int up );
void merge( int a[], int temp[], int low1, int up1, int low2, int up2 );
void copy(int a[], int temp[], int low, int up );

main()
{
	int i, n, a[MAX];
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}

	mergeSort(a,0,n-1);

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void mergeSort(int a[], int low, int up)
{
	int mid;
	int temp[MAX];
	
	if(low==up) /*only one element*/
		return;

	mid = (low+up)/2;
		
	mergeSort(a, low, mid);  /* Sort a[low]....a[mid] */
	mergeSort(a, mid+1, up);  /* Sort a[mid+1]....a[up] */
		
	/* Merge a[low]...a[mid] and a[mid+1]....a[up] to temp[low]...temp[up] */
	merge(a, temp, low, mid, mid+1, up); 
	
	/* Copy temp[low]...temp[up] to a[low]...a[up] */ 
	copy(a,temp,low,up);	
}

/* a[low1]...a[up1] and a[low2]...a[up2] merged to temp[low1]...temp[up2] */
void merge( int a[], int temp[], int low1, int up1, int low2, int up2 )
{
	int i = low1;
	int j = low2;
	int k = low1;

	while( (i<=up1) && (j<=up2) )
	{
		if(a[i]<=a[j])
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
void copy(int a[], int temp[], int low, int up)
{
	int i;
	for(i=low; i<=up; i++)
		a[i]=temp[i];
}
