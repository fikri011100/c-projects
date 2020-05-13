#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<time.h>
#define MAX_NAME 20
#define SUCCESS 0
#define FAILED 1

typedef struct dataa node;
typedef struct dtInput input;

int push(input *input);
void preorder(node *tree);
void inorder(node *tree);
void postorder(node *tree);
void view();
void add();
void order();
struct node *deleteElement(struct node *);

struct dataa
{
    char name[MAX_NAME];
    int number;
    int leftPos;
    int rightPos;
    node *left;
    node *right;
};

node *root = NULL;

struct dtInput
{
    char name[MAX_NAME];
    int number;
};

void preorder(node *tree)
{
    if(tree != NULL)
	{
        printf("%d ",tree->number);
        preorder(tree->left);
        preorder(tree->right);
    }
    return;
}

void inorder(node *tree)
{
    if(tree != NULL)
	{
        inorder(tree->left);
        printf("%d ",tree->number);
        inorder(tree->right);
    }
    return;
}

struct node *deleteElement(struct node *tree) {
  return tree;
}

void postorder(node *tree)
{
    if(tree != NULL)
	{
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->number);
    }
    return;
}

void salin (node *tree)
{
	if(tree != NULL)
	{
        printf("%-30s <%d> \n", tree->name, tree->number);
    }
}

void view(node *tree)
{
    if(tree != NULL)
	{
		salin(tree);
        salin(tree->left);
        salin(tree->right);
    }
    return;
}

void add()
{
    input input;
    int push_status;
    system("cls");
    do{
        printf("Input Book's Name [3..50]: ");
        fflush(stdin);
        gets(input.name);
    } while(strlen(input.name) <3 || strlen(input.name) >50);
    printf("\n");
    do{
        printf("Input Book's Back Number [0..100]: ");
        scanf("%d", &input.number);
        fflush(stdin);
    } while(input.number <1 || input.number >100);
    printf("\n");
    push_status = push(&input);
    if(push_status == SUCCESS)
	{
        printf("\n--- Add Book Success ---");
    } else if(push_status == FAILED)
	{
        printf("\n--- Add Book Failed ---");
    }
    getch();
    system("cls");
}


int push(input *input)
{
    char node_pos[10];
    int tempLeftPos = 0;
    int tempRightPos = 0;
    node *cur;
    node *temp = (node *) malloc(sizeof(node));
    if(temp == NULL)
	{
        perror("Error: ");
        sleep(2);
        return FAILED;
    } 
	else
	{
        strcpy(temp->name, input->name);
        temp->number = input->number;
        temp->left = NULL;
        temp->right = NULL;
        if(root == NULL)
		{
            root = temp;
            root->leftPos = 0;
            root->rightPos = 0;
            return SUCCESS;
        }
        else
		{
            cur = root;
            while(1)
			{
                do{
                	printf("Will He Be in \'left\' or \'right\' %s?: ", root->name);
                    gets(node_pos);
                    fflush(stdin);
                } while (strcmp(node_pos, "left") != 0 && strcmp(node_pos, "right") != 0);
                
				if(strcmp(node_pos, "left") == 0)
				{
                    if(cur->left != NULL)
					{
                        tempLeftPos++;
                        cur = cur->left;
                        printf("Will He Be in \'left\' or \'right\' %s?: ", root->name);
                    } 
                    else
					{
                        tempLeftPos++;
                        cur->left = temp;
                        temp->leftPos = tempLeftPos;
                        temp->rightPos = tempRightPos;
                        return SUCCESS;
                    }
                }
                else if(strcmp(node_pos, "right") == 0)
				{
                    if(cur->right != NULL)
					{
                        tempRightPos++;
                        cur = cur->right;
                        printf("Will He Be in \'left\' or \'right\' %s?: ", root->name);
                    } 
                    else
					{
                        tempRightPos++;
                        cur->right = temp;
                        temp->leftPos = tempLeftPos;
                        temp->rightPos = tempRightPos;
                        return SUCCESS;
                    }
                }
            }
        }
    }
}

void order()
{
    int ans;
    system("cls");
    printf("Preorder  : ");
    preorder(root);
    printf("\nInorder   : ");
    inorder(root);
    printf("\nPostorder : ");
    postorder(root);
    getch();
}


int main()
{
	int repeat=0, choice;
	do
	{
		system("cls");
		printf("PINK LIBRARY \n");
		printf("************ \n\n");
		printf("1. View All Book \n");
		printf("2. Add Book \n");
		printf("3. Remove Book \n");
		printf("4. Inorder, Preorder, Postorder \n");
		printf("5. Exit an Remove All \n\n");
		printf(">> Input choice :");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :{
				system("cls");
				if(root != NULL)
				{
				printf("\n");
				view(root);
        getch();
				}
                else
				{
                    printf("\n--- There is No Book in The Tree ---");
                    getch();
                }
				break;
			}
			case 2 :{
				system("cls");
				add();
				break;
			}
			case 3 :{

				break;
			}
			case 4 :{
                if(root != NULL)
                    order();
                else
				{
                    printf("--- There is No Book in The Tree ---");
                    getch();
                    system("cls");
                }				
				break;
			}
			case 5 :{
				system("cls");
				printf("Delete All Data");
				sleep(3);
				printf("\n\nDone! Thank you for using this application...");
        getch();
				repeat=1;
				break;
			}
			default : {
				system("cls");
				printf ("Sorry, Keyword is wrong!\nPlease to Input again...");
        getch();
				break;
			}
		}
	}while (repeat==0);
}
