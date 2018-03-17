/***************************************************************************************************************************************************************/
/*											3rd Labwork - Data Structures Using C																							*/
/*											-->	Implementation of Stack in Linked List																						*/			
/*										-->	Implementation of Stack in Array of characters [Strings]																		*/
/*									-->	Basic Stack Operations with Integers and Structures																				*/

/*****************************************************************************************************************************************************************/									




#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
# define max 5
#define MAXSIZE 5


struct node
{
int data1;
struct node *link;
};

int i;

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

/*******************/
char stack[max][80];
int top2;
 
/***************************/
void push(void);
int  pop(void);
void display(void);

/*******************************************************************************************************************************************************/

							/*Push function for linked_list operation using structure*/

/*******************************************************************************************************************************************************/

struct node *push1(struct node *p , int value)
{
	struct node *temp;
					/* Allocating the dynamic size for structure */
	
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("No Memory available\n");
		exit(0);
	}
		temp->data1 = value;
		temp->link = p;
		p = temp;
		return(p);
	}

				/* Pop operation using linked list */
struct node *pop1(struct node *p , int *value)
{
	struct node *temp;
	if(p==NULL)
	{
	printf(" The stack is empty and cannot Delete (POP) element\n");
        exit(0);
	}
	 *value = p->data1;
	temp = p;
	p = p->link;
	free(temp);
	return(p);
	}



/**********************************************************************************************************************************************************/

									/* PUSH OPERATION IN STACK WITH STRINGS USING ARRAYS */
		
/*********************************************************************************************************************************************************/







int push2(char stack[max][80], int *top2, char data[80])		//taking array of the size max[5] rows for the string 
{
	if(*top2 == max -1)
		return(-1);
	else
	{
		*top2 = *top2 + 1;
		strcpy(stack[*top2], data);
		return(1);
	} // else
} // push2

 
/* Pop operation to extract strings from stack */

int pop2(char stack[max][80], int *top2, char data[80])
{
	if(*top2 == -1)
		return(-1);
	else
	{
		strcpy(data, stack[*top2]);
		*top2 = *top2 - 1;
		return(1);
	} // else
} // pop2


void show_str()		// functions to display all the strings in the stack
{
	
	if(top2>=0)
	{
        printf("\n The elements in STACK \n");
        for(i=top2; i>=0; i--)
           	printf("\n%s",stack[i]);
        	printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}





/***********************************************************************************************************************************************************/

											//Functions for integer push and pop opeRATIONS
											/*  Function to add an element to the stack */

/**********************************************************************************************************************************************************/


void push ()
{
    int num;
    if (s.top == (MAXSIZE - 1))		//basic push operation comparing the top element with the size of stack
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");		
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
    
}
/*  Function to delete an element from the stack */

int pop ()
{
    int num;	// num = numbers of elements in the stack
    if (s.top == - 1)		// if top is -1 means no element is there 
    {
        printf ("Stack is Empty\nElement can't be Popped ");
        return (s.top);	
    }
    else
    {
        num = s.stk[s.top];
        printf ("poped element is = %dn", s.stk[s.top]);	// the element which is deleted is that which is last inserted
        s.top = s.top - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */

void display ()
{
    int i;
    if (s.top == -1)	// checking the numbers of element in the stack 
    {
        printf ("Stack is empty\n");
        return;	// if stack is empty then return
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}



/*    Layout function no logic */


void thank_you()
{
	printf("\n\n_______________________________________________________________________\n\n");
	printf("\n\t\tTHANK YOU FOR USING MY PROGRAM\n");
	printf("\n\t Press ENter to exit");
	
}
void layout()
{
	printf("\n\t________________________________________________________________________\n");
	printf("\n \t\t\tIMPLEMENTATION OF STACK OPERATIONS\n");
	printf("\n\t_________________________________________________________________________\n\n");
}


/* Layout function ends here */


/*_______________________________________________________________________________________________________________________________________________________*/

						
/*													MAIN FUNCTION STARTS HERE																			*/

/*_______________________________________________________________________________________________________________________________________________________*/



int main()
{
	
	int choose;		//variable for the main switch operation
	
	/*****/
	char stack[max][80], data[80];	// array of characters
	int top2, option, reply;
	
	// Initialise Stack
	top2 = -1;
	system("cls");
	/******/
	
	/*integer operatiom*/
	int choice;
    int opt = 1;
    s.top = -1;
    //integer operation
	a: system("cls");
	layout();
	
	printf("\n\n\t\t1.Press 1 to Use stack Operation using Linked list\n\n\t\t2.Press 2 to use Stack Operation for Strings.\n\n\t\t3.Press 3 to use Stack operation for Integers Using Structure\n\n\t\tPress 4 to exit :\t");
	scanf("%d",&choose);
	getchar();
	
	switch(choose)
	{
		case 1:
			{	
				system("cls");
				struct node *top1 = NULL;
				int n,value;
						do
						{		
  							do
  							{
								printf("Enter the element to be pushed in stack\n");
								scanf("%d",&value);
								top1 = push1(top1,value);	//calling lined list push function
								printf("Enter 1 to continue\n");
								scanf("%d",&n);
							} while(n == 1);

  							printf("Enter 1 to pop an element from stack\n");
  							scanf("%d",&n);
  							while( n == 1)
 							{
 								top1 = pop1(top1,&value);		//calling pop function
 								printf("The value poped is %d\n",value);
 								printf("Enter 1 to pop an element and other to push1\n");
 								scanf("%d",&n);
 							}
  							printf("Enter 1 to continue\n");
  							scanf("%d",&n);
							} while(n == 1);

				break;	
				
				
			}
		
		case 2:
			{
				do
				{
						//printf("\n C Language to implement basic stack operations for String based Stack \n");
					//system("cls");
					printf("\n 1. Press 1 to PUSH String ");
					printf("\n 2. Press 2 to POP String ");
					printf("\n 3. Press 3 to Display Stack Elements ");
					printf("\n 3. Press 4 For Main Menu");
					printf("\n Press 4 to EXIT the program");
					printf("\n Select proper option ( 1 / 2 / 3 ) : ");
					scanf("%d", &option);
					switch(option)
					{
						case 1 : // push2
							printf("\n Enter a String : ");
							getchar();
							gets(data);
							
							reply = push2(stack,  &top2, data);
							if(reply == -1)
								printf("\nStack is Full \nThe String %s can't  be entered into Stack \n",data);
							else
								printf("\n Entered String %s Pushed in Stack \n",data);
							
							break;
							
						case 2 : // pop2
							reply = pop2(stack,  &top2, data);
							if(reply == -1)
								printf("\n Stack is Empty \nNo elements Remaining in the stack");
							else
								printf("\n Popped String is : %s", data);
								printf("\n");
								break;
								
						case 3 :
							{
								if(top2>=0)
								{
       								printf("\n The elements in STACK \n");
        							for(i=top2; i>=0; i--)
        							{
									
           							printf("\n\t\t%s",stack[i]);
           							}
        							printf("\n\n\n");
    							}
    							else
    							{
        							printf("\n The STACK is empty");
    							}
							
								break;							
							}
						case 4 : 
							{
								goto a;
							}
							
						case 5:
							{
								thank_you();
								return 0;
							}
					} // switch
				}while(1);
				
				
			}
			
			/* case 3 calls the function for the stack opeartions of integers */
		case 3:
			{
				system("cls");
				printf ("STACK OPERATION\n");
    			
				while (opt)
    			{
        			printf ("------------------------------------------\n");
        			printf ("      1    -->    PUSH               \n");
        			printf ("      2    -->    POP               \n");
        			printf ("      3    -->    DISPLAY               \n");
        			printf ("      4    -->    EXIT           \n");
        			printf ("------------------------------------------\n");
 
        			printf ("Enter your choice\n");
        			scanf    ("%d", &choice);
       				switch (choice)
        			{
        				case 1:
            				push();
            				break;
       					
						case 2:
            				pop();
            				break;
        				
						case 3:
            				display();
            				break;
        				
						case 4:
            				return;
        			}
        			fflush (stdin);
        			printf ("Do you want to continue(Type 0 or 1)?\n");
       				 scanf    ("%d", &opt);
    				}
				
				
				
			}
			
		default:
		{
			return 0;
		}
	}
	
	return 0;
}








