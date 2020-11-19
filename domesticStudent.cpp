using namespace std;
#include "domesticStudent.hpp"
#include <iostream>
#include <string>

//constructors
DomesticStudent::DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province):Student(firstName,lastName,CGPA,researchScore,applicationID){
	this->province = province;
}
DomesticStudent::DomesticStudent():Student(),province(""){
}


//overloading the output operator for DomesticStudent objects
ostream& operator<<(ostream& outs, DomesticStudent& student){
	// outs<<student.firstName<<" "<<student.lastName<<endl;
	// outs<<"Research Score: "<<student.researchScore<<endl;
	// //ie. if CGPA is 4, print out 4.0
	// if((student.CGPA - floor(student.CGPA)) == 0){
	// 	outs<<"CGPA: "<<student.CGPA<<".0"<<endl;
	// }
	// else{
	// 	outs<<"CGPA: "<<student.CGPA<<endl;
	// }
	// outs<<"Province: "<<student.province<<endl;
	// outs<<"Application ID: "<<student.applicationID<<endl;
	// return outs;
}

//prints out the entire list of DomesticStudent objects
void print(DomesticStudent student){
	// for(int i = 0; i < 100; i++){
	// 	//cout<<i+1<<" ";
	// 	cout<<stuArr[i]<<endl;
	// }
}