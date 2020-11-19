#ifndef INTERNATIONAL_STUDENT
#define INTERNATIONAL_STUDENT

using namespace std;
#include <string>
#include "student.hpp"
#include "internationalStudentNode.hpp"
#include "toefl.hpp"

class InternationalStudent:public Student{
	private:
		InternationalStudentNodePtr head;
		InternationalStudentNodePtr tail;
	public:
		//Constructors
		InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore);
		InternationalStudent();

		//friend functions
		friend ostream& operator<<(ostream& outs, InternationalStudent& student);
		friend void print(InternationalStudent student);
		friend void printValidStudents(InternationalStudent student);
};

#endif