#ifndef INTERNATIONAL_STUDENT
#define INTERNATIONAL_STUDENT

using namespace std;
#include <string>
#include "student.hpp"
#include "toefl.hpp"

template <class T> class LinkedList;

class InternationalStudent:public Student{
	friend class LinkedList<InternationalStudent>;
	private:
		string country;
		Toefl toeflScore;
	public:
		//Constructors 
		InternationalStudent(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore);
		InternationalStudent();
				
		//get/set functions
		string getCountry();
		Toefl getToeflScore();
		void setCountry(string country);
		void setToeflScore(Toefl toeflScore);
		
		//virtual function
		virtual void print();

		//virtual void deleteNode();

		//compare function
		friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
		friend int compareOverall(InternationalStudent student1, InternationalStudent student2);

		//overloaded output operator
		friend ostream& operator<<(ostream& outs, InternationalStudent& student);
		
};
typedef InternationalStudent* InternationalStudentPtr;


#endif
