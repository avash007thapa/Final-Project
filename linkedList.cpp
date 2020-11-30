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
		cout<<"Bad Memory allocation in LinkedList::LinkedList\n";
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
        cout<<"Error(deepCopyLinkedList): bad_alloc\n";
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
        node->student->deleteThis();
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
        if(checkApplicationID(student.getApplicationID())){
            cout<<"Error(insertNode): Cannot insert node with the same applicationID: "<<student.getApplicationID()<<endl;
            return;
        }

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
        cout<<"Error(insertNode): bad_alloc\n";
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
		cout << "Error(deleteNode): List is already empty\n";
        return;
	}
    while(here != nullptr){
        //if name in the linked list matches the input name
        if((here->student->firstName.compare(firstName) == 0) && (here->student->lastName.compare(lastName) == 0)){
            cout<<"----DELETED----\n"<<*(here->student)<<"\n";
            counter++;
            //delete at head
            if(here == head){
                prev = head;
                head = head->link;
                prev->student->deleteThis();
                delete prev;
                here = head;
            }
            //delete at tail
            else if(here == tail){
                here->student->deleteThis();
                delete here;
                here->link = nullptr;
                tail = prev;
                prev->link = nullptr;
                break;
            }
            //delete in list
            else{
                prev->link = here->link;
                here->student->deleteThis();
                delete here;
                here = prev;
            }
        }   
        prev = here;
        here = here->link;
    }
    //if student isn't in list
    if(counter == 0){
        cout <<"Students with (name = "<<firstName<<" "<<lastName<<") are not in this list.\n\n"; 
    }
}


//print all students with same applicationID
template <class T>
void LinkedList<T>::searchApplicationID(int applicationID){
    NodePtr here = head;
    int counter = 0;
    while(here != nullptr){
        if(here->student->applicationID == applicationID){
            cout<<*(here->student)<<endl;
            counter++;
        }
        here = here->link;
    }
    if(counter == 0){
        cout<<"Students with (ApplicationID = "<<applicationID<<") are not in this list.\n\n";
    }
    else{
        cout<<"Found "<<counter<<" students\n\n";
    }
}

//print all students with same applicationID
template <class T>
bool LinkedList<T>::checkApplicationID(int applicationID){
    NodePtr here = head;
    while(here != nullptr){
        if(here->student->applicationID == applicationID){
            return true;
        }
        here = here->link;
    }
    return false;
}

//print all students with same CGPA
template <class T>
void LinkedList<T>::searchCGPA(float CGPA){
    CGPA = float1f(CGPA);
    NodePtr here = head;
    int counter = 0;
    while(here != nullptr){
        if(here->student->CGPA == CGPA){
            cout<<*(here->student)<<endl;
            counter++;
        }
        here = here->link;
    }
    if(counter == 0){
        cout<<"Students with (CGPA = "<<CGPA<<") are not in this list.\n\n";
    }
    else{
        cout<<"Found "<<counter<<" students\n\n";
    }
}

//print all students with same research score
template <class T>
void LinkedList<T>::searchResearchScore(int researchScore){
    NodePtr here = head;
    int counter = 0;
    while(here != nullptr){
        if(here->student->researchScore == researchScore){
            cout<<*(here->student)<<endl;
            counter++;
        }
        here = here->link;
    }
    if(counter == 0){
        cout<<"Students with (reseach score = "<<researchScore<<") are not in this list.\n\n";
    }
    else{
        cout<<"Found "<<counter<<" students\n\n";
    }
}

//print all students with same full name
template <class T>
void LinkedList<T>::searchName(string firstName, string lastName){
    NodePtr here = head;
    int counter = 0;
    formatString(firstName);
    formatString(lastName);
    
    while(here != nullptr){
        if((here->student->firstName.compare(firstName) == 0) && (here->student->lastName.compare(lastName) == 0)){
            cout<<*(here->student)<<endl;
            counter++;
        }
        here = here->link;
    }
    if(counter == 0){
        cout<<"Students with (name = "<<firstName<<" "<<lastName<<") are not in this list.\n\n";
    }
    else{
        cout<<"Found "<<counter<<" students\n\n";
    }
}


//prints all students above the CGPA and research score threshold
template <class T>
void LinkedList<T>::searchThreshold(float CGPAThreshold, int researchScoreThreshold){
    NodePtr here = head;
    int counter = 0;
    while(here != nullptr){
        if((here->student->CGPA >= CGPAThreshold) && (here->student->researchScore >= researchScoreThreshold)){
            cout<<*(here->student)<<endl;
            counter++;
        }
        here = here->link;
    }
    if(counter == 0){
        cout<<"No students with (CGPA = "<<CGPAThreshold<<" research score"<<researchScoreThreshold<<") in this list.\n\n";
    }
    else{
        cout<<"Found "<<counter<<" students\n\n";
    }
}


//deletes head both the head and tail nodes from the linked list
template <class T>
void LinkedList<T>::delete_head_tail(){
    NodePtr here = head;
    
    //if list is empty
    if(head == nullptr){
        cout<<"Error(delete_head_tail): List is empty\n";
        return;
    }
    
    //if theres only one item in the list
    if(head == tail){
        
    }

    //delete head
    head = head->link;
    cout<<"----DELETED HEAD----\n";
    here->student->print();
    cout<<endl<<endl;
    here->student->deleteThis();
    delete here;
    
    //delete tail
    here = head;
    while(here->link != nullptr){
        if(here->link->link == nullptr){
            tail = here;
            cout<<"----DELETED TAIL----\n";
            here->link->student->print();
            cout<<endl<<endl;
            here->link->student->deleteThis();
            delete here->link;
            tail->link = nullptr;
            break;
        }
        here = here->link;
    }
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
