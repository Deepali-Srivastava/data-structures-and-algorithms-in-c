/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
int sum(int n);
void print1(int n);
void print2(int n);
int series(int n);

main()
{
	int n;
	printf("Enter value of n : ");
	scanf("%d", &n);
	
	print1(n);	printf("\n");
	print2(n);	printf("\n");
	
	printf("Sum = %d\n", sum(n));	

	printf("\b\b = %d\n", series(n));
}

int sum(int n)
{
	if(n==0)
		return 0;
	return n+sum(n-1);
}

void print1(int n)
{
	if(n==0)
	   return;
	printf("%d ",n);	
	print1(n-1);
}

void print2(int n)
{
	if(n==0)
	   return;
	print2(n-1);
	printf("%d ",n);	
}

int series(int n)
{
	int sum;
	if(n==0)
		return 0;
	sum=(n+series(n-1));
	printf("%d + ",n);
	return sum;
}