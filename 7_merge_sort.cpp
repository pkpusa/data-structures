#define MAX 20
#define SIZE 10

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <iostream>
#include <cstdio>
#include<stdlib.h>




int a[50];
int b[10];

void merging(int low, int mid, int high)
{
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
   {
		if(a[l1] <= a[l2])
    		b[i] = a[l1++];
    	else
        	b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
		b[i++] = a[l1++];

   while(l2 <= high)   
		b[i++] = a[l2++];

   for(i = low; i <= high; i++)
		a[i] = b[i];
}

void sort(int low, int high)
{
   int mid;
   
   if(low < high)
   {
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid+1, high);
		merging(low, mid, high);
   }
   else
   { 
		return;
   }   
}




struct node
{
    int data;
    struct node* next;
};
 
struct node* sortedmerge(struct node* a, struct node* b);
void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef);
 
 
void mergesort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a;
    struct node* b;
    if ((head == NULL) || (head -> next == NULL))
    {
        return;
    }
    frontbacksplit(head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    *headRef = sortedmerge(a, b);
}
 
struct node* sortedmerge(struct node* a, struct node* b)
{
    struct node* result = NULL;
 
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);
 
    if ( a-> data <= b -> data)
    {
        result = a;
        result -> next = sortedmerge(a -> next, b);
    }
    else
    {
        result = b;
        result -> next = sortedmerge(a, b -> next);
    }
    return(result);
}
 
void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef)
{
    struct node* fast;
    struct node* slow;
    if (source==NULL || source->next==NULL)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source -> next;
        while (fast != NULL)
        {
            fast = fast -> next;
            if (fast != NULL)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
    }
 
    *frontRef = source;
    *backRef = slow -> next;
    slow -> next = NULL;
    }
}
 
void printlist(struct node *node)
{
    while(node != NULL)
    {
        printf("%d\t", node -> data);
        node = node -> next;
    }
}
 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}




void studentfn();
void layout();
void thank_you();


int main()
{
	
	a:

	layout();
	printf("\n");
	
	//student std_array[SIZE];
    
    int index,ch,choice;
    int choice_y_n;
    int std_count;
    
    int opt;
    
    
    	system("cls");
    printf("\n\n1.Press 1 for Array Implementation\n2.Press 2 for Link List Implementation\n\tEnter Choice :\t");
    scanf("%d",&opt);
    
    switch(opt)
    {
	
    	
    	case 1:{
    					do{
						system("cls");
						int i,count;
						printf("\nHow many elements You want to enter \t:");
						scanf("%d", &count);
						
						
						
						
						printf("\nEnter %d Elements: ",count);
						for(i=0;i<count;i++)
							scanf("%d", &a[i]);
						printf("List before sorting\n");
						
						for(i = 0; i <count; i++)
							printf("%d ", a[i]);
						sort(0, count-1);

						printf("\nList after sorting\n");
   
						for(i = 0; i <count; i++)
							printf("%d ", a[i]);
    					
					printf("\nDo you wish to continue ?\nInput(y/n):");
					getchar();
					scanf("%c",&choice_y_n);		
    				}while(choice_y_n == 'y' || choice_y_n == 'Y');
    				
					goto a;	
						break;
	
				}


		
		case 2:{
			
			
			do{
				
				
				system("cls");
			
				struct node* a = NULL;
    			int i,n,arr[20];
    			
				printf("\n\t\t\tImplementation of Mergesort with LInked List \n\n ");
				printf("\n How many Elements you want to Enter :\t\n");
    			scanf(" %d",&n);
    
				printf("\n Enter %d Elements in the List \n",n);
    			for(i=0;i<n;i++)
    			{
    				scanf(" %d",&arr[i]);
				}
				
				for(i=0;i<n;i++)
    			{
    				push(&a,arr[i]);
				}
    
 
    			printf("\n\t Linked List before sorting\n\n");
    			
				for(i=0;i<n;i++)
   				{			
    				printf("%d\t",arr[i]);
				}
 				printf("\n");
 	
    			mergesort(&a);
 
    			printf("\n\n\t Linked List after sorting\n\n");
    			printlist(a);
			
	
				printf("\nDo you wish to continue ?\nInput(y/n):");
				getchar();
				scanf("%c",&choice_y_n);
				}while(choice_y_n == 'y' || choice_y_n == 'Y');
    					
				goto a;
				break;
				}		
			}
			return 0;
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
	printf("\n \t\tMERGE SORT IMPLEMENTATION WITH ARRAY AND LINK LIST \n");
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

