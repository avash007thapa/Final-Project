#ifndef DOMESTICSTUDENTLIST
#define DOMESTICSTUDENTLIST

using namespace std;
#include <string>
#include "studentList.hpp"

class DomStuList:public StudentList{
	private:
		class DomesticStudent:public Student{
			public:
				string province;
				//constructors
				DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
				DomesticStudent();
		};
		typedef DomesticStudent* DomesticStudentPtr;
	public:
		//Constructors
		DomStuList(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
		DomStuList();
		
		//DYNAMIC BIG THREE
		//Copy constructor
		DomStuList(const DomStuList& student);
		DomesticStudentPtr deepCopyStudentList(StudentPtr student);

		//Overloading assingment operator
		DomStuList& operator=(const DomStuList& rStudent);
		DomesticStudentPtr replaceStudentList(DomesticStudentPtr lStudent, DomesticStudentPtr rStudent);

		//Destructor
		~DomStuList();
		void deleteStudentList(DomesticStudentPtr student);

		//friend functions
		friend ostream& operator <<(ostream& outs, DomStuList& studentList);
		
};

#endif