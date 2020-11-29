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


//set functoins
string DomesticStudent::getProvince(){
	return province;
}
void DomesticStudent::setProvince(string province){
	this->province = province;
}
	

//friend functions
//comparing the province between two students
int compareProvince(DomesticStudent student1, DomesticStudent student2){
	return student1.province.compare(student2.province);
}
//comparing the overall score between two students
int compareOverall(DomesticStudent& student1, DomesticStudent& student2){	
	//cout<<"ITS CALLING THE RIGHT ONE\n";
	if(compareResearchScore(student1,student2) == -1){
		return 1;
	}
	else if(compareResearchScore(student1,student2) == 0){
		if(compareCGPA(student1,student2) == -1){
			return 1;
		}
		else if(compareCGPA(student1,student2) == 0){
			if(compareProvince(student1,student2) == -1){
				return 1;
			}
		}
	}
	return 0;
}
//comparing overall between a domestic student and an international student
int compareOverall(DomesticStudent& student1, InternationalStudent& student2){
	cout<<"ITS CALLING THE RIGHT ONE\n";
	//upcasting student1 and student 2
	StudentPtr stu1 = &student1;
	StudentPtr stu2 = &student2;
	
	if(compareResearchScore(*stu1,*stu2) == -1){
		return 1;
	}
	else if(compareResearchScore(*stu1,*stu2) == 0){
		if(compareCGPA(*stu1,*stu2) == -1){
			return 1;
		}
	}
	return 0;
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

// void print(){
// 	cout<<*this;
// }