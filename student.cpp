//student.cpp to implement your classes
using namespace std;
#include "student.hpp"
#include <stdlib.h> //exit
#include <iostream> //cout
#include <string> //strings, compare()
#include <cmath>

//Constructors
Student::Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
	try{
		head = new StudentNode(firstName, lastName, CGPA, researchScore, applicationID);
	}
	catch(bad_alloc){
		cerr<<"Bad Memory allocation\n";
		exit(1);
	};
}
Student::Student():head(nullptr),tail(nullptr){ // Default constructior	 
}

void Student::insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID)  
{  
    // 1. allocate node
    StudentNodePtr new_node = new StudentNode(firstName, lastName, CGPA, researchScore, applicationID);
    StudentNodePtr here = head; 

  
    // 3. If the Linked List is empty, then make the new node as head 
    if (head == nullptr)  
    {  
        head = new_node;  
		tail = new_node;
        return;  
    }  
  
    // 5. Else traverse till the last node
    while (here->link != nullptr)  
	{
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


// //Get functions
// string Student::getFirstName(){ 
// 	return firstName;
// }
// string Student::getLastName(){
// 	return lastName;
// }
// float Student::getCGPA(){
// 	return CGPA;
// }
// int Student::getResearchScore(){
// 	return researchScore;
// }
// int Student::getApplicationID(){
// 	return applicationID;
// }

// //Set functions
// void Student::setFirstName(string firstName){
// 	this->firstName = firstName;
// }
// void Student::setLastName(string lastName){
// 	this->lastName = lastName;
// }
// void Student::setCGPA(float CGPA){
// 	//error checking 
// 	if(CGPA < 0 || round1f(CGPA) > (float)4.3){
// 		std::cout<<"Error (setCGPA): CGPA"<<round1f(CGPA)<<" is invalid.\n";
// 	}
// 	else{
// 		this->CGPA = round1f(CGPA);
// 	}
// }
// void Student::setResearchScore(int researchScore){
// 	//error checking
// 	if(researchScore < 0 || researchScore > 100){
// 		std::cout<<"Error (setResearchScore): researchScore cannot be a negative number.\n";
// 	}
// 	else{
// 		this->researchScore = researchScore;
// 	}
// }
// void Student::setApplicationID(int applicationID){
// 	//error checking
// 	if(applicationID < 0 || applicationID > 20210000){
// 		std::cout<<"Error (setApplicationID): applicationID cannot be a negative number.\n";
// 	}
// 	else{
// 		this->applicationID = applicationID;
// 	}
// }

//Friend functions
//comparing the CGPA between two students
