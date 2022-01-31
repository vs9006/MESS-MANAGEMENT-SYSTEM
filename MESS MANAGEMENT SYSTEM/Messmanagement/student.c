#include"Mess.h"
void student()
{
char ch;
do
{
system("cls");
printf("\n\n 1.Add New Student");
printf("\n\n 2.Search Student Information");
printf("\n\n 3.Update Student Information");
printf("\n\n 4.Display All Information");
printf("\n\n 5.Remove All Data");
printf("\n\n 6.Exit from Student Database");
printf("\n\n Enter your choice :- ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='1')
{ 
addstudent();
}
else if(ch=='2')
{
searchstudent();
}
else if(ch=='3')
{
updatestudent();
}
else if(ch=='4')
{
displaystudent();
}
else if(ch=='5')
{
deletestudent();
}
else if(ch=='6')
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
void addstudent()
{
int i,po,j,k,r,o;
f2=fopen("nos.txt","r");
if(f2!=NULL)
{
fscanf(f2,"%d",&i);
fclose(f2);
remove("nos.txt");
}
else
i=0;
f1=fopen("STUDENT.txt","a+");
f2=fopen("nos.txt","w");
printf("\n\n How many records do you want to enter now ?");
scanf("%d",&j);
for (k=i+1;k<=j+i;k++)
{
x:
system("cls");
printf("\nEnter the registration no: ");
fflush(stdin);     // To prevent infinite Loop....
r=scanf("%d",&s1[k].reg);
if(r==0)
{
	printf("\n\n ERROR !!! You have not entered a number... ");
	getch();
	goto x;
}
for(po=0;po<=i;po++)
{
	fread(&s1,sizeof(s1),1,f1);
	if(s1[k].reg==s1[po].reg)
	{
	printf("\n\n ERROR !!! Registration Number Already Exists... ");
	getch();
	goto x;

	}
}
printf("\nEnter the name: ");
fflush(stdin);
gets(s1[k].name);
r=0;
r=strlen(s1[k].name);
for(o=0;o<r;o++)
{
	if(((s1[k].name[o]>='A')&&(s1[k].name[o]<='Z'))||((s1[k].name[o]>='a')&&(s1[k].name[o]<='z'))||(s1[k].name[o]==' '))
	{
	}
	else
	{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x;
	}
}
printf("\nEnter the gender (M/F) : ");
fflush(stdin);
scanf("%c",&s1[k].gen);
if((s1[k].gen!='M')&&(s1[k].gen!='F'))
{
	printf("\n\n ERROR !!! Enter ony M or F .... ");
	getch();
	goto x;
}
printf("\nEnter the phone number: ");
fflush(stdin);
gets(s1[k].phno);
r=0;
r=strlen(s1[k].phno);
for(o=0;o<r;o++)
{
	if((s1[k].phno[o]>='0')&&(s1[k].phno[o]<='9'))
	{
	}
	else
	{
		printf("\n\n ERROR !!! Enter only Numbers .... ");
		getch();
		goto x;
	}
}
printf("\n\nRecord Entered Successfully........!!!!!!");
fwrite(&s1,sizeof(s1),1,f1);
getch();
}
fprintf(f2,"%d",i+j);
fclose(f2);
fclose(f1);
getch();
}
void searchstudent()
{
	int n1,n=0,c=0;
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	system("cls");
	if((f1!=NULL)&&(f2!=NULL))
	{
	printf("\n\n\n Enter the Registration Number of the Student - ");
	scanf("%d",&n1);
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==n1)
		{
			z=0;
			system("cls");
			if(ch=='1')
			{
			r=n1;
			}
			printf("\n\n Student Details - ");
			printf("\n ^^^^^^^ ^^^^^^^");
			printf("\n\n Registration no: %d",s1[i].reg);
			printf("\n\n Name: %s",s1[i].name);
			printf("\n\n Gender: %c",s1[i].gen);
			printf("\n\n Phone number: %s",s1[i].phno);
			printf("\n\n Due payment = %.2f",s1[i].due);
			c++;
		}
	}
	if(c==0)
	{
		printf("\n\n No student exists with this registration number in the record");
		z=1;
	}
	fclose(f1);
	fclose(f2);
	}
	else 
	printf("\n\n Student record doesn't exist");
	getch();
}
void updatestudent()
{
	int n1,r,o,n=0,c=0;
	int x;
	system("cls");
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r+");
	if((f1!=NULL)&&(f2!=NULL))
	{
	printf("\n\n\n Enter the Registration Number of the Student whose details you want to update- ");
	scanf("%d",&n1);
	fscanf(f2,"%d",&n);
	for(i=1;i<=n;i++)
	{
		y:
		fread(&s1,sizeof(s1),1,f1);
		if((s1[i].reg)==n1)
		{
			system("cls");
			printf("\n\n Old Details - ");
			printf("\n ^^^ ^^^^^^^");
			printf("\n\n Registration no: %d",s1[i].reg);
			printf("\n\n Name: %s",s1[i].name);
			printf("\n\n Gender: %c",s1[i].gen);
			printf("\n\n Phone number: %s",s1[i].phno);
			x=sizeof(s1);
			fseek(f1,-x,SEEK_CUR);
			printf("\n\n Enter New Details-");
			printf("\n ^^^^^ ^^^ ^^^^^^^");
			printf("\n\n Enter the name: ");
			fflush(stdin);
			gets(s1[i].name);
			r=0;
			r=strlen(s1[i].name);
			for(o=0;o<r;o++)
			{
			if(((s1[i].name[o]>='A')&&(s1[i].name[o]<='Z'))||((s1[i].name[o]>='a')&&(s1[i].name[o]<='z'))||(s1[i].name[o]==' '))
			{
			}
			else
			{
			printf("\n\n ERROR !!! You have entered any other character in name... ");
			getch();
			goto y;
			}
			}
			printf("\n Enter the gender (M/F) : ");
			fflush(stdin);
			scanf("%c",&s1[i].gen);
			if((s1[i].gen!='M')&&(s1[i].gen!='F'))
			{
				printf("\n\n ERROR !!! Enter ony M or F .... ");
				getch();
				goto y;
			}
			printf("\n Enter the phone number: ");
			fflush(stdin);
			gets(s1[i].phno);
			r=0;
			r=strlen(s1[i].phno);
			for(o=0;o<r;o++)
			{
				if((s1[i].phno[o]>='0')&&(s1[i].phno[o]<='9'))
				{
				}
				else
				{
					printf("\n\n ERROR !!! Enter only Numbers .... ");
					getch();
					goto y;
				}
			}
			printf("\n\n Record Updated Successfully........!!!!!!");
			fwrite(&s1,x,1,f1);
			c++;
		}
	}
	if(c==0)
	{
		printf("\n\n No student exists with this registration number in the record");
		getch();
	}
	else
	fclose(f1);
	fclose(f2);
	}else 
	printf("\n\n Student record doesn't exist");
	getch();
}
void displaystudent()
{
	int i;
	system("cls");
    f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	if((f1!=NULL)&&(f2!=NULL))
	{
	fscanf(f2,"%d",&n);
	printf("\n\n Student Details - ");
	printf("\n ======= =======");
	gotoxy(2,5);
	printf("Registration");
	gotoxy(2,6);
	printf("^^^^^^^^^^^^");
	gotoxy(2,7);
	printf("Number");
	gotoxy(2,8);
	printf("^^^^^^");
	gotoxy(18,5);
	printf("Name");
	gotoxy(18,6);
	printf("^^^^");
	gotoxy(42,5);
	printf("Gender");
	gotoxy(42,6);
	printf("^^^^^^");
	gotoxy(50,5);
	printf("Phone Number");
	gotoxy(50,6);
	printf("^^^^^ ^^^^^^");
	gotoxy(67,5);
	printf("Due Payment");
	gotoxy(67,6);
	printf("^^^ ^^^^^^^");
	for(i=1;i<=n;i++)
	{
	fread(&s1,sizeof(s1),1,f1);
	gotoxy(2,8+i);
	printf("%d",s1[i].reg);
	gotoxy(18,8+i);
	printf("%s",s1[i].name);
	gotoxy(45,8+i);
	printf("%c",s1[i].gen);
	gotoxy(50,8+i);
	printf("%s",s1[i].phno);
	gotoxy(67,8+i);
	printf("%.2f",s1[i].due);
	}
	fclose(f1);
	fclose(f2);
	}
	else 
	printf("\n\n Student record doesn't exist");
	getch();
}
void deletestudent()
{
	int x;
	f2=fopen("nos.txt","r");
	f1=fopen("STUDENT.txt","r");
	system("cls");
	if((f1!=NULL)&&(f2!=NULL))
	{
	printf("\n\nAll Student Data Deleted........");
	x=1;
	}
	else
	printf("\n\n Student record doesn't exist");
	if(x==1)
	{
	fclose(f2);
	fclose(f1);
	remove("STUDENT.txt");
	remove("nos.txt");
	}
	getch();
}