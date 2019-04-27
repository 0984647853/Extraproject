#include<stdio.h>
#include"screen.h"
void barChart(int a[],int b[])
{
	int i, j; //counters
	setColors(CYAN, bg(BLACK));
	char letter;
	letter = 'A';
    	for(int i=0; i <26; i++)
	{
		printf("\033[%d;%dH",46,i*3);
		printf("%c ", letter);
		letter++;
	}
	int col = 45;
	for(i=0;i<26;i++){
		for(j=0;j<=a[i]/2;j++){
			printf("\033[%d;%dH",col-j,i*3);
#ifdef UNICODE		//conditional compilation
			printf("%s","\u2590");
			if((j==a[i]/(2))&&(j!=0))
				{
					printf("\033[%d;%dH",col-j-2,i*3);
					printf("%d",a[i]);
				}	
#else
			printf("%c",' ');
#endif
		}
	}
	setColors(GREEN,bg(BLACK));
	letter='A';
	for(int i=0; i <26; i++)
	{
		printf("\033[%d;%dH",46,i*3+85);
		printf("%c ", letter);
		letter++;
	}
	for(i=0;i<26;i++){
		for(j=0;j<=b[i]/(4);j++){
			printf("\033[%d;%dH",col-j,i*3+85);
#ifdef UNICODE		//conditional compilation
			printf("%s","\u2590");
			if((j==b[i]/(4))&&(j!=0))
			{
				printf("\033[%d;%dH",col-j-2,i*3+85);
				printf("%d",b[i]);
			}	
#else
			printf("%c",' ');
#endif
		}
	}
}
void clearScreen(void)
{
	printf("\033[2J");
	fflush(stdout);		//output the escape sequence immediately
}

void setColors(short fg, short bg)
{
	printf("\033[%d;%d;1m",fg,bg);
	fflush(stdout);
}
void resetColors(void)
{
	printf("\033[0m");
	fflush(stdout);
}
