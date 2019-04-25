#include<stdio.h>
#include"screen.h"
void barChart(int a[],int b[])
{
	int i, j; //counters
	setColors(CYAN, bg(BLACK));
	for(i=0;i<26;i++){
		for(j=0;j<=a[i];j++){
			printf("\033[%d;%dH",60-j,i*3);
#ifdef UNICODE		//conditional compilation
			printf("%s","\u2590");
			if((j==a[i]-1)&&(j!=0))
				{
					printf("\033[%d;%dH",60-j-2,i*3);
					printf("%d",a[i]);
				}	
#else
			printf("%c",' ');
#endif
		}
	}
	setColors(GREEN,bg(BLACK));
	for(i=0;i<26;i++){
		for(j=0;j<=b[i]/(3);j++){
			printf("\033[%d;%dH",60-j,i*3+85);
#ifdef UNICODE		//conditional compilation
			printf("%s","\u2590");
			if((j==b[i]/(3)-1)&&(j!=0))
			{
				printf("\033[%d;%dH",60-j-2,i*3+85);
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
