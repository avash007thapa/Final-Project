#ifndef DOMESTIC_STUDENT
#define DOMESTIC_STUDENT

using namespace std;
#include <string>
#include "student.hpp"

template <class T> class LinkedList;

class DomesticStudent:public Student{
	friend class LinkedList<DomesticStudent>;
	private:
		string province;
	public:
		//constructors
		DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomesticStudent();
		
		//get/set functions
		string getProvince();
		void setProvince(string province);

		//virtual function
		virtual void print();

		//compare function
		friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
		int compareOverall(DomesticStudent student1, DomesticStudent student2);

		//overloaded output operator
		friend ostream& operator <<(ostream& outs, DomesticStudent& student);
		
};
typedef DomesticStudent* DomesticStudentPtr;


#endif