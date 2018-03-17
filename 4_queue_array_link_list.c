/*
 * C Program to Implement Queue Data Structure using Linked List
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define max 5
#define MODE_INT 1
#define MODE_STR 2
#include<ctype.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;




int i;


int choice;

 
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int validate(char*, int);
 
int count = 0;
 
void main()
{
		a:
	system("cls");

	printf("\n____________________________________________________________________________________\n");
	printf("\n\t\tQUEUE");
	printf("\n_______________________________________________________________________________________\n");
	

	printf("\n1.Press 1 For Link-List Implementation");
	printf("\n2.Press 2 for Array Implementation for Strings");
	printf("\nEnter Your Choice :\t");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			{
				int no, ch, e;
 				b:
 				system("cls");
    			printf("\n 1 - Enter data into queue ");
    			printf("\n 2 - Delete element from queue");
    			printf("\n 3 - Show the Front element");
    			printf("\n 4 - Show the Last Element ");
    			printf("\n 5 - Empty the queue");
   				printf("\n 6 - Exit Program");
    			printf("\n 7 - Display Queue Elements");
    			printf("\n 8 - Display Queue size");
    			printf("\n 9 - Back to Previous Menu");
    			create();
    			while (1)
    			{
        			printf("\n Enter choice :");
        			scanf("%d", &ch);
        			switch (ch)
        			{
        				case 1:
            				printf("\nEnter data \n(ENTER INTEGERS ONLY) :\t ");
            				scanf("%d", &no);
            				
            				
            				
            				enq(no);
            				break;
        				case 2:
            				deq();
            				break;
        					case 3:
            				e = frontelement();
            				if (e != 0)
                				printf("Front element : %d", e);
            				else
                				printf("\n No front element in Queue as queue is empty");
            					break;
            					
            			case 4:
						{
							e = rearelement();
            				if (e != 0)
                				printf("Front element : %d", e);
            				else
                				printf("\n No front element in Queue as queue is empty");
            					break;
								}		
            			
        				case 5:
            				empty();
            				break;
        				case 6:
            				exit(0);
        				case 7:
            				display();
           					break;
        				case 8:
            				queuesize();
            				break;
            				
            			case 9:
            				goto a;
            				break;
        				default:
            				printf("Wrong choice, Please enter correct choice  ");
            				getchar();
            				goto b;
            				break;
        			}
    			}
			}
			
			case 2:
			
			{
				char queue[max][80], data[80];
	int frontq, rearq , reply, option,i;
	int status,temp;
	//... Initialise a Queue
	frontq = rearq = -1;
	do
	{	
		printf("\n Queue using array of strings \n");
		printf("\n 1. Press 1 to Enter String in a Queue");
		printf("\n 2. Press 2 to Delete String from a Queue");
		printf("\n 3. Display the queue Elements");
		printf("\n 4. Press 4 to back to previous menu");
		printf("\n 5. Exit ");
		printf("\nEnter your choice: ");
		//getchar();
		status = scanf("%d", &option);
		while(status != 1)
		{
			while((temp=getchar()) != EOF && temp != '\n');
			printf("Invalid input...\nPlease enter a number: ");
			status = scanf("%d", &option);
		}
		switch(option)
		{
			case 1 : // insert
			//char input[10];
			INPUT:
				printf("\n Enter the String to be insert in a Queue : ");
				getchar();
				//scanf("%s", data);
				//printf("Enter number\n> ");
				fgets(data, 10, stdin);
				data[strcspn(data,"\n")] = 0;
	
				if (validate(data, MODE_STR)) {
					//printf("Valid.\n");
					
					reply = insq(queue, &rearq, data);
					if( reply == -1 )
					printf("\n Queue is Full \n");
					else
						printf("\n Entered String : %s is Inserted in a Queue \n",data);
						break;
				} 
				else {
				printf("Invalid input.\n");
				goto INPUT;
				}
				
				
			case 2 : // delete
				reply = delq(queue, &frontq, &rearq, data);
				if( reply == -1 )
					printf("\n Queue is Empty \n");
				else
					printf("\n Deleted String from Queue is : %s", data);
					printf("\n");
				break;
			case 3 : if (reply == - 1)
        				printf("Queue is empty \n");
    				else
				    {
				        printf("Queue is : \n");
				        for (i = frontq; i < rearq; i++)
				            printf("\n %s ", queue[i]);
				        printf("\n");
				    }
					    break;
					    
			case 4:
				goto a;
		} // switch
	}while(option != 0);
			
			} 
			
			
			case 3:
				{
					exit(0);
				}
				
			default :
				{
					printf("\nWrong Choice Please Enter Again");
					getchar();
					goto a;
					break;
				}
				
			
			
		
	}
	
}
	
	
    
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}

int rearelement()
{
	
	if ((front != NULL) && (rear != NULL))
        return(rear->info);
    else
        return 0;
	
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}






int insq(char queue[max][80], int *rearq, char data[80])
{
	if(*rearq == max -1)
		return(-1);
	else
	{
		*rearq = *rearq + 1;
		strcpy(queue[*rearq], data);
		return(1);
	} // else
} // insq
int delq(char queue[max][80], int *frontq, int *rearq, char data[80])
{
	if(*frontq == *rearq)
		return(-1);
	else
	{
		(*frontq)++;
		strcpy(data, queue[*frontq]);
		return(1);
	} // else
} // delq

/*void queueshow()
{
	int reply;
		if (reply == - 1)
        						printf("Queue is empty \n");
    						else
				    		{
				        		printf("Queue is : \n");
				        		for (i = frontq; i < rearq; i++)
				            		printf("%s ", queue[i]);
				        		printf("\n");
				    		}


}*/



int validate(char *cptr, int mode) {
	int len = strlen(cptr);
	int i;
	for (i = 0; i < len; i++) {
		if (mode == MODE_INT) {
			if (!(isdigit(cptr[i]) || cptr[i] == '-')) {
				return 0;
			}
		} else {
			if (!isalpha(cptr[i])) {
				return 0;
			}
		}
	}
	return 1;
}

