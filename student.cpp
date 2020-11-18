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
