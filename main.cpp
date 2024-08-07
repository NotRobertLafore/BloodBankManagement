#include <iostream>                             //Header for input/output
#include <conio.h>                              //header for getch and console functions
#include "Interface.hpp"                        //Header for Interface
#include "Admin.hpp"                            //Header for Administrator Account
using namespace std;

int main()                                      //Driver Code
{
	Admin A;
    A.readData();                               //Reading Data

    system("cls");

	int loggedAccount,choice;
    bool endFlag=0;

    do{
        loggedAccount=Interface::loginScreen(A);    //Login Screen

        do
        {
            system("cls");
            choice=Interface::mainScreen(A,loggedAccount);  //Main Screen function that returns an int value which is mapped to a corresponding action
            system("cls");
            if(choice==1)
            {                                                   //Choice for each function
                Interface::bloodDonationSc(A,loggedAccount);
            }
            else if(choice==2)
            {
                Interface::bloodTransfusionSc(A,loggedAccount);
            }
            else if(choice==3)
            {
                Interface::editPatientInfo(A,loggedAccount);
            //    A.display(loggedAccount);
            //    _getch();
            }
            else if(choice==4||choice==16)
            {
              break;
            }
//            else if(choice==5||choice==16)
//            {
//                break;
//            }
            else if(choice==5||choice==17)
            {
                endFlag=!endFlag;
                break;
            }

        }while(true);

    }
    while(endFlag==0);

    return 0;
}
