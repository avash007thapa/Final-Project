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
		//Constructors
		DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomesticStudent();
		
		//Member functions
		string getProvince();
		void setProvince(string province);

		//friend functions
		friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
		friend int compareOverall(Student& student1, Student& student2);
		
		friend ostream& operator <<(ostream& outs, DomesticStudent& student);
		virtual void print();
};
typedef DomesticStudent* DomesticStudentPtr;


#endif