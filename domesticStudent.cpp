using namespace std;
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"
#include <iostream>
#include <string>
#include <cmath>

//constructors
DomesticStudent::DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province):Student(firstName,lastName,CGPA,researchScore,applicationID){
	this->province = province;
}
DomesticStudent::DomesticStudent():Student(),province(""){
}


//get/set functoins
string DomesticStudent::getProvince(){
	return province;
}
void DomesticStudent::setProvince(string province){
	this->province = province;
}


//prints out class information
void DomesticStudent::print(){
	cout<<firstName<<" "<<lastName<<endl;
	cout<<"Research Score: "<<researchScore<<endl;
	//ie. if CGPA is 4, print out 4.0
	if((CGPA - floor(CGPA)) == 0){
		cout<<"CGPA: "<<CGPA<<".0"<<endl;
	}
	else{
		cout<<"CGPA: "<<CGPA<<endl;
	}
	cout<<"Province: "<<province<<endl;
	cout<<"Application ID: "<<applicationID<<endl;
}


//comparing the province between two students
int compareProvince(DomesticStudent student1, DomesticStudent student2){
	return student1.province.compare(student2.province);
}


//overloading the output operator for DomesticStudent objects
ostream& operator<<(ostream& outs, DomesticStudent& student){
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
