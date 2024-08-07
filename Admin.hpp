#ifndef ADMIN_HPP
#define ADMIN_HPP

#ifndef STRING_H
#include <string>
#endif

#ifndef FUNCTION_HPP
#include "Function.hpp"
#endif

#ifndef PATIENT_HPP
#include "Patient.hpp"
#endif

#ifndef IOSTREAM_H
#include <iostream>
#endif

#ifndef FSTREAM_H
#include <fstream>
#endif

#ifndef BANK_HPP
#include "Bank.hpp"
#endif

using namespace std;

class Admin
{
	private:
		std::string username;
		std::string password;
		Patient* pat[50];
		int patno;
		Bank B;

	public:

		Admin();

		Admin(std::string,std::string);

		void displayBankRecord();

		void displayBankHistory();

		void addTransfusion(string,string,string,string);

		void addDonation(string,string,string,string);

		void listProfile(int);

		void editProfile();

        void compatibilityCheck();

		void displayPatInfo(int);

		void addNewUser();

		void writeData();

		void readData();

		void readBloodData();

		void display(int);

		int retPatno();

        bool volumeCheck(string);

		bool retUsermatch(int, string);

		bool retPassmatch(int, string);

		friend class Interface;
};


#endif
