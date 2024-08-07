#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#ifndef STRING_H
#include <string.h>
#endif

#ifndef WINDOWS_H
#include <windows.h>
#endif

#ifndef CONIO_H
#include <conio.h>
#endif

#ifndef ADMIN_HPP
#include "Admin.hpp"
#endif

#ifndef IOMANIP
#include <iomanip>
#endif

class Interface
{
	private:
		int no;

	public:

	static int loginScreen(Admin);

	static int mainScreen(Admin, int);

	static int AdmainScreen(Admin);

	static void bloodDonationSc(Admin,int);

	static void bloodTransfusionSc(Admin,int);

	static void editPatientInfo(Admin,int);

};



#endif
