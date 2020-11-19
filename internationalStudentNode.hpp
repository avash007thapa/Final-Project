#ifndef INTERNATIONALSTUDENTNODE
#define INTERNATIONALSTUDENTNODE

#include <iostream>
#include <string>
#include "student.hpp"
#include "toefl.hpp"

using namespace std;

class InternationalStudentNode:public StudentNode{
    public:
        //data
        string country;
        Toefl toeflScore;

        //link
        InternationalStudentNode* link;

        //constructors
        InternationalStudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore);
        InternationalStudentNode();

        //overloadign output operator
		friend ostream& operator <<(ostream& outs, InternationalStudentNode& domesticStudentNode);
};
typedef InternationalStudentNode* InternationalStudentNodePtr;

#endif