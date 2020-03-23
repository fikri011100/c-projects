#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
struct node {
	int price;
	char nameUser[12];
	char nameDress[12];
	struct node *next;
};
struct node *start =NULL;
struct node *display(struct node *);
struct node *insert_beg(struct node*);
struct node *delete_beg(struct node *);

void initData();

int main(){
	initData();
	int option;
	system("cls");
	char * menu[]= {"1. View Queue","2. Add Customer to Queue","3. Serve Cutomer ","4.Exit"};
	do{
		printf("\n\n *****BLUE DRESS SHOP CASHIER QUEUE ***** \n");
		printf("############################################# \n");
		
		for(int i= 0; i<=3;i++){
			printf("%s \n", menu[i]);
		}
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			
	   		case 1: start = display(start);
			break;
			case 2: start = insert_beg(start);
			break;
			case 3: start = delete_beg(start);
			break;
		}
	}while(option !=5);
	getchar();
	return 0;
}

struct node *display(struct node *start){
	system("cls");
	struct node *ptr;
	ptr =start;
	printf("======================\n\n");
 	 printf("NO | Customer Name | Dress Name | Price\n");
 	 printf("--------------------------------------------------------------\n");
 	 	int i=1;
	while (ptr != NULL){
		printf("%d. | %12s | %-12s | Rp. %d \n", i++, ptr->nameUser,ptr->nameDress,ptr->price);
		ptr =ptr->next;
	}
	return start;
}
struct node * delete_beg(struct node *start){
	struct node *ptr;

	ptr= start;
	if(ptr ==NULL ){
		printf("Ksong");
		return start;
	}
	start = start -> next;
	free(ptr);
	return start;
}
struct node * insert_beg(struct node *start){
	system("cls");
	struct node *ptr, *new_node;
	char nameUsr[12],nameDrs[12];
	int priceD,a,b,c;
	do{
		printf("\n Inpur Customer Name ");
		scanf("%s",nameUsr);	
		a = strlen(nameUsr);
	}while(a>=20 || a<=3 );
	do{
		printf("\n Inpur Dress Name ");
		scanf("%s",nameDrs);
		b = strlen(nameDrs);
	}while(b>=20 || b<=3 );
	do{
		printf("\n Inpur Dress Price ");
		scanf("%d",&priceD);
	}while(priceD>=999 && priceD<=50 );
	
	new_node =(struct node *)malloc(sizeof(struct node));
	strcpy(new_node ->nameUser,nameUsr);
	strcpy(new_node ->nameDress,nameDrs);
	new_node -> price = priceD;
	new_node -> next = NULL;
    ptr = start;
    while(ptr -> next != NULL)
    ptr = ptr -> next;
    ptr -> next = new_node;
	return start;
}
void initData(){
	struct node * new_node;	
		
	int	price1[3]={3,15,16};
	char * name[]={"martin","suci","diah"};
	char * nameDre[]={"Batik","Kain","Kaos"};
	for (int i =0;i<3;i++){
		new_node = (struct node *)malloc(sizeof(struct node));
		strcpy(new_node ->nameUser,name[i]);
		strcpy(new_node ->nameDress,nameDre[i]);
		new_node ->price=price1[i];
		new_node ->next= start;
		start= new_node;
	}	
}