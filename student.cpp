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
void Student::insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID){  
    //allocate node
    StudentNodePtr new_node = new StudentNode(firstName, lastName, CGPA, researchScore, applicationID);
    StudentNodePtr here = head; 

    //if the Linked List is empty, then make the new node as head 
    if (head == nullptr){  
        head = new_node;  
		tail = new_node;
        return;  
    }  
  
    //else traverse till the last node
    while (here->link != nullptr){
        //overload < and > operators
	    here = here->link;  
	} 
} 

// void Student::deleteNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID)
// {
// 	StudentNodePtr temp = head; //assign contents of head to temp
// 	StudentNodePtr prev = nullptr; //since at head, there's nothing before it

// 	//if head node is the one we want to delete
// 	if(temp != nullptr && temp->firstName == firstName && temp->lastName == lastName && temp->CGPA == CGPA && temp->researchScore == researchScore && temp->applicationID == applicationID)
// 	{
// 		head = temp->link; //assign the contents of the next node to head (becomes new head)
// 		delete temp; // delete old head
// 		return;
// 	}

// 	//otherwise search for the node we want to delete
// 	while(temp != nullptr && temp->firstName != firstName && temp->lastName != lastName && temp->CGPA != CGPA && temp->researchScore != researchScore && temp->applicationID != applicationID)
// 	{
// 		//keep track of the previous node since we will be changing prev->link
// 		prev = temp; 
// 		temp = temp->link;
// 	}

// 	//if the desired node we want to delete is not found
// 	if(temp == nullptr)
// 	{
// 		cout << "Node not found \n";
// 		return;
// 	}

// 	prev->link = temp->link; //unlinks the node from the list

// 	delete temp;
// }

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