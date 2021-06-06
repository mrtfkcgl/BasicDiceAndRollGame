#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <time.h>
#include"DiceDrivers.h"

#define ArrayLength(array) (sizeof(array)/sizeof(*(array)))

int main()
{

	int ch = 0;
	printf("Please Waiting Game is Loading ...\r\n");
	LoadingPipes(500);


begin:

	printf(" ----- Welcom The Dice And Roll Game -----\n\r");
	printf("-- Menu --\r\n"
			"- To play Press        (P) \r\n"
			"- To Learn Game Press  (H) \r\n"
			"- About Game Press     (A)    \r\n"
			);
	while((ch = getchar()))
	{
		ch = tolower(ch);
		if(ch == 'p')
			{
				MenuSystem( ch,PlayMenu);
				goto end;
			}
		else if ( ch == 'h')
			{MenuSystem( ch,LearnGameMenu);
			goto end;
			}
		else if(ch == 'a')
			{
				MenuSystem( ch, AboutGameMenu );
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

