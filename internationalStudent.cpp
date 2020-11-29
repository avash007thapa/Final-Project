
using namespace std;
#include "internationalStudent.hpp"
#include "toefl.hpp"
#include <iostream>
#include <string>
#include <cmath>

//Constructors
InternationalStudent::InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore):Student(firstName,lastName,CGPA,researchScore,applicationID){
		this->country = country;
		this->toeflScore = toeflScore;
}
InternationalStudent::InternationalStudent():Student(),country(""),toeflScore(){
}

//Member functions
string InternationalStudent::getCountry(){
	return country;
}
Toefl InternationalStudent::getToeflScore(){
	return toeflScore;
}
void InternationalStudent::setCountry(string country){
	this->country = country;
}
void InternationalStudent::setToeflScore(Toefl toeflScore){
	this->toeflScore = toeflScore;
}

//friend functions
//comparing countries between students
int compareCountry(InternationalStudent& student1, InternationalStudent& student2){
	return student1.country.compare(student2.country);
}
int compareOverall(InternationalStudent& student1, InternationalStudent& student2){	
	if(compareResearchScore(student1,student2) == -1){
		return 1;
	}
	else if(compareResearchScore(student1,student2) == 0){
		if(compareCGPA(student1,student2) == -1){
			return 1;
		}
		else if(compareCGPA(student1,student2) == 0){
			if(compareCountry(student1,student2) == -1){
				return 1;
			}
		}
	}
	return 0;
}
//overloading the output operator for InternationalStdents
ostream& operator<<(ostream& outs, InternationalStudent& student){
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
	outs<<"Total Toefl Score: "<<student.getToeflScore().getTotalScore()<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}

void print(){
	cout<<*this;
}