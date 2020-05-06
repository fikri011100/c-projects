#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    char name[30];
	  char course[30];
	  char test[20];
    char nim[20];
    int score;
    struct Node * next;
    struct Node * prev;
}*head, *tail, *current;

void showView() {
	printf("DATABASE STUDENT SCORE\n");
	printf("---------------------------\n\n");
	printf("1. View Student Score\n");
	printf("2. Add New Score\n");
	printf("3. Exit\n\n");
}

void showList() {
    if(head != NULL){
		current=head;
		printf("======================\n\n");
 	    printf("No\t| Student Name\t\t|NIM\t\t |Course\t\t\t |Test\t\t  |Score |\n");
 	    printf("--------------------------------------------------------------\n");
 	    int i=1;
      	while(current != NULL){
            printf("%d. \t| %-18s| %-11s| %-18s| %-11s| %-5d| \n", i++, current->name, current->nim, current->course, current->test, current->score);
			      current = current->next;
      	}
	}
	showView();
}

void stock() {
	char name[30];
	char course[30];
	char test[20];
	char nim[20];
	int score;
	int cho;
	do {
	printf ("Input Student Name [5..30]:");
	scanf("%[^\n]s",&name);
	} while(strlen(name)<5 || strlen (name)>30);	
					
	printf("\nInput NIM:");
	scanf("%s", &nim);
					
	do{
	printf("\nInput Course [5..30]:");
	scanf("%[^\n]s",&course);
	} while(strlen(course)<5 || strlen (course)>30);
					
	do{
	printf("\nInput Test [Mid Test/Final Test]:");
	scanf("%[^\n]s",&test);
	} while(strcmp(test, "Mid Test" )!= 0 && strcmp(test, "Final Test" )!= 0);
					
	do {
	printf("\nInput Score :");
	scanf("%d", &score);
	}while(score>100);
	current = (struct Node *)malloc(sizeof (struct Node));
	strcpy(current->name, name);
	strcpy(current->nim, nim);
	strcpy(current->course, course);
  strcpy(current->test, test);
  current->score = score;
	current->next = current->prev = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
   	printf("\n---Add New Asset Success---\n");

   	showView();
}

void init(){
	char * nim[] ={"2301886531","2301887592","2301834504"};
	int score[3]= {87,95,40};
	char * name[]={"Fikri Imad","Bagus Ardianto","Boby Santoso"};
  char * test[]={"Final Test","Mid Test","Mid Test"};
	char * course[]={"Entrepreneurship","Bussiness Law","Data Structure"};
	for (int i =0;i<3;i++){
		current = (struct Node *)malloc(sizeof (struct Node));
    	strcpy(current->course, course[i]);
    	strcpy(current->name, name[i]);
      strcpy(current->test, test[i]);
    	current->score = score[i];
    	strcpy(current->nim, nim[i]);
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
	    exit(0);
	    break;
	default: printf("\nWrong selection!!! Please try again!!!\n");
      }
  }
	return 0;
}