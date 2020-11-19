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
		//Constructors
		Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
		Student();
		
		//Dynamic big three

		//Copy constructor
		Student(const Student& student);
		StudentNodePtr deepCopyStudent(StudentNodePtr studentNode);
		//Overloading assingment operator
		void operator=(const Student& student);
		//Destructor
		~Student();


		//insert node

		//delete node 

		//print()

		//delete()
};

#endif