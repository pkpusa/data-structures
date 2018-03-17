
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
 
struct pass_data
{
    int  passno;
    char passName[MAX];
    char destination[MAX];
    struct pass_data *next;
};
 
/* ********************************************************************/
/*  Function to insert a node at the front of the linked list.        */
/*  front: front pointer, id: passenger I444444D, name: passenger name        */
/*  desg: passenger destination                                        */
/*  Returns the new front pointer.                                    */
/* ********************************************************************/
struct pass_data *insert(struct pass_data *front, int id, char name[],
char desg[])
{
    struct pass_data *newnode;
 
    newnode = (struct pass_data*)malloc(sizeof(struct pass_data));
 
    if (newnode == NULL)
    {
        printf("\n Allocation failed \n");
        exit(2);
    }
    newnode->passno = id;
    strcpy(newnode->passName, name);
    strcpy(newnode->destination, desg);
    newnode->next = front;
    front = newnode;
    return(front);
}
/*  End of insert() */
 
/*  Function to display a node in a linked list */
void printNode(struct pass_data *p)
{
    printf("\n passenger Details...\n");
    printf("\n Emp No       : %d", p->passno);
    printf("\n Name           : %s", p->passName);
    printf("\n destination    : %s\n", p->destination);
    printf("-------------------------------------\n");
}
/*  End of printNode() */
 
/*  ********************************************************/
/*  Function to deletpnode a node based on passenger number */
/*  front: front pointer, id: Key value                    */
/*  Returns: the modified list.                            */
/*  ********************************************************/
struct pass_data* deletpnode(struct pass_data *front, int id)
{
    struct pass_data *ptr;
    struct pass_data *bptr;
 
    if (front->passno == id)
    {
        ptr = front;
        printf("\n Node deleted:");
        printNode(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
bptr = bptr->next)
    {
        if (ptr->passno == id)
        {
            printf("\n Node deleted:");
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\n passenger Number %d not found ", id);
    return(front);
}
/*  End of deletpnode() */
 
/* ****************************************************************/
/*  Function to search the nodes in a linear fashion based emp ID */
/*  front: front pointer, key: key ID.                            */
/* ****************************************************************/
void search(struct pass_data *front, int key)
{
    struct pass_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->passno == key)
        {
            printf("\n Key found:");
            printNode(ptr);
            return;
        }
    }
    printf("\n passenger Number %d not found ", key);
}
/*  End of search() */
 
/*  Function to display the linked list */
void display(struct pass_data  *front)
{
    struct pass_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}
/*  End of display() */
 
/*  Function to display the menu of operations on a linked list */
void menu()
{
    printf("---------------------------------------------\n");
    printf("Press 1 to CREATE a reservation in the list       \n");
    printf("Press 2 to DELETE a reservation from the list       \n");
    printf("Press 3 to DISPLAY the reservation list                 \n");
    printf("Press 4 to SEARCH the reservation list                   \n");
    printf("Press 5 to EXIT                              \n");
    printf("---------------------------------------------\n");
}
/*  End of menu() */
 
/*  Function to select the option */
char option()
{
    int choice;
 
    printf("\n\n>> Enter your choice: ");
    switch(choice=getch())
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':   return(choice);
        default :   printf("\n Invalid choice.");
    }
    return choice;
}
/*  End of option() */
 
/*  The main() program begins */
void main()
{
    struct pass_data *linkList;
    char name[21], dest[51];
    char choice;
    int pno;
 
    linkList = NULL;
    printf("\n Welcome to BMSRT Reservation System \n");
    menu();
    do
    {
        /*  choose oeration to be performed */
        choice = option();
        switch(choice)
        {
        case '1':
            printf("\n Enter the passenger Number      : ");
            scanf("%d", &pno);
            printf("Enter the passenger name        : ");
            fflush(stdin);
            gets(name);
            printf("Enter the passenger destination : ");
            gets(dest);
            linkList = insert(linkList, pno, name, dest);
            break;
        case '2':
            printf("\n\n Enter the passenger number to be cancel the reservation: ");
            scanf("%d", &pno);
            linkList = deletpnode(linkList, pno);
            break;
        case '3':
            if (linkList == NULL)
            {
                printf("\n There are no resrvations currently....");
                break;
            }
            display(linkList);
            break;
        case '4':
            printf("\n\n Enter the passenger number to be searched: ");
            scanf("%d", &pno);
            search(linkList, pno);
            break;
        case '5': break;
        }
    } while (choice != '5');
}

