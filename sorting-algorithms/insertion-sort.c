/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#define MAX 100

main()
{
	int a[MAX],i,j,temp,n;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &a[i]);
	}

	for(i=1; i<n; i++)
	{
		temp=a[i]; 
		
		for(j=i-1; j>=0 && a[j]>temp; j--)
			a[j+1]=a[j];
		
		a[j+1]=temp;
	}

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


