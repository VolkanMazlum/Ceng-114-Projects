#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
int menu(void);                                                                          //This function is menu.
int CreateDice(void);                                                                   //This function for taking dice.
int Brick(void);                                                                       //This is main function for taking brick.
int CreateBrick(void);                                                                //This function is taking brick.
int TakingControl(char x, char y);                                                   // Controling The colors are similar or different.
char CreateChar(void);
int Dice(void);
int main(void)
{
	int counterBrick=0, counterDice=0;
	char ch=0;
	while (ch !=3)
	{
		ch = menu();
		if (ch == 1)
			counterBrick = counterBrick+ Brick();                                                                  //to show how much player has earned
		else if (ch == 2)
			counterDice = counterDice + Dice();
		else if (ch == 3)
			break;
		else
			ch = 0;
	}
	printf("Bye\n");
	printf("You won %d times brick games and %d times Dice games", counterBrick, counterDice);                    //Showing how much win in both of games.
	return(0);

}
int menu(void)
{
	int ch;
	printf("--------------------------------------------------------------------------------------------\nWELCOME to TIPTOP GAME PLATFORM\n--------------------------------------------------------------------------------------------\n1. Play the Brick Game\n2. Play the Dice Game\n3. Exit\nChoose what to do (1, 2, 3):");
	scanf_s("%d",&ch);
	return(ch);
}
int Dice(void)
{
	int zar1=0,zar2=0,counterwin=0,counter=1,value=0,m=0;
	srand(time(NULL));
	printf("***** Welcome to Dice Game ******\n");
	while (m!= 12)                                                                                             //For stoping, while 12 is occured.
	{
		zar1 = CreateDice();
		zar2 = CreateDice();
		printf("Dices thrown: %d %d \n", zar1, zar2);
		m = zar1 + zar2;                                                                                       //For while
		if (zar1 + zar2 == 7 || zar1 + zar2 == 11)                                                            //These if statements are for continuing.
		{
			printf("You won the game.\n");
			counterwin++;
		}
		else if (zar1 + zar2 == 4 || zar1 + zar2 == 5)
		{
			zar1 = CreateDice();
			zar2 = CreateDice();
			value = zar1 + zar2;                                                                               //For comparing values to earn 7 chances.
			printf("Dices thrown: %d %d \n", zar1, zar2);
			counter++;
			printf("You have 7 chances for get %d\n", value);
			while (counter <= 7)
			{
				zar1 = CreateDice();
				zar2 = CreateDice();
				printf("Dices thrown: %d %d \n", zar1, zar2);
				counter++;                                                                                    //While counter is equal 7, player's chances will end. 
				if (zar1 + zar2 == value)
					counterwin++;
				else if (zar1 + zar2 == 7)                                                                   //If it is equal, game will end.
				{
					printf("You lost the game.\n");
					return(counterwin);
				}
			}
			if (value != zar1 + zar2)                                                                       //If it is not equal, game will end.
			{
				printf("You lost the game.\n");
				return(counterwin);
			}
		}
		else if (zar1 + zar2 == 6 || zar1 + zar2 == 8)
		{
			zar1 = CreateDice();
			zar2 = CreateDice();
			value = zar1 + zar2;
			printf("Dices thrown: %d %d \n", zar1, zar2);
			counter++;
			printf("You have 7 chances for get %d\n", value);                                              //7 tane zar atma hakký verildikten sonra atýlan ilk zar
			while (counter <= 7)
			{
				zar1 = CreateDice();
				zar2 = CreateDice();
				printf("Dices thrown: %d %d \n", zar1, zar2);
				counter++;
				if (zar1 + zar2 == value)
					counterwin++;
				else if (zar1 + zar2 == 7)
					return(counterwin);
			}
			if (value != zar1 + zar2)
				return(counterwin);
		}
		else if (zar1 + zar2 == 9 || zar1 + zar2 == 10)
		{

			zar1 = CreateDice();                                                                             //7 tane zar atma hakký verildikten sonra atýlan ilk zar
			zar2 = CreateDice();
			value = zar1 + zar2;
			printf("Dices thrown: %d %d \n", zar1, zar2);
			counter++;
			printf("You have 7 changes to get %d\n", value);
			while (counter <= 7)                                                                            //To check the given number right.
			{
				zar1 = CreateDice();
				zar2 = CreateDice();
				printf("Dices thrown: %d %d \n", zar1, zar2);
				counter++;
				if (zar1 + zar2 == value)
					counterwin++;
				else if (zar1 + zar2 == 7)
					return(counterwin);
			}
			if (value != zar1 + zar2)
				return(counterwin);
		}
		else if (zar1 == 2 && zar2 == 3)                                                                    //If this statement is true, game will end.
			return(counterwin);
		else if (zar1 == 1 && zar2 == 1)
			return(counterwin);
		else if (zar1 == 2 && zar2 == 1)
			return(counterwin);
		else if (zar1 == 6 && zar2 == 6)
			return(counterwin);
	}
	m = 0;
	return(counterwin);
}
int CreateDice(void)
{
	int zar;
	zar = 1 + rand() % 6;                                                                                   //To get a random number.
	return(zar);
}
int Brick(void)
{
	
	int Brick1, Brick2,value=0,counterwin=0, counterBrick=0,control=1,number=0;
	char Color1,Color2;
	printf("***** Welcome to Brick Game ****** \n");
	while (control == 1)                                                                                    //To continue the game.
	{
		Brick1 = CreateBrick();
		counterBrick++;                                                                                     //To show how much Brick taking.
		Brick2 = CreateBrick();
		counterBrick++;
		Color1 = CreateChar();
		Color2 = CreateChar();
		number = TakingControl(Color1,Color2);                                                              // Controling The colors are similar or different.
		if (number == 1)
			printf("They are similar colors.\n");
		else
			printf("They are not similar colors.\n");
		printf("Two bricks are created:\n");
		printf("Brick1:color: %c point: %d\n", Color1, Brick1);
		printf("Brick2:color: %c point: %d\n", Color2, Brick2);
		if (Color1 == Color2)
		{
			printf("You gained %d points.\n", Brick1 + Brick2);
			value = value + Brick1 + Brick2;
		}
		else if (Color1 == 'Y' && Color2 == 'R')
		{
			printf("You gained %d points.\n", (Brick1 + Brick2) / 2);
			value = value + (Brick1 + Brick2) / 2;
		}
		else if (Color1 == 'R' && Color2 == 'Y')
		{
			printf("You gained %d points.\n", (Brick1 + Brick2) / 2);
			value = value + (Brick1 + Brick2) / 2;
			counterwin++;
		}
		else if (abs(Brick1 - Brick2) == 2)                                                                   //For the end of the game.
		{
			if (Color1 != Color2)                                                                             //Some situations that have to happen for the game to end.
			{
				printf("End of the game.\n");
				printf("Total score: %d\n", value);
				printf("%d bricks are created Bye! \n", counterBrick);
				counterwin++;
				return(counterwin);
			}
		}
		else
		{
			printf("No point gained.\n");
		}
	}
}
int CreateBrick(void)
{
	int Brick;
	Brick= rand() % 10;                                                                                       //For taking a random number between 1 and 3.
	return(Brick);
}
char CreateChar(void)
{
	int color;
	char color1;
	color= 1 + rand() % 3;                                                                                    //For taking a random color.
	if (color == 1)
	{
		color1 = 'Y';
		return(color1);
	}
	else if (color == 2)
	{
		color1 = 'B';
		return(color1);
	}
	else if (color == 3)
	{
		color1 = 'R';
		return(color1);
	}
}
int TakingControl(char x, char y)                                                                             //For controlling the color is similar or different.
{
	if (x == y)
		return(1);
	else
		return(0);
}