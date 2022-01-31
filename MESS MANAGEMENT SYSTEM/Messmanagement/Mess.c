#include"Mess.h"
void order()
{
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	if((fp!=NULL)&&(fs!=NULL))
	{
	do
	{
	system("cls");
	printf("\n\n Enter your choice :-");
	printf("\n\n 1.Student");
	printf("\n\n 2.Outsider");
	printf("\n\n 3.Exit to Main Menu ");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='1')
	{
		f2=fopen("nos.txt","r");
		f1=fopen("STUDENT.txt","r");
		if((f1!=NULL)&&(f2!=NULL))
		{
		searchstudent();
		if(z==0)
		{
		printf("\n\n Do you want to purchase any Item (y/any key) ? ");
		fflush(stdin);
		scanf("%c",&k);
		if((k=='y')||(k=='Y'))
		{
		bill();
		}
		else
		s=0;
		duepayment();
		fclose(f1);
		fclose(f2);
		}
		}
		else 
		{
		system("cls");
		printf("\n\n Student record doesn't exist");
		getch();
		}
	}
	else if(ch=='2')
	{
		bill();
	}
	else if(ch=='3')
	{
		break;
	}
	else
	{
	printf("\n\n You have entered a wrong choice");
	getch();
	}
	}while(1);
	fclose(fp);
	fclose(fs);
	}
	else 
	{
	system("cls");
	printf("\n\n Menu doesn't exist");
	getch();
	}
}
void bill()
{
	int df=0,o=0,t,j,c=0,a[100],q[100];
	s=0;
	system("cls");
	displaymenu();
	printf("\n\n Enter the total no. of Items you want to purchase - ");
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
	system("cls");
	displaymenu();
	i=j;
	c=0;
	pos();
	printf("\n\n  %d%c%c Item No. = ",j,x,y);
	scanf("%d",&a[j]);
	printf("\n\n  Quantity = ");
	scanf("%d",&q[j]);
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&m1,sizeof(m1),1,fp);
		pos();
		if(i==a[j])
		{
		printf("\n\n  Item Details -");
		printf("\n  ^^^^^^^^^^^^");
		if(i<10)
		{
		printf("\n\n  %d%c%c Item Name - %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price - %.2f",m1[i].itemprice);
		s+=m1[i].itemprice*q[j];
		}
		else
		{
		printf("\n\n  %d%c%c Item Name - %s",i,x,y,m1[i].itemname);
		printf("\n\n  Price - %.2f",m1[i].itemprice);
		s+=m1[i].itemprice*q[j];
		}
		c=1;
		df++;
		getch();
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
		getch();
	}
	}
	fclose(fs);
	fclose(fp);
	if(df!=0)
	{
	system("cls");
	printf("\n ********************************* Cash Memo **********************************");
	printf("\n ********************************* ^^^^ ^^^^ **********************************");
	printf("\n================================================================================");
	gotoxy(2,7);
	printf("Serial Number");
	gotoxy(2,8);
	printf("^^^^^^ ^^^^^^");
	gotoxy(20,7);
	printf("Item Name");
	gotoxy(20,8);
	printf("^^^^ ^^^^");
	gotoxy(42,7);
	printf("Quantity");
	gotoxy(42,8);
	printf("^^^^^^^^");
	gotoxy(60,7);
	printf("Price");
	gotoxy(60,8);
	printf("^^^^^");
	for(j=1;j<=t;j++)
	{
	fs=fopen("noe.txt","r");
	fp=fopen("PROJECT.txt","r");
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
	fread(&m1,sizeof(m1),1,fp);
	if(i==a[j])
	{
	++o;
	gotoxy(2,9+j);
	printf("%d",o);
	gotoxy(20,9+j);
	printf("%s",m1[i].itemname);
	gotoxy(45,9+j);
	printf("%d",q[j]);
	gotoxy(60,9+j);
	printf("%.2f",m1[i].itemprice*q[j]);
	}
	}
	}
	gotoxy(1,45);
	printf("===============================================================================");
	gotoxy(50,46);
	printf(" Total Payment = %.2f",s);
	gotoxy(1,47);
	printf("===============================================================================");
	getch();
	system("cls");
	fclose(fs);
	fclose(fp);
}}
void duepayment()
{
	int n=0,x,rt;
	float d,a;
	system("cls");
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==r)
		{
			system("cls");
			printf("\n\n Student Details - ");
			printf("\n ^^^^^^^ ^^^^^^^");
			printf("\n\n Registration no: %d",s1[i].reg);
			printf("\n\n Name: %s",s1[i].name);
			printf("\n\n Gender: %c",s1[i].gen);
			printf("\n\n Phone number: %s",s1[i].phno);
			printf("\n\n Due payment = %.2f",s1[i].due);
			d=s1[i].due;
		}
	}
	fclose(f1);
	fclose(f2);
	printf("\n\n Current Payment = %.2f",s);
	printf("\n\n Total Payment = %.2f",s+d);
	if((k=='y')||(k=='Y'))
	{
	z:
	printf("\n\n Enter the amounnt,you want to pay now = ");
	fflush(stdin);
	rt=scanf("%f",&a);
	if(rt==0)
	{
	printf("\n\n ERROR !!! You have not entered a number... ");
	getch();
	goto z;
	}
	}
	else
	{
	if(d!=0)
	{
	fr:
	printf("\n\n Enter the amounnt,you want to pay now = ");
	fflush(stdin);
	rt=scanf("%f",&a);
	if(rt==0)
	{
	printf("\n\n ERROR !!! You have not entered a number... ");
	getch();
	goto fr;
	}
	}
	else
	a=0;
	}
	printf("\n\n Remaining Balance = %.2f",s+d-a);
	d=s+d-a;
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r+");
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==r)
		{
			x=sizeof(s1);
			fseek(f1,-x,SEEK_CUR);
			s1[i].due=d;
			fwrite(&s1,x,1,f1);
		}
	}
	fclose(f1);
	fclose(f2);
	getch();
}
