#ifndef LINKEDLIST_CPP
#define LINEDLIST_CPP

using namespace std;
#include "linkedList.hpp"
#include "student.hpp"
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"
#include "helper.hpp"
#include <string>
#include <typeinfo>


//Node class implementation -------------------------------------------------------------------/

//constructors 
template <class T>
LinkedList<T>::Node::Node(T* student):student(student),link(nullptr){
}
template <class T> 
LinkedList<T>::Node::Node():student(nullptr),link(nullptr){
}


//Linked List implementation -------------------------------------------------------------------/

//constructors
template <class T>
LinkedList<T>::LinkedList(T* student){
    try{
		head = new Node(student);
		tail = head;
		tail->link = nullptr;
	}
	catch(bad_alloc){
		cerr<<"Bad Memory allocation in LinkedList::LinkedList\n";
		exit(1);
	}
}
template <class T>
LinkedList<T>::LinkedList():head(nullptr),tail(nullptr){
}


//copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& linkedList){
    head = deepCopyLinkedList(linkedList.head);
}
template <class T>
typename LinkedList<T>::NodePtr LinkedList<T>::deepCopyLinkedList(NodePtr node){
    //if linked list is empty or at the end of the linked list
    if(node == nullptr){
		return nullptr;
    }
    try{
        //allocating memory to new Node
        NodePtr newNode = new Node(node->student);
        
        //base case
        if(node->link == nullptr){
            return newNode;
        }
		//recursive call to deepCopyStack
		newNode->link = deepCopyLinkedList(node->link);
		//assigning tail 
		if(node->link == nullptr){
			tail = newNode;
			node->link = nullptr;
		}
        return newNode;
    }
    catch(bad_alloc){
        cerr<<"Error(deepCopyLinkedList): bad_alloc\n";
        exit(1);
    }
}


//overloaded assignment operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& linkedList){
    if(head != linkedList.head){
        deleteLinkedList(head);
        head = deepCopyLinkedList(linkedList.head);
    }
    return *this;
}


//destructor
template <class T>
LinkedList<T>::~LinkedList(){
    deleteLinkedList(head);
}
template <class T>
void LinkedList<T>::deleteLinkedList(NodePtr node){
    if(node != nullptr){
		deleteLinkedList(node->link);
		delete node->student;
        delete node;
		node = nullptr;
	}
	else{
		head = nullptr;
		tail = nullptr;
	}
}



//inserts node in a sorted order in the linked list
template <class T>
void LinkedList<T>::insertNode(T* student){
    try{
		NodePtr prev = nullptr;
        NodePtr here = head; 
        NodePtr newNode = new Node(student);

        //if list is empty
        if(head == nullptr){
            head = newNode;
            tail = head;
            return;
        }
        while (here != nullptr){
            if(compareOverall(*(here->student),*(newNode->student)) == 1){
                if(prev == nullptr){
                    newNode->link = here;
                    head = newNode;
                }
                else{
                    prev->link = newNode;
                    newNode->link = here;
                }
                break;
            }
            //if end of list insert at tail
            else if(here->link == nullptr){
                here->link = newNode;
                tail = newNode;
                break;
            }
            
            //itterating through linked list
            prev = here;
            here = here->link;
		} 
    }
    catch(bad_alloc){
        cerr<<"Error(insertNode): bad_alloc\n";
        exit(1);
    }
}


//deletes all nodes that have the same first name and last name
template <class T>
void LinkedList<T>::deleteNode(string firstName, string lastName){
    NodePtr prev = nullptr;
	NodePtr here = head;
    int counter = 0;
    
    //if head is nullptr, list is empty
	if(head == nullptr){
		cerr << "Error(deleteNode): List is already empty\n";
        return;
	}
    while(here != nullptr){
        cout << here->student->firstName << " " << here->student->lastName << endl;
        cout << ((here->student->firstName.compare(firstName) == 0) && (here->student->lastName.compare(lastName) == 0)) <<endl;

        //if name in the linked list matches the input name
        if((here->student->firstName.compare(firstName) == 0) && (here->student->lastName.compare(lastName) == 0)){
            cout<<"----DELETED----\n"<<*(here->student)<<"\n";
            //delete at head
            if(here == head){
                prev = head;
                head = head->link;
                delete prev;
                prev->link = nullptr;
            }
            //delete at tail
            else if(here == tail){
                delete here;
                here->link = nullptr;
                tail = prev;
                prev->link = nullptr;
            }
            //delete in list
            else{
                prev->link = here->link;
                delete here;
                here->link = nullptr;
            }
        }   
        prev = here;
        here = here->link;
    }
    cout<< counter;
    if(counter == 0){
        cout << "\nThe student with name " << firstName << " " << lastName << " was not found!\n\n\n"; 
    }
}


//print all students with same applicationID
template <class T>
void LinkedList<T>::searchApplicationID(int applicationID){
    NodePtr here = head;
    int counter = 0;
    while(here != nullptr){
        if(here->student->applicationID == applicationID){
            counter++;
            cout<<*(here->student)<<endl;
            flag = true;
        }
        here = here->link;
    }
    if(counter == 0){
        cout<<"Students with (ApplicationID = "<<applicationID<<") are not in this list.\n";
    }
    else{
        cout<<"There are "<<counter"<< students 
    }
}

//print all students with same CGPA
template <class T>
void LinkedList<T>::searchCGPA(float CGPA){
    NodePtr here = head;
    bool flag = false;
    while(here != nullptr){
        if(here->student->CGPA == CGPA){
            cout<<*(here->student)<<endl;
            flag = true;
        }
        here = here->link;
    }
    if(flag == false){
        cout<<"Students with (CGPA = "<<CGPA<<") are not in this list.\n";
    }
}

//print all students with same research score
template <class T>
void LinkedList<T>::searchResearchScore(int researchScore){
    NodePtr here = head;
    bool flag = false;
    while(here != nullptr){
        if(here->student->researchScore == researchScore){
            cout<<*(here->student)<<endl;
            flag = true;
        }
        here = here->link;
    }
    if(flag == false){
        cout<<"Students with (reseach score = "<<researchScore<<") are not in this list.\n";
    }
}

//print all students with same full name
template <class T>
void LinkedList<T>::searchName(string firstName, string lastName){
    NodePtr here = head;
    bool flag = false;
    while(here != nullptr){
        if((here->student->firstName.compare(firstName) == 0) && (here->student->lastName.compare(lastName) == 0)){
            cout<<*(here->student)<<endl;
            flag = true;
        }
        here = here->link;
    }
    if(flag == false){
        cout<<"Students with (name = "<<firstName<<" "<<lastName<<") are not in this list.\n";
    }
}


//prints all students above teh CGPA and research score threshold
template <class T>
void LinkedList<T>::searchThreshold(float CGPAThreshold, int researchScoreThreshold){
    bool flag;
    NodePtr here = head;

    while(here != nullptr){
        if((here->student->CGPA >= CGPAThreshold) && (here->student->researchScore >= researchScoreThreshold)){
            cout<<*(here->student)<<endl;
            flag = true;
        }
        here = here->link;
    }
    if(flag == false){
        cout<<"No students with (CGPA = "<<CGPAThreshold<<" research score"<<researchScoreThreshold<<") in this list.\n";
    }
}


//deletes head both the head and tail nodes from the linked list
template <class T>
void LinkedList<T>::delete_head_tail(){
    NodePtr here = head;
    
    //delete head
    head = head->link;
    delete here;
    
    //delete tail
    here = head;
    while(here->link != nullptr){
        if(here->link->link == nullptr){
            tail = here;
            delete here->link;
            tail->link = nullptr;
        }
        here = here->link;
    }
    cout<<"out\n"; return;
}


//prints all student info in the linked list
template <class T>
void LinkedList<T>::print(){
    auto here = head;
    int counter = 0;

    if(head == nullptr){
        cout<<"\nList is empty\n";
    }
    else{
        while(here != nullptr){
            here->student->print();
            cout<<"\n";
            here = here->link;
            counter++;
        }
    }
    cout<<"Total Students: "<<counter<<endl<<endl;
}


//overload output operators
template <class T>
ostream& operator<<(ostream& outs, LinkedList<T>& linkedList){
    typename LinkedList<T>::NodePtr here = linkedList.head;
    int counter = 1;
    while(here != nullptr){
        outs<<counter<<" "<<*(here->student)<<endl;
        here = here->link;
        counter++;
    }
    return outs;
}

#endif