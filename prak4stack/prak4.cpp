#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
   int qty;
   int price;
   char name[30];
   char type[30];
   struct Node *next, *prev;
}*head, *tail, *current;

void showView() {
	printf("COOL COMPUTER ADMINISTRATOR\n");
	printf("---------------------------\n\n");
	printf("1. Item List\n");
	printf("2. Add <PUSH> New Item\n");
	printf("3. Delete <POP> Recently Added Item\n");
	printf("4. Exit\n\n");
}

void showList() {
    if(head != NULL){
		current=head;
		printf("======================\n\n");
 	    printf("NO\t| Name\t\t|Type\t\t|QTY\t|PRICE \n");
 	    printf("--------------------------------------------------------------\n");
 	    int i=1;
      	while(current != NULL){
            printf("%d. \t| %-14s| %-14s|%7d| $ %d \n", i++, current->name, current->type, current->qty, current->price);
			current = current->next;
      	}
	} else {
	    printf("======================\n\n");
 	    printf("NO\t| Name\t\t|Type\t\t|QTY\t|PRICE \n");
 	    printf("--------------------------------------------------------------\n");
	}
	getch();
	showView();
}

void stock() {
	char name[30], type[30];
	int qty, price;
	do{
	    printf("\n Input Name of the new item [3..20] : ");
		scanf("%s",name);
	}while(strlen(name)>=20 || strlen(name)<=3);
	do {
		printf("Input type of the new item[processor/graphic card/memory] : ");
		scanf("%s", &type);
	} while(strcmp(type, "processor") != 0 && strcmp(type, "graphic card") != 0 && strcmp(type, "memory") != 0);
	do {
		printf("Input quantity of the new item [1..20 level] : ");
		scanf("%d", &qty);
	} while (qty <= 1 && qty >= 20);
	do {
		printf("Input price of the new item [$1..$1000 level] : ");
		scanf("%d", &price);
	} while (price <= 1 && price >= 1000);
	current = (struct Node *)malloc(sizeof (struct Node));
	strcpy(current->type, type);
	strcpy(current->name, name);
	current->qty = qty;
	current->price = price;
	current->next = current->prev = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
   	printf("\n---Add new Item Success---\n");
   	getch();
   	showView();
}

void sell() {
	if(head==NULL){
		printf("There are no item available.");
	}else if(head==tail){
		current=head;
		head=tail=NULL;
		free(current);
	    printf("\n the recently added item <%s - %s> is being delete\n", current->name, current->type);
	}else{
		current=head;
		head=head->next;
		head->prev=NULL;
		free(current);
	    printf("\n the recently added item <%s - %s> is being delete\n", current->name, current->type);
	}
   	getch();
   	showView();
}

int getCount(struct Node* head) {
	int count = 0;
    current = head; 
	while(current != NULL){
		count++;
		current = current->next;
    }
    return count;
}

void init(){
	int	price[3]={100,150,4};
	int qty[3]= {12,19,4};
	char * name[]={"ASUS","TOSHOBA","APPLE"};
	char * type[]={"processor","graphic card","memory"};
	for (int i =0;i<3;i++){
		current = (struct Node *)malloc(sizeof (struct Node));
    	strcpy(current->type, type[i]);
    	strcpy(current->name, name[i]);
    	current->qty = qty[i];
    	current->price = price[i];
    	current->next = current->prev = NULL;

    	if(head==NULL){
    		head=tail=current;
    	}else{
    		head->prev=current;
    		current->next=head;
    		head=current;
    	}
	}	
}

int main() {
	int choice;
	showView();
	init();
	while(1){
	printf(">> Input Choice : ");
	scanf("%d", &choice);
	switch(choice) {
	case 1:
	    showList();
		break;
	case 2:
		stock();
		break;
	case 3:
		sell();
		break;
	case 4:
	    exit(0);
	    break;
	default: printf("\nWrong selection!!! Please try again!!!\n");
      }
  }
	return 0;
}