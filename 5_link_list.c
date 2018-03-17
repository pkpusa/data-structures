  

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void display_design();

int flag = 0;

struct node
{
    int data;
    struct node *next;
}*head,*var,*trav;
struct node *start = NULL;
void display_design()
{
	printf("\t_______________________________________________________________________\n\n");
	printf("\t ------------------LINK LIST IMPLEMENTATION-------------------\n");
	printf("\t_______________________________________________________________________\n\n\n");
}


void insert_at_begning(int value)
{
     var=(struct node *)malloc(sizeof (struct node));
     var->data=value;
     if(head == NULL)
     {
         head=var;
         head->next=NULL;
     }
     else
     {
         var->next=head;
         head=var;
     }
     flag += 1;
}

void insert_at_end(int value)
{
      struct node *temp; 
      temp=head;
      var=(struct node *)malloc(sizeof (struct node));
      var->data=value;
      if(head == NULL)
      {
          head=var;
          head->next=NULL;
      }
      else
      {
          while(temp->next!=NULL)
          {     
               temp=temp->next;
          }
          var->next=NULL;
          temp->next=var;
      }
      flag += 1;
}

void insert_at_middle(int value, int loc)
{
     struct node *var2,*temp;
     var=(struct node *)malloc(sizeof (struct node));
     var->data=value;
     temp=head;

     if(head == NULL)
     {
          head=var;
          head->next=NULL;
     }
     else
     {
          while(temp->data!=loc)
          {
                temp=temp->next;
          }
          var2=temp->next;
          temp->next=var;
          var->next=var2;
     }
     flag += 1;
}



void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->data) ;
 
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++)
                {
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}


int delete_from_middle(int value)
{
     struct node *temp,*var;
     temp=head;
     while(temp != NULL)
     {
          if(temp->data == value)
          {
                if(temp == head)
                {
                     head = temp->next;
                     free(temp);
                     return 0;
                }
                else
                {
                     var->next = temp->next;
                     free(temp);
                     return 0;
                }
          }
          else
          {
               var = temp;
               temp = temp->next;
          }
     }
printf("data deleted from list is %d",value);

flag -= 1;
}

int delete_from_end()
{
     struct node *temp;
     temp = head;
     while(temp->next != NULL)
     {
          var = temp;
          temp = temp->next;
     }
     if(temp == head)
     {
          head = temp->next; 
          free(temp);
          return 0;
     }
     printf("data deleted from list is %d",temp->data);
     var->next = NULL;
     free(temp);
     return 0;
     
     flag -= 1;
}

void display()
{
     trav = head;
     if(trav == NULL)
     {
          printf("\nList is Empty");
     }
     else
     {
          printf("\n\nDATA INSERTED IS ");
          while(trav != NULL)
          {
               printf(" -> %d \n",trav->data);
               trav = trav->next;
          }
      printf("\n");
      }
}

int main()
{
     char choice;
	 int i=0;
     head = NULL;
     do
     {
     	system("cls");
     display_design();
     printf("\t\t\tPLEASE SELECT AN OPTION FROM BELOW\n\n");
     printf("\n 1. Insert new Node at frist");
     printf("\n 2. Insert New node at Last");
     printf("\n 3. Insert New node at specific position");
     printf("\n 4. Delete the last Node");
     printf("\n 5. Delete the Node from Specific Position");
     printf("\n 6. Exit\n");
           printf("\n\nEnter the choice of operation to perform\nInput:-\t");
           scanf("%d",&i);
           switch(i)
           {
                case 1:
                {
                 int value;
                 printf("\nEnter Data\nInput:\t");
                 scanf("%d",&value);
                 insert_at_begning(value);
                 printf("\nData Inserted at the Begning of the Link List");
                 display();                
                 break; 
                }
                case 2:
                {  
                int value;
                printf("\nEnter Data\nInput:\t");
                scanf("%d",&value);
                insert_at_end(value);
                 printf("\nData INserted at the Last position of the Link List");
                display();
                break;
                }
                case 3:
                {
                int value,loc;
                printf("\nEnter the position where you want to INsert data\nInput:\t");
                scanf("%d",&loc);
                printf("\nEnter Data\nInput:\t");
                scanf("%d",&value);
                insert_at_middle(value,loc);
                display();
                break;
                }
                case 4:
                {
                delete_from_end();
                display();
                break;
                }
                case 5:
                {
                int value;
                display();
                printf("\nEnter the data which You want to delete\nInput:\t");
                scanf("%d",&value);
                delete_from_middle(value);
                display();
                break;
                }
                case 6:
                {
                exit(0);
                }  
}
printf("\n\nDo you wish to continue? {y/n}\nInput:\t");
           fflush(stdin);
		   scanf("%c",&choice);
      } while(choice == 'y' || choice == 'Y');
getch();
}
