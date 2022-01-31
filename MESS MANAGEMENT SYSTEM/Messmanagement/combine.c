#include"Mess.h"
void main()
{
  char a;
  printf("\n********************************************************************************");
  printf("********************************************************************************");
  printf("\n  W       W       W  EEEEEE L      CCCCCC OOOOOO  M               M  EEEEEE");
  printf("\n  W      W W      W  E      L      C      O    O  M M           M M  E");
  printf("\n  W     W   W     W  E      L      C      O    O  M  M         M  M  E");
  printf("\n  W    W     W    W  EEEEEE L      C      O    O  M   M       M   M  EEEEEE");
  printf("\n  W   W       W   W  E      L      C      O    O  M    M     M    M  E");
  printf("\n  W  W         W  W  E      L      C      O    O  M     M   M     M  E");
  printf("\n  W W           W W  E      L      C      O    O  M      M M      M  E");
  printf("\n  W               W  EEEEEE LLLLLL CCCCCC OOOOOO  M       M       M  EEEEEE");
  printf("\n\n********************************************************************************");
  printf("********************************************************************************");
  getch();
  password();
  if(pass==0)
  {
	  exit(0);
  }
  do
  {
  system("cls");
  printf("\n\n\t\t\t HMRITM MESS MANAGEMENT SYSTEM");
  printf("\n\t\t\t ^^^^^^ ^^^^ ^^^^^^^^^^ ^^^^^^");
  printf("\n\n Enter Your Choice -");
  printf("\n\n 1.Menu");
  printf("\n\n 2.Student Record");
  printf("\n\n 3.Order");
  printf("\n\n 4.Exit");
  printf("\n\n Enter Your Choice :- ");
  fflush(stdin);
  scanf("%c",&a);
  if(a=='1')
  {
	  menu();
  }
  else if(a=='2')
  {
	  student();
  }
  else if(a=='3')
  {
	order();
  }
  else if(a=='4')
  {
  exit(0);
  }
  else
  {
  printf("\n\n You have entered a wrong choice");
  getch();
  }
  }while(1);
}