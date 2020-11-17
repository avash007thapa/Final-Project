#ifndef STUDENT
#define STUDENT


#include <string> 
#include "node.hpp"
using namespace std; 

class Student{
	protected:
		NodePtr head;
		NodePtr tail;
	public:
		//Constructors
		Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
		Student();

		//Friend functions
		friend int compareCGPA(Student student1, Student student2);
		friend int compareResearchScore(Student student1, Student student2);
		friend int compareFirstName(Student student1, Student student2);
		friend int compareLastName(Student student1, Student student2);
		friend ostream& operator <<(ostream& outs, Student& student);
};
//rounding function for CGPA
float round1f(float num);



#endif