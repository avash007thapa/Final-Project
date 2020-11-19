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

		//Overloading assingment operator

		//Destructor

		//insert node
		void insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID); //for now inserts at tail end

		//void findNode

		//delete node 
		void deleteNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID);

		//print()

		//delete()

};

#endif