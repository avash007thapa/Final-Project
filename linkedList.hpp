#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

using namespace std;
#include <iostream>
#include <string>
#include "student.hpp"
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"

template <class T>
class LinkedList{
    private:
        class Node{
            public:
                T* student;
                Node* link;
            
                //constructors
                Node(T* student);
                Node();
        };
        typedef Node* NodePtr;
        
        NodePtr head;   
        NodePtr tail;
    public:
        //constructors
        LinkedList(T* student);
        LinkedList();

        //copy constructor
        LinkedList(const LinkedList<T>& linkedList);
        NodePtr deepCopyLinkedList(NodePtr node);
        
        //overloading assignment operator
        LinkedList<T>& operator=(const LinkedList<T>& linkedList);

        //destructor
        ~LinkedList();
        void deleteLinkedList(NodePtr node);

        //insertNode
        void insertNode(T* student);

        //deleteNode
        void deleteNode(string firstName, string lastName);

        //print (all sutdents with same ApplicationID/CGPA/researchScore/Name)
        void searchApplicationID(int applicationID);
        void searchCGPA(float CGPA);
        void searchResearchScore(int researchScore);
        void searchName(std::string firstName, std::string lastName);
        
        //delete (deletes head and tail ptrs)
        void delete_head_tail();
        
        //prints out entire linked list
        void print();

        //merges a domestic and international linked list
        friend LinkedList<Student> mergeList(LinkedList<DomesticStudent>& domesticList, LinkedList<InternationalStudent>& internationalList);

        //overloaded output operator
        template <class Y>
        friend std::ostream& operator<<(std::ostream& outs, LinkedList<Y>& linkedList);
};


#endif