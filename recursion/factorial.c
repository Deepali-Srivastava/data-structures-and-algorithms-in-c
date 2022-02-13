/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
long int factorial(int n);
long int sum(int n);

main()
{
	int n;
	printf("Enter a number greater than or equal to zero : ");
	scanf("%d",&n);

	printf("Factorial of %d is %ld\n",n,factorial(n));
	printf("Sum of numbers from 1 to %d is %ld\n",n,sum(n));
}
long int factorial(int n)
{
	if(n==0)
		return 1;
	return n*factorial(n-1);
}

long int sum(int n)
{
	if(n==1)
		return 1;
	return n + sum(n-1);
}



