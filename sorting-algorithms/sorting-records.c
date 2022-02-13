/*
Copyright (C) Deepali Srivastava - All Rights Reserved
This code is part of DSA course available on CourseGalaxy.com    
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct date
{
	int day;
	int month;
	int year;
};

struct student
{
	char name[20];
	struct date dob;
	int grade;
};

void sortName(struct student stu[], int n);
void sortDob(struct student stu[], int n);
void sortGrade(struct student stu[], int n);
int dateCmp(struct date date1, struct date date2);

main()
{
	struct student stu[] = { 
								{"Sam", {12,1,1993}, 2},
								{"Pam", {24,1,1993}, 3},
								{"Adam",{14,3,1992}, 4},
								{"Tom", {23,1,1994} ,4},
								{"Chris", {2,1,1992}, 3},
								{"John", {23,2,1993}, 2},
							};
	int i,n=6,choice;
	
	while(1)
	{
		printf("1.Sort by name alphabetically\n");
		printf("2.Sort by date of birth, in descending order\n");
		printf("3.Sort by grade in ascending order\n");
		printf("4.Exit\n");
		printf("Enter your choice :");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				sortName(stu,n);
				break;
			case 2:
				sortDob(stu,n);
				break;
			case 3:
				sortGrade(stu,n);
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice\n");
		}
	
		for( i=0; i<n; i++ )
		{
			printf("%s\t\t", stu[i].name);
			printf("%d/%d/%d\t\t", stu[i].dob.day, stu[i].dob.month,stu[i].dob.year);
			printf("%d\n", stu[i].grade);
		}
		printf("\n");
	}
}/*End of main()*/

void sortName(struct student stu[], int n)
{
	struct student temp;
	int x,j,swaps;
	
	for(x=n-2; x>=0; x--)
	{
		swaps=0;
		for(j=0; j<=x; j++)
		{
			if( strcmp(stu[j].name, stu[j+1].name) > 0 )
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
				swaps++;
			}
		}
		if(swaps==0)
			break;
	}
}/*End of sortName()*/

void sortDob(struct student stu[], int n)
{
	struct student temp;
	int x,j,swaps;
	
	for(x=n-2; x>=0; x--)
	{
		swaps=0;
		for(j=0; j<=x; j++)
		{
			if( dateCmp(stu[j].dob, stu[j+1].dob) > 0 )
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
				swaps++;
			}
		}
		if(swaps==0)
			break;
	}
}/*End of sortDob()*/


void sortGrade(struct student stu[], int n)
{
struct student temp;
	int x,j,swaps;
	
	for(x=n-2; x>=0; x--)
	{
		swaps=0;
		for(j=0; j<=x; j++)
		{
			if ( stu[j].grade > stu[j+1].grade  )
			{
				temp = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = temp;
				swaps++;
			}
		}
		if(swaps==0)
			break;
	}
}/*End of sortGrade()*/

/*Returns 1 if date1 < date2, returns -1 if date1 > date2, return 0 if equal*/
int dateCmp(struct date date1, struct date date2 )
{
	if( date1.year < date2.year )
		return 1;
	if( date1.year > date2.year )
		return -1;
	if( date1.month < date2.month )
		return 1;
	if( date1.month > date2.month )
		return -1;
	if( date1.day < date2.day )
		return 1;
	if( date1.day > date2.day )
		return -1;
	return 0;
}/*End of dateCmp()*/
