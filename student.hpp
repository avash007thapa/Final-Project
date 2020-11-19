#ifndef STUDENT
#define STUDENT

#include <string> 
#include "studentNode.hpp"
using namespace std; 

class Student{
	protected:
		StudentNodePtr head;
		StudentNodePtr tail;
	public:
		//constructors
		Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
		Student();
		
		//DYNAMIC BIG THREE
		//copy constructor
		Student(const Student& student);
		StudentNodePtr deepCopyStudent(StudentNodePtr studentNode);

		//overloading assingment operator
		Student& operator=(const Student& rStudent);
		StudentNodePtr replaceStudent(StudentNodePtr lStudent, StudentNodePtr rStudent);

		//destructor
		~Student();
		void deleteStudent(StudentNodePtr studentNode);


		//insert node
		void insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID); //for now inserts at tail end

		//void findNode

		//delete node 
		void deleteNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID);

		//print()

		//delete()

		//print()

		//delete()
};

#endif