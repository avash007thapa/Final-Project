using namespace std;
#include "domStuList.hpp"
#include <iostream>
#include <string>

//constructors
DomesticStudent::DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province):Student(firstName,lastName,CGPA,researchScore,applicationID){
	this->province = province;
}
DomesticStudent::DomesticStudent():Student(),province(""){
}

//DYNAMIC BIG THREE

//copy constructor
DomesticStudent::DomesticStudent(const DomesticStudent& student):Student(student){
	head = deepCopyStudent(student.head);
}
DomesticStudentNodePtr DomesticStudent::deepCopyStudent(DomesticStudentNodePtr studentNode){
	
}



//overloading assignment operator
DomesticStudent& DomesticStudent::operator=(const DomesticStudent& rStudent){
	head = replaceStudent(head, rStudent.head);
    return *this;
}
DomesticStudentNodePtr DomesticStudent::replaceStudent(StudentNodePtr lStudent, StudentNodePtr rStudent){
    if(lStudent != rStudent){
        deleteStudent(lStudent);
        lStudent = deepCopyStudent(rStudent);
    }
    return lStudent;
}



//overloading destructor
Student::~Student(){
	deleteStudent(head);
}
void Student::deleteStudent(StudentNodePtr studentNode){
	if(studentNode != nullptr){
		deleteStudent(studentNode->link);
		delete studentNode;
		studentNode = nullptr;
	}
	else{
		head = nullptr;
		tail = nullptr;
	}
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