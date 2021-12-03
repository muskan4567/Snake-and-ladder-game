#include<stdio.h>
#include<conio.h>
int dice=0,p1=0,p2=0,turn=1,r1=1,r2=1;
int ladder[100]={0};
int snake[100]={0};
void snakeandladderboard()
{
     printf("\n---------SNAKE AND LADDER BOARD-----------");
	printf("\n||100 99 98 97 96 95 94 93 92 91||");
	printf("\n||81  82 83 84 85 86 87 88 89 90||");
	printf("\n||80  79 78 77 76 75 74 73 72 71||");
	printf("\n||61  62 63 64 65 66 67 68 69 70||");
	printf("\n||60  59 58 57 56 55 54 53 52 51||");
	printf("\n||41  42 43 44 45 46 47 48 49 50||");
	printf("\n||40  39 38 37 36 35 34 33 32 31||");
	printf("\n||21  22 23 24 25 26 27 28 29 30||");
	printf("\n||20  19 18 17 16 14 15 13 12 11||");
	printf("\n||1   2  3  4  5  6  7  8  9  10||");
	printf("\n----------SNAKE AND LADDER POINTS----------");
	printf("\nLADDER AT 1  GOES TO 38           SNAKE AT 17 COMES TO 7");
	printf("\nLADDER AT 4  GOES TO 14           SNAKE AT 54 COMES TO 34");
	printf("\nLADDER AT 9  GOES TO 31           SNAKE AT 62 COMES TO 18");
	printf("\nLADDER AT 21 GOES TO 42           SNAKE AT 64 COMES TO 60");
	printf("\nLADDER AT 28 GOES TO 84           SNAKE AT 87 COMES TO 36");
	printf("\nLADDER AT 51 GOES TO 67           SNAKE AT 93 COMES TO 73");
	printf("\nLADDER AT 72 GOES TO 91           SNAKE AT 95 COMES TO 75");
	printf("\nLADDER AT 80 GOES TO 99           SNAKE AT 98 COMES TO 79");
}
void readtherule(void)
{
	printf("\n----THE RULES ARE----");
	printf("\n1.Roll the dice alternatively starting from player 1.");
	printf("\n2.It is necessary to get either '1' or '6' in first roll of dice.");
	printf("\n3.If the number on dice is '6' then one extra chance will be given to that player.");
	printf("\n4.If three consecutive '6' comes than the score will be same as previous and chance goes to next player.");
	printf("\n5.If the number pointing to snake then score will get decremented.");
	printf("\n5.If the number pointing to ladder then score will get incremented.");
	printf("\n6.Continue this until one person get 100.");
	printf("\n7.Print the score of both player and also print the number of time dice was rolled by players.");
	printf("\n7.If both player are at 100 then player with less no. of dice roll will win.");
	printf("\n8.If both player have rolled the dice equal number of times than declare it a DRAW");
	printf("\n9.If rule 7 is not true than simply that player will be winner who is at 100.");
}
int checkdice(int *m,int *n)
{
	int x=1,rollcount=*n;
	do
	{
		printf("\nYOU GOT '6' SO ONE MORE CHANCE:-ROLL THE DICE\n");
		scanf("%d",&dice);
		rollcount++;
		if(dice==6)
		x++;
		*m+=dice;
		printf("You got %d and now you are at %d",dice,*m);
		if(x==3)
		{
		printf("\nYOU GOT THREE CONSECUTIVE '6' SO SCORE WILL REMAIN SAME");	
		*m = *m-18;
		break;
	    }
	}while(dice==6);
	*n = rollcount;
	return *m;
}
int checkposition(int n)
{
	int res = n;
	if(ladder[n]!=0)
	{
		printf("\nCongrats You landed on ladder and it goes to position %d",ladder[n]);
		res = ladder[n];
	}
	else if(snake[n]!=0)
	{
		printf("\nSorry you landed on snake and it comes back to postition %d",snake[n]);
		res = snake[n];
	}
	else
	printf("\nYou landed on normal position,neither snake nor ladder hence on same position %d",n);
	return res;
}
int main()
{
	ladder[1]=38; ladder[4]=14; ladder[9]=31; ladder[21]=42; ladder[28]=84; ladder[51]=67; ladder[72]=91; ladder[80]=99;
snake[17]=7; snake[54]=34; snake[62]=18; snake[64]=60; snake[87]=36; snake[93]=73; snake[95]=75; snake[98]=79;	
	int select,c;
	printf("----------SNAKE AND LADDER GAME----------");
	printf("\nIf you want to read the rule then enter '1'");
	scanf("%d",&select);
	if(select==1)
	{
		printf("You have entered 1 to read the rules first.");
		readtherule();
		printf("\n YOU HAVE READ THE RULES!!");
	}
	else
	printf("You have entered %d so you cant read the rules,move further .",select);
	printf("\n\nIf you want to see the snake and ladder board then enter '2'");
	scanf("%d",&c);
	if(c==2)
	{
		printf("You have entered 2 to see the game board");
		snakeandladderboard();
		printf("\nYou have seen the board");
	}
	else
	printf("You have entered %d so you cant see the board,now start playing the game",c);
	printf("\n-------------------------------GAME START-------------------------------");
	do
	{
		if(turn==1)
		printf("\n\nPlayer 1 turn,so roll the dice");
		else
		printf("\n\nPlayer 2 turn,so roll the dice");
		scanf("%d",&dice);
		if(dice>6)
		{
			printf("you have entered wrong dice number,it should be from 1 to 6,roll again");
			continue;
		}
		printf("the number on dice is:%d",dice);
		switch(turn)
		{
			case 1:
				if(r1==1 &&(dice!=1 && dice!=6))
				{
					turn++;
					printf("\nYou should get '1' or '6' in first turn.");
					continue;
				}
				else
				{
					r1++;
					printf("\nYou were at %d and now you get %d,so you are at %d",p1,dice,p1+dice);
					p1+=dice;
					if(dice==6)
					p1 = checkdice(&p1,&r1);
					p1 = checkposition(p1);
					printf("\nPlayer1, you are at position:%d",p1);
					turn++;
				}
				break;
			case 2:
				if(r2==1 &&(dice!=1 && dice!=6))
				{
					turn=turn-1;
					printf("You should get '1' or '6' in first turn.");
					continue;
				}
				else
				{
					r2++;
					printf("\nYou were at %d and now you get %d,so you are at %d",p2,dice,p2+dice);
					p2+=dice;
					if(dice==6)
					p2 = checkdice(&p2,&r2);
					p2 = checkposition(p2);
					printf("\nPlayer2, you are at position:%d",p2);
					turn--;
				}
				break;
			default:
				printf("\nyou have entered wrong choice,try again please");
		}
	}while(p1<100 && p2<100);
	printf("\nScore of player 1:%d in total %d chance.\nScore of player 2:%d in total %d chance.",p1,r1,p2,r2);
	if(p1>=100 && p2<100)
	printf("\n\n--------PLAYER 1 WON THE GAME!CONGRATULATIONS---------");
	else if(p2>=100 && p1<100)
	printf("\n\n--------PLAYER 2 WON THE GAME!CONGRATULATIONS---------");
	else
	{
		printf("\n\nBoth players are at 100 so the player with less no. of dice roll will win the game.");
		if(r1<r2)
		printf("\nPlayer1 rolled the dice less no. of times than player2,so\n\n---------Player 1 won the game---------");
		else if(r2<r1)
		printf("\nPlayer2 rolled the dice less no. of times than player1,so\n\n---------Player 2 won the game---------");
		else
		printf("\nr1 and r2 are equal,so\n\n-------------MATCH DRAW---------------");
	}
	return 0;
}
