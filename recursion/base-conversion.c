/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
void toBinary(int n);
void convertBase(int, int);

main()
{
	int n;
	printf("Enter a positive decimal number : ");
	scanf("%d",&n);

	printf("Binary form : "); toBinary(n);		printf("\n");

	printf("Binary form : "); convertBase(n,2);	printf("\n");
	printf("Octal form : "); convertBase(n,8);	printf("\n");
	printf("Hexadecimal form : "); convertBase(n,16);	printf("\n");
}

void toBinary(int n)
{
	if(n==0)
		return;
	toBinary(n/2);
	printf("%d",n%2);	
}

void convertBase(int n,int base)
{
	int remainder;
	
	if(n==0)
		return;
	convertBase(n/base,base);
	
	remainder=n%base;
	if(remainder<10)
		printf("%d",remainder);	
	else
		printf("%c",remainder-10+'A');
}


