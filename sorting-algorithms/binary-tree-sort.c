/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *stack[MAX];
int top;
void initializeStack();
void push(struct node *item);
struct node *pop();
int empty();

struct node *getnode(int x);
struct node *insertNode(struct node *root, int x);
void inorder(struct node *ptr, int a[]);
struct node *Destroy(struct node *ptr);

main()
{
	struct node *root=NULL;
	int a[MAX], n, i;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&a[i]);
	}

	for(i=0; i<n; i++)
		root = insertNode(root, a[i]);

	inorder(root,a);
    
	printf("\nSorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");

   	root=Destroy(root);
}

struct node *getnode(int x)
{
	struct node *p=(struct node *) malloc(sizeof(struct node));
	p->info=x;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}

struct node *insertNode(struct node *root, int x)
{       
	struct node *temp,*par,*p;
	
	p=root;
	par=NULL;
	
	while(p!=NULL)
	{
		par=p;
		if(x < p->info)
			p=p->lchild;	
		else 
			p=p->rchild;
	}
	
	temp=getnode(x);

	if(par==NULL)
		root=temp;
	else if(x < par->info)
		par->lchild=temp;
	else
		par->rchild=temp;

	return root;
}

void inorder(struct node *root, int a[])
{
	struct node *p;
	int i;

	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	
	initializeStack();
	p=root;
	i=0;
	while(1)
	{
        /*Move on leftmost path rooted at p,pushing all the nodes in the path*/
		while(p->lchild!=NULL) /*Stop when we reach leftmost node*/
		{
			push(p);
			p=p->lchild;
		}
			
		while(p->rchild==NULL) /*visit and pop nodes till a node with right subtree is popped*/
		{
			a[i++]=p->info; /*Visit p*/
			if(empty())  /*If stack becomes empty traversal is finished*/
				return;
			p=pop();
		}
		/*Now p points to node that has a right subtree*/
		a[i++]=p->info; /*Visit p*/
		p=p->rchild;  /*Move to right subtree of p*/
	}
	printf("\n");
}

struct node *Destroy(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Destroy(ptr->lchild);
		Destroy(ptr->rchild);
		free(ptr);
	}
	return NULL;
}

/*Functions for implementation of stack*/
void initializeStack()
{
	top=-1;
}

void push(struct node *item)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	stack[++top]=item;
}

struct node *pop()
{
	struct node *item;
	if(top==-1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item=stack[top--];
	return item;
}

int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
} 


