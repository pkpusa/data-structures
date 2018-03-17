// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
 
// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}


struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
 
// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE
 	if (root == NULL)
        return root;
  
    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->key = temp->key;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }
    
    
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

/*void search(struct Node* root, int key)
{
	if(root != NULL)
    {
        if(ser == root->key)
        {
        	printf("\nElement found .");
        	return ;
        	
		}
        preOrder(root->left);
        preOrder(root->right);
    }
	
}*/
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d ",root->key);
		inOrder(root->right);
		
	}
 } 

void postOrder(struct Node *root)
 {
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
 }
 
void layout()
{
	printf("\n\t\t10th Data Structure Lab");
	printf("\n\t\t____________________________________________________________________________\n");
	printf("\t\t\t\tAVL TREE :- INSERTION, DELETION\n");
	printf("\t\t_______________________________________________________________________________");
}



int main()
{
	int no_of_nodes, i, element, opt;
	int arr[MAX];
  	struct Node *root = NULL;
  	char choice;
  	int options;
  	
  	
  	main:
  	system("cls");
	  layout();
 		
 		
 		printf("\n\nPress 1 for Insert Nodes in AVL Tree.\nPress 2 For Display the Elements\nPress 3 for Delete Elements form Tree\nPress 4 to Exit the Program");
 		printf("\n\nEnter your choice here :\t");
 		fflush(stdin);
 		scanf("%d", &options);
 		
 		switch(options)
 		{
 			case 1:
 				{
 					do{
					 
 						printf("\n\nHow many Nodes you Want to Enter :- ");
 						scanf("%d", &no_of_nodes);
 						
						printf("\nEnter %d Elements  :-\t ",no_of_nodes);
  						for(i = 0; i < no_of_nodes; i += 1)
  						{
				
  							scanf("%d", &arr[i]);
  							root = insert(root, arr[i]);
  		
						}
					
						printf("\n\nDo you want To Insert More Element :\nPress Y For Yes :\t");
						getchar();
						scanf("%c", &choice);
						}while(choice == 'Y' || choice == 'y');
						
						
					printf("\n\nDo You want to Go to Main Menu. Press Y or y for yes :\t");
  					getchar();
  					scanf("%c",&choice);
  					if(choice == 'y' || choice == 'Y')
  					{
  						goto main;
					}
					
					break;
				}
				
			case 2:
				{
					if(root != NULL)
					{
					
					printf("\nPreorder traversal of the constructed AVL tree is \n");
					
					printf("\n\t\t\t____________________________________________\n");
  					printf("\t\t\t\t\t");
					preOrder(root);
					printf("\n\t\t\t____________________________________________");
					
  					
  					printf("\n\nInorder traversal of the constructed AVL tree is \n");
  					printf("\n\t\t\t____________________________________________\n");
  					printf("\t\t\t\t\t");
					inOrder(root);
					printf("\n\t\t\t____________________________________________");
  					
  					printf("\n\nPostOrder traversal of the constructed AVL tree is \n");
					printf("\n\t\t\t____________________________________________\n");
  					printf("\t\t\t\t\t");
					postOrder(root);
					printf("\n\t\t\t____________________________________________");
					
				}
					else
					{
						system("cls");
						printf("\n\n\t\tDear SIR there is NO elements in Tree ..... \n********\t\tPlease goto first menu and insert Some elements ");
					}
  					
  					printf("\n\nDo You want to Go to Main Menu. Press Y or y for yes :\t");
  					getchar();
  					scanf("%c",&choice); 
  					if(choice == 'y' || choice == 'Y')
  					{
  						goto main;
					}
					
					break;
					  
  				}
  				
  				case 3:
  					{
  						if(root!= NULL)
  						{
  							
						  
  						system("cls");
						printf("\t\t\tAVL TREE DELETION");
						printf("\n_______________________________________________________________________________________\n");	
						printf("\nTree Elements Are :-\t");
						preOrder(root);
						
						
						do{
						
							printf("\nWhich element you want to delete :\t");
  							scanf("%d", &element);
  							root = deleteNode(root, element);
  							
  							printf("\nPreorder traversal of the AVL tree AFTER DELETION is \n");
					
					printf("\n\t\t\t____________________________________________\n");
  					printf("\t\t\t\t\t");
					preOrder(root);
					printf("\n\t\t\t____________________________________________");
					
  					
  					printf("\n\nInorder traversal of the constructed AVL tree AFTER DELETION  is \n");
  					printf("\n\t\t\t____________________________________________\n");
  					printf("\t\t\t\t\t");
					inOrder(root);
					printf("\n\t\t\t____________________________________________");
  					
  					printf("\n\nPostOrder traversal of the constructed AVL tree AFTER DELETION  is \n");
					printf("\n\t\t\t____________________________________________\n");
  					printf("\t\t\t\t\t");
					postOrder(root);
					printf("\n\t\t\t____________________________________________");
						
							printf("\n\nWant to delete more. Press Y :\t");
							getchar();
							scanf("%c",&choice);
							}while(choice == 'y' || choice == 'Y');
					}
					
					else
					{
						system("cls");
						printf("\n\n\t\tDear SIR there is NO elements in Tree ..... \n********\t\tPlease goto first menu and insert Some elements ");
					}
					printf("\n\nDo You want to Go to Main Menu. Press Y or y for yes :\t");
  					getchar();
  					scanf("%c",&choice);
  					if(choice == 'y' || choice == 'Y')
  					{
  						goto main;
					}
					
					break;
  						
				}
				
				case 4:
					{
						exit(0);
						break;
						
					}
					
				default:
					{
						goto main;
					}

		 }
 	
		
	
	
  	
  	
 
  return 0;
}
