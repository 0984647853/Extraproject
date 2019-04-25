#include<stdio.h>
#include<string.h>
#include"screen.h"
void findDuplicate(void);
int main() {
	FILE *f;
	f = fopen("wlist.txt", "r");
	if (f == NULL) {
		printf("Can not open the file! \n");
	}
	else printf("Open successfully \n");
	char content[255];
	int Number_Of_Start_Letter[26]={0}; // array contains 26 Alphabet, use for counting how many words which start with each letters
	int Num_Letter_in_file[26]={0}; // array contains 26 Alphabet, use for counting how much times each letter appear in file
	int a;
	int x=0;
	while(fscanf(f, "%s", content) != EOF) {
		a = content[0]; //take the first letter of the word and convert it into Decimal value 
		Number_Of_Start_Letter[a-65]++; // counting the frequency of the appearance 
		int c=0;
		while(content[c] != '\0'){
			if (content[c] >= 'A' && content[c] <= 'Z') {
				x = content[c] - 'A';
				Num_Letter_in_file[x]++;
			}
		c++;
		}
	}
    fclose(f);
	clearScreen();
	findDuplicate();
	barChart(Number_Of_Start_Letter,Num_Letter_in_file);
	resetColors();
	printf("\033[1;60H");
}
void findDuplicate(){
	FILE *fp;
	fp = fopen("wlist.txt", "r");
	int i = 0;
	char s[255]; 
	int N=0;
	while(fscanf(fp,"%s",s) != EOF){N++;}
	char strings[255][10];

	rewind(fp);
	for(i=0;i<N;i++){
		fscanf(fp,"%s",s);
		strcpy(strings[i], s);
	}
	printf("\033[4;6H");
	setColors(YELLOW,bg(BLACK));
	printf("These words are appear multiple times in the file: ");
	int count=0;
	for(int j=0;j<N;j++){
		for(int z=j+1;z<N;z++)
		{
			if(!strcmp(strings[j],strings[z])) 
			{
				printf("%s ",strings[j]);
				break;
			}
		}
	}
	
	resetColors();
}

