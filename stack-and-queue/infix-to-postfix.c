/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<string.h>

#define MAX 100

void infixToPostfix(char infix[], char postfix[]);
long int evaluatePostfix(char postfix[]);
int precedence(char symbol);
int power(int b,int a);

long int stack[MAX];
int top=-1;
void push(long int symbol);
long int pop();
int isEmpty();

main()
{
	char infix[MAX],postfix[MAX];
		
	printf("Enter infix expression: ");
	gets(infix);
	
	infixToPostfix(infix, postfix);
	printf("Postfix expression is : %s\n",postfix);
	printf("Value of expression : %ld\n",evaluatePostfix(postfix));
}

void infixToPostfix(char infix[], char postfix[])
{
	unsigned int i,p;
	char next,symbol;

	p=0;
	for(i=0; i<strlen(infix); i++)
	{
		symbol=infix[i];

		if(symbol==' ' || symbol=='\t') /*ignore blanks and tabs*/
			continue;
		
		switch(symbol)
		{
			case '(':
				push(symbol);
				break;
			case ')':
				while((next=pop())!='(')
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while( !isEmpty() &&  precedence(stack[top])>= precedence(symbol) )
					postfix[p++]=pop();
				push(symbol);
				break;
			default: /*operand*/
			     postfix[p++]=symbol;
		}
	}
	while(!isEmpty()) 
		postfix[p++]=pop();
	postfix[p]='\0'; /*Add '\0' to make postfix a string*/
}

int precedence(char symbol)
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default :
		return 0;
	}
}

void push(long int symbol)
{
	if(top>MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	stack[++top]=symbol;
}

long int pop()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (stack[top--]);
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

long int evaluatePostfix(char postfix[])
{
	long int x,y,result;
	unsigned int i;
	
	for(i=0; i<strlen(postfix); i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push(postfix[i]-'0');
		else
		{
			x=pop();
			y=pop();
			switch(postfix[i])
			{
			case '+':
				push(y+x); break;
			case '-':
				push(y-x); break;
			case '*':
				push(y*x); break;
			case '/':
				push(y/x); break;
			case '%':
				push(y%x); break;
			case '^':
				push(power(y,x));
			}
		}
	}
	result=pop();
	return result;
}

int power(int b,int a)
{
	int i,x=1;
	for(i=1; i<=a; i++)
		x=x*b;
	return x;
}

