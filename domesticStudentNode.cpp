#include "domesticStudentNode.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//constructors
DomesticStudentNode::DomesticStudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province):StudentNode(firstName,lastName,CGPA,researchScore,applicationID){
    this->province = province;
    link = nullptr;
}
DomesticStudentNode::DomesticStudentNode():StudentNode(),province(""),link(nullptr){
}

//overloading the output operator for DomesticStudent objects
ostream& operator<<(ostream& outs, DomesticStudentNode& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	outs<<"Research Score: "<<student.researchScore<<endl;
	
    //ie. if CGPA is 4, print out 4.0
	if((student.CGPA - floor(student.CGPA)) == 0){
		outs<<"CGPA: "<<student.CGPA<<".0"<<endl;
	}
	else{
		outs<<"CGPA: "<<student.CGPA<<endl;
	}
    
	outs<<"Province: "<<student.province<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}
