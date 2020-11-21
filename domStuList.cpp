using namespace std;
#include "domStuList.hpp"
#include <iostream>
#include <string>

//constructors for DomesticStudent
DomStuList::DomesticStudent::DomesticStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province):Student(firstName,lastName,CGPA,researchScore,applicationID){
	this->province = province;
	link = nullptr;
}
DomStuList::DomesticStudent::DomesticStudent():Student(),province(""){
	link = nullptr;
}

//---------------------------------------------------------------------------------------------------------------------------------------------//
//constructors
DomStuList::DomStuList(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province){
	try{
		head = new DomesticStudent(firstName, lastName, CGPA, researchScore, applicationID, province);
		tail = head;
		tail->link = nullptr;
	}
	catch(bad_alloc){
		cerr<<"Bad Memory allocation in Student::Student\n";
		exit(1);
	}
}
DomStuList::DomStuList():StudentList(){
}

//DYNAMIC BIG THREE

//copy constructor
DomStuList::DomStuList(const DomStuList& student){
	head = deepCopyStudentList(student.head);
}
DomesticStudentPtr DomStuList::deepCopyStudentList(StudentPtr student){
	
}



//overloading assignment operator
DomStuList& DomStuList::operator=(const DomStuList& rStudent){
	head = replaceStudentList(head, rStudent.head);
    return *this;
}
DomesticStudentPtr DomStuList::replaceStudentList(DomesticStudentPtr lStudent, DomesticStudentPtr rStudent){
    if(lStudent != rStudent){
        deleteStudentList(lStudent);
        lStudent = deepCopyStudentList(rStudent);
    }
    return lStudent;
}



//overloading destructor
DomStuList::~DomStuList(){
	deleteStudentList(head);
}
void DomStuList::deleteStudentList(DomesticStudentPtr student){
	if(student != nullptr){
		deleteStudent(student->link);
		delete student;
		student = nullptr;
	}
	else{
		head = nullptr;
		tail = nullptr;
	}
}
//overloading the output operator for DomStuList objects
ostream& operator<<(ostream& outs, DomStuList& student){
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

//prints out the entire list of DomStuList objects
void print(DomStuList student){
	// for(int i = 0; i < 100; i++){
	// 	//cout<<i+1<<" ";
	// 	cout<<stuArr[i]<<endl;
	// }
}