/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top;
void initializeStack();
void push(char);
char pop();
int isEmpty();

int isValid(char exp[]);
int matchParentheses(char leftPar,char rightPar);

main()
{
	char expression[MAX];

	int choice = 'y';
	
	while(choice=='y')
	{
		printf("Enter an expression with parentheses : ");
		gets(expression);
		
		initializeStack();
		
		if(isValid(expression))
			printf("Valid expression\n");
		else
			printf("Invalid expression\n");
		
		printf("Want to check another expression (Enter 'y' for yes) : ");
		scanf("%c",&choice);
		fflush(stdin);
	}
}

int isValid(char expr[])
{
	int i;
	char ch;

	for(i=0; i<strlen(expr); i++)
	{
		if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
			push(expr[i]);

		if(expr[i]==')' || expr[i]=='}' || expr[i]==']')
			if(isEmpty())    
			{
				printf("Right parentheses are more than left parentheses\n");
				return 0;
			}
			else
			{
				ch=pop();
				if(!matchParentheses(ch,expr[i]))
				{
					printf("Mismatched parentheses are : "); 
					printf("%c and %c\n",ch,expr[i]);	
					return 0;
				}
			}
	}

	if(isEmpty()) 
	{
		printf("Balanced Parentheses\n"); 
		return 1;
	}
	else 
	{
		printf("Left parentheses are more than right parentheses\n");	
		return 0;
	}
}

int matchParentheses(char leftPar,char rightPar)
{
	if(leftPar=='[' && rightPar==']')
		return 1;
	if(leftPar=='{' && rightPar=='}')
		return 1;	
	if(leftPar=='(' && rightPar==')')
		return 1;
	return 0;
}

void push(char x)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	stack[top]=x;
}

char pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return(stack[top--]);
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void initializeStack()
{
	top=-1;
}
