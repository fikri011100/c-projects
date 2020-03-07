#include <stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node* getnode( )
{
    return ( struct node *)malloc( sizeof( struct node ));
};
struct node* top; int c=0;
struct node* add( struct node *);
struct node* del( struct node *);
void display( struct node *);

int main()
{
  struct node *F;
  int ch;
  F = NULL; top=F;
  while( 1 )
  {
      printf("1. Add new element\n");
      printf("2. Delete element\n");
      printf("3. Display elements \n");
      printf("4. Exit \n");
      scanf("%d", &ch );
      if( ch == 1 )
        F = add ( F );
        else if( ch == 2 )
        F=del(F);
        else if(ch==3)
        display( F );
        else if( ch == 4 )
        return 0;
  }
}

struct node* add( struct node *FIRST)
{
    struct node *T;
    if( FIRST == NULL )
    {
        FIRST = getnode();
        T =top=FIRST;
        T->left=NULL;
    }
    else
    {  T=getnode();
       top->right=T;   T->left=top;
       top=T;
    }
    printf("Enter a val\n"); c++;
    scanf("%d",&T->val );
    T->right= NULL;
    return FIRST;
}
struct node* del( struct node *FIRST)
{
    struct node *T;
    if(( FIRST== NULL)&&(c<1))
    {
     printf("Underflow\n"); return FIRST;
    }
    T=top;
    printf("The deleted value is : %d\n",T->val);
    if(c!=1)
    {top=T->left;
    T->left= NULL; top->right=NULL;}
    else if(c==1)
    {FIRST=NULL;}
    c--;
    return FIRST;
}

void display( struct node *T)
{   if(T==NULL)
   {
       printf("Empty\n"); return;
    }
    while( T != NULL )
    {
        printf("%d  ",T->val);
        T = T->right;
    }
    printf("\n");
}


