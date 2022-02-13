/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include <stdio.h>
#define MAX 100

main()
{
	int a[MAX],i,x,j,temp,n,swaps;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}

	for(x=n-2; x>=0; x--)
	{
		swaps=0;
		for(j=0; j<=x; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swaps++;
			}
		}
		if(swaps==0)
			break;
	}

	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	printf("\n");
}
























