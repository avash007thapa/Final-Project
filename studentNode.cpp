#include "studentNode.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//constructors
StudentNode::StudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
    //error checking CGPA
	if(CGPA < 0 || round1f(CGPA) > (float)4.3){
		std::cout<<"Error (Student Node): CGPA"<<CGPA<<" is in valid.\n";
	}
	else{
		this->CGPA = round1f(CGPA);
	}
	//error checking reserachScore
	if(researchScore < 0 || researchScore > 100){
		std::cout<<"Error (Student Node): researchScore cannot be a negative number.\n";
	}
	else{
		this->researchScore = researchScore;
	}
	//error checking applicationID
	if(applicationID < 0 || applicationID > 20210000){
		std::cout<<"Error (Student Node): applicationID cannot be a negative number.\n";
	}
	else{
		this->applicationID = applicationID;
	}
	//setting firstName, lastName and link
	this->firstName = firstName;
	this->lastName = lastName;
	link = nullptr;
}
StudentNode::StudentNode():firstName(""),lastName(""),CGPA(0),researchScore(0),applicationID(0),link(nullptr){
}

//compare functions

//comparing the CGPA between two students
int StudentNode::compareCGPA(StudentNode student){
	if(CGPA < student.CGPA){
		return -1;
	}else if(CGPA == student.CGPA){
		return 0;
	}
	return 1;
}

//comparing the CGPA between two students
int StudentNode::compareResearchScore(StudentNode student){
	if(researchScore < student.researchScore){
		return -1;
	}else if(researchScore == student.researchScore){
		return 0;
	}
	return 1;
}

//comparing the first names between two students
int StudentNode::compareFirstName(StudentNode student){
	return firstName.compare(student.firstName);
}

//comparing the last names between two students
int StudentNode::compareLastName(StudentNode student){
	return lastName.compare(student.lastName);
}

ostream& operator<<(ostream& outs, StudentNode& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	outs<<"CGPA: "<<student.CGPA<<endl;
	outs<<"Research Score: "<<student.researchScore<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}

//round function to the first decimal. Used to round the CGPA 
float round1f(float num){
	return roundf(num * 10)/10;
}
