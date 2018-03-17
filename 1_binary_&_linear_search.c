/*Program to implement Sequential Search and Binary Search
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 50			/*Maximum size of the array*/

int seq_search(int [],int);
void sort_arr(int [],int);
int binarySearch(int [],int);
void layout_func();

int main()
{
	int choice,arr[MAX],i,length,flag,temp,foundOrNot;
	char choice_y_n,check[MAX];
		layout_func();
		printf("Enter the number of elements in array\n");
		scanf("%d",&length);
		while(length < 2)
		{
			printf("\nMinimum elements required should be 2\nRe-Enter Length:\t");
			scanf("%d",&length);
		}
		printf("Enter %d elements\n",length);
		for(i = 0;i < length;i += 1)
		{
			gets(check);
			temp = atoi(check);
			if(isdigit(check[0]))
			{
				arr[i] = temp;
			}
			else
			{
				printf("\nOnly Integers as Input\n");
				i -= 1;
			}
			
		}
		for(i = 0;i < length-1; i += 1)
		{
			if(arr[i] < arr[i+1])
			{
				//printf("if mein huuu");
				flag = 0;
			}
			else
			{
				//printf("else mein huuu");
				flag = 1;
				break;
			}
		}
	do
	{
		system("cls");
		layout_func();
		printf("Please enter your choice\n1. Sequential Search\n2. Binary Search\nInput:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					foundOrNot = seq_search(arr,length);
					if(foundOrNot == -1)
					{
						printf("\nElement Not Found");
					}
					else
					{
						printf("\nElement found at position %d",foundOrNot);
					}
					break;
				}
			case 2:
				{
					if(flag == 1)
					{
						printf("\nArray is not sorted, PERFORMING SORTING");
						sort_arr(arr,length);
					}
					else
					{
						printf("\nArray is sorted, performing Binary Search");
					    foundOrNot = binarySearch(arr,length);
					
					if(foundOrNot == -1)
					{
						printf("\nElement Not found");
					}
					else
					{
						printf("\nElement found at position %d",foundOrNot);
					 } 
					   
					}
					break;
				}
			default:
				{
					printf("\nWrong Choice, Please try again\n");
					break;
				}	
		}
		printf("\nDo you wish to continue?\nInput(y/n):");
		getchar();
		scanf("%c",&choice_y_n);
	}while(choice_y_n == 'Y' || choice_y_n == 'y');
	return 0;
}



void sort_arr(int rcv_arr[MAX],int length)
{	
	int i,j,temp,foundOrNot;
	for(i = 0; i < length; i += 1)
    {
        /* 
         * Place the currently selected element array[i]
         * to its correct place.
         */
        for(j = i+1; j < length; j += 1)
        {
            /* 
             * Swap if currently selected array element
             * is not at its correct position.
             */
            if(rcv_arr[i] > rcv_arr[j])
            {
            	temp = rcv_arr[i];
                rcv_arr[i] = rcv_arr[j];
                rcv_arr[j] = temp;
            }
        }
    }

    /* Print the sorted array */
    printf("\nElements of array in sorted ascending order: ");
    for(i = 0; i < length; i += 1)
    {
        printf("%d\t", rcv_arr[i]);
    }
    
    foundOrNot = binarySearch(rcv_arr,length);
	if(foundOrNot == -1)
	{
		printf("\nElement Not found");
	}
	
}





int seq_search(int rcv_arr[MAX],int size)
{
	int no_search,pos = 0,i;
		printf("\nEnter a number to be search\n");
	scanf("%d",&no_search);
	for(i = 0;i < size;i += 1)
	{
		if(rcv_arr[i] == no_search)
		{
		pos = i+1;
		break;
		}
	}	
	if(pos!=0)
	{
	return pos;
	}
	else
	{
	return - 1;
	}
}


int binarySearch(int arr[], int size)
{
	int i, first, last, middle, search;
	printf("\nEnter element to find\n");
	scanf("%d", &search);

	first = 0;
	last = size - 1;
	middle = (first+last)/2;

	while (first <= last) {
	if (arr[middle] < search)
	first = middle + 1;
	else if (arr[middle] == search) {
	return middle+1;
	break;
	}
	else
	last = middle - 1;

	middle = (first + last)/2;
	}
	if (first > last)
 	return -1;
 
}

void layout_func()  
{
	printf("\t\t\t ___________________________________ \n");
	printf("\n\t\t\t ***** LINEAR AND BINARY SEARCH ***** \n");
	printf("\t\t\t ___________________________________ \n\n\n");
	printf("\t______________________________________________________________________\n");
}

