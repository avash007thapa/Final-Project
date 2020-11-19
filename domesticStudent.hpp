#ifndef DOMESTIC_STUDENT
#define DOMESTIC_STUDENT

using namespace std;
#include <string>
#include "student.hpp"
#include "domesticStudentNode.hpp"

class DomesticStudent:public Student{
	private:
		DomesticStudentNodePtr head;
		DomesticStudentNodePtr tail;
	public:
		//Constructors
		DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomesticStudent();
		
		//DYNAMIC BIG THREE
		//Copy constructor
		DomesticStudent(const DomesticStudent& student);
		DomesticStudentNodePtr deepCopyStudent(DomesticStudentNodePtr studentNode);

		//Overloading assingment operator
		DomesticStudent& operator=(const DomesticStudent& rStudent);
		DomesticStudentNodePtr replaceDomesticStudent(StudentNodePtr lStudent, StudentNodePtr rStudent);

		//Destructor
		~DomesticStudent();
		void deleteDomesticStudent(StudentNodePtr studentNode);

		//friend functions
		friend ostream& operator <<(ostream& outs, DomesticStudent& student);
		friend void print(DomesticStudent student);
};

#endif