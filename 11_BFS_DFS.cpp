#define MAX 1000

#include<stdio.h>
#include<stdlib.h>


typedef struct np
{
	int data;
	struct np *left, *right;
}node;

node *root = NULL;



node **createQueue(int *front,int *rear)
{
	node **queue = (node **)malloc(sizeof(node *)*MAX);
	
	*front = *rear = 0;
	return queue;
}

void enqueue(node **queue,int *rear,node *new_node)
{
	queue[*rear] = new_node;
	(*rear) += 1;
}

node *dequeue(node **queue,int *front)
{
	(*front) += 1;
	return queue[(*front) - 1];
}

void levelOrder(node *root)
{
	int front,rear;
	node **queue = createQueue(&front,&rear);
	node *temp_node = root;
	
	while(temp_node)
	{
		printf("\n %d",temp_node->data);
		
		if(temp_node->left)
		enqueue(queue,&rear,temp_node->left);
		
		if(temp_node->right)
		enqueue(queue,&rear,temp_node->right);
		
		temp_node = dequeue(queue,&front);
	}
}

node *newnode(int x)
{
	node *temp = (node *)malloc(sizeof(node));
	if(NULL == temp)
	{
		printf("\n Malloc failed");
	}
	
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

node *insert(node *node,int data)
{
	if(node == NULL)
	return newnode(data);
	
	if(data < node->data)
	node->left = insert(node->left,data);
	
	else if(data > node->data)
	node->right = insert(node->right,data);
	
	return node;
}


/************************************************************************************************************************/


typedef struct np1
{
	int key;
	struct np1 *left, *right;
}node1;

node1 *root1 = NULL;

node1 *newnode1(int x)
{
	node1 *temp = (node1 *)malloc(sizeof(node1));
	
	temp->key = x;
	temp->left = temp->right = NULL;
	
	return temp;
}


void inorder(node1 *root1)
{
	if(root1 != NULL)
	{
		inorder(root1->left);
		printf("%d \n",root1->key);
		inorder(root1->right);
	}
}

void preorder(node1 *root1)
{
	if(root1 != NULL)
	{
		printf("%d \n",root1->key);
		preorder(root1->left);
		preorder(root1->right);
	}
}

void postorder(node1 *root1)
{
	if(root1 != NULL)
	{
		postorder(root1->left);
		postorder(root1->right);
		printf("%d \n",root1->key);
	}
}


node1 *insert(node1 *node1,int key)
{
	if(node1 == NULL)
		return newnode1(key);
	
	if(key < node1->key)
		node1->left = insert(node1->left,key);
	
	else if(key > node1->key)
		node1->right = insert(node1->right,key);
	
	return node1;
}

node1 *search(node1 *root1,int key)
{
	if(root1 == NULL || root1->key == key)
	return root1;
	
	if(root1->key < key)
	return search(root1->right,key);
	
	else if(root1->key > key)
	return search(root1->left,key);
}



int main()
{
	int choose;
	
	main_menu:
		system("cls");
	printf("\n\n___________________________________________________________________");
	printf("\nBREADTH & DEPTH FRIST SEARCH");
	printf("\n----------------------------------------------------------------------");
	
	
	printf("\nPress 1 For Breadth First Search");
	printf("\nPress 2 for Depth First Search");
	printf("\nPress 3 for Exit");
	printf("\nEnter Choice :\t");
	scanf("%d",&choose);
	
	switch(choose)
	{
		case 1:
			
			system("cls");
			{
					int value,ele;
	int choice;
	char ch;
	
	root = newnode(1);
	
	do
	{
		do
		{
			printf("\n BFS MENU");
			printf("\n 1.insert");
			printf("\n 2.levelOrder traversal");
			printf("\n 3.Goto Main Menu");
			printf("\n Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:printf("\n Enter the value to be inserted into tree:");
				       scanf("%d",&value);
				       insert(root,value);
				       break;
				       
				case 2:printf("\n levelOrder traversal:");
				       levelOrder(root);
					   break;
					   	   
				case 3:
				{
					goto main_menu;
					   }	   
				default:printf("\n !!!!WRONG CHOICE!!!!");
				        break;	   	   	          
			}
		}
		while(choice != 3);
		printf("\n Do you wish to continue?");
		getchar();
		scanf("%c",&ch);
	}
	while(ch == 'y' || ch == 'Y');
			
			break;	
				
				
			}
			
			
		case 2:
			{		
	system("cls");			
	int value,ele;
	int choice;
	char ch;
	root = newnode(1)	;
	do
	{
		do
		{
			printf("\n BST MENU");
			printf("\n 1.insert");
			printf("\n 2.inorder traversal");
			printf("\n 3.preorder traversal");
			printf("\n 4.postorder traversal");
			printf("\n 5.search");
			printf("\n 6.Goto Main Menu");
			printf("\n Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:printf("\n Enter the value to be iserted into tree:");
				       scanf("%d",&value);
				       insert(root,value);
				       break;
				       
				case 2:printf("\n Inorder traversal:");
				       inorder(root1);
					   break;
					   
				case 3:printf("\n Preorder traversal:");
				       preorder(root1);
					   break;
					   
				case 4:printf("\n Postorder traversal:");
				       postorder(root1);
					   break;
					   
				case 5:printf("\n Enter the value to be searched:");
				       scanf("%d",&ele);
					   printf("%d",search(root1,ele));
					   break;	   
					 
					 
				case 6:
					{
						goto main_menu;
						break;
					}  	   
				default:printf("\n !!!!WRONG CHOICE!!!!");
				        break;	   	   	          
			}
		}
		while(choice != 6);
		printf("\n Do you wish to continue?");
		getchar();
		scanf("%c",&ch);
	}
	while(ch == 'y' || ch == 'Y');
				
				
			}
			
		case 3:
			{
				exit(0);
				
			}
	}
}
