#ifndef NODE_CPP
#define NODE_CPP

#include "node.hpp"
using namespace std;
//constructors
template <class T> 
Node<T>::Node(T student):student(student),link(nullptr){
}
template <class T> 
Node<T>::Node():student(),link(nullptr){
}

//overload print function
template <class T>
ostream& operator <<(ostream& outs, T student){
    outs<<student;
	return outs;
}

//comparision functions
template <class T>
int compareCGPA(T student){

}
template <class T>
int compareResearchScore(T student){

}
template <class T>
int compareFirstName(T student){

}
template <class T>
int compareLastName(T student){

}
    



#endif