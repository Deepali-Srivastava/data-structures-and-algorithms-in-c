/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
int fib(int n);		
main()
{
	int terms,i;
	
	printf("Enter number of terms : ");
	scanf("%d", &terms);
	
	for(i=0; i<=terms; i++)
		printf("%d  ", fib(i));
	printf("\n");
}
 
int fib(int n)		
{
	if(n==0 )
		return 0;
	if(n==1)
		return 1;
	return fib(n-1) + fib(n-2);
}













//#include<stdio.h>
//
//int fib(int n);		
//int fibSum1(int n);		
//int TR_fib(int n, int next, int result);		
//
//main()
//{
//	int nterms,i;
//	printf("Enter number of terms : ");
//	scanf("%d", &nterms);
//	
//	for(i=0; i<=nterms; i++)
//		printf("%d  ", fib(i));
//	printf("\n");
//	
//	for(i=0; i<nterms; i++)
//		printf("%d  ", fibSum1(i));
//	printf("\n");
//}
// 
//int fib(int n)		
//{
//	if(n==0 )
//		return 0;
//	if(n==1)
//		return 1;
//	return fib(n-1) + fib(n-2);
//}
//
//int fibSum1(int n)		
//{
//	return TR_fib(n,1,1);
//}
//
//int TR_fib(int n, int next, int result)	
//{
//	if(n==0)
//		return result;
//	return TR_fib(n-1, next+result, next);
//}
//
