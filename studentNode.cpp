#include "studentNode.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//constructors
StudentNode::StudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
    if(CGPA < 0 || round1f(CGPA) > (float)4.3){
		std::cout<<"Error (Student Node): CGPA"<<CGPA<<" is in valid.\n";
	}
	else{
		this->CGPA = round1f(CGPA);
	}
	if(researchScore < 0 || researchScore > 100){
		std::cout<<"Error (Student Node): researchScore cannot be a negative number.\n";
	}
	else{
		this->researchScore = researchScore;
	}
	if(applicationID < 0 || applicationID > 20210000){
		std::cout<<"Error (Student Node): applicationID cannot be a negative number.\n";
	}
	else{
		this->applicationID = applicationID;
	}
	this->firstName = firstName;
	this->lastName = lastName;
	link = nullptr;
}
StudentNode::StudentNode():firstName(""),lastName(""),CGPA(0),researchScore(0),applicationID(0),link(nullptr){
}

//compare functions
//comparing the CGPA between two students
//comparing the CGPA between two students
int compareCGPA(StudentNode student1, StudentNode student2){
	if(student1.CGPA < student2.CGPA){
		return -1;
	}else if(student1.CGPA == student2.CGPA){
		return 0;
	}
	return 1;
}

//comparing the research score between two students
int compareResearchScore(StudentNode student1, StudentNode student2){
	if(student1.researchScore < student2.researchScore){
		return -1;
	}else if(student1.researchScore == student2.researchScore){
		return 0;
	}
	return 1;
}

//comparing the first names between two students
int compareFirstName(StudentNode student1, StudentNode student2){
	return student1.firstName.compare(student2.firstName);
}

//comparing the last names between two students
int compareLastName(StudentNode student1, StudentNode student2){
	return student1.lastName.compare(student2.lastName);
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
