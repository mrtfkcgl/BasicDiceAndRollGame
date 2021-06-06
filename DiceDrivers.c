#include "DiceDrivers.h"
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <time.h>

#define ArrayLength(array) (sizeof(array)/sizeof(*(array)))



void Delay(int milli_seconds)
{
clock_t start_time = clock();
while (clock() < start_time + milli_seconds) ;
}


void LoadingPipes(int LoadingPipeTime)
{

	printf("=    %% %d\r",5U);
	Delay(LoadingPipeTime);
	printf("=== %% %d\r",15U);
	Delay(LoadingPipeTime);
	printf("==========    %% %d\r",50U);
	Delay(LoadingPipeTime);
	printf("============    %% %d\r",60U);
	Delay(LoadingPipeTime);
	printf("================   %% %d\r",80U);
	Delay(LoadingPipeTime);
	printf("====================  %% %d\r",100U);
	Delay(LoadingPipeTime);

}


int MenuSystem(int comingCharValue,enum MenuPlace MenuStatus)
{
	int ValidOrNot  = 0;
	static const int Menu_Commands_Small[] = {
			'p',
			'h',
			'a',
		};
	int checkValue = tolower(comingCharValue);


	switch(MenuStatus)
	{
	case BaseMenu:
		for(int i = 0; i<ArrayLength(Menu_Commands_Small); ++i)
			if(Menu_Commands_Small[i] == checkValue)
			{
				switch(checkValue)
				{
				case 'p':
					MenuSystem('p',PlayMenu);
					break;
				case 'h':
					MenuSystem('h',LearnGameMenu);
					break;
				case 'a':
					MenuSystem('a',AboutGameMenu);
					break;
				}
			}
			else return 0;

		break;

	case PlayMenu:

		printf("Play menu pressed \r\n");
		printf("Game Starting...\n");
		playGame();
		printf("------\n");
		break;

	case StopMenu:
		break;

	case LearnGameMenu:

				printf("Learn menu pressed \r\n\\n\n\n");
				printf("Simple dice and roll game you make guess and play...\n\n\n\n");
				printf("Enjoy the  game \r\n");
				printf("------\n");

		break;
	case AboutGameMenu:
				printf("Game has been created this time %s &s \n",__DATE__);
				printf("Enjoy the  game \r\n");
				printf("------\n");

		break;
	default :
		printf("Default happen\r\n");
	}

	return ValidOrNot;
}

void CleanInputBuffer(void)
{
		int c;
	while( (c = getchar()) != '\n' ||( c != EOF) )
		;

}

void ArrangeRandomSeed(void)
{
	srand(time(NULL));

}

int  RollDice(void)
{
	 ArrangeRandomSeed();
	printf("The dice are rolled .... \n");
 	return (rand()%6)+1;

}
void WarringDicePrediction()
{
	printf("The dice guess entered must be between 1 and 6 \n");
	printf("Please try new guess \n");
  (void) getchar();;
}

void playGame(void)
{

tryAgain:
	printf("let's guess \n");
	int GuessFromUser = TakeGuesNumber();

	if(GuessFromUser == FAIL)
	{
		WarringDicePrediction();
		goto tryAgain;
	}
	else
	{
		int Dice = RollDice();
		if(GuessFromUser == Dice)
			printf("WIN =) \n");
		else
		{
			printf("%d \n",Dice);
			printf("No, let's try again \n");
			goto tryAgain;
		}


	}

}


int TakeGuesNumber(void)
{
	int flagINPUT  = DIGITOK;
	char ch;
	(void) getchar();
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		if(flagINPUT)
		{
			flagINPUT = DIGITNOK;
			if(isdigit(ch))
			{
				int number = ch-'0';
				if(((number <7) && (number > 0)))
				{
					printf("number is %d\n",number);
					return number;
				}
			}
		}
	 }

	return FAIL;
}
