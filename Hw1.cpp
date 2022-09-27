#include <stdio.h>
void printMainMenu(void);
void updateStocks(void); 
void updatePrices(void);
void sell(void);
void addMoney(int y);
void printStockInformation(void);
int calculateBill(int x,int y);
int stockControl(int m,int n);
void printCashInfo(void);
void printProductPrices(void);
int RedTulip = 0, PinkTulip = 0, WhiteTulip = 0, YellowTulip = 0, BlackTulip = 0;                                        //To be able to assign value first
int RedTulipTl = 15, PinkTulipTl = 16, WhiteTulipTl = 17, YellowTulipTl = 18, BlackTulipTl = 30;
int Cash=0;
int main(void)
{
	int Operation=0;
	
	while (Operation != 6)
	{
		printMainMenu();
		printf("Select your operation :");
		scanf_s("%d", &Operation);
		switch (Operation)
		{
		case 1:
		{
			printStockInformation();
			break;
		}
		case 2:
		{
			updateStocks();
			break;
		}
		case 3:
		{
			updatePrices();
			break;
		}
		case 4:
		{
			sell();
			break;
		}
		case 5:
		{
			printCashInfo();
			break;
		}

		}
	}
}
void printMainMenu(void)
{
	printf("-OPERATIONS-\n1-Stock Info\n2-Update Stock\n3-Update Prices\n4-Sell\n5-Current Cash Info\n6-Quit\n");
}
void updateStocks(void)
{
	int Product, RedTulip1, PinkTulip1, WhiteTulip1, YellowTulip1, BlackTulip1,Operation=0;
	while (Operation != 2)
	{
		printf("Current Stock Information\n1-Red Tulip :%d\n2-Pink Tulip :%d\n3-White Tulip: %d\n4-Yellow Tulip: %d\n5-Black Tulip : %d\n", RedTulip, PinkTulip, WhiteTulip, YellowTulip, BlackTulip);
		printf("Select Product: ");
		scanf_s("%d", &Product);
		if (Product == 1)
		{
			printf("Enter stock for ‘Red Tulip’ product :");
			scanf_s("%d", &RedTulip1);                                                                                   //For enterring new stock.
			RedTulip = RedTulip + RedTulip1;

		}
		else if (Product == 2)
		{
			printf("Enter stock for ‘Pink Tulip’ product :");
			scanf_s("%d", &PinkTulip1);
			PinkTulip = PinkTulip + PinkTulip1;
		}
		else if (Product == 3)
		{
			printf("Enter stock for ‘White Tulip’ product :");
			scanf_s("%d", &WhiteTulip1);
			WhiteTulip = WhiteTulip + WhiteTulip1;
		}
		else if (Product == 4)
		{
			printf("Enter stock for ‘Yellow Tulip’ product :");
			scanf_s("%d", &YellowTulip1);
			YellowTulip = YellowTulip + YellowTulip1;
		}
		else if (Product == 5)
		{
			printf("Enter stock for ‘Black Tulip’ product :");
			scanf_s("%d", &BlackTulip1);
			BlackTulip = BlackTulip + BlackTulip1;
		}
		printf("Current Stock Information\n1-Red Tulip :%d\n2-Pink Tulip :%d\n3-White Tulip: %d\n4-Yellow Tulip: %d\n5-Black Tulip : %d\n", RedTulip, PinkTulip, WhiteTulip, YellowTulip, BlackTulip);
		printf("OPERATIONS :\n1. Continue update stock\n2. Return main menu");
		scanf_s("%d", &Operation);
	}
	
}
void updatePrices(void)
{
	int Product,Operation=0,RedTulipTl1=0,PinkTulipTl1=0,WhiteTulipTl1=0,YellowTulipTl1=0,BlackTulipTl1=0;
	while (Operation != 2)
	{
		printf("Prices :\n1. Red Tulip : %d TL\n2. Pink Tulip : %d TL\n3. White Tulip : %d TL\n4. Yellow Tulip : %d TL\n5. Black Tulip : %d TL\n",RedTulipTl,PinkTulipTl,WhiteTulipTl,YellowTulipTl,BlackTulipTl);
		printf("Select product:");
		scanf_s("%d", &Product);
		if (Product == 1)
		{
			printf("Enter new price for ‘Red Tulip’ product :");
			scanf_s("%d", &RedTulipTl1);                                                                                       //For taking the new price which is wanted.
			RedTulipTl = RedTulipTl1;
		}
		else if (Product == 2)
		{
			printf("Enter new price for ‘Pink Tulip’ product :");
			scanf_s("%d", &PinkTulipTl1);
			PinkTulipTl =  PinkTulipTl1;
		}
		else if (Product == 3)
		{
			printf("Enter new price for ‘White Tulip’ product :");
			scanf_s("%d", &WhiteTulipTl1);
			WhiteTulipTl = WhiteTulipTl1;
		}
		else if (Product == 4)
		{
			printf("Enter new price for ‘Yellow Tulip’ product :");
			scanf_s("%d", &YellowTulipTl1);
			YellowTulipTl =  YellowTulipTl1;
		}
		else if (Product == 5)
		{
			printf("Enter new price for ‘Black Tulip’ product :");
			scanf_s("%d", &BlackTulipTl1);
			BlackTulipTl =  BlackTulipTl1;
		}
		printf("Prices :\n1.Red Tulip : % d TL\n2.Pink Tulip : % d TL\n3.White Tulip : % d TL\n4.Yellow Tulip : % d TL\n5.Black Tulip : % d TL\n", RedTulipTl, PinkTulipTl, WhiteTulipTl,YellowTulipTl,BlackTulipTl);
		printf("OPERATIONS :\n1. Continue update price\n2. Return main menu");
		scanf_s("%d", &Operation);
	}
}
void sell(void)
{
	int Product,RedTulip1,PinkTulip1,WhiteTulip1,YellowTulip1,BlackTulip1,Cash1=0,Operation=0,return1;
	while (Operation != 2)
	{
		printf("Products :\n1. Red Tulip - %d  - (%dTL)\n2. Pink Tulip - %d - (%d TL )\n3. White Tulip - %d  - (%dTL)\n4. Yellow Tulip - %d  - (%d TL)\n5. Black Tulip - %d - (%d TL)",RedTulip,RedTulipTl,PinkTulip,PinkTulipTl,WhiteTulip,WhiteTulipTl,YellowTulip,YellowTulipTl,BlackTulip,BlackTulipTl);
		printf("Select Product:");
		scanf_s("%d", &Product);
		if (Product == 1)
		{
			printf("Enter how many sold ‘Red Tulip’ product :");
			scanf_s("%d", &RedTulip1);
			return1=stockControl(RedTulip1 ,RedTulip);
			if (return1==1)
			{
				RedTulip = RedTulip - RedTulip1;
				Cash1=calculateBill(RedTulip1,RedTulipTl);                                                            //For finding how much selling Red Tulip.
				addMoney(Cash1);
			}
			else
				printf("SORRY… ‘Red Tulip’ product out of stock.");                                                 //If there is no enough goods,this line is activated.

		}
		else if (Product == 2)
		{
			printf("Enter how many sold ‘Pink Tulip’ product :");
			scanf_s("%d", &PinkTulip1);
			return1 = stockControl(PinkTulip1, PinkTulip);
			if (return1==1)                                                                                         //For controlling  there are enough goods or no goods.
			{
				PinkTulip = PinkTulip - PinkTulip1;
				Cash1 = calculateBill(PinkTulip1, PinkTulipTl);
				addMoney(Cash1);
			}
			else
				printf("SORRY… ‘Pink Tulip’ product out of stock.");

		}
		else if (Product == 3)
		{
			printf("Enter how many sold ‘White Tulip’ product :");
			scanf_s("%d", &WhiteTulip1);
			return1 = stockControl(WhiteTulip1, WhiteTulip);
			if (return1==1)
			{				
				WhiteTulip = WhiteTulip - WhiteTulip1;
				Cash1 = calculateBill(WhiteTulip1, WhiteTulipTl);
				addMoney(Cash1);				
			}
			else
				printf("SORRY… ‘White Tulip’ product out of stock.");

		}
		else if (Product == 4)
		{
			printf("Enter how many sold ‘Yellow Tulip’ product :");
			scanf_s("%d", &YellowTulip1);
			return1 = stockControl(YellowTulip1, YellowTulip);
			if (return1==1)
			{
				YellowTulip = YellowTulip - YellowTulip1;
				Cash1 = calculateBill(YellowTulip1, YellowTulipTl);
				addMoney(Cash1);
			}
			else
				printf("SORRY… ‘Yellow Tulip’ product out of stock.");

		}
		else if (Product == 5)
		{
			printf("Enter how many sold ‘Black Tulip’ product :");
			scanf_s("%d", &BlackTulip1);
			return1 = stockControl(BlackTulip1, BlackTulip);
			if (return1==1)
			{
				BlackTulip = BlackTulip - BlackTulip1;
				Cash1 = calculateBill(BlackTulip1, BlackTulipTl);
				addMoney(Cash1);
			}
			else
				printf("SORRY… ‘Black Tulip’ product out of stock.");

		}
		printf("OPERATIONS :\n1. Continue selling\n2. Return main menu\n");
		printf("Select your operation :");
		scanf_s("%d", &Operation);
	}
}
void addMoney(int y)                                                                                      //For adding the money which is taken from selling.
{
	printf("Add %d TL to cash register.", y);
	Cash = Cash + y;
}
int calculateBill(int x,int y)                                                                           //For calculating the bills
{
	int Cash1;
	Cash1 = x * y;
	return(Cash1);
}
void printCashInfo(void)
{
	printf("Current cash information :%d\n", Cash);
}
int stockControl(int m, int n)
{
	if (m <= n)                                                                                          //For controlling the goods are enough or not enough.
		return(1);
	else
		return(0);
}
void printStockInformation(void)
{
	printf("Current Stock Information\n1-Red Tulip :%d\n2-Pink Tulip :%d\n3-White Tulip: %d\n4-Yellow Tulip: %d\n5-Black Tulip : %d\n", RedTulip, PinkTulip, WhiteTulip, YellowTulip, BlackTulip);
}
void printProductPrices(void)
{
	printf("Prices :\n1.Red Tulip : % d TL\n2.Pink Tulip : % d TL\n3.White Tulip : % d TL\n4.Yellow Tulip : % d TL\n5.Black Tulip : % d TL\n", RedTulipTl, PinkTulipTl, WhiteTulipTl, YellowTulipTl, BlackTulipTl);
}