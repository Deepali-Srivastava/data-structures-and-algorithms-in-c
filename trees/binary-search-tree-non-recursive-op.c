/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *getnode(int x);
void display(struct node *p,int level);
struct node *search(struct node *p, int x);
struct node *insertNode(struct node *root, int x);
struct node *deleteNode(struct node *root, int x);
struct node *Min(struct node *p);
struct node *Max(struct node *p);

main()
{
	struct node *root=NULL, *p;
	int choice,x;
		
	while(1)
	{
		printf("\n");
		printf("1.Display Tree\n");
		printf("2.Search\n");
		printf("3.Insert a new node\n");
		printf("4.Delete a node\n");
		printf("5.Find minimum\n"); 
		printf("6.Find maximum\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		if(choice==7)
			break;

		switch(choice)
		{
		case 1: 
			display(root,0);
			break;
		case 2:
			printf("Enter the key to be searched : ");
			scanf("%d",&x);
			p=search(root,x);
			if(p==NULL)
				printf("Key not found\n");
			else
				printf("Key found\n");
			break;
		case 3:
			printf("Enter the key to be inserted : ");
			scanf("%d",&x);
			root=insertNode(root,x);
			break;
		case 4:
			printf("Enter the key to be deleted : ");
			scanf("%d",&x);
			root=deleteNode(root,x);
			break;
		case 5:
			p=Min(root);
			if(p==NULL)
			  printf("Tree is empty\n"); 
			else
			  printf("Minimum key is %d\n", p->info);
			break;
		case 6:
			p=Max(root); 	
			if(p==NULL)
			  printf("Tree is empty\n"); 
			else
			  printf("Maximum key is %d\n", p->info);
			break;
		}/*End of switch*/
	}/*End of while */
}/*End of main()*/

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
		else if(x > p->info)
			p=p->rchild;
		else
		{
			printf("%d already present in the tree\n",x);
			return root;
		}
	}
	
	temp=getnode(x);

	if(par==NULL)
		root=temp;
	else if(x < par->info)
		par->lchild=temp;
	else
		par->rchild=temp;

	return root;
}/*End of insertNode()*/

struct node *search(struct node *p, int x)
{
	while(p!=NULL)
	{
		if(x < p->info)
			p=p->lchild; /*Move to left child*/
		else if(x > p->info)
			p=p->rchild;  /*Move to right child */ 
		else	/*x found*/
			return p;
	}
	return NULL;
}/*End of search()*/

struct node *deleteNode(struct node *root, int x)
{
	struct node *par,*p,*ch,*s,*ps;
	
	p=root;
	par=NULL;
	while(p!=NULL)
	{
		if(x==p->info)
			break;
		par=p;
		if(x < p->info)
			p=p->lchild;	
		else 
			p=p->rchild;
	}

	if(p==NULL)
	{
		printf("%d not found\n",x);
		return root;
	}
	
	/*Case C: 2 children*/
	/*Find inorder successor and its parent*/
	if(p->lchild!=NULL && p->rchild!=NULL)
	{
		ps=p;
		s=p->rchild;
		while(s->lchild!=NULL)
		{
			ps=s;
			s=s->lchild;
		}
		p->info=s->info; 
		p=s;
		par=ps;
	}	

	/*Case B and Case A : 1 or no child*/
	if(p->lchild!=NULL) /*node to be deleted has left child */
		ch=p->lchild;
	else                /*node to be deleted has right child or no child*/
		ch=p->rchild;

	if(par==NULL)   /*node to be deleted is root node*/
		root=ch;
	else if(p==par->lchild)/*node is left child of its parent*/
		par->lchild=ch;
	else       /*node is right child of its parent*/
		par->rchild=ch;
	free(p);
	return root;
}

struct node *Min(struct node *p)
{
	if(p==NULL)
		return NULL;
	while(p->lchild!=NULL)
		p=p->lchild;
	return p;
}/*End of Min()*/

struct node *Max(struct node *p)
{
	if(p==NULL)
		return NULL;
	while(p->rchild!=NULL)
		p=p->rchild;
	return p;
}/*End of Max()*/

void display(struct node *p,int level)
{
	int i;
	if(p==NULL)
		return;
	
	display(p->rchild, level+1);
	printf("\n");
	
	for(i=0; i<level; i++)
		printf("    ");
	printf("%d",p->info);
	
	display(p->lchild, level+1);
}/*End of display()*/