#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include "student.hpp" //data
#include "domesticStudent.hpp" //data
#include "internationalStudent.hpp" //data

using namespace std;

template <class T>
class Node{
    private:
        T student;
        Node<T>* link;
    public:
        //constructors
        Node(T student);
        Node();

        //overload print function
        friend ostream& operator <<(ostream& outs, T student);

        //comparision functions
        int compareCGPA(T student);
        int compareResearchScore(T student);
        int compareFirstName(T student);
        int compareLastName(T student);
};

template <class T>
using NodePtr = Node<T>*;

#endif

