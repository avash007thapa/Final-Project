
using namespace std;
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "linkedList.cpp"
#include "linkedList.hpp"
#include "student.hpp"
#include "internationalStudent.hpp"
#include "domesticStudent.hpp"
#include "helper.hpp"


int main(){

    //linked lists
    LinkedList<Student> studentList;
    LinkedList<DomesticStudent> domesticStudentList;
    LinkedList<InternationalStudent> internationalStudentList;
    
    //getting inputs from domestic-stu.txt and putting it into domesticStudentList
    domFile2DomList(domesticStudentList);

    //getting inputs from international-stu.txt and putting it into internationalStudentList
    intFile2IntList(internationalStudentList);

  
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //title card
    std::cout<<"**********************************************************************\n";
    std::cout<<"G R A D U A T E   A D M I S S I O N   S Y S T E M\n";
    std::cout<<"**********************************************************************\n";
    std::cout<<"\n";
    
    //interface
    string userInput;
    while(true){

        outputMenu();

        cout<<"Enter input: ";
        cin>>userInput;
        cout<<"\n\n";      
      
        //error checking
        while(!inputIsValid(userInput)){
            
            outputMenu();

            cout<<"Enter input: ";
            cin>>userInput;
            cout<<"\n\n";
        }

        int inputNum = atoi(userInput.c_str());
        switch(inputNum){
            case 1 :
                cout<<"(1) Exiting Program\n"<<endl; 
                return 0;
            case 2 :
                cout<<"(2) Insert Node"<<endl;
                cout<<"****************************************************************\n";
                cout<<"(1) Create a new domestic student\n";
                cout<<"(2) Create a new international student\n";
                

            case 3 :
                cout << "DELETE SELECTED" << endl;
                
            case 4 :
                cout << "MERGE SELECTED" << endl;
        }        
    }
}