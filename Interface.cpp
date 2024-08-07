#include "Interface.hpp"

#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef CTIME
#include <ctime>
#endif
using namespace std;

int Interface::loginScreen(Admin a)
{
	int ret=0;
	int flag=0;
	do{
		flag=0;

		cout<<"\t\t\Welcome to VersaLife Blood Bank:\n\n";
		cout<<"Enter Login Information:\n";
		cout<<"Enter username: \n";
		string user,pass;
		getline(cin,user);

		if(user==a.username)
		{
			cout<<"Enter password:\n";
			getline(cin,pass);

			if(pass==a.password)
			{
				cout<<"Login successful!\n";
				Sleep(800);
				system("cls");
				return 100;
			}
			else
			{
				cout<<"Login unsuccessful\n";
				Sleep(800);
				system("cls");
				continue;
			}

		}

		for(int i=0;i<a.retPatno();i++)
		{
			if(a.retUsermatch(i,user)==1)
			{
				cout<<"\nEnter password:\n";
				getline(cin,pass);

				if(a.retPassmatch(i,pass)==1)
				{
					cout<<"Login successful\n";
					ret++;
					Sleep(1000);
					system("cls");
					return i;

				}
				else
				{
					cout<<"Login unsuccessful\n";
					Sleep(1000);
					system("cls");
					break;
				}

			}

		flag++;
		}

		if(flag==a.retPatno())
		{
			cout<<"\nNo such account found\n";
            Sleep(1000);
            system("cls");
		}


	}while(ret==0);

}

int Interface::AdmainScreen(Admin a)
{
    cout<<"\t\tVersaLife Blood Bank\n\n";
    cout<<"Administrator Account\n";

	cout<<"Select an option: \n\n";
    cout.setf(ios::left);
	cout<<setw(30)<<"1: View Stock"<<setw(25)<<"2: View History"<<endl;
	cout<<setw(30)<<"3: View Profiles"<<setw(25)<<"4: Add a New User"<<endl;
	cout<<setw(30)<<"5: Check User Compatibility"<<setw(25)<<"6: Logout"<<endl;
	cout<<setw(30)<<"7: Exit"<<endl;
	cout.unsetf(ios::left);

	int out=100;

	while(out!=1&&out!=2&&out!=3&&out!=4&&out!=5&&out!=6&&out!=7)
	{
		out=intCheck();
	}

	if(out==1)
    {
        system("cls");
        a.displayBankRecord();
        _getch();
    }
    else if(out==2)
    {
        system("cls");
        a.displayBankHistory();
        _getch();
    }
    else if(out==3)
    {
        system("cls");
        a.listProfile(0);
        a.editProfile();
    }
    else if(out==4)
    {
        system("cls");
        a.addNewUser();
        a.writeData();
        a.readData();
        Sleep(1000);
    }
    else if(out==5)
    {
        system("cls");
        a.listProfile(0);
        a.compatibilityCheck();
        _getch();
    }

	return out;


}


int Interface::mainScreen(Admin a,int acc)
{
    if(acc==100)
    {
        return AdmainScreen(a)+10;
    }

	cout<<"\t\tVersaLife Blood Bank\n\n";

	cout<<"Select an option: \n\n";
    cout.setf(ios::left);
	cout<<setw(30)<<"1: Donate Blood"<<setw(25)<<"2: Request Transfusion"<<endl;
	cout<<setw(30)<<"3: Set Personal Information"<<setw(25)<<"4: Logout"<<endl;
	cout<<setw(30)<<"5: Exit"<<endl;
	cout.unsetf(ios::left);

	int out=0;
	while(out!=1&&out!=2&&out!=3&&out!=4&&out!=5)
	{
		out=intCheck();
	}

	return out;

}

void Interface::bloodDonationSc(Admin a, int acc)
{
	cout<<"Please confirm that you would like to make a blood donation. Y/N\n";
	char choice;



	do{
		choice=choiceCheck();
		if(choice=='y'||choice=='Y')
		{
			cout<<"Blood successfully donated!\n";
			time_t curr_time;
			time(&curr_time);
			string x=asctime(localtime(&curr_time));
			x.erase(x.length()-1,x.length());
			a.pat[acc]->addDonationHistory(x);


            a.addDonation(x,a.pat[acc]->retBloodString(),a.pat[acc]->retfname(),a.pat[acc]->retlname());
            a.writeData();
            cout<<"\nReceipt:\n\n";
            cout<<setw(12)<<"First Name"<<setw(12)<<"Last Name"<<setw(5)<<"Age"<<setw(15)<<"Blood Type";
            cout.setf(ios::left);
            cout<<setw(30)<<"\tTime"<<endl<<endl;
            cout.unsetf(ios::left);
            cout<<setw(12)<<a.pat[acc]->retfname()<<setw(12)<<a.pat[acc]->retlname()<<setw(5)<<a.pat[acc]->retage()<<setw(15)<<a.pat[acc]->retBloodString()<<setw(30)<<x<<endl;
            cout<<"\n\nPress any key to proceed";
            _getch();
		}
		else if(choice=='n'||choice=='N')
		{
			cout<<"Blood not donated\nThank you for applying";
			Sleep(1000);
		}
		else
		{
			cout<<"Invalid choice, please re-enter";
		}
	}while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');

}

void Interface::bloodTransfusionSc(Admin a,int acc)
{
    time_t curr_time;
    time(&curr_time);
    string x=asctime(localtime(&curr_time));
    x.erase(x.length()-1,x.length());

	char btype=a.pat[acc]->retBtype();
	bool rh = a.pat[acc]->retRh();
	string fname = a.pat[acc]->retfname();
	string lname = a.pat[acc]->retlname();

	bool receiptFlag=0;

	cout<<"The available compatible Blood Types in the bank for you:\n";

	if(btype=='A'&&rh==true)
	{

		cout<<"1: A+\n";
		cout<<"2: A-\n";
		cout<<"3: O+\n";
		cout<<"4: O-\n";

		cout<<"\n\nPlease select an option:\nPress 0 to exit\n";
		int choice=-5;

		while(choice<0||choice>4)
		{
		choice=intCheck(-1,5);
		}

		system("cls");

        if(choice==0)
        {
            return;
        }
        else if(choice==1)
        {
            if(a.volumeCheck("A+"))
            {
                a.addTransfusion(x,"A+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"A+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("A-"))
            {
                a.addTransfusion(x,"A-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"A-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==3)
        {
            if(a.volumeCheck("O+"))
            {
                a.addTransfusion(x,"O+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==4)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }

	}
	else if(btype=='A'&&rh==false)
	{
		cout<<"1: A-\n";
		cout<<"2: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>2)
		{
		choice=intCheck(0,3);
		}

		if(choice==1)
        {
            if(a.volumeCheck("A-"))
            {
                a.addTransfusion(x,"A-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"A-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }

	}
	else if(btype=='B'&&rh==true)
	{
		cout<<"1: B+\n";
		cout<<"2: B-\n";
		cout<<"3: O+\n";
		cout<<"4: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>4)
		{
		choice=intCheck(0,5);
		}

		if(choice==1)
        {
            if(a.volumeCheck("B+"))
            {
                a.addTransfusion(x,"B+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"B+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("B-"))
            {
                a.addTransfusion(x,"B-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"B-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==3)
        {
            if(a.volumeCheck("O+"))
            {
                a.addTransfusion(x,"O+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==4)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }


	}
	else if(btype=='B'&&rh==false)
	{
		cout<<"1: B-\n";
		cout<<"2: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>2)
		{
		choice=intCheck(0,3);
		}

		if(choice==1)
        {
            if(a.volumeCheck("B-"))
            {
                a.addTransfusion(x,"B-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"B-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }

	}
	else if(btype=='C'&&rh==true)
	{
		cout<<"1: A+\n";
		cout<<"2: A-\n";
		cout<<"3: B+\n";
		cout<<"4: B-\n";
		cout<<"5: AB+\n";
		cout<<"6: AB-\n";
		cout<<"7: O+\n";
		cout<<"8: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>8)
		{
		choice=intCheck(0,9);
		}

		if(choice==1)
        {
            if(a.volumeCheck("A+"))
            {
                a.addTransfusion(x,"A+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"A+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("A-"))
            {
                a.addTransfusion(x,"A-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"A-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==3)
        {
            if(a.volumeCheck("B+"))
            {
                a.addTransfusion(x,"B+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"B+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==4)
        {
            if(a.volumeCheck("B-"))
            {
                a.addTransfusion(x,"B-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"B-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==5)
        {
            if(a.volumeCheck("AB+"))
            {
                a.addTransfusion(x,"AB+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"AB+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==6)
        {
            if(a.volumeCheck("AB-"))
            {
                a.addTransfusion(x,"AB-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"AB-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==7)
        {
            if(a.volumeCheck("O+"))
            {
                a.addTransfusion(x,"O+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==8)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }

	}
	else if(btype=='C'&&rh==false)
	{
		cout<<"1: A-\n";
		cout<<"2: B-\n";
		cout<<"3: AB-\n";
		cout<<"4: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>4)
		{
		choice=intCheck(0,5);
		}

        if(choice==1)
        {
            if(a.volumeCheck("A-"))
            {
                a.addTransfusion(x,"A-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"A-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("B-"))
            {
                a.addTransfusion(x,"B-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"B-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==3)
        {
            if(a.volumeCheck("AB-"))
            {
                a.addTransfusion(x,"AB-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"AB-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==4)
        {
            if(a.volumeCheck("O-")==1)
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }


	}
	else if(btype=='O'&&rh==true)
	{
		cout<<"1: O+\n";
		cout<<"2: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>2)
		{
		choice=intCheck(0,3);
		}

        if(choice==1)
        {
            if(a.volumeCheck("O+"))
            {
                a.addTransfusion(x,"O+",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O+");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
        else if(choice==2)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }

	}
	else if(btype=='O'&&rh==false)
	{
		cout<<"1: O-\n";

		cout<<"\n\nPlease select an option:\n";
		int choice=0;

		while(choice<1||choice>1)
		{
		choice=intCheck(0,2);
		}

        if(choice==1)
        {
            if(a.volumeCheck("O-"))
            {
                a.addTransfusion(x,"O-",fname,lname);
                a.pat[acc]->addTransfusionHistory(x,"O-");
                receiptFlag=!receiptFlag;
            }
            else
            {
                cout<<"The selected blood type is not available in the bank currently\n";
            }
        }
	}


    if(receiptFlag==1)
    {
        cout<<"Blood Transfusion successful\n\n";

        cout<<"\nReceipt:\n\n";
        cout<<setw(12)<<"First Name"<<setw(12)<<"Last Name"<<setw(5)<<"Age"<<setw(15)<<"Blood Type";
        cout.setf(ios::left);
        cout<<setw(30)<<"\tTime"<<endl<<endl;
        cout.unsetf(ios::left);
        cout<<setw(12)<<a.pat[acc]->retfname()<<setw(12)<<a.pat[acc]->retlname()<<setw(5)<<a.pat[acc]->retage()<<setw(15)<<a.pat[acc]->retBloodString()<<setw(30)<<x<<endl;
        cout<<"\n\nPress any key to proceed";


    }

    a.writeData();
    _getch();
}

void Interface::editPatientInfo(Admin a,int acc)
{

    int choice;
    do{
	cout<<"Personal information: \n\n";

	a.displayPatInfo(acc);

	cout<<"\nWhat information do you want to edit?\nPress 0 to exit\n";

		choice=intCheck();

		if(choice==4||choice==5)
		{
			cout<<"That information cannot be edited\n";
            Sleep(1000);
		}

        system("cls");
	}
	while(choice!=1&&choice!=2&&choice!=3&&choice!=6&&choice!=7&&choice!=0);

	if(choice==1)
	{
		a.pat[acc]->changeFname();
	}
	else if(choice==2)
	{
		a.pat[acc]->changeLname();
	}
	else if(choice==3)
	{
		a.pat[acc]->changeAge();
	}
	else if(choice==6)
	{
		a.pat[acc]->changePassword();
	}
	else if(choice==7)
	{
		a.pat[acc]->changeBlood();
	}
    else if(choice==0)
    {
    return;
    }

	a.writeData();

}
