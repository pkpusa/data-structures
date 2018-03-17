#define MAX 20
#define SIZE 10

#include<stdio.h>
#include<conio.h>
#include<string.h>



typedef struct
{
	char student_name[MAX];
	int yearofadmsn;
	char fname[MAX];
    //int std_count;
	//int student[SIZE];
	int marks;
} student;


void sel_name_sort(student [],int );
void sel_price_sort(student [],int );
void ins_name_sort(student [],int );
void ins_price_sort(student [],int );
void studentfn();
void layout();
void thank_you();


int main()
{
	printf("===============================================Implementation of structures in Quick Sort=============================================");
	layout();
	printf("\n");
	
	student std_array[SIZE];
    
    int index,ch,choice;
    
    int std_count;
    
    
    
    
    
    
    printf("\nHow Many Records You want to Enter :\t");
    scanf("%d",&std_count);
    getchar();
    
    
	
    system("cls");
    studentfn();
    printf("Enter Some Details : \t");
    for(index=0;index<std_count;index+=1)
    {
    	printf("\n Student's name: ");
    	scanf("%s",std_array[index].student_name);
    	
		//printf("\nFather's Name : ");
    	//scanf("%s",std_array[index].fname);
    	
    	printf("\nMarks Obtained : ");
    	scanf("%d",&(std_array[index].marks));
    	
    	//printf("\n Year of dmission : ");
    	//scanf("%d",&(std_array[index].yearofadmsn));
    	
    	printf("\n");
	}
	
	printf("\n The array entered is");
		for(index=0;index<std_count;index+=1)
	{
		printf("\n Student's name : ");
		printf("%s",std_array[index].student_name);
		printf("\t");
		
	
		
		//printf("Father's Name': ");
		//printf("%s",std_array[index].fname);
		//printf("\t");
		
		printf("Marks Obtained: ");
		printf("%d",std_array[index].marks);
		printf("\t");
		
		//printf("Year of admission: ");
		//printf("%d",std_array[index].yearofadmsn);
		//printf("\n");
	}
	
	do
	{	system("cls");
		printf("\n MAIN MENU");
		printf("\n 1. QUICK  SORT");
		printf("\n 2. MERGE SORT");
		printf("\n 3.exit");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				system("cls");
			
			printf("\n Selection sort chosen");
			       do
	               {	
		                printf("\n QUICK SORT MENU");
		                printf("\n 1.sort by Student's name");
		                printf("\n 2.sort by Student's Marks");
		                printf("\n 3.exit");
		                printf("\n Enter your choice:");
		                scanf("%d",&ch);
		
		                switch(ch)
		                {
			                 case 1: printf("\n Sorting by Student's name ");
			                 sel_name_sort(std_array,std_count);
			                 printf("\n\n");
			                 break;
			        
			                 case 2: printf("\n Sorting by Student's Marks ");
			                 sel_price_sort(std_array,std_count);
			                 printf("\n\n");
					         break;
						
		                     default: printf("\n Wrong choice ");
			                 break;			        
		                }
	                }
	                while(ch!=3);
	                
	                break;
	
	        case 2:/*printf("\n Insertion sort chosen ");
			       do
	               {
		                printf("\n MERGE SORT MENU ");
		                printf("\n 1.sort by Student's name");
		                printf("\n 2.sort by Student's Marks");
		                printf("\n 3.exit");
		                printf("\n Enter your choice:");
		                scanf("%d",&ch);
		
		                switch(ch)
		                {
			                case 1: printf("\n Sorting by Student's name ");
			                ins_name_sort(std_array,std_count);
			                break;
			        
			                case 2: printf("\n Sorting by Student's Marks ");
			                ins_price_sort(std_array,std_count);
					        break;
					
		                    default: printf("\n Wrong choice ");
			                break;	
							
							        
		                }
	                }
	                while(ch!=3);   */     
	                	printf("\n\nWork in Progress-.........................");	
	                break;
	                
	        default : printf("\n !!!!Wrong choice!!!!!");
			          break;        
		}
		
	}
	while(choice != 3);
	
	return 0;
}

//void quick_name_sort()

void sel_name_sort(student b_array[],int std_count)
{
	int i , j , min , index ;
	student temp;
	for( i = 0 ; i <  std_count - 1 ; i++ )
	{
		min = i;
		for( j = i + 1 ; j < std_count ; j++ )
		{
			if( strcmp( b_array[j].student_name , b_array[min].student_name ) < 0 )
			{
				min = j;
			}
		}
		if( min != i )
		{
			temp = b_array[i];
			b_array[i] = b_array[min];
			b_array[min] = temp;
		}
	}
	
	printf("\n The array sorted is");
	printf("\n Student's name\t\t Marks Obtained\t");
		for(index=0;index<std_count;index+=1)
	{
		
		printf("\n\n%s",b_array[index].student_name);
		printf("\t\t\t");
		
		//printf("Marks Obtained ");
		printf("%d",b_array[index].marks);
		printf("\t");
		
		//printf("Father's Name' ");
		//printf("%s",b_array[index].fname);
		//printf("\t");
		
		//printf("Year of admission ");
		//printf("\t%d",b_array[index].yearofadmsn);
		//printf("\n");
	}
}

void sel_price_sort(student b_array[],int std_count)
{
	int i , j , min , index ;
	student temp;
	for( i = 0 ; i <  std_count - 1 ; i++ )
	{
		min = i;
		for( j = i + 1 ; j < std_count ; j++ )
		{
			if( b_array[j].marks < b_array[min].marks )
			{
				min = j;
			}
		}
		if( min != i )
		{
			temp = b_array[i];
			b_array[i] = b_array[min];
			b_array[min] = temp;
		}
	}
	
	printf("\n The array sorted is ");
	printf("\n Student's name\t\tMarks Obtained");
		for(index=0;index<std_count;index+=1)
	{
		
		printf("\n\n%s",b_array[index].student_name);
		printf("\t\t\t");
		
		
		
		//printf("Father's Name' " );
		//printf("\t%s",b_array[index].fname);
		//printf("\t");
		
		//printf("Marks Obtained ");
		printf("\t%d",b_array[index].marks);
		printf("\t");
		
		//printf("Year of Admission : ");
		//printf("\t%d",b_array[index].yearofadmsn);
		//nbmnbvprintf("\n");
	}
}

void ins_name_sort(student b_arrayins[],int std_count)
{
	int i , j ;
	student key;
	
	for(i = 1; i < std_count; i+=1)
	{
		key = b_arrayins[i];
		j = i - 1;
		
		while( (strcmp(b_arrayins[j].student_name , key.student_name) > 0) && j >= 0)
		{
			b_arrayins[j+1] = b_arrayins[j];
			j = j-1 ;
		}
		
		b_arrayins[j+1] = key;
		
	}
	
	printf("\n The array sorted is");
		for(i=0;i<std_count;i+=1)
	{
		printf("\n Student's name : ");
		printf("%s",b_arrayins[i].student_name);
		printf("\t");
		
		printf("Student's price : ");
		printf("%d",b_arrayins[i].marks);
		printf("\t");
		
		printf("Student's fname : ");
		printf("%s",b_arrayins[i].fname);
		printf("\t");
		
		printf("Year published : ");
		printf("%d",b_arrayins[i].yearofadmsn);
		printf("\n");
	}
}

void ins_price_sort(student b_arrayins[],int std_count)
{
	int i , j ;
	student key;
	
	for(i = 1; i < std_count; i+=1)
	{
		key = b_arrayins[i];
		j = i - 1;
		
		while(j >= 0 && b_arrayins[j].marks > key.marks)
		{
			b_arrayins[j+1] = b_arrayins[j];
			j = j-1 ;
		}
		
		b_arrayins[j+1] = key;
    }
    
    	printf("\n The array sorted is");
		for(i=0;i<std_count;i+=1)
	{
		printf("\n Student's name : ");
		printf("%s",b_arrayins[i].student_name);
		printf("\t");
		
		printf("Student's price : ");
		printf("%d",b_arrayins[i].marks);
		printf("\t");
		
		printf("Father's Name : '");
		printf("%s",b_arrayins[i].fname);
		printf("\t");
		
		printf("Year of Admission : ");
		printf("%d",b_arrayins[i].yearofadmsn);
		printf("\n");
	}
}


void thank_you()
{
	printf("\n\n_______________________________________________________________________\n\n");
	printf("\n\t\tTHANK YOU FOR USING MY PROGRAM\n");
	printf("\n\t Press ENter to exit");
	
}
void layout()
{
	printf("\n________________________________________________________________________\n");
	printf("\n \t\tQUICK & MERGE SORT IMPLEMENTATION\n");
	printf("\n_________________________________________________________________________\n\n");
}
void studentfn()
{
	printf("\n\n***************************************************************************************\n");
	printf("\n\n");
	printf("\t\tSTUDENT MANAGEMENT SYSTEM");
	printf("\n\n");
	printf("\n\n");
	printf("\n\n***************************************************************************************\n");
	
}

