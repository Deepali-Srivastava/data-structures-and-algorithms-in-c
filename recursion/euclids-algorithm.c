/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
int GCD(int a, int b);
main()
{
	int a,b;
	printf("Enter values for a and b : ");
	scanf("%d%d", &a, &b);
	printf("GCD of %d and %d is %d\n",a,b,GCD(a,b));
}

int GCD(int a, int b)   
{
	if(b==0)
	   return a;
	return GCD(b, a%b);
}


