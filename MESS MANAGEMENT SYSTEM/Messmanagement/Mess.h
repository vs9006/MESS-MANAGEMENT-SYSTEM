#include"conio.h"
#include"stdio.h"
#include"stdlib.h"
#include "windows.h"
#include "process.h"
#include"string.h"
typedef struct menu
{
	char itemname[100];
	float itemprice;
};
typedef struct student
{
	char name[100];
	int reg;
	char gen;
	char phno[20];
	float due;
};
struct student s1[100];
struct menu m1[100];
int i,n,r,z,pass;
char x,y,ch,k;
float s;
FILE *fp,*fs,*f1,*f2;
void gotoxy(int, int);
void password();
void pos();
void menu();
void searchmenu();
void newmenu();
void acceptmenu();
void updatemenu();
void deletemenu();
void displaymenu();
//////////////////////////////////////////////////////////////
void student();
void addstudent();
void searchstudent();
void updatestudent();
void displaystudent();
void deletestudent();
//////////////////////////////////////////////////////////////
void order();
void bill();
void duepayment();