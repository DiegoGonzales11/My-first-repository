/*
	Abstract of the first week 
*/

#include <stdio.h>

//constans
#define	MAX 100
#define YES	1
#define NO 0

//variables
long	income[MAX];
int		month[MAX], day[MAX], year[MAX];
int		x,y,ctr;
int 	cont;
long	month_total, grand_total;

//prototype of function
void main(void);
int display_instructions(void);
void get_data(void);
void display_report();
int continue_function(void);

//beginning
void main()
{
	cont = display_instructions();
	
	if(cont == YES)
	{
		get_data();
		display_report();
	}
	else
		printf("\nProgram Aborted by User!\n\n");
}

//this function gives instrucctions about the program
int display_instructions(void)
{
	printf("\n\n");
	printf("\nThis program enables you to enter up to 99 people\'s");
	printf("\nincomes and birthdays. It then prints the incomes by");
	printf("\nmonth along with the overall omcome and overall average.");
	printf("\n");
	
	cont=continue_function();
	
	return(cont);
}

//this function get the imformation of the users
void get_data(void)
{
	for(cont=YES, ctr=0; ctr<MAX && cont == YES; ctr++)
	{
		printf("\nEnter information for Person %d.", ctr+1);
		printf("\n\tEnter Birthday:");
		
		do
		{
			printf("\n\tMonth(0-12):");
			scanf("%d",&month[ctr]);
		}while(month[ctr]<0 || month[ctr]>12);
		
		do
		{
			printf("\n\tDay(0-31):");
			scanf("%d",&day[ctr]);
		}while(day[ctr]<0 || day[ctr]>31);
		
		do
		{
			printf("\n\tYear(0-2020):");
			scanf("%d",&year[ctr]);
		}while(year[ctr]<0 || year[ctr]>2020);
		
		printf("\nEnter Yearly Income (whole dollars):");
		scanf("%d",&income[ctr]);
		
		cont=continue_function();
	}
}

//this function give a report about the data

void display_report()
{
	grand_total=0;
	printf("\n\n\n");
	printf("\n		SALARY SUMMARY");
	printf("\n		==============");
	
	for(x=0; x<=12; x++)
	{
		month_total = 0;
		for(y=0; y<ctr;y++)
		{
			if(month[y]==x)
				month_total +=income[y];
		}
		printf("\nTotal for month %d is %ld",x,month_total);
		grand_total += month_total;
	}
	printf("\n\nReport totals:");
	printf("\nTotal Income is %ld", grand_total);
	printf("\nAverage Income is %ld", grand_total/ctr);
	
	printf("\n\n* * * End of Report* * *");
}

//this function ask the user to continue or to ficnish
int continue_function(void)
{
	printf("\n\nDo you wish to continue? (0=NO/1=YES):");
	scanf("%d", &x);
	
	while(x<0 || x>1)
	{
		printf("\n%d ois invalid!", x);
		printf("\nplease enter 0 to Quit or 1 to Continue: ");
		scanf("%d",&x);
	}
	if(x==0)
		return(NO);
	else
		return(YES);
}
