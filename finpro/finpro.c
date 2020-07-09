#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 4

struct Node
{
	char jenisLapangan[16];
	char namaBooking[16];
	char tanggal[10];
	int durasi;
	int price;
	struct Node *left;
	struct Node *right;

} * root, *newnode;

void menu()
{

	printf("\n\n=====Booking Lapangan=====\n");
	printf("--------------------------\n\n");
	printf("1. List booking Anda\n");
	printf("2. List Harga Booking\n");
	printf("3. Booking Lapangan\n");
	printf("4. Exit\n\n");
}

void showListPrice()
{
	printf("\n===========List Harga Booking==========\n");
	printf("_________________________________________\n");
	printf("No\t| Jenis Lapangan   \t | Harga Per-Jam\n");
	printf("-----------------------------------------\n");
	printf("1.\t| Lapangan futsal   \t| Rp. 60.000 	 \n");
	printf("2.\t| Lapangan Basket   \t| Rp. 80.000 	 \n");
	printf("3.\t| Lapangan Badminton\t| Rp. 100.000	 \n\n");
}

void AddCar()
{
	char tanggal[10];
	int a, fieldCode, dd, MM, yyyy, duration;
	struct Node *Y;
	struct Node *temp;

	Y = (struct Node *)malloc(sizeof(struct Node));
	showListPrice();
	printf("Input Field Code : ");
	scanf("%d", &fieldCode);
	fflush(stdin);

	printf("Input Nama Pembooking : ");
	scanf("%s", &Y->namaBooking);
	fflush(stdin);

	printf("Input Tanggal [dd] : ");
	scanf("%s", &dd);
	fflush(stdin);

	printf("Input Bulan [MM] : ");
	scanf("%s", &MM);
	fflush(stdin);

	printf("Input Tahun [yyyy] : ");
	scanf("%s", &yyyy);
	fflush(stdin);
	strcpy(tanggal, ("$d/$d/$d", &dd, &MM, &yyyy));
	strcpy(Y->jenisLapangan, &tanggal);

	printf("Input Durasi [jam] : ");
	scanf("%d", &duration);
	fflush(stdin);

	switch (fieldCode)
	{
	case 1:
		strcpy(Y->jenisLapangan, "Lapangan Futsal");
		Y->durasi = duration * 60000;
		break;
	case 2:
		strcpy(Y->jenisLapangan, "Lapangan Basket");
		Y->durasi = duration * 80000;
		break;
	case 3:
		strcpy(Y->jenisLapangan, "Lapangan Badminton");
		Y->durasi = duration * 100000;
		break;
	default:
		break;
	}

	Y->left = NULL;
	Y->right = NULL;

	if (root == NULL)
	{

		root = Y;
		root->left = NULL;
		root->right = NULL;
		printf("\n\n---Add New Order Success---\n\n");
	}
	else
	{

		newnode = root;
		while (newnode != NULL)
		{
			temp = newnode;
			if (newnode->jenisLapangan)
			{
				newnode = newnode->left;
			}
			else
			{
				newnode = newnode->right;
			}
		}

		if (maxsize <= 4)
		{
			if (Y->namaBooking < temp->jenisLapangan)
			{
				temp->left = Y;
			}
			else if (Y->jenisLapangan > temp->jenisLapangan)
			{
				temp->right = Y;
			}
			printf("\n\n---Add New Order Success--\n\n");
		}
		else
		{
			printf("\n\n--Maximum Size of tree is 4 Level!");
		}
	}
}

void PreOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		printf("\n%s [ %s ] ", newnode->jenisLapangan, newnode->namaBooking);
		PreOrder(newnode->left);
		PreOrder(newnode->right);
	}
}

void InOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		InOrder(newnode->left);
		printf("\n%s [ %s ] ", newnode->jenisLapangan, newnode->namaBooking);
		InOrder(newnode->right);
	}
}

void PostOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		PreOrder(newnode->left);
		PreOrder(newnode->right);
		printf("\n%s [ %s ] ", newnode->jenisLapangan, newnode->namaBooking);
	}
}

int main()
{

	int choose;

	menu();

	printf(">>Input choice : ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		if (root == NULL)
		{
			printf("\n\t---There is No Order in The Tree---");
		}
		else
		{
			printf("Preorder  : ");
			PreOrder(root);
			printf("\nInorder   : ");
			InOrder(root);
			printf("\nPostorder : ");
			PostOrder(root);
		};
		main();
		break;

	case 2:
		showListPrice();
		main();
		break;

	case 3:
		AddCar();
		main();
		break;

	case 4:
		break;
	}
}
