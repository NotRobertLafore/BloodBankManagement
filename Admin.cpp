#include "Admin.hpp"

using namespace std;

Admin::Admin(std::string a, std::string b): username(a), password(b), patno(0)
{
}

Admin::Admin() : username("default"), password("123"), patno(0)
{

}

void Admin::displayBankRecord()
{
        B.readBankData();
		B.displayRecord();

}

void Admin::displayBankHistory()
{
        B.readBankData();
        B.displayHistory();
}

void Admin::addDonation(string a, string b,string c,string d)
{
    B.readBankData();
    B.addDonation(a,b,c,d);
    B.incBag(b);
    B.writeBankData();
}

void Admin::addTransfusion(string a, string b,string c,string d)
{
    B.readBankData();
    B.addTransfusion(a,b,c,d);
    B.decBag(b);
    B.writeBankData();
}

void Admin::addNewUser()
{
	std::string a;
	std::string b;
	int c;
	char d;
	bool e;
	std::string f;
	std::string g;

	std::cout<<"Input first name of patient: ";
	std::getline(std::cin,a);
	std::cout<<"Input last name of patient: ";
	std::getline(std::cin,b);
	std::cout<<"Enter age of patient: ";
	c=intCheck(-1,121);
	std::cout<<"Enter blood type: ";
	string newblood;
	newblood=bloodGroupCheck();
	bloodCentrifuge(newblood,&d,&e);


	std::cout<<"Enter username: ";
	std::cin.ignore(5,'\n');
	std::getline(std::cin,f);
	std::cout<<"Enter password: ";
	std::getline(std::cin,g);

	pat[patno] = new Patient(a,b,c,d,e,f,g);
	patno++;
    writeData();
    cout<<"\nNew user account created successfully";
}

void Admin::listProfile(int mode)
{
    readData();
    cout<<"List of Profiles:\n\n";

    if(mode==0)
    {
        cout.setf(ios::left);
        cout<<setw(3)<<"#";
        cout.unsetf(ios::left);
        cout<<setw(10)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Age"<<setw(15)<<"Blood Type"<<endl;
        int i;
        for(i=0;i<patno;i++)
        {
            cout.setf(ios::left);
            cout<<setw(3)<<i+1;
            cout.unsetf(ios::left);
            cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
        }
    }
    else if(mode==1)
    {
        cout.setf(ios::left);
        cout<<setw(3)<<"#";
        cout.unsetf(ios::left);
        cout<<setw(10)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Age"<<setw(15)<<"Blood Type"<<setw(15)<<"Username"<<setw(15)<<"Password"<<endl;
        int i;
        for(i=0;i<patno;i++)
        {
            cout.setf(ios::left);
            cout<<setw(3)<<i+1;
            cout.unsetf(ios::left);
            cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<setw(15)<<pat[i]->retUsername()<<setw(15)<<pat[i]->retPassword()<<endl;
        }
    }



}

void Admin::editProfile()
{

    cout<<"\nPlease enter the profile you want to view:\nPress 0 to exit\n";
    int choice=0;

    if(patno==0)
    {
        cout<<"No profiles made yet\n";
        _getch();
        return;
    }

        choice=intCheck(-1,patno+1);

        if(choice==0)
        {
            return;
        }

    system("cls");
    cout<<"Personal information: \n\n";

    displayPatInfo(choice-1);

    cout<<"\nDo you want to modify user information?\n";
    char choice2;
    choice2=choiceCheck();

    if(choice2=='Y')
    {

        cout<<"\nWhat information do you want to edit?\n";
        int choice3;

        choice3=intCheck(0,8);

        if(choice3==1)
        {
            pat[choice-1]->changeFname();
        }
        else if(choice3==2)
        {
            pat[choice-1]->changeLname();
        }
        else if(choice3==3)
        {
            pat[choice-1]->changeAge();
        }
        else if(choice3==4)
        {
            pat[choice-1]->changeBlood();
        }
        else if(choice3==5)
        {
            pat[choice-1]->changeUsername();
        }
        else if(choice3==6)
        {
            pat[choice-1]->changePassword();
        }
        else if(choice3==7)
        {
            pat[choice-1]->changeBlood();
        }

        writeData();
    }
}

void Admin::compatibilityCheck()
{
    cout<<"\nPlease enter the profile you want to view:\n";
    int choice=0;

    choice=intCheck(0,patno+1);
    choice--;
    system("cls");
    cout<<pat[choice]->retfname()<<' '<<pat[choice]->retlname()<<"("<<pat[choice]->retBloodString()<<")"<<" can receive blood from:\n\n";

    cout.setf(ios::left);
    cout<<setw(3)<<"#";
    cout.unsetf(ios::left);
    cout<<setw(10)<<"First Name"<<setw(15)<<"Last Name"<<setw(15)<<"Age"<<setw(15)<<"Blood Type"<<endl;

    if(pat[choice]->retBloodString()=="O-")
    {   int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="O-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="O+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="O-"||pat[i]->retBloodString()=="O+")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="A+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="A+"||pat[i]->retBloodString()=="A-"||pat[i]->retBloodString()=="O+"||pat[i]->retBloodString()=="O-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="A-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="A-"||pat[i]->retBloodString()=="O-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="B+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="B+"||pat[i]->retBloodString()=="B-"||pat[i]->retBloodString()=="O+"||pat[i]->retBloodString()=="O-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="B-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="B-"||pat[i]->retBloodString()=="O-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="AB+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;

        }
    }
    else if(pat[choice]->retBloodString()=="AB-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="B-"||pat[i]->retBloodString()=="O-"||pat[i]->retBloodString()=="A-"||pat[i]->retBloodString()=="AB-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }

    cout<<"\nCan Donate To:\n\n";

    if(pat[choice]->retBloodString()=="O-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
        }
    }
    else if(pat[choice]->retBloodString()=="O+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+"||pat[i]->retBloodString()=="O+"||pat[i]->retBloodString()=="A+"||pat[i]->retBloodString()=="B+")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="A+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+"||pat[i]->retBloodString()=="A+")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="A-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+"||pat[i]->retBloodString()=="AB-"||pat[i]->retBloodString()=="A+"||pat[i]->retBloodString()=="A-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="B+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+"||pat[i]->retBloodString()=="B+")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="B-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+"||pat[i]->retBloodString()=="AB-"||pat[i]->retBloodString()=="B+"||pat[i]->retBloodString()=="B-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="AB+")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }
    else if(pat[choice]->retBloodString()=="AB-")
    {
        int j=1;
        for(int i=0;i<patno;i++)
        {
            if(i==choice)
            {
                continue;
            }

            if(pat[i]->retBloodString()=="AB+"||pat[i]->retBloodString()=="AB-")
            {
                cout.setf(ios::left);
                cout<<setw(3)<<j++;
                cout.unsetf(ios::left);
                cout<<setw(10)<<pat[i]->retfname()<<setw(15)<<pat[i]->retlname()<<setw(15)<<pat[i]->retage()<<setw(15)<<pat[i]->retBloodString()<<endl;
            }
        }
    }

}

void Admin::writeData()
{
	ofstream writer;
	writer.open("Data/AccountData.txt");
    int i;
	for(i=0;i<patno;i++)
	{
		writer<<pat[i]->fname<<' ';
		writer<<pat[i]->lname<<' ';
		writer<<pat[i]->age<<' '<<pat[i]->b_type<<' '<<pat[i]->Rh<<' ';
		writer<<pat[i]->username<<' ';
		writer<<pat[i]->password<<' ';
		writer<<pat[i]->donatno<<' ';
		writer<<pat[i]->transno<<' ';
	}

	writer.close();

    ofstream writer2;
    writer2.open("Data/PatientHistory.txt");

    for(int i=0;i<patno;i++)
    {
     writer2<<i<<'\n';

        for(int j=0;j<pat[i]->retDonatno();j++)
        {
            writer2<<pat[i]->donationHistory[j][0]<<'\n';
        }

    }
    writer2<<"Transactions\n";
    for(int i=0;i<patno;i++)
    {
     writer2<<i<<'\n';

        for(int j=0;j<pat[i]->retTransno();j++)
        {
            writer2<<pat[i]->transfusionHistory[j][0]<<'\n';
            writer2<<pat[i]->transfusionHistory[j][1]<<'\n';
        }

    }

    writer2.close();

}

void Admin::readData()
{
	ifstream reader;
	reader.open("Data/AccountData.txt");

	int i=0;

	if(reader.is_open()==0)
    {

    }
    else
    {

    while(reader.good())
    {
	pat[i] = new Patient;

	reader>>pat[i]->fname;
	reader>>pat[i]->lname;
	reader>>pat[i]->age>>pat[i]->b_type>>pat[i]->Rh;
	reader>>pat[i]->username;
	reader>>pat[i]->password;
	reader>>pat[i]->donatno;
	reader>>pat[i]->transno;
	i++;
	}

    patno=i-1;
    }
//    if(bad==0)
//    {
//        loadingBar("Reading",1);
//    }
//    else
//    {
//        loadingBar("Reading",0);
//        cout<<"\nResetting Account Data..."<<endl;
//    }

    reader.close();

    ifstream infile2;

    infile2.open("Data/PatientHistory.txt");

    i=0;
    int pos;
    char ch;

           infile2.seekg(3);

     for(int j=0;j<patno;j++)
     {

        for(int i=0;i<pat[j]->retDonatno();i++)
        {
            if(pat[j]->retDonatno()!=0)
            {
                getline(infile2,pat[j]->donationHistory[i][0]);
            }
            else{
                infile2.get();
            }

        }
        infile2.get();
        infile2.get();
     }


  //  }



//    {
//        for(int k=0;k<patno;k++)
//        {
//          infile2.get(ch);
//          for(int j=0;j<pat[i]->retDonatno();j++)
//          {
//              getline(infile2,pat[j]->donationHistory[j][0]);
//          }
//        }
//        for(int k=0;k<patno;k++)
//        {
//          infile2.get(ch);
//          for(int j=0;j<pat[i]->retTransno();j++)
//          {
//              getline(infile2,pat[j]->transfusionHistory[j][0]);
//              getline(infile2,pat[j]->transfusionHistory[j][1]);
//          }
//        }
//    }


//     for(int i=0;i<patno;i++)
//    {
//     writer2<<i<<'\n';
//
//        for(int j=0;j<pat[i]->retDonatno();j++)
//        {
//            writer2<<pat[i]->donationHistory[j][0]<<'\n';
//        }
//
//    }
//    writer2<<"Transactions\n";
//    for(int i=0;i<patno;i++)
//    {
//     writer2<<i<<'\n';
//
//        for(int j=0;j<pat[i]->retTransno();j++)
//        {
//            writer2<<pat[i]->transfusionHistory[j][0]<<'\n';
//            writer2<<pat[i]->transfusionHistory[j][1]<<'\n';
//        }
//
//    }



}

void Admin::readBloodData()
{


}

void Admin::display(int a)
{

	pat[a]->showDonationHistory();
    pat[a]->showTransfusionHistory();
}

void Admin::displayPatInfo(int a)
{
	pat[a]->displayInfo();
}

int Admin::retPatno()
{
	return patno;
}

bool Admin::retUsermatch(int a, string b)
{
	if(pat[a]->retUsername()==b)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Admin::retPassmatch(int a, string b)
{
	if(pat[a]->retPassword()==b)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Admin::volumeCheck(string a)
{

    return B.volumeCheck(a);

}
