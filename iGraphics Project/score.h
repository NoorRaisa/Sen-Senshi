#ifndef SCORE_INCLUDED
#define SCORE_INCLUDED
#include "variables.h"
#include<iostream>
using namespace std;
int score;
int sscore;
char* stringConverter(int killpoint)
{
	char *ch = new char[3000];
	itoa(killpoint, ch, 10);
	return ch;
}
 
void highScore()
{
		FILE *fp = fopen("Image\\score2.txt", "r");
		//FILE *fptr = fopen("score.txt", "w");
		if (fp != NULL){
			fscanf(fp, "%d", &score);
			fclose(fp);
		}
			if (killScore > score){
			score = killScore;
			fp=fopen("Image\\score2.txt", "w");
			if (fp != NULL){
				fprintf(fp, "%d", killScore);
				fclose(fp);
			}
		}
}
void showscore()
{
	FILE *fptr = fopen("Image\\score2.txt", "r");
	if (fptr != NULL){
		fscanf(fptr, "%d", &sscore);
		fclose(fptr);
	}
	iSetColor(255, 0, 234);
	iText(500, 300, "HIGH SCORE IS:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(690, 300, stringConverter(sscore), GLUT_BITMAP_TIMES_ROMAN_24);

}
void scoreCounter()
{
	iSetColor(0, 0, 0);
	iText(1050, 560, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1150, 560, stringConverter(killScore), GLUT_BITMAP_TIMES_ROMAN_24);
}
#endif