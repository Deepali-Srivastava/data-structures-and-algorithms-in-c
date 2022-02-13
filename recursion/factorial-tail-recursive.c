/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
long TailRecursiveFact(int n);
long TRfact(int n, int result);
main( )
{
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	if(num<0)
		printf("No factorial for negative number\n");
	printf("Factorial of %d is %ld\n", num, TailRecursiveFact(num) );
}

long TRfact(int n, int result)
{
	if(n==0)
		return result;
	return TRfact(n-1, n*result);
}

long TailRecursiveFact(int n)
{
	return TRfact(n, 1);
}


