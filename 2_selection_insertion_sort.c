#include <stdio.h>
#include <string.h>
//#define MAX_STRINGS 5
#define MAX_STRING_LEN 200
#include<stdlib.h>
#define MAX_LEN 200

char MAX_STRINGS;
void InsertionSort(char list[][MAX_STRING_LEN]);
void selectionSort(char arr[][MAX_LEN], int n);
void layout();
void thank_you();
int main()
{
    int index,choice;
    char strings[15][MAX_STRING_LEN];
    char choice_y_n;
    int flag;
    

    /* Get input */
    layout();
    
    do{
   	printf("\n1.Press 1 to Enter Data:\n2.Press 2 for Insertion Sort\n3.Press 3 for Selection sort\n4.Press 4 to exit");
	
	
	a:printf("\n\nEnter your choice :\t");
    scanf("%d",&choice);
    
	
   
	
    	switch(choice)
    	{
    		case 1:
    			{
    				printf("Enter the size of Array");
    				scanf("%d",&MAX_STRINGS);
    				/*int flag=1;
    

    				while(flag==1){
    					
    						
					if ( scanf("%d", &MAX_STRINGS) == 1 ){ // also you were missing & specifier
            		flag = 0;
            //return 0;
        			}
					else{
            		printf("-> Wrong format, try again! <-\n");
            		getchar(); // to catch the enter from the input -- make sure you include stdlib.h

        			}
    				}*/
    				printf("Enter %d strings.\n", MAX_STRINGS);
    				for (index = 0; index < MAX_STRINGS; index++)
    				{
        				printf("Input string %d : ", index);
        				scanf("%199s", strings[index]);     // limit the width so we don't go past the buffer
        				strings[index][sizeof(strings[index]) - 1] = '\0';
    				}
					break;	
				}
			
			case 2:
				{
					InsertionSort(strings);

    				printf("\nThe input set, in alphabetical order:\n");
    				for (index = 0; index < MAX_STRINGS; index++)
    				{
        			printf("%s\n", strings[index]);
    				}
					break;	
				}
			
			case 3:
				{
				
					selectionSort(strings,MAX_STRINGS);	
					printf("\nThe input set, in alphabetical order:\n");
    				for (index = 0; index < MAX_STRINGS; index++)
    				{
        			printf("%s\n", strings[index]);
    				}
				
				
							
				break;
			}
		
		case 4:
			{
				return 0;
			}
			
		
		
		}

	
	
	printf("\nDo you wish to continue?\nInput(y/n):");
	getchar();
	scanf("%c",&choice_y_n);
	}while(choice_y_n == 'Y' || choice_y_n == 'y');
	

	
	
    
   system("cls");
    thank_you();
    return 0;
    
}
    


void InsertionSort(char list[][MAX_STRING_LEN])
{
	int i;
    for ( i = 1; i < MAX_STRINGS; i++)
    {
        int j = i;

        while (j > 0 && strcmp(list[j - 1], list[j]) > 0)
        {
            char tmp[MAX_STRING_LEN];
            strncpy(tmp, list[j - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(list[j - 1], list[j], sizeof(list[j - 1]) - 1);
            list[j - 1][sizeof(list[j - 1]) - 1] = '\0';

            strncpy(list[j], tmp, sizeof(list[j]));
            list[j][sizeof(list[j]) - 1] = '\0';

            --j;
        }
    }
}


void selectionSort(char arr[][MAX_LEN], int n)
					{
    				int i, j, min_idx;
  
    				// One by one move boundary of unsorted subarray
    				char minStr[MAX_LEN];
    				for (i = 0; i < n-1; i++)
    				{
        			// Find the minimum element in unsorted array
        			int min_idx = i;
        			strcpy(minStr, arr[i]);
        			for (j = i+1; j < n; j++)
        			{
            		// If min is greater than arr[j]
            		if (strcmp(minStr, arr[j]) > 0)
            		{
               		 // Make arr[j] as minStr and update min_idx
                	strcpy(minStr, arr[j]);
                	min_idx = j;
            		}
        			}
  
        			// Swap the found minimum element with the first element
        		if (min_idx != i)
       		 	{
            	char temp[MAX_LEN];
            	strcpy(temp, arr[i]); //swap item[pos] and item[i]
            	strcpy(arr[i], arr[min_idx]);
            	strcpy(arr[min_idx], temp);
        	}
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
	printf("\n \t\tSELECTION & INSERTION SORT\n");
	printf("\n_________________________________________________________________________\n\n");
}
