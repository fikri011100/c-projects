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
	printf("\n===========List Harga Booking============\n");
	printf("_________________________________________\n");
	printf("No | Jenis Lapangan      | Harga Per-Jam\n");
	printf("=========================================\n");
	printf("1. | Lapangan futsal     | Rp. 60.000 	 \n");
	printf("2. | Lapangan Basket     | Rp. 80.000 	 \n");
	printf("3. | Lapangan Badminton  | Rp. 100.000	 \n\n");
}

void addField()
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
		Y->price = duration * 60000;
		Y->durasi = duration;
		break;
	case 2:
		strcpy(Y->jenisLapangan, "Lapangan Basket");
		Y->price = duration * 80000;
		Y->durasi = duration;
		break;
	case 3:
		strcpy(Y->jenisLapangan, "Lapangan Badminton");
		Y->price = duration * 100000;
		Y->durasi = duration;
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
			if (Y->jenisLapangan < temp->jenisLapangan)
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

void showPreOrder(struct Node *newnode)
{
	printf("\n====List Booking Anda=====\n");
	printf("__________________________________________________________\n");
	printf("| Jenis Lapangan | Nama Pembooking\t| Tanggal\t | Durasi | Total Harga\t ");
	if (newnode != NULL)
	{
		printf("\n| %-14s | %-18s | %-12s | %d Jam | Rp. %d ", newnode->jenisLapangan, newnode->namaBooking, newnode->tanggal, newnode->durasi, newnode->price);
		showPreOrder(newnode->left);
		showPreOrder(newnode->right);
	}
}

void showInOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		showInOrder(newnode->left);
		printf("\n| %-14s | %-18s | %-12s | %d Jam | Rp. %d ", newnode->jenisLapangan, newnode->namaBooking, newnode->tanggal, newnode->durasi, newnode->price);
		showInOrder(newnode->right);
	}
}

void showPostOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		showPreOrder(newnode->left);
		showPreOrder(newnode->right);
		printf("\n| %-14s | %-18s | %-12s | %d Jam | Rp. %d ", newnode->jenisLapangan, newnode->namaBooking, newnode->tanggal, newnode->durasi, newnode->price);
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
			printf("showPreOrder  : ");
			showPreOrder(root);
			printf("\showInOrder   : ");
			showInOrder(root);
			printf("\nshowPostorder : ");
			showPostOrder(root);
		};
		main();
		break;

	case 2:
		showListPrice();
		main();
		break;

	case 3:
		addField();
		main();
		break;

	case 4:
		break;
	}
}
