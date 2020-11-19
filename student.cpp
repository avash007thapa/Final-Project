//student.cpp to implement your classes
using namespace std;
#include "student.hpp"
#include <stdlib.h> //exit
#include <iostream> //cout
#include <string> //strings, compare
#include <cmath>

//Constructors
Student::Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
	try{
		head = new StudentNode(firstName, lastName, CGPA, researchScore, applicationID);
		tail = head;
		tail->link = nullptr;
	}
	catch(bad_alloc){
		cerr<<"Bad Memory allocation in Student::Student\n";
		exit(1);
	};
}
Student::Student():head(nullptr),tail(nullptr){ // Default constructior	 
}

//Dynamic big three

//copy constructor
Student::Student(const Student& student){
	head = deepCopyStudent(student.head);
}
StudentNodePtr Student::deepCopyStudent(StudentNodePtr studentNode){
    
    //if stack is empty or at the end of the linked list
    if(studentNode == nullptr){
		return nullptr;
    }
    
    try{
        //allocating memory to new stackframe
        StudentNodePtr newStudentNode = new StudentNode(studentNode->firstName, studentNode->lastName, studentNode->CGPA, studentNode->researchScore, studentNode->applicationID);
        
        //base case
        if(studentNode->link == nullptr){
            return newStudentNode;
        }

		//recursive call to deepCopyStack
		newStudentNode->link = deepCopyStudent(studentNode->link);

		//assigning tail 
		if(studentNode->link == nullptr){
			tail = newStudentNode;
			tail->link = nullptr;
		}

        return newStudentNode;
    }
    catch(std::bad_alloc){
        std::cout<<"bad_alloc in Student::deepCopySudent\n";
        std::exit(1);
    }
}