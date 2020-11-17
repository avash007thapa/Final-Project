#ifndef NODE
#define NODE

#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
        //data
        string firstName;
        string lastName;
        float CGPA;
        int reserachScore;
        int applicationID;

        //link
        Node* link;

        //constructors
        Node(string firstName, string lastName, float CGPA, int researchScore, int applicationID);
        Node();
};
typedef Node* NodePtr;

#endif