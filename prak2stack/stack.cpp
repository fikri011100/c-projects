#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Node
{
   int level;
   char type[30];
   struct Node *next, *prev;
}*head, *tail, *current;

void showView() {
	printf("ADE MAKARONI STOCK\n");
	printf("------------------\n\n\n");
	printf("Makaroni Stock <STACK>\n\n");
	if(head != NULL){
		current=head;
      	while(current != NULL){
      		if(current->prev == NULL) {
      			printf("[ %-6s makaroni : hot level %2d ] -> TOP \n", current->type, current->level);
			} else {
				printf("[ %-6s makaroni : hot level %2d ]\n", current->type, current->level);
			}
			current = current->next;
      	}
	}
	printf("\nOption\n");
	printf("1. Stock of Makaroni\n");
	printf("2. Sell Makaroni\n");
	printf("3. Exit\n\n");
}

void stock() {
	char type[30];
	int level;
	do {
		printf("Input makaroni type [small/medium/large] : ");
		scanf("%s", &type);
	} while(strcmp(type, "small") != 0 && strcmp(type, "medium") != 0 && strcmp(type, "large") != 0);
	do {
		printf("Input the hot of makaroni [5..15 level] : ");
		scanf("%d", &level);
	} while (level <= 5 && level >= 15);
	current = (struct Node *)malloc(sizeof (Node));
	strcpy(current->type, type);
	current->level = level;
	current->next = current->prev = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
   	printf("\nInsertion is Success!!!\n");
   	getch();
   	showView();
}

void sell() {
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
	printf("\nSell Makaroni Success\n");
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

int main() {
	int choice;
	showView();
	while(1){
	printf(">> Input Choice : ");
	scanf("%d", &choice);
	switch(choice) {
	case 1:
		if (getCount(head) < 10) {
			printf("%d", getCount(head));
			stock();
		} else {
			printf("barang maksimal 10");
		}
		break;
	case 2:
		sell();
		break;
	case 3:
		exit(0);
		break;
	default: printf("\nWrong selection!!! Please try again!!!\n");
      }
  }
	return 0;
}
