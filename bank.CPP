#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<string.h>
class account
{
	int acno;
	char name[50];
	double  deposit;
	char type;

	public:

	int checkac(int,int);
	int checktype(char,int);
	void create();
	void displaysp();
	void displayall();
	void modify();
	void deleteac();
	void depositb();
	void withdraw();

}ac[10]; //end of class account
int n=0; //For storing the number of accounts
int account::checkac(int x,int y)//Function for checking the validity of the account
{
	int i=0;
	for(i=0;i<y;i++)
	{
		if(ac[i].acno==x)
		{
			return 1;
		}
	}
	return 0;
}
int account::checktype(char x,int y)//Function for checking the validity of type
{
      x=ac[y].type;
      if((x!='S')&&(x!='C'))
	return 1;
      return 0;
}

void account::create()     //Function for creating an account
{
	int i=n,x,y;
	cout<<"\nEnter the account No. :";
	cin>>ac[i].acno;
	x=checkac(ac[i].acno,i);
	while(x==1)
	{
		cout<<"\nThis account no is already used. Enter a valid account No. :";
		cin>>ac[i].acno;
		x=checkac(ac[i].acno,i);
	}
	cout<<"\n\nEnter the Name of the account Holder : ";
	gets(ac[i].name);
	cout<<"\nEnter Type of the account (c for current and s for savings) : ";
	cin>>ac[i].type;
	ac[i].type=toupper(ac[i].type);
	y=checktype(ac[i].type,i);
	while(y==1)
	{
		cout<<"\nInvalid type. Press c for current and s for savings\n";
		cin>>ac[i].type;
		ac[i].type=toupper(ac[i].type);
		y=checktype(ac[i].type,i);
	}
	cout<<"\nEnter the initial amount for saving or for current account) : ";
	cin>>ac[i].deposit;
	n++;
	cout<<"\n\n\nYour Account has been created..";
}
void account::displaysp()     //Funcction for displaying a specific record
{
	int x;   //For storing the account number
	int i=0,flag=0;
	if(n==0)
		cout<<"\nNo accounts created....\n";
	else
	{
		cout<<"\n\nEnter your account number\n";
		cin>>x;
	}
	for(i=0;i<n;i++)
	{
		if(ac[i].acno==x)
		{
			cout<<"\nAccount No. : "<<ac[i].acno;
			cout<<"\nAccount Holder Name : ";
			puts(ac[i].name);
			cout<<"\nType of Account : "<<ac[i].type;
			cout<<"\nBalance amount : "<<ac[i].deposit;
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\n\nThe requested acoount doesnot exist\n";
	}
}
void account::modify()    //Function for modify an account
{
	int i=0;
	int x,flag=0;
	if(n==0)
		cout<<"\nNo accounts created\n";
	else
	{
		cout<<"\n\nEnter your account number\n";
		cin>>x;
	}
	for(i=0;i<=n;i++)
	{
		if(ac[i].acno==x)
		{
			cout<<"\nThe account no. to modify  "<<ac[i].acno;
			cout<<"\n\nEnter the new name of the account holder : ";
			gets(ac[i].name);
			cout<<"\nEnter the new type of account (C/S) : ";
			cin>>ac[i].type;
			ac[i].type=toupper(ac[i].type);
			cout<<"\nEnter the new amount : ";
			cin>>ac[i].deposit;
			cout<<"\n\nYour account has been created\n";
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\n\nThis account doesnt exist\n";
	}
}
void account::depositb()     //Function for depositing into an account
{
	int i=0;
	int x,flag=0;double y;
	if(n==0)
		cout<<"\nNo accounts created\n";
	else
	{
		cout<<"\n\nEnter your account number\n";
		cin>>x;
	}
	for(i=0;i<n;i++)
	{
		if(ac[i].acno==x)
		{
			cout<<"\nEnter the amount to be deposited : ";
			cin>>y;
			ac[i].deposit=ac[i].deposit+y;
			flag=1;
			cout<<"\nYour transaction is processed\n";
		}

	}
	if(flag==0)
	{
		cout<<"\nYour transaction could not be processed\n";
	}

}
void account::withdraw()     //Function for withdrawing from an account
{
	int i=0;
	int x,flag=0;double y;
	if(n==0)
		cout<<"\nNo accounts created\n";
	else
	{
		cout<<"\n\nEnter your account number\n";
		cin>>x;
	}
	for(i=0;i<=n;i++)
	{
		if(ac[i].acno==x)
		{
			cout<<"\nEnter the amount to be withdrawn : ";
			cin>>y;
			ac[i].deposit=ac[i].deposit-y;
			if(ac[i].deposit<0)
			{
				cout<<"\nInsuffient funds\n";
				ac[i].deposit=ac[i].deposit+y;
				flag=0;
			}
			else
			{

				cout<<"\nYour transaction is processed\n\n";
				flag=1;
			}
		}

	}
	if(flag==0)
	{
		cout<<"\nYour transaction could not be processed\n";
	}


}
void account::displayall()   //Function for displaying all accounts
{
	int i=0;
	if(n==0)
		cout<<"\nNo accounts created\n";

	cout<<"A/c no.      NAME         Type       Balance\n";
	for(i=0;i<n;i++)
	{
		if(n==0)
		{
			cout<<"\nNo accounts created\n";
		}
		else
		{

			cout<<ac[i].acno<<setw(12)<<"    "<<ac[i].name<<setw(10)<<"        "<<ac[i].type<<setw(12)<<"  "<<ac[i].deposit;
			cout<<"\n================================================================================";
		}
	}

}
void account::deleteac()   //Function for closing an account
{
	int i=0;
	int x,flag=0;
	if(n==0)
		cout<<"\nNo accounts created\n";
	else
	{
		cout<<"\nEnter the account no. to delete\n";
		cin>>x;
	}
	for(i=0;i<n;i++)
	{
		if(ac[i].acno==x)
		{
			flag=i;
		}
	}
	if((flag==0)&&(n>1))
	{
		cout<<"\nThis account does not exist\n";

	}
	else if((flag==0)&&(n==1))
	{
		n=0;
		cout<<"\nDone\n";
	}
	else if(flag==n-1)
	{
	       n--;
	       cout<<"\nYour request has been processed\n";
	}
	else if(n==0)
	{
		cout<<"\nThere are no accounts\n";
	}
	else
	{
		for(i=flag;i<n-1;i++)
		{
			if(n==1)
			{
				n=0;
			}
			else
			{
				int t=i+1;
				ac[i].acno=ac[t].acno;
				strcpy(ac[i].name,ac[t].name);
				ac[i].deposit=ac[t].deposit;
				ac[i].type=ac[t].type;
				n--;
			}
		}
		cout<<"\nThe requested account has been closed\n";
	}


}
void intro()  //Function for introduction
{
	cout<<"\n\n\n\n\n\tBANK MANAGEMENT SYSTEM\n\n\n\tAman Bhatia\n";
	getch();
}
void main()
{

	account a;
	char ch;
	int num;
	clrscr();
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. New Account";
		cout<<"\n\n\t2. Deposit Amount";
		cout<<"\n\n\t3. Withdraw Amount";
		cout<<"\n\n\t4. Balance Enquiry";
		cout<<"\n\n\t5. Show all account info";
		cout<<"\n\n\t6. Close an account";
		cout<<"\n\n\t7. Modify an account";
		cout<<"\n\n\t8. Exit";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			a.create();
			break;
		case '2':
			a.depositb();
			break;
		case '3':
			a.withdraw();
			break;
		case '4':
			a.displaysp();
			break;
		case '5':
			a.displayall();
			break;
		case '6':
			a.deleteac();
			break;
		 case '7':
			a.modify();
			break;
		 case '8':
			cout<<"\n\n\tExiting....";
			break;
		 default :cout<<"\n\n\nInvalid choice enter your choice again";
		}
		getch();
    }while(ch!='8');

}
