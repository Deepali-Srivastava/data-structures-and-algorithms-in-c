/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include <stdio.h>
#include<stdlib.h>

#define TSIZE 7

struct student
{
	int studentId;
	char studentName[20];
};

struct Node 
{
	struct student info;
	struct Node *link;
};

void insert(struct student emprec, struct Node *table[]);
int search(int key, struct Node *table[]);
void del(int key, struct Node *table[]);
void displayTable(struct Node *table[]);
int hash(int key);

main()
{
	struct Node *table[TSIZE];	
	struct student rec;
	int i,key,choice;
	
	for(i=0; i<=TSIZE-1; i++)
		table[i] = NULL;

	while(1)
	{
		printf("1.Insert a record\n");
		printf("2.Search a record\n");
		printf("3.Delete a record\n");
		printf("4.Display table\n");
		printf("5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : 
				printf("Enter studentId  : ");
				scanf("%d",&rec.studentId);
				printf("Enter student name : ");
				scanf("%s",rec.studentName);
				insert(rec, table);
				break;
			case 2 : 
				printf("Enter a key to be searched : ");
				scanf("%d", &key);
				i = search(key, table);
				if(i==-1)
					printf("Key not found\n");
				else
					printf("Key found in chain %d\n", i);
				break;
			case 3: 
				printf("Enter a key to be deleted\n");
				scanf("%d",&key);
				del(key,table);
				break;
			case 4:
				displayTable(table);
				break;
			case 5:
				exit(1);
		}
	}
}

int hash(int key)
{
	return (key % TSIZE);
}

void insert(struct student rec, struct Node *table[])
{
	int h, key;
	struct Node *temp;

	key = rec.studentId;  
		
	if(search(key, table)!=-1)
	{
		printf("Duplicate key\n");
		return;
	}

    h = hash(key);		

	/*Insert in the beginning of list h*/
	temp =(struct Node*) malloc(sizeof(struct Node));
	temp->info = rec;
	temp->link = table[h];
	table[h] = temp;
}

int search(int key, struct Node *table[])
{
    int h = hash(key);				
	struct Node *p = table[h];

	while(p!=NULL)
	{
		if(p->info.studentId == key)
		{
			printf("%d %s \n", p->info.studentId, p->info.studentName);
			return h;
		}
		p = p->link;

	}
	return -1;
}

void displayTable(struct Node *table[])
{
	int i;
	struct Node *p;

	for(i=0; i<TSIZE; i++)
	{
		printf("\n[%d]  ",i);

		if(table[i]!=NULL)
		{
			p=table[i];
			while(p!=NULL)
			{
				printf("%d %s\t", p->info.studentId, p->info.studentName);
				p=p->link;
			}
		}
	}
	printf("\n");
}

void del(int key, struct Node *table[])
{
	int h;
    struct Node *temp, *p;
	h = hash(key);				
	
	if(table[h]==NULL)
	{
		printf("Key %d not found\n", key);
		return;
	}
	if(table[h]->info.studentId == key)
	{
		temp = table[h];
		table[h] = table[h]->link;  
		free(temp);
		return;
	}
	p = table[h];
	while(p->link != NULL)
	{
		if(p->link->info.studentId == key)   
		{
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return;
		}
		p=p->link;
	}
	printf("Key %d not found\n",key);
}


