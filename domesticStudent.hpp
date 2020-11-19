#ifndef DOMESTIC_STUDENT
#define DOMESTIC_STUDENT

using namespace std;
#include <string>
#include "student.hpp"

class DomesticStudent:public Student{
	private:
		string province;
	public:
		//Constructors
		DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomesticStudent();
		
		//Member functions
		string getProvince();
		void setProvince(string province);

		//friend functions
		friend ostream& operator <<(ostream& outs, DomesticStudent& student);
		friend void print(DomesticStudent student);
};

#endif