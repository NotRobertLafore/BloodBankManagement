#include "Function.hpp"

int intCheck()
{
    int choice;
    while(true)
    {
        cin>>choice;
        if(cin.good())
        {
           cin.ignore(10,'\n');
           break;
        }
        cin.clear();
        cin.ignore(10,'\n');
    }

    return choice;
}

int intCheck(int LL, int UL)
{
    int choice;
    while(true)
    {
        cin>>choice;
        if(cin.good()&&choice>LL&&choice<UL)
        {
           cin.ignore(10,'\n');
           break;
        }
        cin.clear();
        cin.ignore(10,'\n');
    }

    return choice;
}

char choiceCheck()
{
    char choice;
    while(true)
    {
        cin>>choice;
        if(cin.good()&&(choice=='y'||choice=='Y'||choice=='n'||choice=='N'))
        {
           cin.ignore(100,'\n');
           if(choice=='y')
           {
               choice='Y';
           }
           else if(choice=='n')
           {
               choice='N';
           }
           break;
        }
        cin.clear();
        cin.ignore(100,'\n');
    }

    return choice;
}

string bloodGroupCheck()
{

    string bloodgcheck;

	do{

	cin>>bloodgcheck;

	if(bloodgcheck.at(0)!='A'&&bloodgcheck.at(0)!='B'&&bloodgcheck.at(0)!='O')
	{
		cout<<"Invalid blood group. Please re-enter: \n";
		continue;
	}
	else if(bloodgcheck.length()==1||bloodgcheck.length()>3)
	{
		cout<<"Invalid blood group. Please re-enter with appropriate notation: \n";
		continue;
	}
	else if(bloodgcheck.at(0)=='A')
	{
		if(bloodgcheck.at(1)=='B')
		{
			if(bloodgcheck.at(2)=='+')
			{
				break;
			}
			else if(bloodgcheck.at(2)=='-')
			{
				break;
			}

		}

		if(bloodgcheck.at(1)=='+'&&bloodgcheck.length()<3)
		{
			break;
		}
		else if(bloodgcheck.at(1)=='-'&&bloodgcheck.length()<3)
		{
			break;
		}

	}
	else if(bloodgcheck.at(0)=='B')
	{
		if(bloodgcheck.at(1)=='+'&&bloodgcheck.length()<3)
		{
			break;
		}
		else if(bloodgcheck.at(1)=='-'&&bloodgcheck.length()<3)
		{
			break;
		}

	}
	else if(bloodgcheck.at(0)=='O')
	{
		if(bloodgcheck.at(1)=='+'&&bloodgcheck.length()<3)
		{
			break;
		}
		else if(bloodgcheck.at(1)=='-'&&bloodgcheck.length()<3)
		{
			break;
		}

	}

	}while(true);

	return bloodgcheck;
}

void bloodCentrifuge(string x,char* b_type,bool* Rh)
{

    if(x.at(0)=='A')
    {
        if(x.at(1)=='B')
        {

            *b_type='C';
            if(x.at(2)=='+')
            {
                *Rh=true;
            }
            else if(x.at(2)=='-')
            {
                *Rh=false;
            }
        }
        else if(x.at(1)=='+')
        {
            *b_type='A';
            *Rh=true;
        }
        else if(x.at(1)=='-')
        {
            *b_type='A';
            *Rh=false;
        }

    }
	else if(x.at(0)=='B')
    {
        *b_type='B';
        if(x.at(1)=='+')
        {
            *Rh=true;
        }
        else if(x.at(1)=='-')
        {
            *Rh=false;
        }

    }
    else if(x.at(0)=='O')
    {
        *b_type='O';
        if(x.at(1)=='+')
        {
            *Rh=true;
        }
        else if(x.at(1)=='-')
        {
            *Rh=false;
        }

    }

}

void loadingBar(string name,bool res)
{

    cout<<name<<"...\n";
    cout<<"{_________}\r";

    int check=0;
    for(int i=0;i<12;i++)
    {
        srand (time(NULL));
        int t = rand() % 100 + 250;

        while(check!=i)
        {
            cout<<'#';
            check++;
        }
        cout<<'\r';
        Sleep(t);
        check=0;
    }
    cout<<endl;
    if(res==1)
    {
    cout<<name<<" successful\n";
    }
    else if(res==0)
    {
    cout<<name<<" failed\n";
    }

    Sleep(1000);

}
