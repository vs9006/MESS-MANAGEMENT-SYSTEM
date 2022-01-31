#include"Mess.h"
void gotoxy(int x, int y)
{
  HANDLE hConsoleOutput;
  COORD dwCursorPosition;
  fflush(stdin);
  dwCursorPosition.X = x;
  dwCursorPosition.Y = y;
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
} 
void menu()
{
  char a;
  do
  {
  system("cls");
  printf("\n\n 1.Enter New Items in Menu");
  printf("\n\n 2.Update Menu");
  printf("\n\n 3.Delete Menu");
  printf("\n\n 4.Display Menu");
  printf("\n\n 5.Search any Item in the Menu");
  printf("\n\n 6.Exit from Menu Database");
  printf("\n\n Enter Your Choice :- ");
  fflush(stdin);
  scanf("%c",&a);
  if(a=='1')
  {
	  acceptmenu();
  }
  else if(a=='2')
  {
	  updatemenu();
  }
  else if(a=='3')
  {
	  deletemenu();
  }
  else if(a=='4')
  {
  displaymenu();
  }
  else if(a=='5')
  {
  searchmenu();
  }
  else if(a=='6')
  {
	break;
  }
  else
  {
  printf("\n\n You have entered a wrong choice");
  getch();
  }
  }while(1);
}
void acceptmenu()
{
	int n,j,k,r,o;
	fs=fopen("noe.txt","r");
	if(fs!=NULL)
	{
	fscanf(fs,"%d",&n);
	fclose(fs);
	remove("noe.txt");
	}
	else
	n=0;
	fp=fopen("PROJECT.txt","a+");
	fs=fopen("noe.txt","w");
	printf("\n\n Enter the number of Elements you want to Enter in the Menu - \n");
	scanf("%d",&j);
	for (k=n+1;k<=j+n;k++)
	{
		i=k;
		x4:
		system("cls");
		pos();
		printf("\n\n %d%c%c Item Name : ",k,x,y);
		fflush(stdin);
		gets(m1[k].itemname);
		r=0;
		r=strlen(m1[k].itemname);
		for(o=0;o<r;o++)
		{
		if(((m1[k].itemname[o]>='A')&&(m1[k].itemname[o]<='Z'))||((m1[k].itemname[o]>='a')&&(m1[k].itemname[o]<='z'))||(m1[k].itemname[o]==' '))
		{
		}
		else
		{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x4;
		}
		}
		printf("\n\n\t Price : ");
		r=scanf("%f",&m1[k].itemprice);
		if(r==0)
		{
		printf("\n\n ERROR !!! You have not entered a number... ");
		getch();
		goto x4;
		}
		fwrite(&m1,sizeof(m1),1,fp);
		getch();
	}
	fprintf(fs,"%d",n+j);
	fclose(fs);
	fclose(fp);
}
void updatemenu()
{
	int n1,c=0;
	int p,r,o;
	system("cls");
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r+");
	if((fp!=NULL)&&(fs!=NULL))
	{
	printf("\n\n Enter the item number you want to update -");
	scanf("%d",&n1);
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		x5:
		fread(&m1,sizeof(m1),1,fp);
		pos();
		if(i==n1)
		{
		system("cls");
		printf("\n\n Old Details -");
		printf("\n ^^^ ^^^^^^^");
		printf("\n\n  %d%c%c Item Name : %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		p=sizeof(m1);
		fseek(fp,-p,SEEK_CUR);
		printf("\n\n Enter New Details -");
		printf("\n\n  %d%c%c Item Name : ",i,x,y);
		fflush(stdin);
		gets(m1[i].itemname);
		r=0;
		r=strlen(m1[i].itemname);
		for(o=0;o<r;o++)
		{
		if(((m1[i].itemname[o]>='A')&&(m1[i].itemname[o]<='Z'))||((m1[i].itemname[o]>='a')&&(m1[i].itemname[o]<='z'))||(m1[i].itemname[o]==' '))
		{
		}
		else
		{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x5;
		}
		}
		printf("\n  Price : ");
		r=scanf("%f",&m1[i].itemprice);
		if(r==0)
		{
		printf("\n\n ERROR !!! You have not entered a number... ");
		getch();
		goto x5;
		}
		c++;
		fwrite(&m1,p,1,fp);
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
		getch();
	}
	else
	printf("\n\n  Menu Updated....");
	fclose(fp);
	fclose(fs);
	}
	else 
	printf("\n\n Menu doesn't exist");
	getch();
}
void searchmenu()
{
	int n1,c=0;
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	system("cls");
	if((fp!=NULL)&&(fs!=NULL))
	{
	printf("\n\n\n Enter the Item Number You Want to Search - ");
	scanf("%d",&n1);
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&m1,sizeof(m1),1,fp);
		pos();
		if(i==n1)
		{
		printf("\n\n Item Details -");
		printf("\n ^^^^ ^^^^^^^");
		if(i<10)
		{
		printf("\n\n  %d%c%c Item Name : %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		}
		else
		{
		printf("\n\n  %d%c%c Item Name : %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		}
		c++;
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
	}
	fclose(fp);
	fclose(fs);
	}
	else 
	printf("\n\n Menu doesn't exist");
	getch();
}
void deletemenu()
{
	int x;
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	system("cls");
	if((fp!=NULL)&&(fs!=NULL))
	{
	printf("\n\n Menu Deleted....");
	x=1;
	}
	else
	printf("\n\n Menu doesn't exist");
	if(x==1)
	{
	fclose(fs);
	fclose(fp);
	remove("PROJECT.txt");
	remove("noe.txt");
	}
	getch();
}
void displaymenu()
{
	system("cls");
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	if((fp!=NULL)&&(fs!=NULL))
	{
	fscanf(fs,"%d",&n);
	printf("\n\n\n ====================================MENU===================================");
	for(i=1;i<=n;i++)
	{
	fread(&m1,sizeof(m1),1,fp);
	pos();
	if(i<10)
	{
	gotoxy(2,4+i);
	printf("%d%c%c  Item Name : %s",i,x,y,m1[i].itemname);
	}
	else
	{
	gotoxy(2,4+i);
	printf("%d%c%c Item Name : %s",i,x,y,m1[i].itemname);
	}
	if(m1[i].itemprice<10)
	{
	gotoxy(62,4+i);
	printf("Price :  %.2f",m1[i].itemprice);
	}
	else
	{
	gotoxy(62,4+i);
	printf("Price : %.2f",m1[i].itemprice);
	}
	}
	fclose(fp);
	fclose(fs);
	}
	else 
	printf("\n\n Menu doesn't exist");
	getch();
}
void pos()
{
	if(i%10==1&&i!=11)
	{
		x='s';
		y='t';
	}
	
	else if(i%10==2&&i!=12)
	{
		x='n';
		y='d';
	}
	
	else if(i%10==3&&i!=13)
	{
		x='r';
		y='d';
	}
	else
	{
		x='t';
		y='h';
	}
}