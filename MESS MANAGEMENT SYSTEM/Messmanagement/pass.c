#include"Mess.h"
void password()
{
int k;
char p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
for(k=3;k>0;k--)
{
system("cls");
printf("\n\n\n  Enter your Password:-");
p1=getch();
printf("*");
p2=getch();
printf("*");
p3=getch();
printf("*");
p4=getch();
printf("*");
p5=getch();
printf("*");
p6=getch();
printf("*");
p7=getch();
printf("*");
p8=getch();
printf("*");
p9=getch();
printf("*");
p10=getch();
printf("*");
p11=getch();
printf("*");
if(((p1=='m')||(p1=='M'))&&((p2=='e')||(p2=='E'))&&((p3=='s')||(p3=='S'))&&((p4=='s')||(p4=='S'))&&(p5=='@')&&((p6=='h')||(p6=='H'))&&((p7=='m')||(p7=='M'))&&((p8=='r')||(p8=='R'))&&((p9=='i')||(p9=='I'))&&((p10=='t')||(p10=='T'))&&((p11=='m')||(p11=='M')))
{
printf("\n\n\n\n  Correct Password......Press any key to continue");
getch();
pass=1;
break;
}
else
{
printf("\n\n\n\n  Incorrect Password......Press any key");
printf("\n\n  Trials Remaining:- %d",k-1);
getch();
pass=0;
}
}
}
