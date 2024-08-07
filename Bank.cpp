#include "Bank.hpp"

Bank::Bank() : Record(), vol_Apos(0), vol_Aneg(0), vol_Bpos(0), vol_Bneg(0), vol_ABpos(0), vol_ABneg(0), vol_Opos(0), vol_Oneg(0), donatno(0), transno(0)
{
    readBankData(1);

}

void Bank::incBag(string a)
{
	if(a=="A+")
	{
        vol_Apos+=450;
	}
	else if(a=="A-")
	{
        vol_Aneg+=450;
	}
	else if(a=="B+")
	{
        vol_Bpos+=450;
	}
	else if(a=="B-")
	{
        vol_Bneg+=450;
	}
	else if(a=="AB+")
	{
        vol_ABpos+=450;
	}
	else if(a=="AB-")
	{
        vol_ABneg+=450;
	}
	else if(a=="O+")
	{
	    vol_Opos+=450;
	}
	else if(a=="O-")
	{
        vol_Oneg+=450;
	}


}

void Bank::decBag(string a)
{

	if(a=="A+")
	{
        vol_Apos-=450;
	}
	else if(a=="A-")
	{
        vol_Aneg-=450;
	}
	else if(a=="B+")
	{
        vol_Bpos-=450;
	}
	else if(a=="B-")
	{
        vol_Bneg-=450;
	}
	else if(a=="AB+")
	{
        vol_ABpos-=450;
	}
	else if(a=="AB-")
	{
        vol_ABneg-=450;
	}
	else if(a=="O+")
	{
	    vol_Opos-=450;
	}
	else if(a=="O-")
	{
        vol_Oneg-=450;
	}


}

void Bank::addDonation(string time,string btype, string fname,string lname)
{

	donationHistory[donatno][0]=time;
	donationHistory[donatno][1]=btype;
	donationHistory[donatno][2]=fname;
	donationHistory[donatno][3]=lname;
    donatno++;
}

void Bank::addTransfusion(string time,string btype,string fname,string lname)
{

	transfusionHistory[transno][0]=time;
	transfusionHistory[transno][1]=btype;
	transfusionHistory[transno][2]=fname;
	transfusionHistory[transno][3]=lname;
    transno++;
}

void Bank::writeBankData()
{
	ofstream outfile;
	outfile.open("Data/BankVolume.dat",ios::binary);

	outfile.write(reinterpret_cast<char*>(&vol_Apos),sizeof(vol_Apos));
	outfile.write(reinterpret_cast<char*>(&vol_Aneg),sizeof(vol_Aneg));
	outfile.write(reinterpret_cast<char*>(&vol_Bpos),sizeof(vol_Bpos));
	outfile.write(reinterpret_cast<char*>(&vol_Bneg),sizeof(vol_Bneg));
	outfile.write(reinterpret_cast<char*>(&vol_ABpos),sizeof(vol_ABpos));
	outfile.write(reinterpret_cast<char*>(&vol_ABneg),sizeof(vol_ABneg));
	outfile.write(reinterpret_cast<char*>(&vol_Opos),sizeof(vol_Opos));
	outfile.write(reinterpret_cast<char*>(&vol_Oneg),sizeof(vol_Oneg));
//	outfile.write(reinterpret_cast<char*>(&donatno),sizeof(donatno));
//	outfile.write(reinterpret_cast<char*>(&transno),sizeof(transno));
	outfile.close();

	ofstream outfile2;
	outfile2.open("Data/DonationHistory.txt");

	for(int i=0;i<donatno;i++)
    {
        outfile2<<donationHistory[i][0]<<'\n';
        outfile2<<donationHistory[i][1]<<'\n';
        outfile2<<donationHistory[i][2]<<'\n';
        outfile2<<donationHistory[i][3]<<'\n';
    }

    outfile2.close();

    ofstream outfile3;
	outfile3.open("Data/TransfusionHistory.txt");

	for(int i=0;i<transno;i++)
    {
        outfile3<<transfusionHistory[i][0]<<"\n";
        outfile3<<transfusionHistory[i][1]<<"\n";
        outfile3<<transfusionHistory[i][2]<<"\n";
        outfile3<<transfusionHistory[i][3]<<"\n";
    }

    outfile3.close();

}

void Bank::readBankData(int mode)
{
    bool donatcheck=false;
	ifstream infile;
	infile.open("Data/BankVolume.dat",ios::binary);

    if(infile.good()==0)
    {
        if(mode==1)
        {
        loadingBar("Reading",0);
        cout<<"Bank Volume Data file unreadable\n";
        donatcheck=true;
        }

        donatcheck=true;
    }
    else
    {

        infile.read(reinterpret_cast<char*>(&vol_Apos),sizeof(vol_Apos));
        infile.read(reinterpret_cast<char*>(&vol_Aneg),sizeof(vol_Aneg));
        infile.read(reinterpret_cast<char*>(&vol_Bpos),sizeof(vol_Bpos));
        infile.read(reinterpret_cast<char*>(&vol_Bneg),sizeof(vol_Bneg));
        infile.read(reinterpret_cast<char*>(&vol_ABpos),sizeof(vol_ABpos));
        infile.read(reinterpret_cast<char*>(&vol_ABneg),sizeof(vol_ABneg));
        infile.read(reinterpret_cast<char*>(&vol_Opos),sizeof(vol_Opos));
        infile.read(reinterpret_cast<char*>(&vol_Oneg),sizeof(vol_Oneg));
//      infile.read(reinterpret_cast<char*>(&donatno),sizeof(donatno));
//      infile.read(reinterpret_cast<char*>(&transno),sizeof(transno));
        infile.close();
        }

	ifstream infile2;

	infile2.open("Data/DonationHistory.txt");

	if(infile2.good()==0)
    {
        if(mode==1)
        {
         loadingBar("Reading",0);
        cout<<"Donation History file unreadable\n";
        donatno=0;
        }

        donatno=0;
    }
    else
    {
        int i=0;

        while(!infile2.eof())
        {
            getline(infile2,donationHistory[i][0]);
            getline(infile2,donationHistory[i][1]);
            getline(infile2,donationHistory[i][2]);
            getline(infile2,donationHistory[i][3]);
            i++;
        }
        infile2.close();
        donatno=i-1;

    }


	ifstream infile3;
    infile3.open("Data/TransfusionHistory.txt");

	if(infile3.good()==0)
    {
        if(mode==1)
        {
        loadingBar("Reading",0);
        cout<<"Transfusion History file unreadable\n";
        }

        transno=0;
    }
    else
    {
        int j=0;

        while(!infile3.eof())
        {
            getline(infile3,transfusionHistory[j][0]);
            getline(infile3,transfusionHistory[j][1]);
            getline(infile3,transfusionHistory[j][2]);
            getline(infile3,transfusionHistory[j][3]);
            j++;
        }

        infile3.close();


         transno=j-1;

        if(mode==1)
        {
            loadingBar();
        }

    }
    Sleep(1000);
}

void Bank::displayRecord()
{
	cout<<"\t\tVersaLife Blood Stock\n\n";

	cout<<"A+: "<<vol_Apos<<"ml"<<endl;
	cout<<"A-: "<<vol_Aneg<<"ml"<<endl;
	cout<<"B+: "<<vol_Bpos<<"ml"<<endl;
	cout<<"B-: "<<vol_Bneg<<"ml"<<endl;
	cout<<"AB+: "<<vol_ABpos<<"ml"<<endl;
	cout<<"AB-: "<<vol_ABneg<<"ml"<<endl;
	cout<<"O+: "<<vol_Opos<<"ml"<<endl;
	cout<<"O-: "<<vol_Oneg<<"ml"<<endl;

	cout<<"\n\n\n";
}

void Bank::displayHistory()
{
    cout<<"Donation History:\n";

    cout.setf(ios::left);
    cout<<setw(5)<<"#"<<setw(24)<<"Time";
    cout.unsetf(ios::left);
    cout<<setw(15)<<"Blood Type"<<setw(15)<<"Name"<<endl;
        int i;
        for(i=0;i<donatno;i++)
        {
            cout.setf(ios::left);
            cout<<setw(5)<<i+1;
            cout.unsetf(ios::left);
            cout<<setw(24)<<donationHistory[i][0]<<setw(15)<<donationHistory[i][1]<<setw(15)<<donationHistory[i][2]<<' '<<donationHistory[i][3]<<endl;
        }

//	for(int i=0;i<donatno;i++)
//	{
//		cout<<setw(30)<<"Time: "<<donationHistory[i][0]<<"\tBlood Type: "<<donationHistory[i][1]<<"\tName: "<<donationHistory[i][2]<<donationHistory[i][3]<<endl;
//	}

	cout<<"\nTransfusion History:\n";

	 cout.setf(ios::left);
    cout<<setw(5)<<"#"<<setw(24)<<"Time";
    cout.unsetf(ios::left);
    cout<<setw(15)<<"Blood Type"<<setw(15)<<"Name"<<endl;

        for(i=0;i<transno;i++)
        {
            cout.setf(ios::left);
            cout<<setw(5)<<i+1;
            cout.unsetf(ios::left);
            cout<<setw(24)<<transfusionHistory[i][0]<<setw(15)<<transfusionHistory[i][1]<<setw(15)<<transfusionHistory[i][2]<<' '<<transfusionHistory[i][3]<<endl;
        }

//	for(int i=0;i<transno;i++)
//	{
//		cout<<setw(30)<<"Time: "<<transfusionHistory[i][0]<<"\tBlood Type: "<<transfusionHistory[i][1]<<"\tName: "<<transfusionHistory[i][2]<<transfusionHistory[i][3]<<endl;
//	}
}

bool Bank::volumeCheck(string a)
{

    if(a=="A+")
    {
        return (vol_Apos>=450) ? true : false;

    }
    else if(a=="A-")
    {
        return (vol_Aneg>=450) ? true : false;

    }
    else if(a=="B+")
    {
        return (vol_Bpos>=450) ? true : false;

    }
    else if(a=="B-")
    {
        return (vol_Bneg>=450) ? true : false;

    }
    else if(a=="AB+")
    {
        return (vol_ABpos>=450) ? true : false;

    }
    else if(a=="AB-")
    {
        return (vol_ABneg>=450) ? true : false;

    }
    else if(a=="O+")
    {
        return (vol_Opos>=450) ? true : false;

    }
    else if(a=="O-")
    {
        return (vol_Oneg>=450) ? true : false;

    }
}
