#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

struct employee
{ 	char code[8],name[12],phone_n[15];
	long basic_salary;
	long acc;
};

void line()
{  for(int i=0;i<79;i++)
	 cout<<'-';
}

void data_entry()
{	ofstream ofile;
	ofile.open("emp.dbf");       //as per file location
	char cond;                   //condition of repition
	do
	  {  employee a;
	     cout<<"\nEnter employee's Name:";
	     gets(a.name);
	     cout<<"Enter code: ";
	     gets(a.code);
	     cout<<"Enter phone number: ";
	     gets(a.phone_n);
	     cout<<"Enter account number: ";
	     cin>>a.acc;
	     cout<<"Enter basic salary: ";
	     cin>>a.basic_salary;
	     ofile.write((char *)&a,sizeof a);
	     cout<<"Press y to contiue ";
	     cond=getch();
	   } while(cond=='y');
  }

  void data_update()
  {
	ifstream ifile;
	employee a;
	char code[8];
	ofstream ofile("emptemp.dbf");
	ifile.open("emp.dbf");
	cout<<"enter code of employee ";
	gets(code);
	int check=0;
	while(!ifile.eof())
	{	ifile.read((char *)&a,sizeof a);
		if(strcmp(code,a.code)==0&&check==0)
		{	check=1;
			cout<<"Enter name of employee ";
			gets(a.name);
			cout<<"Enter phone number ";
			gets(a.phone_n);
			cout<<"Enter basic salary ";
			cin>>a.basic_salary;
			cout<<"Enter bank account number ";
			cin>>a.acc;
		   }
		  if(!ifile.eof())                   //to avoid extra input
		  ofile.write((char *)&a,sizeof a);

	}
	ofile.close();
	ifile.close();
	remove("emp.dbf");
	rename("emptemp.dbf","emp.dbf");
	if(!check)
	cout<<"Emplyee not found \nPlease try again !";
	else
	cout<<"Record updated sucessfully ";
  }
  void data_delete()
  {     ifstream ifile;
	employee a;
	char code[8];
	ofstream ofile;
	ofile.open("emptemp.dbf",ios::in);
	ifile.open("emp.dbf");
	cout<<"enter code of employee ";
	gets(code);
	int check=0;       //variable to indicate if data in file
	while(!ifile.eof())
	{	ifile.read((char *)&a,sizeof a);
		if(strcmp(code,a.code))
		{        check=1;
			ofile.write((char *)&a,sizeof a);
	       }
	}
	ofile.close();
	ifile.close();
	remove("emp.dbf");
	rename("emptemp.dbf","emp.dbf");
	if(!check)
	cout<<"Emplyee not found \nPlease try again !";
       else
       cout<<"Record delted successfully ";
   }
  void reg()
  {     ifstream ifile;
	employee a;
	ifile.open("emp.dbf");
	cout.setf(ios::left);         //formatting output
	line();
	cout<<endl<<setw(8)<<"Code"<<setw(12)<<"Employee"<<setw(10)<<"B.S."<<setw(10)<<"D.A."<<setw(10)<<"M.A."<<setw(10)<<"H.R.A."<<setw(10)<<"P.F."<<setw(10)<<"Total";
	line();
	while(!ifile.eof())
	{  ifile.read((char *)&a,sizeof a);
	   if(!ifile.eof())
	   cout<<endl<<setw(8)<<a.code<<setw(12)<<a.name<<setw(10)<<a.basic_salary<<setw(10)<<a.basic_salary*0.3<<setw(10)<<a.basic_salary*0.15<<setw(10)<<a.basic_salary*0.1<<setw(10)<<a.basic_salary*0.156<<setw(10)<<a.basic_salary*1.806;
	  }
	  cout<<endl;
	  line();
   }

   void payslip()
   {	 ifstream ifile;
	ifile.open("emp.dbf");
	int check=0;
	char input[10];
	employee a;
	cout<<"Enter emplyee code: ";
	gets(input);
	while(!ifile.eof())
	{   ifile.read((char *)&a,sizeof a);
		if(strcmp(a.code,input)==0)
		{   check=1;
		    break;
		}
	}
	if(check==0)
	cout<<"ERROR! Employee not found \nTRY AGAIN ";
	if(check)
	{
		cout<<endl<<"\t\t\tANY-COMP"<<endl;

		cout<<"\t\t\tPayslip"<<endl;

		cout<<"\nName: "<<a.name<<"\t\tCode: "<<a.code<<endl;
		line();
		cout<<endl<<"\tParticulars\tAmount\n";
		line();
		cout<<endl;
		cout<<setw(20)<<"Basic\t"<<a.basic_salary<<endl;
		cout<<setw(20)<<"D.A\t"<<a.basic_salary*0.3<<endl;
		cout<<setw(20)<<"Medical allowances\t"<<a.basic_salary*0.15<<endl;
		cout<<setw(20)<<"H.R.A\t"<<a.basic_salary*0.1<<endl;
		cout<<setw(20)<<"Provident Fund\t"<<a.basic_salary*0.156<<endl;
		line();
		cout<<"\n\tTotal:"<<setw(14)<<a.basic_salary*1.806;
       }        cout<<endl;
		line();
}

void pf_statement()
{	ifstream ifile;
	employee a;
	ifile.open("emp.dbf");
	cout<<"\t\t\tANY-COMP\n\t\t\tPF STATEMENT \n";
	cout.setf(ios::left);
	line();
	cout<<endl<<setw(10)<<"Code"<<setw(15)<<"Name"<<setw(12)<<"PF"<<setw(12)<<"EPF"<<setw(12)<<"CPF"<<endl;
	line();
	cout<<endl;
	while(!ifile.eof())
	{	ifile.read((char *)&a,sizeof a);

		if(!ifile.eof())
		cout<<setw(10)<<a.code<<setw(15)<<a.name<<setw(12)<<a.basic_salary*0.156<<setw(12)<<a.basic_salary*0.104<<setw(12)<<a.basic_salary*0.052<<endl;

	 }
	      line();
}

void bank_statement()
{	ifstream ifile;
	employee a;
	ifile.open("emp.dbf");
	cout<<"\t\t\tANY-COMP \n\t\t\t Bank statement \n";
	line();
	cout<<setw(15)<<"Account Number"<<setw(12)<<"Name"<<setw(10)<<"Salary "<<endl;
	line();
	while(!ifile.eof())
	{	ifile.read((char *)&a,sizeof a);
		if(!ifile.eof())
		cout<<endl<<setw(15)<<a.acc<<setw(12)<<a.name<<setw(10)<<a.basic_salary;
	}
	cout<<endl;
	line();
}
    void data_management()
    {   char choice;
	cout<<"\n1.Data Entry \n2.Data update \n3.Data delete \n";
	choice=getch();
	switch(choice)
	{	case '1':data_entry();
			break;
		case '2':data_update();
			break;
		case '3':data_delete();
			break;
		default:cout<<"Invalid choice ";
	 }
    }
   void main()
{
    clrscr();
    char choice;
    cout<<"\nWELCOME TO SALARY PORTAL OF (ANY-COMP) \n";
    cout<<"1.Data management\n2.Payslip\n3.Register\n4.PF statement\n5.Bank statement \n6.Exit\n";
    choice=getch();
    switch(choice)
    {  case'1': data_management();
		break;
       case '2':payslip();
		break;
       case '3':reg();
		break;
       case '4':pf_statement();
		break;
       case '5':bank_statement();
		break;
       case '6':exit(0);
		break;
       default:cout<<"Invalid choice";
      }
	       getch();
}