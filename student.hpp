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
		
		//Dynamic big three

		//Copy constructor

		//Overloading assingment operator

		//Destructor

		//insert node

		//delete node

};
//rounding function for CGPA
float round1f(float num);

#endif