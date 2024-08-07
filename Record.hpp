#ifndef RECORD_HPP
#define RECORD_HPP

#ifndef STRING
#include<string>
#endif

using namespace std;

class Record
{
	protected:
		string donationHistory [150][4];
		string transfusionHistory [150][4];

	public:

		Record();


};

#endif
