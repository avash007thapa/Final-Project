
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

//keeping track of number of students
int studentNum = 0;

int main(){

    //linked lists
    LinkedList<Student> studentList;
    LinkedList<DomesticStudent> domesticStudentList;
    LinkedList<InternationalStudent> internationalStudentList;
    
    //getting inputs from domestic-stu.txt and putting it into domesticStudentList
    domFile2DomList(domesticStudentList,studentNum);

    //getting inputs from international-stu.txt and putting it into internationalStudentList
    intFile2IntList(internationalStudentList,studentNum);

  
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
                cout<<"Exiting Program\n"<<endl; 
                return 0;
            case 2 :
                cout<<"Insert Node"<<endl;
                cout<<"****************************************************************\n";
                cout<<"(1) - Create a new domestic student\n";
                cout<<"(2) - Create a new international student\n";
                cout<<"Enter input: ";
                cin>>inputNum;

                switch(inputNum){
                    case 1 :
                        insertDomesticStudent(domesticStudentList,studentNum);
                        break;
                    case 2 :
                        insertInternationalStudent(internationalStudentList,studentNum);
                        break;
                }
                break;
            case 3 :
                cout<<"Delete Node"<<endl;
                cout<<"****************************************************************\n";
                cout<<"(1) - Delete a domestic student\n";
                cout<<"(2) - Delete a international student\n";
                cout<<"Enter input: ";
                cin>>inputNum;
                cout<<inputNum<<"\n\n";

                switch(inputNum){
                    case 1 :
                        deleteDomesticStudent(domesticStudentList);
                    case 2 :
                        deleteInternationalStudent(internationalStudentList);
                }
                break;
            case 4 :
                cout<<"Delete Node"<<endl;
                cout<<"****************************************************************\n";
                studentList = mergeList(domesticStudentList,internationalStudentList);
                studentList.print(); 
                break;
        }        
    }
}