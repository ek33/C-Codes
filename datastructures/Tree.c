#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 16
#define FALSE 0
#define TRUE 1

/*A tree Node declaration*/
struct Node
{
	     int val;
		 struct Node* left;
	     struct Node* right;
};

/*A tree decleration which is mainly a pointer to a Node*/
typedef struct Node *Tree;

/*Function signatures*/
Tree CreateTree(void);
Tree MakeEmptyTree(Tree);
Tree InsertElement(int, Tree);
void DisplayTree(Tree);
int IterativeFindMinimum(Tree);
int IterativeFindMaximum(Tree);
int RecursiveFindMinimum(Tree);
int RecursiveFindMaximum(Tree);
Tree FindElement(Tree,int);
Tree DeleteBinaryTreeStructure(Tree,int);

int main()
{
    Tree myTree, pos,t;
    int exit, val, height;
    char command;
    
    
    myTree = CreateTree();        
    exit = FALSE;
    
    while (!exit)
    {
        fflush(stdin);
        printf("\nMenu:\n i)nitialize\n n)ew element\n f)ind min iteratively\n fin(d) max iteratively\n find (m)in recursively\n find ma(x) recursively\n find e(l)ement\n dele(t)e element\n e)xit\nEnter command:");
        scanf("%c", &command);  
        fflush(stdin);
        
        switch(command) 
        {       
            case 'i':
                 myTree = MakeEmptyTree(myTree);
            break;
            case 'n':
                 printf("enter value: ");
                 scanf("%d", &val);
                 myTree = InsertElement(val,myTree);
                 DisplayTree(myTree);
            break;  
            case 'f':
                 printf("\nThe minimum value :%d\n",IterativeFindMinimum(myTree));
            break;
            
            case 'd':
                 printf("\nThe maximum value :%d\n",IterativeFindMaximum(myTree));
            break;
            case 'm':
                 printf("\nThe minimum value :%d\n",RecursiveFindMinimum(myTree));
            break;
            case 'x':
                 printf("\nThe maximum value :%d\n",RecursiveFindMaximum(myTree));
            break;  
            case 'l':
                 printf("enter value to be found: ");
                 scanf("%d", &val);
                 t=FindElement(myTree,val);
                if(t!=NULL)
                    printf("The node that includes %d has been found",t->val);
                else
                    printf("The node couldn't be found");
            break;
            case 't':
                 printf("enter value to be deleted: ");
                 scanf("%d", &val);
                 myTree=DeleteBinaryTreeStructure(myTree,val);
                /*
                if(t!=NULL)
                    printf("The node that includes %d has been found",t->val);
                else
                    printf("The node couldn't be found");
                */
            break;                               
            case 'e':
                 exit = TRUE;
            break;       
            default:
                    printf("command not recognized\n");
            break;
        }
    
    
    }
    
    printf("\n\n");              
    system("PAUSE");	
    return 0;
}

Tree DeleteBinaryTreeStructure(Tree root,int val){
   // STEP 1: PERFORM STANDARD BST DELETE
 
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child
 
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's data to this node
            root->key = temp->key;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
}

Tree FindElement(Tree t,int val){
     if(t==NULL)
         return t;
     else{
         if(t->val==val)
             return t;
         else if(val>t->val)
             return FindElement(t->right,val);
         else if(val<t->val)
             return FindElement(t->left,val);
         }
}

int IterativeFindMinimum(Tree t){
    for(;t->left!=NULL;t=t->left);
    return t->val;
}

int IterativeFindMaximum(Tree t){
    for(;t->right!=NULL;t=t->right);
    return t->val;
}
int RecursiveFindMinimum(Tree t){
    if(t->left==NULL)
        return t->val;
    else
        return RecursiveFindMinimum(t->left);
}

int RecursiveFindMaximum(Tree t){
    if(t->right==NULL)
        return t->val;
    else
        return RecursiveFindMaximum(t->right);
}

/*Function that mainly creates a tree which is initially NULL*/
Tree CreateTree(void)
{
    return NULL;
}

/*Function that takes a tree and makes it an empty tree by removing all the nodes from that tree*/
Tree MakeEmptyTree(Tree t)
{
     if (t != NULL)
     {
         MakeEmptyTree(t->left);
         MakeEmptyTree(t->right);
         free(t);
     }
     return NULL;
}

/*This function takes an integer value and a tree,
  and inserts that value to the tree*/
Tree InsertElement(int val, Tree t)
{
     if(t==NULL){
         t=(Tree)malloc(sizeof(struct Node));
         
         if(t==NULL)
              printf("Out of memory!!");
         else{
              t->val=val;
              t->left=t->right=NULL;
         }
     }else if(val<t->val)
          t->left=InsertElement(val,t->left);
     else if(val>t->val)
          t->right=InsertElement(val,t->right);
     return t;
}

/*This function takes a tree and displays its content on the screen*/
void DisplayTree(Tree t)
{
   if (t !=NULL) 
   {
		DisplayTree(t->left);
		printf("%d\n", t->val);
		DisplayTree(t->right);
   }
}
