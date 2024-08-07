#ifndef BANK_HPP
#define BANK_HPP

#ifndef RECORD_HPP
#include "Record.hpp"
#endif

#ifndef FUNCTION_HPP
#include "Function.hpp"
#endif

#ifndef FSTREAM_H
#include <fstream>
#endif

#ifndef WINDOWS_H
#include <windows.h>
#endif

#ifndef CONIO_H
#include <conio.h>
#endif

#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef IOMANIP
#include <iomanip>
#endif

using namespace std;

class Bank : public Record
{
	private:
	unsigned int vol_Apos;
	unsigned int vol_Aneg;
    unsigned int vol_Bpos;
	unsigned int vol_Bneg;
	unsigned int vol_ABpos;
	unsigned int vol_ABneg;
    unsigned int vol_Opos;
    unsigned int vol_Oneg;
     int donatno;
     int transno;

	public:

		Bank();

		void incBag(string);

		void decBag(string);

		void writeBankData();

		void addDonation(string,string,string,string);

        bool volumeCheck(string);

		void addTransfusion(string,string,string,string);

		void displayRecord();

		void displayHistory();

		void readBankData(int =0);

		friend class Admin;

};

#endif
