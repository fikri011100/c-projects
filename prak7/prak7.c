#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char nama[30];
	char food[21];
	char add[31];
	struct node *next;
	struct node *prev;	
}*start, *end, *current;

void clrscr ()
{
	system ("cls");
}

void print(){
	int index;
	index = 1;
	struct node *n;
	n = start;
	do{
		if(current!=NULL){
		printf ("|%-5d| %-17s| %-22s| %26s|\n", index, n->nama, n->food, n->add);
		n = n->next;
		index++;
		}
	}while(n!=start);
}

void push (char nama[], char food[], char add[]){
	struct node *ptr;
	current = (struct node*) malloc (sizeof(struct node));
	strcpy (current->nama, nama);
	strcpy (current->food,food);
	strcpy (current->add,add);
	
	if (start==NULL){
		start=current;
		current->next=start;
		current->prev=start;
	}
	else{
		ptr = start;
		while (ptr->next!=start){
			ptr=ptr->next;
		}
		ptr->next=current;
		start->prev=ptr;
		current->next=start;
		current->prev=ptr;
	}
}

void removeE(int take){
	int u,i;
	u=1;
	struct node *ptr;
	struct node *temp;
	ptr=start;
	while (ptr->next!=start){
		ptr=ptr->next;
		u++;
	}
	if (take==1){
		ptr=start;
		do{
			ptr=ptr->next;
		}while (ptr->next!=start);
		temp=ptr->next;
		ptr->next=start->next;
		start->next->prev=ptr;
		start=start->next;
		free(temp);
	}
	else if (take==u){
		ptr=start;
		while (ptr->next->next!=start){
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
		ptr = start->prev;
	}
	else{
		ptr=start;
		for (i=1;i<take-1;i++){
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
	}
}

int main ()
{
	int ops,data=0,hapus;
	do {
	clrscr();
	char add[31];
	char nama[30];
	char food[21];
	printf ("ACE Food Delivery\n");
	printf ("-----------\n\n");
	printf ("1. View Order List\n2. Add New Order\n3. Take Order\n4. Exit\n\n");
	printf (">> Input Choice : ");
	scanf ("%d",&ops);
	switch (ops)
	{
		case 1: 
		clrscr();
		printf("                      --- ACE FOOD DELIVERY ORDER LIST ---              \n \n");
		printf("+-----+------------------+-----------------------+---------------------------+\n");
		printf("| No. |	Costomer Name    |       Food Order      |    Delivery Address       |\n");
		printf("+-----+------------------+-----------------------+---------------------------+\n");
		print();
		printf("+-----+------------------+-----------------------+---------------------------+\n");
		getch();
		break;
		case 2:
		clrscr();
		do{
		printf("Input Customer Name [3....30] : ");
		fflush(stdin);
		scanf("%[^\n]s",&nama);
		}while(strlen(nama)<3 || strlen (nama)>30);	
		do{
		printf("\nInput Food Order [3....20] : ");
		fflush(stdin);
		scanf("%[^\n]s",&food);
		}while(strlen(food)<3 || strlen (food)>20);
		do{
		printf ("\nInput Delivery address [6...30] : ");
		fflush(stdin);
		scanf("%[^\n]s",&add);
		}while(strlen(add)<6 || strlen (add)>30);
		printf ("\n\n\n--- Add New Order Success ---");
		data++;
		push (nama,food,add);
		getch();
		break;
		case 3:
		clrscr();
		if(data==0){
			printf("-- There is No Order in The List --");
			getch();
		}else{
		printf("                      --- ACE FOOD DELIVERY ORDER LIST ---               \n \n");
		printf("+-----+------------------+-----------------------+-------------------------+\n");
		printf("| No. |	Costomer Name    |       Food Order      |    Delivery Address     |\n");
		printf("+-----+------------------+-----------------------+-------------------------+\n");
		print();
		printf("+-----+------------------+-----------------------+-------------------------+\n");
		do{
			printf("\n\nInput Number of The Order [1...%d] : ", data);
			scanf("%d",&hapus);
		}while(hapus<1 || hapus>data);
		if (data==1){
			free(start);
			printf("\n\n--- Take an Order Success ---");
			getch();
		}else{
			removeE(hapus);
			printf("\n\n--- Take an Order Success ---");
			getch();
		}
		data--;;
	}
	break;		
	}
}while (ops!=4);
}
