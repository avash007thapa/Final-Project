#ifndef STUDENTNODE
#define STUDENTNODE

#include <iostream>
#include <string>

using namespace std;

class StudentNode{
    public:
        //data
        string firstName;
        string lastName;
        float CGPA;
        int researchScore;
        int applicationID;
        //link
        StudentNode* link;

        //constructors
        StudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
        StudentNode();

        //compare functions
        int compareCGPA(StudentNode studentNode);
		int compareResearchScore(StudentNode studentNode);
		int compareFirstName(StudentNode studentNode);
		int compareLastName(StudentNode studentNode);

        //overloading output operator
		friend ostream& operator <<(ostream& outs, StudentNode& studentNode);
};
//rounding function for CGPA
float round1f(float num);

typedef StudentNode* StudentNodePtr;

#endif