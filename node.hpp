#ifndef NODE
#define NODE

#include <iostream>
#include <string>
#include "toefl.hpp"

using namespace std;

class Node{
    public:
        //data
        string firstName;
        string lastName;
        float CGPA;
        int researchScore;
        int applicationID;

        //child class data
        string province;
        string country;
        Toefl toeflScore;

        //link
        Node* link;

        //constructors
        Node(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
        Node(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string province);
        Node(string firstName, string lastName, float CGPA, int researchScore, int applicationID, string country, Toefl toeflScore);
        Node();

        //Friend functions
		friend int compareCGPA(Node Node1, Node Node2);
		friend int compareResearchScore(Node Node1, Node Node2);
		friend int compareFirstName(Node Node1, Node Node2);
		friend int compareLastName(Node Node1, Node Node2);
		friend ostream& operator <<(ostream& outs, Node& Node);
};
typedef Node* NodePtr;

#endif