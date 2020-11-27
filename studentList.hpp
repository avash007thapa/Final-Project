#ifndef STUDENTLIST
#define STUDENTLIST

#include <iostream>
#include <string>
using namespace std; 

class StudentList{
    protected:
		//Student class definition
		class Student{
			public:
				//data
				string firstName;
				string lastName;
				float CGPA;
				int researchScore;
				int applicationID;
				//link
				Student* link;
				//constructors
				Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
				Student();
				//compare functions
				int compareCGPA(Student student);
				int compareResearchScore(Student student);
				int compareFirstName(Student student);
				int compareLastName(Student student);
				
		};
        typedef Student* StudentPtr;
       
        //Student private variables
		StudentPtr head;
		StudentPtr tail;
		
	public:
    
		//constructors
		StudentList(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
		StudentList();
		
		//DYNAMIC BIG THREE
		//copy constructor
		StudentList(const StudentList& studentList);
		StudentPtr deepCopyStudentList(StudentPtr student);

		//overloading assingment operator
		StudentList& operator=(const StudentList& rStudentList);
		StudentPtr replaceStudentList(StudentPtr lStudentList, StudentPtr rStudentList);

		//destructor
		~StudentList();
		void deleteStudentList(StudentPtr student);


		//insert node
		void insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID); //for now inserts at tail end

		//overloading >/< operators
		friend bool operator >(const StudentList::Student& s1, const StudentList::Student& s2);
		friend bool operator <(const StudentList::Student& s1, const StudentList::Student& s2);

		//void findNode

		//delete node 
		void deleteNode(string firstName, string lastName);

		//print()

		//delete()
		//overloading Student's output operator
		friend ostream& operator <<(ostream& outs, StudentList::Student& student);
};

//rounding function for CGPA
float round1f(float num);
#endif