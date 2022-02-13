/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>

#define TSIZE 19

enum type_of_record {EMPTY, DELETED,OCCUPIED};

struct student
{
	int studentId;
	char studentName[20];
};

struct Record
{
	struct student info;
	enum type_of_record status;
};	

void insert( struct student rec, struct Record table[]);
int search(int key, struct Record table[]);
void del(int key, struct Record table[]);
void displayTable(struct Record table[]);
int hash(int key);

int main()
{
	struct Record table[TSIZE];
	
	struct student rec;

	int i,key,choice;
	
	for( i=0; i<=TSIZE-1; i++ )
		table[i].status = EMPTY;
		
	while(1)
	{
		printf("1. Insert a record\n");
		printf("2. Search a record\n");
		printf("3. Delete a record\n");
		printf("4. Display table\n");
		printf("5. Exit\n");

		printf("Enter your choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : 
				printf("Enter studentId  : ");
				scanf("%d",&rec.studentId);
				printf("Enter student name : ");
				scanf("%s",rec.studentName);
				insert(rec,table);
				break;
			case 2 : 
				printf("Enter a key to be searched : ");
				scanf("%d", &key);
				i = search(key, table);
				if(i==-1)
					printf("Key not found\n");
				else
				{
					printf("Key found at index %d\n", i);
					printf("%d %s", table[i].info.studentId, table[i].info.studentName);
				}
				break;
			case 3: 
				printf("Enter a key to be deleted\n");
				scanf("%d",&key);
				del(key, table);
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
	return (key%TSIZE);
}

void insert( struct student rec, struct Record table[] )
{
	int i, location, h;
	
	int key = rec.studentId;	
	h = hash(key);				
	
	location = h;	

	for( i=1; i<TSIZE; i++ )
	{
		if(table[location].status == EMPTY || table[location].status == DELETED)
		{
			table[location].info = rec;
			table[location].status = OCCUPIED;	
			printf("Record inserted\n\n");
			return;
		}
		if(table[location].info.studentId == key)
		{
			printf("Duplicate key\n\n");
			return;
		}
        location = ( h + i) % TSIZE;				
	}
	printf("Record can't be inserted : Table overFlow\n\n");
}


int search(int key, struct Record table[])
{
	int i, h, location;
    h = hash(key);				

	location = h;

	for( i=1; i<TSIZE; i++ )
	{
		if( table[location].status == EMPTY  ) 
			return -1;
		if( table[location].info.studentId == key )
			return location;
		location = ( h + i ) % TSIZE;								
	}
	return -1;
}

void displayTable(struct Record table[])
{
	int i;
	for(i=0; i<TSIZE; i++)
	{
		printf("[%d]  : ",i );
		if(table[i].status==OCCUPIED) 
			printf("Occupied : %d   %s\n",table[i].info.studentId, table[i].info.studentName);
		else if(table[i].status==DELETED)
			printf("Deleted\n");
		else
			printf("Empty\n");
	}
}

void del(int key, struct Record table[])
{
	int location = search(key, table);
	if(location == -1)
		printf("Key not found\n");
	else
		table[location].status = DELETED;
}


