#ifndef STUDENT
#define STUDENT

using namespace std; 
#include <string> 

template <class T> class LinkedList;

class Student{
	friend class LinkedList<Student>;
	protected:
		string firstName;
		string lastName;
		float CGPA;
		int researchScore;
		int applicationID;
	public:
		//constructors 
		Student(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
		Student();

		//get/set functions
		string getFirstName();
		string getLastName();
		float  getCGPA();
		int getResearchScore();
		int getApplicationID();
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setCGPA(float CGPA);
		void setResearchScore(int researchScore);
		void setApplicationID(int applicationID);
		
		//virtual function
		virtual void print();
		
		//virtual void deleteNode();

		//compare functions
		friend int compareCGPA(Student student1, Student student2);
		friend int compareResearchScore(Student student1, Student student2);
		friend int compareFirstName(Student student1, Student student2);
		friend int compareLastName(Student student1, Student student2);
		friend int compareOverall(Student student1, Student student2);

		//overloaded output operator
		friend ostream& operator <<(ostream& outs, Student& student);
};
typedef Student* StudentPtr;

//rounding function for CGPA
float round1f(float num);



#endif