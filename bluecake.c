
//Object Struct
struct Cake
{
  char code[6];
  char name[21];
  int stock;
  int price;
};
//variables
int inMenu;
struct Cake Products[100];
int prodIndex;
char inCode[6];
int inQuantity;
bool isInCodeOk;
bool isInQuaOk;
bool isStockOk;
//functions
void Enter(int iEnter)
{
  for (int a = 0; a < iEnter; a++)
  {
    printf("\n");
  }
}
void initCake()
{
  strcpy(Products[0].code, "CK001");
  strcpy(Products[0].name, "Blueberry Cake");
  Products[0].stock = 10;
  Products[0].price = 25000;
  strcpy(Products[1].code, "CK009");
  strcpy(Products[1].name, "Chocochip Cake");
  Products[1].stock = 5;
  Products[1].price = 20000;
  strcpy(Products[2].code, "CK017");
  strcpy(Products[2].name, "Mayoinase Cake");
  Products[2].stock = 12;
  Products[2].price = 30000;
  strcpy(Products[3].code, "CK023");
  strcpy(Products[3].name, "Strowberry ShortCake");
  Products[3].stock = 7;
  Products[3].price = 17500;
}
void showCake()
{
  printf("BLUE CAKE SHOP CASHIER\n");
  printf("======================\n\n");
  printf("No. | Cake Code | Cake Name | Available | Price\n");
  printf("--------------------------------------------------------------\n");
  for (int a = 0; a < 4; a++)
  {
    printf("0%d. | %5s | %-20s | %9d | Rp. %d \n", a + 1, Products[a].code, Products[a].name, Products[a].stock, Products[a].price);
  }
  printf("--------------------------------------------------------------\n");
}
void Menu()
{
  printf("\nMenu :\n");
  printf("1. Sell\n");
  printf("2. Add stock\n");
  printf("3. Exit\n");
  printf("Input Choice : ");
  scanf("%d", &inMenu);
  fflush(stdin);
}
void Sell()
{
  isStockOk = true;
  do
  {
    isInCodeOk = false;
    printf("\nInput Cake Code [5 Char] : ");
    scanf("%[^\n]", &inCode);
    fflush(stdin);
    for (int a = 0; a < 4; a++)
    {
      if (strcmp(Products[a].code, inCode) == 0)
      {
        isInCodeOk = true;
        prodIndex = a;
        if (Products[prodIndex].stock == 0)
        {
          isStockOk = false;
          printf("\n\nStock Habis Bro!!");
          getchar();
        }
      }
    }
    if (isInCodeOk == false)
    {
      printf("\nThe Cake Code doesn't exist\n");
    }
  } while (isInCodeOk == false);
  if (isStockOk == true)
  {
    do
    {
      isInQuaOk = true;
      printf("Input Quantity [0..%d] : ", Products[prodIndex].stock);
      scanf("%d", &inQuantity);
      fflush(stdin);
      if (inQuantity < 0 || inQuantity > Products[prodIndex].stock)
      {
        isInQuaOk = false;
      }
    } while (isInQuaOk == false);

    printf("\n\nTotal price is : Rp %d,- x %d = Rp %d,-\n\n", Products[prodIndex].price, inQuantity, (inQuantity * Products[prodIndex].price));
    Products[prodIndex].stock -= inQuantity;
    printf("\n--- Matur Nuwun ---");
    getchar();
  }
}
void Stock()
{
  do
  {
    isInCodeOk = false;
    printf("\nInput Cake Code [5 Char] : ");
    scanf("%[^\n]", &inCode);
    fflush(stdin);
    for (int a = 0; a < 4; a++)
    {
      if (strcmp(Products[a].code, inCode) == 0)
      {
        isInCodeOk = true;
        prodIndex = a;
      }
    }
    if (isInCodeOk == false)
    {
      printf("\nThe Cake Code doesn't exist\n");
    }
  } while (isInCodeOk == false);
  do
  {
    isInQuaOk = true;
    printf("Input Quantity [0..10] : ", Products[prodIndex].stock);
    scanf("%d", &inQuantity);
    fflush(stdin);
    if (inQuantity < 0 || inQuantity > 10)
    {
      isInQuaOk = false;
    }
  } while (isInQuaOk == false);
  Products[prodIndex].stock += inQuantity;
  printf("\n--- Adding Stock Success ---");
  getchar();
}

int main()
{
  initCake();
  do
  {
    Enter(25);
    showCake();
    Menu();
    switch (inMenu)
    {
    case 1:
    {
      Sell();
      break;
    }
    case 2:
    {
      Stock();
      break;
    }
    }
  } while (inMenu != 3);
}
