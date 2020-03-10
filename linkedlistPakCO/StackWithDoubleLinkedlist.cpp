#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct book{
  int value;
  struct book *next, *prev;
}*head, *tail, *current;

void print(){
  if(head!=NULL){
    current=head;
    while(current!=NULL){
      printf("%d -> ", current->value);
      current=current->next;
    }
  }else{
    printf("No Data");
  }
  printf("\n\n");
};

void pushHead(int value){
  current = (struct book *)malloc(sizeof (book));
  current->value=value;
  current->next = current->prev = NULL;

  if(head==NULL){
    head=tail=current;
  }else{
    head->prev=current;
    current->next=head;
    head=current;
  }
}

void popHead(){
  if(head==NULL){
    printf("No Data");
  }else if(head==tail){
    current=head;
    head=tail=NULL;
    free(current);
  }else{
    current=head;
    head=head->next;
    head->prev=NULL;
    free(current);
  }
}

int main(){
  int menu;
  int stacke = 1;
  char studentname[30];
  print();
  do{
    do{
      system("cls");
      print();
      printf("1. Stack\n");
      printf("2. UnStack\n");
      printf("3. Exit\n");
      printf("Choose : "); scanf("%d", &menu); fflush(stdin);
    }while(menu<1 || menu>3);
    switch(menu){
      case 1 : 
        pushHead(stacke);
        stacke++;
        break;
      case 2 :
        stacke--; 
        popHead();
        
        break;
    }
  }while(menu!=3);
}
