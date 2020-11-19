using namespace std;
#include "internationalStudent.hpp"
#include "toefl.hpp"
#include <iostream>
#include <string>
#include <cmath>

//Constructors
InternationalStudent::InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore):Student(firstName,lastName,CGPA,researchScore,applicationID){
}
InternationalStudent::InternationalStudent(){
}

//overloading the output operator for InternationalStdents
ostream& operator<<(ostream& outs, InternationalStudent& student){
}

//prints out the entire list of InternationalStudent objects
void print(InternationalStudent student){
	// for(int i = 0; i < 100; i++){
	// 	//cout<<i+1<<" ";
	// 	cout<<stuArr[i]<<endl;
	// }
}

//only prints InternationalStudent objects if they passed their toefl exam
void printValidStudents(InternationalStudent student){
	// //int counter = 1;
	// for(int i = 0; i < 100; i++){
	// 	if(stuArr[i].getToeflScore().passed()){
	// 		//cout<<counter<<" ";
	// 		cout<<stuArr[i]<<endl;
	// 		//counter++;
	// 	}
	// 	// else{
	// 	// 	cout<<"INVALID TOEFL";
    // //   cout<<stuArr[i];
    // //   cout<<stuArr[i].toeflScore<<endl;
	// 	// }	
	// }
}


































