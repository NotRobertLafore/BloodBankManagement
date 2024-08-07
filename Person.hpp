#ifndef PERSON_HPP
#define PERSON_HPP

#ifndef STRING
#include <string>
#endif

class Person
{
	protected:
		std::string fname;
		std::string lname;
		int age;

	public:

		Person();

		Person(std::string,std::string,int);

};

#endif
