#ifndef DOMESTICSTUDENTLIST
#define DOMESTICSTUDENTLIST

using namespace std;
#include <string>
#include "studentList.hpp"

class DomStuList:public StudentList{
	private:
		class DomesticStudent:Student{
			public:
				string province;
				//constructors
				DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
				DomesticStudent();
		};
	public:
		//Constructors
		DomStuList(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomStuList();
		
		//DYNAMIC BIG THREE
		//Copy constructor
		DomStuList(const DomStuList& student);
		DomesticStudentPtr deepCopyStudent(DomesticStudentPtr student);

		//Overloading assingment operator
		DomStuList& operator=(const DomStuList& rStudent);
		DomesticStudentNodePtr replaceDomesticStudent(DomesticStudentPtr lStudent, DomesticStudentPtr rStudent);

		//Destructor
		~DomStuList();
		void deleteDomesticStudentList(DomesticStudentPtr student);

		//friend functions
		friend ostream& operator <<(ostream& outs, DomStuList& studentList);
		
};

#endif