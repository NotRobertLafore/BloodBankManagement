#ifndef PATIENT_HPP
#define PATIENT_HPP

#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef WINDOWS_H
#include <windows.h>
#endif

#ifndef FUNCTION_HPP
#include"Function.hpp"
#endif

#ifndef STRING_H
#include <string.h>
#endif

#ifndef PERSON_HPP
#include "Person.hpp"
#endif

#ifndef RECORD_HPP
#include "Record.hpp"
#endif


using namespace std;

class Patient : public Person, public Record
{
	private:
		char b_type;
		bool Rh;
		string username;
		string password;
		int donatno;
		int transno;

	public:

		Patient();

		Patient(string a,string b);

		Patient(string,string,int,char,bool,string,string);

		string retfname();

		string retlname();

		int retage();

		string retUsername();

		string retPassword();

		int retDonatno();

		int retTransno();

		bool retRh();

		char retBtype();

		char retRh2();

		string retABtype();

		string retBloodString();

		void donatnoInc();

		void displayInfo();

		void changeFname();

		void changeLname();

		void changeAge();

        void changeUsername();

		void changeBlood();

		void changePassword();

		void addDonationHistory(string);

		void addTransfusionHistory(string,string);

        void showDonationHistory();

        void showTransfusionHistory();

		void operator ++ (int);

		friend class Admin;
};


#endif
