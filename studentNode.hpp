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

        //Friend functions
		friend int compareCGPA(StudentNode studentNode1, StudentNode studentNode2);
		friend int compareResearchScore(StudentNode studentNode1, StudentNode studentNode2);
		friend int compareFirstName(StudentNode studentNode1, StudentNode studentNode2);
		friend int compareLastName(StudentNode studentNode1, StudentNode studentNode2);
		friend ostream& operator <<(ostream& outs, StudentNode& studentNode);
};
//rounding function for CGPA
float round1f(float num);

typedef StudentNode* StudentNodePtr;

#endif