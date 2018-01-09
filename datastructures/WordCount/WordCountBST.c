//metuncccng.txt myoutput.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORDS 512

/*A tree Node declaration*/
struct Node{
	char word[32];
	int count;
	struct Node* left;
	struct Node* right;
};

/*A tree decleration which is mainly a pointer to a Node*/
typedef struct Node *Tree;


void normalize(char*);	// To get rid of punctiation marks and make all characters uppercase in a word
Tree insert(Tree,char*);
void print(Tree,FILE*);
Tree freeTree(Tree);
Tree CreateTree(void);
void DisplayTree(Tree);
Tree FindMinimum(Tree);
Tree FindMaximum(Tree);
Tree FindElement(Tree,char*);
Tree DeleteBinaryTreeStructure(Tree,char*);

int main(){	//int main(int argc, char *argv[]){
	Tree bst=CreateTree();
	char str[MAXWORDS][32];
	char c='e';
	int i,numberOfWords;
	FILE *input, *output;
	input=fopen("metuncccng.txt","r");	//input=fopen(argv[1],"r");
	output=fopen("myoutput.txt","w");	//output=fopen(argv[2],"w");
	
	if (input==NULL||output==NULL){
        printf("Error while allocating memory!!");
        exit(1);
    }
    	
	for(i=0;getc(input)!=EOF;i++)
		fscanf(input,"%s",str[i]);
	
	numberOfWords=i;
	fclose(input);
	for(i=0;i<numberOfWords;i++){
		normalize(str[i]);
		bst=insert(bst,str[i]);
	}
	print(bst,output);
	
	fclose(output);
	bst=freeTree(bst);
	printf("\n\tOutput file was created and filled successfully!!!\n\n\n");
	system("PAUSE");
	return 0;
}

void normalize(char *s){	// To get rid of punctiation marks and make all characters uppercase in a word
	int i,j;
	for(i=0,j=0;s[i]!='\0';i++){
		if(s[i]<123&&s[i]>96){
			s[j]=s[i]-32;	//lowercase to uppercase
			j++;
		}else if(s[i]<91&&s[i]>64){
			s[j]=s[i];		//If character is uppercase it will be directly copied 
			j++;
		}					//If character is not a letter it wont be processed
	}
	s[j]=s[i];				//'\0' is copied
}

Tree insert(Tree t,char *s){
	if(t==NULL){
		t=(Tree)malloc(sizeof(struct Node));
        if(t==NULL){
            printf("Error while allocating memory!!");
            exit(1);
        }
		strcpy(t->word,s);
		t->count=1;
		t->left=t->right=NULL;
	}else if(strcmp(s,t->word)<0)
		t->left=insert(t->left,s);
	else if(strcmp(s,t->word)>0)
		t->right=insert(t->right,s);
	else
		t->count++;
	return t;
}

void print(Tree t,FILE *f){
	if (t !=NULL){
		print(t->left,f);
		fprintf(f,"%d\t%s\n", t->count,t->word);
		print(t->right,f);
   }	
}

Tree freeTree(Tree t){
	if (t != NULL){
		freeTree(t->left);
		freeTree(t->right);
		free(t);
	}
	return NULL;
}
Tree DeleteBinaryTreeStructure(Tree root,char *s){
   if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if ( strcmp(s,root->word)<0 )
        root->left = DeleteBinaryTreeStructure(root->left, s);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if( strcmp(s,root->word)>0 )
        root->right = DeleteBinaryTreeStructure(root->right, s);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) ){
            Tree temp = root->left ? root->left : root->right;
 
            // No child case
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child
 
            free(temp);
        }
        else{
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Tree temp = FindMinimum(root->right);
 
            // Copy the inorder successor's data to this node
        	strcpy(root->word,temp->word);
 
            // Delete the inorder successor
            root->right = DeleteBinaryTreeStructure(root->right, temp->word);
        }
    }
 
    // If the tree had only one node then return
    if (root == NULL)
      return root;
}

Tree FindElement(Tree t,char* s){
	if(t==NULL)
		return t;	//If searched node couldnt be found return NULL
	else{
		if(strcmp(s,t->word)==0)
			return t;
		else if(strcmp(s,t->word)>0)
			return FindElement(t->right,s);
		else if(strcmp(s,t->word)<0)
			return FindElement(t->left,s);
    }
}

Tree FindMinimum(Tree t){
    for(;t->left!=NULL;t=t->left);
    return t;
}

Tree FindMaximum(Tree t){
    for(;t->right!=NULL;t=t->right);
    return t;
}

/*Function that mainly creates a tree which is initially NULL*/
Tree CreateTree(void)
{
    return NULL;
}

/*This function takes a tree and displays its content on the screen*/
void DisplayTree(Tree t)
{
   if (t !=NULL) 
   {
		DisplayTree(t->left);
		printf("%s\n", t->word);
		DisplayTree(t->right);
   }
}
