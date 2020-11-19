#ifndef DOMESTICSTUDENTNODE
#define DOMESTICSTUDENTNODE

#include <iostream>
#include <string>
#include "student.hpp"

using namespace std;

class DomesticStudentNode:public StudentNode{
    public:
        //data
        string province;
        //link
        DomesticStudentNode* link;

        //constructors
        DomesticStudentNode(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
        DomesticStudentNode();

        //overloadign output operator
		friend ostream& operator <<(ostream& outs, DomesticStudentNode& domesticStudentNode);
};
typedef DomesticStudentNode* DomesticStudentNodePtr;

#endif