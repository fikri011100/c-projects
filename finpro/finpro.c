#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 4

char code[4];

struct Node
{
	char jenisLapangan[20];
	char namaBooking[18];
	char orderCode[4];
	char tanggal[3];
	char bulan[3];
	char tahun[4];
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
	printf("4. Edit Pesanan\n");
	printf("5. Exit \n\n");
}

void showListPrice()
{
	printf("\n===========List Harga Booking============\n");
	printf("_________________________________________\n");
	printf("No | Jenis Lapangan      | Harga Per-Jam\n");
	printf("=========================================\n");
	printf("1. | Lapangan Futsal     | Rp. 60.000 	 \n");
	printf("2. | Lapangan Basket     | Rp. 80.000 	 \n");
	printf("3. | Lapangan Badminton  | Rp. 100.000	 \n\n");
}

void addField()
{
	char tanggal[12];
	int a, fieldCode, duration;
	char dd[3];
	char mm[3];
	char yyyy[4];
	struct Node *Y;
	struct Node *temp;

	Y = (struct Node *)malloc(sizeof(struct Node));
	showListPrice();

	do
	{
		printf("Input Order Code [1-9][0-9][0-9] : ");
		scanf("%s", &Y->orderCode);
		fflush(stdin);
		a = strlen(Y->orderCode);
	} while (a < 1 || a > 3);

	printf("Input Field Code : ");
	scanf("%d", &fieldCode);
	fflush(stdin);

	printf("Input Nama Pembooking : ");
	scanf("%s", &Y->namaBooking);
	fflush(stdin);

	printf("Input Tanggal [dd] : ");
	scanf("%s", &Y->tanggal);
	fflush(stdin);

	printf("Input Bulan [MM] : ");
	scanf("%s", &Y->bulan);
	fflush(stdin);

	printf("Input Tahun [yyyy] : ");
	scanf("%s", &Y->tahun);
	fflush(stdin);

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

void scan(struct Node *root, char *check)
{

	struct Node *newnode;

	while (1)
	{
		if (strcmp(check, newnode->orderCode) < 0)
		{
			scan(root->left, check);
		}
		else if (strcmp(check, newnode->orderCode) > 0)
		{
			scan(root->right, check);
		}
		else
		{
			break;
		}
	}
}

struct Node *minValueNode(struct Node *node)
{
	struct Node *current = node;
	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

void editField(struct Node *root)
{
	if (strcmp(root->orderCode, code) != 0)
	{
		editField(root->left);
		editField(root->right);
		printf("\nOrder Code not Found\n");
	}
	else if (strcmp(root->orderCode, code) == 0)
	{
		int hasil, durasi;
		char name[20], tgl[2], bulan[2], tahun[4];
		printf("______________________________________________________________________________\n\n");
		printf("| Jenis Lapangan     | Nama Pembooking\t  | Tanggal    | Durasi | Total Harga\t \n");
		printf("|______________________________________________________________________________\n");
		printf("\n| %-18s | %-18s | %-2s/%2s/%s | %d Jam  | Rp. %d ", root->jenisLapangan, root->namaBooking, root->tanggal, root->bulan, root->tahun, root->durasi, root->price);
		printf("\n\nInput new Name Order : ");
		scanf("%s", &name);
		strcpy(root->namaBooking, name);
		printf("\nInput new Date [dd] : ");
		scanf("%s", &tgl);
		strcpy(root->tanggal, tgl);
		printf("\nInput new Month [MM] : ");
		scanf("%s", &bulan);
		strcpy(root->bulan, bulan);
		printf("\nInput new Year [yyyy] : ");
		scanf("%s", &tahun);
		strcpy(root->tahun, tahun);
		printf("\nInput new Duration : ");
		scanf("%d", &durasi);
		root->durasi = durasi;
		if (strcmp(root->jenisLapangan, "Lapangan Futsal") == 0)
		{
			root->price = durasi * 60000;
			root->durasi = durasi;
		}
		else if (strcmp(root->jenisLapangan, "Lapangan Basket") == 0)
		{
			root->price = durasi * 80000;
			root->durasi = durasi;
		}
		else if (strcmp(root->jenisLapangan, "Lapangan Badminton") == 0)
		{
			root->price = durasi * 100000;
			root->durasi = durasi;
		}
		printf("\n\n--- Update Order Data Success ---");
	}
}

void showPreOrder(struct Node *newnode)
{
	if (newnode != NULL)
	{
		printf("\n| %-18s | %-18s | %-2s/%2s/%s | %d Jam  | Rp. %d ", newnode->jenisLapangan, newnode->namaBooking, newnode->tanggal, newnode->bulan, newnode->tahun, newnode->durasi, newnode->price);
		showPreOrder(newnode->left);
		showPreOrder(newnode->right);
	}
}

void showInOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		showInOrder(newnode->left);
		printf("\n| %-18s | %-18s | %-2s/%2s/%s | %d Jam  | Rp. %d ", newnode->jenisLapangan, newnode->namaBooking, newnode->tanggal, newnode->bulan, newnode->tahun, newnode->durasi, newnode->price);
		showInOrder(newnode->right);
	}
}

void showPostOrder(struct Node *newnode)
{

	if (newnode != NULL)
	{
		showPreOrder(newnode->left);
		showPreOrder(newnode->right);
		printf("\n| %-18s | %-18s | %-2s/%2s/%s | %d Jam  | Rp. %d ", newnode->jenisLapangan, newnode->namaBooking, newnode->tanggal, newnode->bulan, newnode->tahun, newnode->durasi, newnode->price);
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
			printf("\n====List Booking Anda=====\n");
			printf("__________________________________________________________\n");
			printf("| Jenis Lapangan     | Nama Pembooking\t  | Tanggal    | Durasi | Total Harga\t \n");
			printf("______________________________________________________________________________\n");
			printf("\nPreOrder  : ");
			showPreOrder(root);
			printf("\nInOrder   : ");
			showInOrder(root);
			printf("\nPostorder : ");
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
		printf("Input Order Code : ");
		scanf("%s", &code);
		editField(root);
		main();
		break;

	case 5:
		break;
	}
}