#include "studentList.hpp"
#include <stdlib.h> //exit
#include <iostream> //cout
#include <string> //strings, compare
#include <cmath>
using namespace std;


//constructors
StudentList::Student::Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
    //error checking CGPA
	if(CGPA < 0 || round1f(CGPA) > (float)4.3){
		std::cout<<"Error (Student): CGPA"<<CGPA<<" is in valid.\n";
	}
	else{
		this->CGPA = round1f(CGPA);
	}
	//error checking reserachScore
	if(researchScore < 0 || researchScore > 100){
		std::cout<<"Error (Student): researchScore cannot be a negative number.\n";
	}
	else{
		this->researchScore = researchScore;
	}
	//error checking applicationID
	if(applicationID < 0 || applicationID > 20210000){
		std::cout<<"Error (Student): applicationID cannot be a negative number.\n";
	}
	else{
		this->applicationID = applicationID;
	}
	//setting firstName, lastName and link
	this->firstName = firstName;
	this->lastName = lastName;
	link = nullptr;
}
StudentList::Student::Student():firstName(""),lastName(""),CGPA(0),researchScore(0),applicationID(0),link(nullptr){
}

//compare functions

//comparing the CGPA between two students
int StudentList::Student::compareCGPA(Student student){
	if(CGPA < student.CGPA){
		return -1;
	}else if(CGPA == student.CGPA){
		return 0;
	}
	return 1;
}

//comparing the CGPA between two students
int StudentList::Student::compareResearchScore(Student student){
	if(researchScore < student.researchScore){
		return -1;
	}else if(researchScore == student.researchScore){
		return 0;
	}
	return 1;
}

//comparing the first names between two students
int StudentList::Student::compareFirstName(Student student){
	return firstName.compare(student.firstName);
}

//comparing the last names between two students
int StudentList::Student::compareLastName(Student student){
	return lastName.compare(student.lastName);
}

ostream& operator<<(ostream& outs, StudentList::Student& student){
	outs<<student.firstName<<" "<<student.lastName<<endl;
	outs<<"CGPA: "<<student.CGPA<<endl;
	outs<<"Research Score: "<<student.researchScore<<endl;
	outs<<"Application ID: "<<student.applicationID<<endl;
	return outs;
}

//round function to the first decimal. Used to round the CGPA 
float round1f(float num){
	return roundf(num * 10)/10;
}


//---------------------------------------------------------------------------------------------------------------------------------------------//


//Constructors
StudentList::StudentList(string firstName, string lastName, float CGPA, int researchScore, int applicationID){
	try{
		head = new Student(firstName, lastName, CGPA, researchScore, applicationID);
		tail = head;
		tail->link = nullptr;
	}
	catch(bad_alloc){
		cerr<<"Bad Memory allocation in Student::Student\n";
		exit(1);
	}
}
StudentList::StudentList():head(nullptr),tail(nullptr){ // Default constructior	 
}


//DYNAMIC BIG THREE

//copy constructor
StudentList::StudentList(const StudentList& studentList){
	head = deepCopyStudentList(studentList.head);
}
StudentList::StudentPtr StudentList::deepCopyStudentList(StudentPtr student){
    //if stack is empty or at the end of the linked list
    if(student == nullptr){
		return nullptr;
    }
    try{
        //allocating memory to new Node
        StudentPtr newStudent = new Student(student->firstName, student->lastName, student->CGPA, student->researchScore, student->applicationID);
        
        //base case
        if(student->link == nullptr){
            return newStudent;
        }
		//recursive call to deepCopyStack
		newStudent->link = deepCopyStudentList(student->link);
		//assigning tail 
		if(student->link == nullptr){
			tail = newStudent;
			student->link = nullptr;
		}
        return newStudent;
    }
    catch(bad_alloc){
        cerr<<"bad_alloc in StudentList::deepCopySudentList.\n";
        exit(1);
    }
}



//overloading assignment operator
StudentList& StudentList::operator=(const StudentList& rStudentList){
	head = replaceStudentList(head, rStudentList.head);
    return *this;
}
StudentList::StudentPtr StudentList::replaceStudentList(StudentPtr lStudentList, StudentPtr rStudentList){
    if(lStudentList != rStudentList){
        deleteStudentList(lStudentList);
        lStudentList = deepCopyStudentList(rStudentList);
    }
    return lStudentList;
}



//overloading destructor
StudentList::~StudentList(){
	deleteStudentList(head);
}
void StudentList::deleteStudentList(StudentPtr student){
	if(student != nullptr){
		deleteStudentList(student->link);
		delete student;
		student = nullptr;
	}
	else{
		head = nullptr;
		tail = nullptr;
	}
}



//member functions

void StudentList::insertNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID){  
    //allocate node
    try{
		StudentPtr prev;
        StudentPtr new_node = new StudentList::Student(firstName, lastName, CGPA, researchScore, applicationID);
        StudentPtr here = head; 

        //if the Linked List is empty, then make the new node as head 
        if (head == nullptr){  
            head = new_node;  
            tail = new_node;
            return;  
        }  
    
        //else traverse till the last node
        while (here->link != nullptr){
            if(here < new_node) {	
				prev = here;
				here = here->link;
			}
			else {
				
				new_node->link = here;
				prev->link = new_node;
				break;
			}
			
		} 
    }
    catch(bad_alloc){
        cerr<<"bad_alloc in Student::insertNode.\n";
        exit(1);
    }
    
} 

bool operator>(const StudentList::Student& s1, const StudentList::Student& s2)
{
    if(s1.researchScore > s2.researchScore)
		{
			return true;
		}
    else if(s1.researchScore == s2.researchScore)
	   	{
		   if(s1.CGPA > s2.CGPA)
		   {
			   return true;
		   }
	   	}
	else if(s1.CGPA == s2.CGPA)
		{
			if(s1.applicationID > s2.applicationID)
			{
				return true;
			}
		}
	else return false;
}

bool operator<(const StudentList::Student& s1, const StudentList::Student& s2)
{
    if(s1.researchScore < s2.researchScore)
		{
			return true;
		}
    else if(s1.researchScore == s2.researchScore)
	   	{
		   if(s1.CGPA < s2.CGPA)
		   {
			   return true;
		   }
	   	}
	else if(s1.CGPA == s2.CGPA)
		{
			if(s1.applicationID < s2.applicationID)
			{
				return true;
			}
		}
	else return false;
}


// void Student::deleteNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID)
// {
// 	NodePtr temp = head; //assign contents of head to temp
// 	NodePtr prev = nullptr; //since at head, there's nothing before it

// 	//if head node is the one we want to delete
// 	if(temp != nullptr && temp->firstName == firstName && temp->lastName == lastName && temp->CGPA == CGPA && temp->researchScore == researchScore && temp->applicationID == applicationID)
// 	{
// 		head = temp->link; //assign the contents of the next node to head (becomes new head)
// 		delete temp; // delete old head
// 		return;
// 	}

// 	//otherwise search for the node we want to delete
// 	while(temp != nullptr && temp->firstName != firstName && temp->lastName != lastName && temp->CGPA != CGPA && temp->researchScore != researchScore && temp->applicationID != applicationID)
// 	{
// 		//keep track of the previous node since we will be changing prev->link
// 		prev = temp; 
// 		temp = temp->link;
// 	}

// 	//if the desired node we want to delete is not found
// 	if(temp == nullptr)
// 	{
// 		cout << "Node not found \n";
// 		return;
// 	}

// 	prev->link = temp->link; //unlinks the node from the list

// 	delete temp;
// }

