#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <time.h>


#define ArrayLength(array) (sizeof(array)/sizeof(*(array)))
enum MenuPlace
{
		BaseMenu,
		PlayMenu,
		StopMenu,
		LearnGameMenu,
		AboutGameMenu
};

void delay(int milli_seconds)
{
clock_t start_time = clock();
while (clock() < start_time + milli_seconds) ;
}

/*
	Show some pipes to screen to give user info about loading value

	Screen bug will fix other versions
*/
void loading_pipes(int LoadingPipeTime)
{

	printf("=    %% %d\r",20U);
	delay(LoadingPipeTime);
	printf("== %% %d\r",40U);
	delay(LoadingPipeTime);
	printf("===    %% %d\r",50U);
	delay(LoadingPipeTime);
	printf("====    %% %d\r",60U);
	delay(LoadingPipeTime);
	printf("=====   %% %d\r",80U);
	delay(LoadingPipeTime);
	printf("======  %% %d\r",100U);
	delay(LoadingPipeTime);

}
int Menu_System(int comingCharValue,enum MenuPlace MenuStatus)
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
					Menu_System('p',PlayMenu);
					break;
				case 'h':
					Menu_System('h',LearnGameMenu);
					break;
				case 'a':
					Menu_System('a',AboutGameMenu);
					break;
				}
			}
			else
				return 0;

		break;

	case PlayMenu:
		printf("Play menu pressed \r\n");
		printf("Game Starting...\n");
		printf("------\n");

		break;

	case StopMenu:


		break;

	case LearnGameMenu:

				printf("Learn menu pressed \r\n");
				printf("Simple dice and roll game you make guess and play...\n");
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

void Clean_Input_Buffer(void)
{
		int c;
	while( (c = getchar()) != '\n' ||( c != EOF) )
		;

}
int main()
{

	int ch = 0;
	printf("Please Waiting Game is Loading ...\r\n");
	loading_pipes(200);

begin:

	printf(" ----- Welcom The Dice And Roll Game -----\n\r");
	printf("-- Menu --\r\n"
			"- To play Press        (P) \r\n"
			"- To Learn Game Press  (H) \r\n"
			"- About Game Press     (A)    \r\n"
			);
	while(ch = getchar())
	{
		ch = tolower(ch);
		if(ch == 'p')
			{Menu_System( ch,PlayMenu);
			goto end;
			}
		else if ( ch == 'h')
			{Menu_System( ch,LearnGameMenu);
			goto end;
			}
		else if(ch == 'a')
			{
				Menu_System( ch, AboutGameMenu );
				goto end;
			}
		else
		{
		  printf("Invalid input :/ \n\r");

		  ch = 0;
		  	fseek(stdin,0,SEEK_END);
		  goto begin;

		}

	}
	end:
		printf("\nGOODBYE...\n");













    return 0;
}

