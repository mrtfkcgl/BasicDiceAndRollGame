#ifndef       	__DICE_DRIVER__
#define 	 	__DICE_DRIVER__


#define  FAIL 				   0
#define  DIGITOK		       1
#define  DIGITNOK			   0


enum MenuPlace
{
		BaseMenu,
		PlayMenu,
		StopMenu,
		LearnGameMenu,
		AboutGameMenu
};

int  RollDice(void);
void  ArrangeRandomSeed(void);


void Delay(int milli_seconds);
void LoadingPipes(int LoadingPipeTime);
void CleanInputBuffer(void);

void playGame(void);
int TakeGuesNumber(void);
void clearInputFromEnter(void);




#endif
