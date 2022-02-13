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
struct node *insertNode(struct node *p, int x);
struct node *deleteNode(struct node *p, int x);
struct node *Min(struct node *p);
struct node *Max(struct node *p);
int height(struct node *p);
void preorder(struct node *p);
void inorder(struct node *p);
void postorder(struct node *p);

main()
{
	struct node *root=NULL,*p;
	int choice,x;

	root=insertNode(root,70);
root=insertNode(root,80);
root=insertNode(root,75);
root=insertNode(root,89);
root=insertNode(root,82);
root=insertNode(root,93);
root=insertNode(root,83);
display(root,0);
root=deleteNode(root,80);
display(root,0);

	while(1)
	{
		printf("\n");
		printf("1.Display Tree\n");
		printf("2.Search\n");
		printf("3.Insert a new node\n");
		printf("4.Delete a node\n");
		printf("5.Preorder Traversal\n");
		printf("6.Inorder Traversal\n");
		printf("7.Postorder Traversal\n");
		printf("8.Height of tree\n");
		printf("9.Find Minimum key\n");
		printf("10.Find Maximum key\n");
		printf("11.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		if(choice==11)
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
			preorder(root);
			break;
		 case 6:
			inorder(root);
			break;
		 case 7:
			postorder(root);
			break;
		 case 8:
			 printf("Height of tree is %d\n", height(root));
			 break;
		 case 9:
			p=Min(root);
			if(p==NULL)
			  printf("Tree is empty\n"); 
			else
			  printf("Minimum key is %d\n", p->info);
			  break;
		 case 10:
			 p=Max(root); 	
			 if(p==NULL)
			   printf("Tree is empty\n"); 
			 else
			   printf("Maximum key is %d\n", p->info);
			 break;
		}/*End of switch */
	}/*End of while */
}/*End of main( )*/

struct node *getnode(int x)
{
	struct node *p=(struct node *) malloc(sizeof(struct node));
	p->info=x;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}

struct node *insertNode(struct node *p, int x)
{
	if(p==NULL)	
		p=getnode(x);
	else if(x < p->info)	
		p->lchild = insertNode(p->lchild,x);
	else if(x > p->info)	
		p->rchild = insertNode(p->rchild,x);  
	else
		printf("%d already present in tree\n",x);
	return p;
}/*End of insertNode()*/

struct node *search(struct node *p, int x)
{
	if(p==NULL)   
		return NULL; /*key not found*/
	if(x < p->info)/*search in left subtree*/	
		return search(p->lchild, x);	
	if(x > p->info)/*search in right subtree*/
		return search(p->rchild, x);
	return p; /*key found*/
}/*End of search()*/

struct node *deleteNode(struct node *p, int x)
{
	struct node *ch,*s;

	if(p==NULL)
	{
		printf("%d not found\n",x);
		return p;
	}
	if(x < p->info)  /*delete from left subtree*/
		p->lchild = deleteNode(p->lchild, x);
	else if(x > p->info) /*delete from right subtree*/
		p->rchild = deleteNode(p->rchild, x);
	else
	{
		/*key to be deleted is found*/
		if( p->lchild!=NULL  &&  p->rchild!=NULL )  /*2 children*/
		{
			s=p->rchild;
			while(s->lchild)
				s=s->lchild;
			p->info=s->info;
			p->rchild = deleteNode(p->rchild,s->info);
		}
		else   /*1 child or no child*/	
		{
			if(p->lchild != NULL) /*only left child*/
				ch=p->lchild;
			else  /*only right child or no child*/
				ch=p->rchild;
			free(p);
			p=ch;
		}						
	}
	return p; 
}/*End of deleteNode()*/


struct node *Min(struct node *p)
{
	if(p==NULL)
		return NULL;
	if(p->lchild==NULL)
        return p;
	return Min(p->lchild);
}/*End of Min()*/

struct node *Max(struct node *p)
{
	if(p==NULL) 
		return NULL;
	if(p->rchild==NULL)
        return p;
	return Max(p->rchild);
}/*End of Max()*/

void preorder(struct node *p)
{
	if(p == NULL )	/*Base Case*/
		return;
	printf("%d  ",p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}/*End of preorder( )*/

void inorder(struct node *p)
{
	if(p == NULL )/*Base Case*/
		return;
	inorder(p->lchild);
	printf("%d  ",p->info);
	inorder(p->rchild);
}/*End of inorder( )*/

void postorder(struct node *p)
{
	if(p == NULL)/*Base Case*/
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%d  ",p->info);
	
}/*End of postorder()*/

int height(struct node *p)
{
	int hL,hR; 

	if(p==NULL) /*Base Case*/
		return 0; 

	hL=height(p->lchild); 
	hR=height(p->rchild); 

	if(hL>hR) 
		return 1+hL; 
	else 
		return 1+hR; 
}/*End of height()*/

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