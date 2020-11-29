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
				
		//Member functions
		string getCountry();
		Toefl getToeflScore();
		void setCountry(string country);
		void setToeflScore(Toefl toeflScore);

		//friend functions
		friend int compareCountry(InternationalStudent& student1, InternationalStudent& student2);
		friend int compareOverall(InternationalStudent& student1, InternationalStudent& student2);
		friend ostream& operator<<(ostream& outs, InternationalStudent& student);
		virtual void print();
};
typedef InternationalStudent* InternationalStudentPtr;


#endif