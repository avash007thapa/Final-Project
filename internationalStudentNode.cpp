#include "internationalStudentNode.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//constructors
InternationalStudentNode::InternationalStudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore):StudentNode(firstName,lastName,CGPA,researchScore,applicationID){
    this->country = country;
    this->toeflScore = toeflScore;
    link = nullptr;
}
InternationalStudentNode::InternationalStudentNode():StudentNode(),country(""),link(nullptr){
}

//overloading the output operator for DomesticStudent objects
ostream& operator<<(ostream& outs, InternationalStudentNode& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	outs<<"Research Score: "<<student.researchScore<<endl;
	
    //ie. if CGPA is 4, print out 4.0
    if((student.CGPA - floor(student.CGPA)) == 0){
		outs<<"CGPA: "<<student.CGPA<<".0"<<endl;
	}
	else{
		outs<<"CGPA: "<<student.CGPA<<endl;
	}

	outs<<"Country: "<<student.country<<endl;
	outs<<"Total Toefl Score: "<<student.toeflScore.getTotalScore()<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}
