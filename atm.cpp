#include<iostream>
#include<windows.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<fstream>
using namespace std;

class Admin
{
	public:
		void admin();
};
class Complete:public Admin
{
	public:
		void complete();
};
class Create:public Complete
{
	public:
		void create();
	private:
		string x,y,z,c,e;
		char a;
		int i,j;
};
class Proceed:public Create
{
	public:
		void proceed();
};
class Help:public Admin
{
	public:
		void help();
};


void Admin::admin()
{
	char c,h,p,e;
	cout<<"\n\n\n\n      ADMIN                                                   Date\n";
	cout<<"--------------------------------------------------------------------------------";
	cout<<"                           ";
	
	cout<<"      CREATE ACCOUNT\n";
	cout<<"                         ALLREADY HAVE ACCOUNT PRESS P\n";
	cout<<"\n\n\n\n\n\n\n";
	cout<<"--------------------------------------------------------------------------------";
	
	cout<<"C: CREATE ACCOUNT  H: HELP  P: PROCEDURE  E: EXIT        ";
	
}

void Complete::complete()
{
	Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
    cin.get();
	cout<<"\n\n\n\n                                                         Date\n";
	cout<<"\n\n\n";
	cout<<"--------------------------------------------------------------------------------";
	srand(time(0));

     char arr[9] = {1};
     char arr2[4]={1};
     
    fstream file;
   	file.open("pincode.txt",ios::out);

   for(int i = 0; i < 9; i++){

      arr[i] = rand() % 10+ '0';
      file<<arr[i];
   }
   file.close();
   
   fstream fint;
   fint.open("atm_pin.txt",ios::out);
   
   for(int j=0;j<4;j++)
   {
   	arr2[j]=rand()%10+'0';
   	fint<<arr2[j];
   }
   fint.close();

   
	cout<<"                    YOUR ACCOUNT HAS SUCCESSFULLY CREATED ";
	cout<<"\n\n\n";
	cout<<"                    ACCOUNT NUMBER : ";
	for(int i = 0; i < 9; i++)
   {
     cout << arr[i];
   }
   cout<<"\n\n\n                     ATM PIN : ";
   for(int j=0;j<4;j++)
   {
   	cout<< arr2[j];
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   cout<<"\n\n\n\n\n         NOTE : THESE ARE THE ACCOUNT CREDENTIALS FOR USING ATM SERVICES.";
   cout<<"\n\n";
   cout<<"--------------------------------------------------------------------------------";
   cout<<"\n\n\n                 MAIN MENU : PRESS ENTER ";
   cin.ignore();
   if(cin.ignore())
   {
   	system("cls");
   	admin();
   }
   
   
}
void Create::create()
{
	Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
    cin.get();
	fstream file;
	file.open("create.txt",ios::out);
	//string x,y,z,c,e;
	//char a;
	//int i,j;
	cout<<"                               Application Form\n";
	cout<<"\nEnter Full Name :  ";
	cin.ignore();
	getline(cin,x);
	file<<x<<"\n";

	
	cout<<"\nFather/Guardian :  ";
	getline(cin,y);
	file<<y<<"\n";
	cout<<"\nDate Of Birth (dd/mm/yyyy) :  ";
	getline(cin,z);
	file<<z<<"\n";
	cout<<"\nCity : ";
	getline(cin,c);
	file<<c<<"\n";
	
	
	cout<<"\nEmail Id : ";
	getline(cin,e);
	file<<e<<"\n";
	cout<<"\nAccount Type (S/C) :  ";
	cin>>a;
	file<<a<<"\n";
	cout<<"\nPINCODE : ";
	cin>>i;
	file<<i<<"\n";
	
	cout<<"Enter initial amount (>=500)  ";
	cin>>j;
	file<<j<<"\n";
	file.close();
	fstream amount;
	amount.open("amount.txt",ios::out);
	amount<<j;
	amount.close();
	cout<<"                 Submit             ";
	cin.ignore();
	if(cin.ignore())
	{
		system("cls");
		complete();
		
	}
}

void Proceed::proceed()
{
	Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
    cin.get();
	long int pin;
	long int acno,ac,amount;
	fstream file;
	file.open("pincode.txt",ios::in);
	while(file)
	{
		file>>acno;
		break;
	}
	file.close();
	fstream fin;
	fin.open("atm_pin.txt",ios::in);
	while(fin)
	{
		fin>>pin;
		break;
	}
	fin.close();
	fstream amt;
	amt.open("amount.txt",ios::in);
	while(amt)
	{
		amt>>amount;
		break;
	}
	amt.close();
	//fin.open("create.txt",ios::out);
	
	int i,amout,final;
	long int pi;
	char x;
	cout<<"Enter any number \n\nbetween 10 and 99\n\nfor eg. 25 ";
	cin>>i;
	if(i>=10&&i<=99)
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n";
		cout<<"                PLEASE ENTER YOUR ACCOUNT NUMBER";
		cin>>ac;
		
		if(ac==acno)
		{
			cout<<"Welcome Your !";
			cout<<"\nEnter Your Pin No.";
			cin>>pi;
			if(pi==pin)
			{
				cout<<"\nEnter your amount \n";
				cin>>amout;
				if(amout>=500&&amout<amount)
				{
					Beep(523,1000); // 523 hertz (C5) for 1000 milliseconds     
    				cin.get();
					system("cls");
					cout<<"                 Transaction Successfully\n";
					final=amount-amout;
					fstream fin;
					fin.open("amount.txt",ios::out);
					fin<<final;
					cout<<"                 press x to go main menu     ";
					cin>>x;
					if(x=='x')
					{
						system("cls");
						admin();
					}
				}
				else
				{
					system("cls");
					Beep(523,1000); // 523 hertz (C5) for 1000 milliseconds     
    				cin.get();
					cout<<"                Transaction Incomplete! \n";
					cout<<"                press x to go main menu  ";
					cin>>x;
					if
					(x=='x')
					{
						system("cls");
						admin();
					}
					else
					{
						cout<<"             \npress x to go main menu ";
						cin>>x;
						if(x=='x')
						{
							system("cls");
							admin();
						}
						else
						{
							system("cls");
							admin();
						}
					}
				}
				
			}
			else
			{
				cout<<"\n           wrong pin no\n";
				cout<<"             press x to go main menu  ";
				cin>>x;
				if(x=='x')
				{
					system("cls");
					admin();
				}
				
			}
		}
		else
		{
			cout<<"              Wrong Account no .";
			cout<<"\n            press x to go main menu  ";
			cin>>x;
			if(x=='x')
			{
				system("cls");
				admin();
			}
			else
					{
						cout<<"             \npress x to go main menu ";
						cin>>x;
						if(x=='x')
						{
							system("cls");
							admin();
						}
						else
						{
							system("cls");
							admin();
						}
					}
		}
		
		
	}
	else
	{
		cout<<"   \nNot correct!\n";
		cout<<"press x to go main menu \n";
		cin>>x;
		if(x=='x')
		{
			system("cls");
			admin();
		}
		else
					{
						cout<<"             \npress x to go main menu ";
						cin>>x;
						if(x=='x')
						{
							system("cls");
							admin();
						}
						else
						{
							system("cls");
							admin();
						}
					}
		
		//break;
	}
}
void Help::help()
{
	Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
    cin.get();
	
	char x;
	cout<<"Inorder to use our ATM services be sure that,\n";
	cout<<"you might have already opened an account previously.\n";
	cout<<"\n\n";
	cout<<"ATM Services\n";
	cout<<"\n\n";
	cout<<"Cash Withdrawal : Use this to withdraw amount (40,000/-per day).\n";
	cout<<"\n";
	cout<<"Fast Cash : This enables to withdraw your amounts with a touch.\n";
	cout<<"\n";
	cout<<"Pin Change : Use this service to change your ATM password.\n";
	cout<<"\n";
	cout<<"Balance Enquiry : To check the current balance in your account.\n";
	cout<<"\n";
	cout<<"Ministatement : Keep track of the transactions in your account.\n";
	cout<<"\n";
	cout<<"Fund Transfer : Transfers amount instantly to your loved ones.\n";
	cout<<"\n";
	cout<<"For more information contact:\n";
	cout<<"\n";
	cout<<"call our 24x7 helpline through toll free 1800 100 2400\n";
	cout<<"\n\n";
	cout<<"Press x to go main menu    ";
	cin>>x;
	system("cls");
	if(x=='x')
	{
		admin();
	}
	else
					{
						cout<<"             \npress x to go main menu ";
						cin>>x;
						if(x=='x')
						{
							system("cls");
							admin();
						}
						else
						{
							system("cls");
							admin();
						}
					}
}

int main()
{
	Admin A;
	Complete C;
	Create Cr;
	Proceed P;
	Help H;
	int a,b,c,h,p,e;
	char x;
	A.admin();
	while(1)
	{
		cin>>x;
		system("cls");
		if(x=='h')
		{
			H.help();
		}
		if(x=='c')
		{
			system("cls");
			Cr.create();
		}
		if(x=='p')
		{
			system("cls");
			P.proceed();
		}
		if(x=='e')
		{
			exit(0);
		}
	}
}



