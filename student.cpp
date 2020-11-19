#include "student.hpp"
#include <stdlib.h> //exit
#include <iostream> //cout
#include <string> //strings, compare
using namespace std;


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
	}
}
Student::Student():head(nullptr),tail(nullptr){ // Default constructior	 
}


//DYNAMIC BIG THREE

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
        //allocating memory to new studentNode
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
    catch(bad_alloc){
        cerr<<"bad_alloc in Student::deepCopySudent.\n";
        exit(1);
    }
}



//overloading assignment operator
Student& Student::operator=(const Student& rStudent){
	head = replaceStudent(head, rStudent.head);
    return *this;
}
StudentNodePtr Student::replaceStudent(StudentNodePtr lStudent, StudentNodePtr rStudent){
    if(lStudent != rStudent){
        deleteStudent(lStudent);
        lStudent = deepCopyStudent(rStudent);
    }
    return lStudent;
}



//overloading destructor
Student::~Student(){
	deleteStudent(head);
}
void Student::deleteStudent(StudentNodePtr studentNode){
	if(studentNode != nullptr){
		deleteStudent(studentNode->link);
		delete studentNode;
		studentNode = nullptr;
	}
	else{
		head = nullptr;
		tail = nullptr;
	}
}



//member functions

void Student::insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID){  
    //allocate node
    try{
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
    catch(bad_alloc){
        cerr<<"bad_alloc in Student::insertNode.\n";
        exit(1);
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

