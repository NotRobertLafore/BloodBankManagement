#include "Patient.hpp"

using namespace std;

Patient::Patient() : Person(), Record()
{

}

Patient::Patient(string a, string b) : username(a), password(b), Person(), Record()
{
}

Patient::Patient(std::string a,std::string b,int c,char d,bool e,std::string f,std::string g) : Person(a,b,c), b_type(d), Rh(e), username(f), password(g)
{
}

string Patient::retfname()
{
    return fname;
}

int Patient::retage()
{
    return age;
}

string Patient::retlname()
{
    return lname;
}

string Patient::retUsername()
	{
		return username;
	}

string Patient::retPassword()
{
	return password;
}

char Patient::retBtype()
{
	return b_type;
}

bool Patient::retRh()
{
	return Rh;
}

void Patient::displayInfo()
{
    std::cout<<"1: First name: "<<fname<<std::endl;
    std::cout<<"2: Last name: "<<lname<<std::endl;
    std::cout<<"3: Age: "<<age<<std::endl;
    std::cout<<"4: Blood Type: "<<retABtype();
    std::cout<<retRh2()<<std::endl;
    std::cout<<"5: Username: "<<username<<std::endl;
    std::cout<<"6: Password: "<<password<<std::endl;

}

void Patient::addDonationHistory(string a)
{
	donationHistory[donatno][0]=a;
	donatno++;
}

void Patient::addTransfusionHistory(string a,string b)
{
    transfusionHistory[transno][0]=a;
    transfusionHistory[transno][1]=b;
    transno++;
}

void Patient::showDonationHistory()
{
    cout<<"Donation History:\n";

    for(int i=0;i<donatno;i++)
    {
        cout<<donationHistory[i][0]<<endl;
    }

}

void Patient::showTransfusionHistory()
{

    cout<<"Transfusion History:\n";

    for(int i=0;i<transno;i++)
    {
        cout<<transfusionHistory[i][0]<<endl;
        cout<<transfusionHistory[i][1]<<endl;
    }
}

string Patient::retBloodString()
{
    string str;

    if(b_type=='C')
	{
        str="AB";


		if(Rh==true)
        {
            str+="+";
        }
        else
        {
            str+="-";
        }
	}
	else
	{
        str=b_type;
		if(Rh==true)
        {
            str+="+";
        }
        else
        {
            str+="-";
        }
	}

	return str;
}

int Patient::retDonatno()
{
	return donatno;
}

int Patient::retTransno()
{
	return transno;
}

char Patient::retRh2()
{

	return (Rh==true) ? '+' : '-';

}

void Patient::changeBlood()
{
	cout<<"Enter new blood";

	string x=bloodGroupCheck();
	if(x.at(0)=='A')
    {
        if(x.at(1)=='B')
        {

            b_type='C';
            if(x.at(2)=='+')
            {
                Rh=true;
            }
            else if(x.at(2)=='-')
            {
                Rh=false;
            }
        }
        else if(x.at(1)=='+')
        {
            b_type='A';
            Rh=true;
        }
        else if(x.at(1)=='-')
        {
            b_type='A';
            Rh=false;
        }

    }
	else if(x.at(0)=='B')
    {
        b_type='B';
        if(x.at(1)=='+')
        {
            Rh=true;
        }
        else if(x.at(1)=='-')
        {
            Rh=false;
        }

    }
    else if(x.at(0)=='O')
    {
        b_type='O';
        if(x.at(1)=='+')
        {
            Rh=true;
        }
        else if(x.at(1)=='-')
        {
            Rh=false;
        }

    }
}

string Patient::retABtype()
{
	if(b_type=='C')
	{
		return "AB";
	}

	else
	{
		string x;
		x=b_type;
		return x;
	}
}

void Patient::donatnoInc()
{
	donatno++;
}

void Patient::operator ++ (int)
{
	donatnoInc();
}

void Patient::changeFname()
{
	cout<<"Enter new first name: ";
	string newname;
	getline(cin,newname);

        fname=newname;
    cout<<"\nName change successful";
    Sleep(1000);

}

void Patient::changeLname()
{
	cout<<"Enter new last name: ";
	string newname;
	getline(cin,newname);
	lname=newname;
    cout<<"\nName change successful";
    Sleep(1000);
}

void Patient::changeAge()
{
	cout<<"Enter age: ";
	int newage;
	do{
    newage=intCheck();

	}while(newage<=0);


	age=newage;
	cout<<"\nAge change successful";
    Sleep(1000);
}

void Patient::changeUsername()
{
    cout<<"Enter new username: ";
	getline(cin,username);

    cout<<"\nUsername change successful";
    Sleep(1000);
}

void Patient::changePassword()
{

	cout<<"Enter new password: ";
	string newpass1,newpass2;
	getline(cin,newpass1);
	cout<<"Re-enter your password\n";
	getline(cin,newpass2);

	if(newpass1!=newpass2)
	{
		cout<<"The password does not match\n";
		Sleep(1000);
		return;
	}
	else
	{
		password=newpass1;
		cout<<"\nPassword change successful";
        Sleep(1000);
	}

}
