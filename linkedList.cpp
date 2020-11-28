#ifndef LINKEDLIST_CPP
#define LINEDLIST_CPP

#include "linkedList.hpp"
#include <string>
#include "student.hpp"
#include "domesticStudent.hpp"
#include "internationalStudent.hpp"
#include <typeinfo>
using namespace std;

//Node Class implementation
template <class T>
LinkedList<T>::Node::Node(T student):student(student),link(nullptr){
}
template <class T> 
LinkedList<T>::Node::Node():student(),link(nullptr){
}


//LinkedList class implementation

//constructors
template <class T>
LinkedList<T>::LinkedList(T student){
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
        std::cerr<<"Error(deepCopyLinkedList): bad_alloc\n";
        std::exit(1);
    }
}


//overloading assignment operator
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
		delete node;
		node = nullptr;
	}
	else{
		head = nullptr;
		tail = nullptr;
	}
}



//insertNode
template <class T>
void LinkedList<T>::insertNode(T student){
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

        // cout<<"head "<<head<<endl;
        // cout<<"here "<<here<<endl;
        // cout<<"newNode "<<newNode<<endl;
        // cout<<"prev "<<prev<<endl<<endl;

        while (here != nullptr){
            if(compareOverall(here->student,newNode->student) == 1){
                //if at head
                //cout<<"it got in\n\n";
                if(prev == nullptr){
                    //cout<<"test\n";
                    newNode->link = here;
                    head = newNode;
                    //cout<<"test\n";
                }
                else{
                    //cout<<"awdad\n";
                    prev->link = newNode;
                    //cout<<"awdad\n";
                    newNode->link = here;
                    //cout<<"awdad\n";
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
        std::cerr<<"Error(insertNode): bad_alloc\n";
        std::exit(1);
    }
}


//deleteNode
template <class T>
void LinkedList<T>::deleteNode(std::string firstName, std::string lastName){
    NodePtr prev = nullptr;
	NodePtr here = head;

	if(head == nullptr){
		std::cerr << "Error(deleteNode): List is already empty\n";
        return;
	}
    while(here != nullptr){
        if((here->student->firstName.compare(firstName) == 1) && (here->lastName.compare(lastName) == 1)){
            std::cout<<"Deleted"<<here->student<<std::endl;
            if(here == head){
                prev = head;
                head = head->link;

                delete prev;
                prev->link = nullptr;
            }
            else if(here == tail){
                delete here;
                here->link = nullptr;

                tail = prev;
                prev->link = nullptr;
            }
            else{
                prev->link = here->link;
                delete here;
                here->link = nullptr;
            }
        }
        prev = here;
        here = here->link;
    }
}


//print (all sutdents with same applicationID/CGPA/researchScore/name)
template <class T>
void LinkedList<T>::searchApplicationID(int applicationID){
    NodePtr here = head;
    while(here != nullptr){
        if(here.student.applicationID == applicationID){
            std::cout<<here.student<<std::endl;
        }
        else if(here.student.applicationID < applicationID){
            break;
        }
        here = here->link;
    }
}
template <class T>
void LinkedList<T>::searchCGPA(float CGPA){
    NodePtr here = head;
    while(here != nullptr){
        if(here.student.CGPA == CGPA){
            std::cout<<here.student<<std::endl;
        }
        else if(here.student.CGPA < CGPA){
            break;
        }
        here = here->link;
    }
}
template <class T>
void LinkedList<T>::searchResearchScore(int researchScore){
    NodePtr here = head;
    while(here != nullptr){
        if(here.student.researchScore == researchScore){
            std::cout<<here.student<<std::endl;
        }
        else if(here.student.researchScore < researchScore){
            break;
        }
        here = here->link;
    }
}
template <class T>
void LinkedList<T>::searchName(std::string firstName, std::string lastName){
    NodePtr here = head;
    while(here != nullptr){
        if((here.student.firstName.compare(firstName) == 0) && (here.student.lastName.compare(lastName) == 0)){
            std::cout<<here.student<<std::endl;
        }
        here = here->link;
    }
}



//delete (deletes head and tail ptrs)
template <class T>
void LinkedList<T>::delete_head_tail(){
    delete head;
    delete tail;
    head = nullptr;
    tail = nullptr;
}


//Merge (merges a domestic list and an international list into a student list)
template <class T>
LinkedList<Student> merge(LinkedList<DomesticStudent>& domesticList, LinkedList<InternationalStudent>& internationalList){
    LinkedList<Student> returnList;
    returnList.head = domesticList.deepCopyLinkedList(domesticList.head);

    typename LinkedList<T>::NodePtr here = internationalList.head;

    while(here != nullptr){
        if(!here.student.getToeflScore().passed()){
            here = here->link;
        }
        returnList.insertNode(here.student);
    }

    return returnList;
}


//overload output operators
template <class T>
std::ostream& operator<<(std::ostream& outs, LinkedList<T>& linkedList){
    typename LinkedList<T>::NodePtr here = linkedList.head;
    int counter = 1;
    while(here != nullptr){
        outs<<counter<<" "<<here->student<<std::endl;
        here = here->link;
        counter++;
    }
    return outs;
}

#endif