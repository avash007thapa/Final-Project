
using namespace std;
#include "internationalStudent.hpp"
#include "toefl.hpp"
#include <iostream>
#include <string>
#include <cmath>

//constructors
InternationalStudent::InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore):Student(firstName,lastName,CGPA,researchScore,applicationID){
		this->country = country;
		this->toeflScore = toeflScore;
}
InternationalStudent::InternationalStudent():Student(),country(""),toeflScore(){
}


//get/set functions
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


//prints out class information
void InternationalStudent::print(){
	cout<<firstName<<" "<<lastName<<endl;
	cout<<"Research Score: "<<researchScore<<endl;
	//ie. if CGPA is 4, print out 4.0
	if((CGPA - floor(CGPA)) == 0){
		cout<<"CGPA: "<<CGPA<<".0"<<endl;
	}
	else{
		cout<<"CGPA: "<<CGPA<<endl;
	}
	cout<<"Country: "<<country<<endl;
	cout<<"Application ID: "<<applicationID<<endl;
}


//comparing countries between students
int compareCountry(InternationalStudent& student1, InternationalStudent& student2){
	return student1.country.compare(student2.country);
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