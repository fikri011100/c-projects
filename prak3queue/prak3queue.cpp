#include <stdio.h>
#include <stdlib.h>
// #include <malloc.h>
#include <string.h>

struct node
{
	int tableNo;
	char nameUser[12];
	char foodName[12];
	int qty;
	struct node *next;
};
struct node *start = NULL;
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_beg(struct node *);

void initData();

int main()
{
	initData();
	int option;
	char *menu[] = {"1. Order List", "2. Add Order", "3. Take Order ", "4. Exit"};
	do
	{
		printf("\n\nORDER CHINESE FOOD \n");
		printf("######################################## \n");

		for (int i = 0; i <= 3; i++)
		{
			printf("%s \n", menu[i]);
		}
		printf("\n\n Input your choice : ");
		scanf("%d", &option);
		switch (option)
		{

		case 1:
			start = display(start);
			break;
		case 2:
			start = insert_beg(start);
			break;
		case 3:
			start = delete_beg(start);
			break;
		}
	} while (option != 4);
	getchar();
	return 0;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	printf("======================\n\n");
	printf("NO | Table Number | Customer Name | FoodName | Quantity\n");
	printf("--------------------------------------------------------------\n");
	int i = 1;
	while (ptr != NULL)
	{
		printf("%d. | %12d | %-13s | %-19s | %-8d \n", i++, ptr->tableNo, ptr->nameUser, ptr->foodName, ptr->qty);
		ptr = ptr->next;
	}
	return start;
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;

	ptr = start;
	if (ptr == NULL)
	{
		printf("There Are No Order Available.");
		return start;
	}
	start = start->next;
	free(ptr);
	printf("Order Has Been Delivered to Table.");
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *ptr, *new_node;
	char nameUsr[12], nameFood[12];
	int tableNoD, a, b, c, qtyD;
	do
	{
		printf("\n Inpur Table Number[1..20] ");
		scanf("%d", &tableNoD);
	} while (tableNoD >= 19 && tableNoD <= 0);
	do
	{
		printf("\n Inpur Customer Name ");
		scanf("%s", nameUsr);
		a = strlen(nameUsr);
	} while (a >= 19 || a <= 2);
	do
	{
		printf("\n Inpur Food Name[5..20] ");
		scanf("%s", nameFood);
		b = strlen(nameFood);
	} while (b >= 19 || b <= 3);
	do
	{
		printf("\n Inpur Quantity[1..1000] ");
		scanf("%d", &qtyD);
	} while (qtyD >= 1000 && qtyD <= 0);

	new_node = (struct node *)malloc(sizeof(struct node));
	strcpy(new_node->nameUser, nameUsr);
	strcpy(new_node->foodName, nameFood);
	new_node->tableNo = tableNoD;
	new_node->qty = qtyD;
	new_node->next = NULL;
	ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node;
	printf("\n\n--- Add New Order Success ---\n");
	return start;
}
void initData()
{
	struct node *new_node;

	int tableNo1[3] = {7, 2, 9};
	int qty1[3] = {1, 2, 9};
	char *name[] = {"Linda", "Nad", "Jarjit"};
	char *nameFoodd[] = {"AyamGoreng", "GuleIkan", "Sambalado"};
	for (int i = 0; i < 3; i++)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		strcpy(new_node->nameUser, name[i]);
		strcpy(new_node->foodName, nameFoodd[i]);
		new_node->tableNo = tableNo1[i];
		new_node->qty = qty1[i];
		new_node->next = start;
		start = new_node;
	}
}