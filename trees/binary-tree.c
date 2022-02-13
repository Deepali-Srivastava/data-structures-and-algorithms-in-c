/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	char info;
	struct node *rchild;
};

struct node *getnode(char x);
void display(struct node *p,int level);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);
void levelOrder(struct node *root);
int height(struct node *p);

#define MAX 100
struct node *queue[MAX];
int front=-1,rear=-1;
void insertQueue(struct node *item);
struct node *deleteQueue();
int queueEmpty();

main()
{
	struct node *root=NULL;

	root = getnode('P');  
	
	root->lchild = getnode('Q');
	root->rchild = getnode('R');
	root->lchild->lchild = getnode('A');
	root->lchild->rchild = getnode('B');
	root->rchild->lchild = getnode('X');
	
	display(root,0);
	printf("\n\n");

    printf("Preorder : ");
	preorder(root); 
	printf("\n\n");

	printf("Inorder : ");
	inorder(root);
	printf("\n\n");

	printf("Postorder : ");
	postorder(root);
	printf("\n\n");

	printf("Level order : ");
	levelOrder(root);
	printf("\n\n");

	printf("Height of tree is %d\n", height(root));

	getchar();

}

struct node *getnode(char x)
{
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->info=x;
	p->lchild=p->rchild=NULL;
	return p;
}

void display(struct node *p,int level)
{
	int i;
	if(p==NULL)
		return;
	
	display(p->rchild, level+1);
	printf("\n");
	
	for(i=0; i<level; i++)
		printf("    ");
	printf("%c",p->info);
	
	display(p->lchild, level+1);
}/*End of display()*/

void preorder(struct node *p)
{
	if(p==NULL)	
		return;
	printf("%c  ",p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}/*End of preorder()*/

void inorder(struct node *p)
{
	if(p==NULL )
		return;
	inorder(p->lchild);
	printf("%c  ",p->info);
	inorder(p->rchild);
}/*End of inorder()*/

void postorder(struct node *p)
{
	if(p==NULL )
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%c  ",p->info);
	
}/*End of postorder()*/

int height(struct node *p)
{
	int hL,hR; 

	if(p==NULL) 
		return 0; 

	hL=height(p->lchild); 
	hR=height(p->rchild); 

	if(hL > hR) 
		return 1+hL; 
	else 
		return 1+hR; 
}/*End of height()*/

void levelOrder(struct node *p)
{
	if(p==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	
	insertQueue(p);
	while(!queueEmpty()) 
	{
		p=deleteQueue();
		printf("%c  ",p->info);
		if(p->lchild!=NULL)
			insertQueue(p->lchild);
		if(p->rchild!=NULL)
			insertQueue(p->rchild);
	} 
}

/*Functions for implementation of queue*/
void insertQueue(struct node *item)
{
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)  /*If queue is initially empty*/
		front=0;
	rear=rear+1;
	queue[rear]=item ;
}

struct node *deleteQueue()
{
	struct node *item;
	if(front==-1 || front==rear+1)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	item=queue[front];
	front=front+1;
	return item;
}/*End of deleteQueue()*/

int queueEmpty()
{
	if(front==-1 || front==rear+1)
		return 1;
	else
		return 0;
}
