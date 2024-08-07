#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#ifndef CSTDLIB
#include<cstdlib>
#endif

#ifndef TIME_H
#include <time.h>
#endif

#ifndef WINDOWS_H
#include <windows.h>
#endif

#ifndef IOSTREAM
#include<iostream>
#endif
using namespace std;

int intCheck();                 //checks if int value is good and valid

int intCheck(int,int);

void loadingBar(string = "Loading", bool = true);

char choiceCheck();

string bloodGroupCheck();

void bloodCentrifuge(string,char*,bool*);

#endif
