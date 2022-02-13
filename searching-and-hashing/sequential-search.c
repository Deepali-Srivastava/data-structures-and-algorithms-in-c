/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include <stdio.h>
#define SIZE 100
int Search(int a[], int n, int searchValue);

main()
{
	int i, n, searchValue, a[SIZE], index;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	printf("Enter the elements : \n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i] );

	printf("Enter the value to be searched : ");
	scanf("%d", &searchValue);
	
	index = Search(a, n, searchValue);
	
	if(index == -1)
		printf("%d not found in array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);
}

int Search(int a[], int n, int searchValue)
{
	int i;
	for(i=0; i<n ; i++)
	{
		if( a[i] == searchValue )
			return i;
	}
	return -1;
}




