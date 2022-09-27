#include <stdio.h>
char Customer(int countera, int counterb, int Money);
int main(void)
{
	char ch = '0', countera = 0, counterb = 0, Money = 0;
	int m, n;
	printf("------>Welcome to ABC Cinema<-------");
	printf("->Choose user:\n1. Admin \n2. Customer\n");
	scanf_s("%c", &ch);
	while (ch != '5')
	{
		if (ch == '2')
			ch = Customer(int(countera), int(counterb), int(Money));
		else if (ch == '1')                                                                                                   // First choosing admin, everthing is 0, because any information has not stored yet.I wrote this statement because of that.
		{
			printf("Category A: 0 \n ");
			printf("Category B: 0  \n");
			printf("Category A: Reservation :0 \n");
			printf("Category B : Reeservation :0 \n");
			printf("Category A and Category B: amount of sold tickets :0 \n");
			printf("->Choose user:\n1. Admin \n2. Customer\n");
			scanf_s(" %c", &ch);

		}

	}
	printf("Thank you for choosing our movie theater.\n");
	return(0);
}

char Customer(int countera, int counterb, int Money)                                                                                       // For finding information
{
	int num, rowa = 1, rowb = 1, refund, m, n;
	char ch2 = '0', Seat, ch3;
	while (ch2 != 5)
	{
		printf("->Choose your request:\n1. Book seats\n2. Check availability\n3. Switch \n4.Cancel the Ticket\n5. Exit\n");               //It is a chart for choice
		scanf_s(" %c", &ch2);
		switch (ch2)
		{
		case '1':
		{
			printf("\nHow many tickets do you want? ");
			scanf_s(" %d", &num);
			printf("\nWhich category A or B?");
			scanf_s(" %c", &Seat);
			if (countera >= 10 && countera < 11)                                                                                                             //If it is passed 10, row will increase and it will look like in other line.
				rowa++;
			else if (countera >= 20 && countera < 21)
				rowa++;
			else if (countera >= 30 && countera < 31)
				rowa++;
			else if (countera >= 40 && countera < 41)
				rowa++;
			if (counterb >= 10 && counterb<11)
				rowb++;
			else if (counterb >= 20 && counterb < 21)
				rowb++;
			else if (counterb >= 30 && counterb < 31)
				rowb++;
			else if (counterb >= 40 && counterb < 41)
				rowb++;

			if (Seat == 'A')
			{
				countera = countera + num;
				m = num * 30;
				printf("You  should pay %d from %d row", m, rowa);
				Money = Money + m;
				
			}

			else
			{
				counterb = counterb + num;
				n = num * 20;
				printf("You should pay %d from %d row", n, rowb);
				Money = Money + n;
				
			}
			break;
		}
		case'2':
		{
			printf("Category A: Available seats: %d \nCategory B : Available seats : %d\n", 50 - countera, 50 - counterb);
			break;
		}
		case '3':
		{
			printf(">Choose user:\n 1. Admin\n2. Customer");
			scanf_s(" %c", &ch2);
			ch3 = ch2;
			while (ch3 != '5')                                                                                                         //For choosing admin, I wrote this statement in there.
			{
				printf("For admin following menu will be shown:\n1. Check availability\n2. Show number of reservations\n3. Check gross revenue\n4. Switch Role\n5. Exit\n->Choose your request :");
				scanf_s(" %c", &ch3);
				switch (ch3)
				{
				case '1':
				{
					printf("Category A:%d\n ", 50 - countera);
					printf("Category B:%d \n", 50 - counterb);
					break;
				}
				case'2':
				{
					printf("\nCategory A: Reservation :%d \n", countera);
					printf("\nCategory B : Reeservation :%d \n", counterb);
					break;
				}
				case'3':
				{
					printf("\nCategory A and Category B: amount of sold tickets :%d \n", Money);
					break;

				}
				case'4':
				{
					printf("\nChoose user: \n1. Admin \n2. Customer");
					scanf_s(" %c", &ch3);
					if (ch3 == '2')
						ch3 = '5';                                                                                             // For return to the Customer function
					break;
				}
				case'5':
				{
					return(ch3);                                                                                                 //To return to the main function.

				}
				}
			}
			break;
		}
		case '4':
		{
			printf("\nHow many ticket will you give back?");                                                              //For finding money which the customer want back.
			scanf_s(" %d", &refund);
			printf("\nWhich category A or B?");
			scanf_s(" %c", &Seat);
			if (Seat == 'A')
			{
				printf("Money that repay is %d ", refund * 30);
				countera = countera - refund;
			}
			else
			{
				printf("Money that repay is ", refund * 20);
				counterb = counterb - refund;
			}
			break;
		}
		case'5':
			return(ch2);                                                                                                       //To return to the main function
			break;

		}


	}
	return(ch2);
}