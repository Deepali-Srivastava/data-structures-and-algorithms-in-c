/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
int sumDigits( long int n);

main()
{
	long int n;
	printf("Enter a number : ");
	scanf("%ld", &n);
	printf("%d\n",sumDigits(n));
}
int sumDigits(long int n)
{
	if(n/10==0) 
		return n;
	return sumDigits(n/10) + n%10;		
}

