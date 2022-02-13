/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#define MAX 100

void quickSort(int a[],int low,int up);
int partition(int a[], int low, int up);

main()
{
	int a[MAX],n,i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}

	quickSort(a,0,n-1);

	printf("Sorted list is :\n");
	for(i=0; i<n; i++ )
		printf("%d ",a[i]);
	printf("\n");

}

void quickSort(int a[],int low,int up)
{
	int p; /*index for pivot*/

	if(low>=up) /*zero or one element in sublist*/
		return;
	p = partition(a,low,up);
	quickSort(a,low,p-1); /*Sort left sublist*/
	quickSort(a,p+1,up);  /*Sort right sublist*/
}

int partition(int a[], int low, int up)
{
	int temp,i,j,pivot;
	
	pivot=a[low]; 

	i=low+1; /*moves from left to right*/
	j=up;    /*moves from right to left*/
	
	while(i<=j)  
	{
		while( a[i]<pivot && i<up ) 
   			i++; 
		
		while( a[j] > pivot ) 	
			j--;
		
		if(i<j) /*swap a[i] and a[j]*/
		{
			temp=a[i];	
			a[i]=a[j];	
			a[j]=temp;
			i++; 
			j--;
		}
		else /*found proper place for pivot*/
			break;
	}
	
	/* Proper place for pivot is j */
	a[low]=a[j];
	a[j]=pivot;
	
	return j;
}
