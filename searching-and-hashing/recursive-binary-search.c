/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include <stdio.h>
#define SIZE 100

int Search(int a[], int n, int searchValue);
int SearchR(int a[], int first, int last, int searchValue);

main()
{
	int i, n, searchValue, a[SIZE], index;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	printf("Enter the elements in sorted order : \n");
	for( i=0; i<n; i++)
		scanf("%d", &a[i] );

	printf("Enter the item to be searched : ");
	scanf("%d", &searchValue);
	
	index = Search(a, n, searchValue);

	if( index == -1 )
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);
}

int Search(int a[], int n, int searchValue)
{
	return SearchR(a, 0, n-1, searchValue);
}

int SearchR(int a[], int first, int last, int searchValue)
{
	int mid;

	if( first > last)
		return -1;

	mid = (first+last)/2;
	
	if(searchValue > a[mid]) /*Search in right half*/
		return SearchR(a, mid+1, last, searchValue);
	else if( searchValue < a[mid] )/*Search in left half*/
		return SearchR(a, first, mid-1, searchValue);
	else
		return mid;
}

