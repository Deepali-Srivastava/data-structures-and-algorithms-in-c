/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
float power(float x,int n);
main()
{
	float x;
	int n;
	printf("Enter values for x and n : ");
	scanf("%f %d",&x,&n);
	printf("%f^%d = %f\n",x,n,power(x,n));
}

float power(float x,int n)
{
	if(n==0)
		return 1;
	return x*power(x,n-1);
}

