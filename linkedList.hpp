#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
#include "student.hpp"
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"




template <class T>
class LinkedList{
    private:
        T* head;
        T* tail;
    public:
        //constructors
        

        //dynamic big three


        
        //insertNode

        //deleteNode

        //print (all sutdents with same CGPA & researchScore)

        //delete (deletes head and tail ptrs)

        //overload output operators

        //merge
        friend LinkedList<Student> merge(LinkedList<DomesticStudent>& domList, LinkedList<InternationalStudent>& intList);
};
template <class T>
using Tptr = T*;


#endif