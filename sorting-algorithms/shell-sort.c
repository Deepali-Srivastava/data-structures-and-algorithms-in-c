/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#define MAX 100

main()
{
	int a[MAX],i,j,temp,n,h;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	
	printf("Enter maximum increment(odd value) : ");
	scanf("%d",&h);
		
	while(h>=1)
	{
		for(i=h; i<n; i++)
		{
			temp=a[i];
			for(j=i-h; j>=0 && a[j]>temp; j=j-h)
				a[j+h]=a[j];
			a[j+h]=temp;
		}
		h=h-2; 
	}
	
	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}









/* Program of sorting using shell sort using knuth increments*/
/*
#include<stdio.h>
#define MAX 100
main()
{
	int a[MAX],i,j,temp,n,h;

	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}
	
	h=1;
	while(h<=(n-1)/9)
		h=3*h+1;
		
	while(h>=1)
	{
		for(i=h; i<n; i++)
		{
			temp=a[i];
			for(j=i-h; j>=0 && temp<a[j]; j=j-h)
				a[j+h]=a[j];
			a[j+h]=temp;
		}
		h=h/3; 
	}
	
	printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
*/