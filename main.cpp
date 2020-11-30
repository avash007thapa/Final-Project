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
#include "unitTest.hpp"

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
    std::cout<<"\n\n\n*******************************************************************************\n";
    std::cout<<"G R A D U A T E   A D M I S S I O N   S Y S T E M\n";
    std::cout<<"*******************************************************************************\n";
    std::cout<<"\n";
    
    //interface
    string userInput;
    bool merged = false;
    while(true){

        outputMenu(merged);

        cout<<"Enter input: ";
        cin>>userInput;
        cout<<"\n\n";      
      
        //error checking input
        while(!inputIsValid(userInput,7)){
            
            outputMenu(merged);

            cout<<"Enter input: ";
            cin>>userInput;
            cout<<"\n\n";
        }

        //main menu
        float fInput;
        string sInput1;
        string sInput2;
        string sInput3;
        string firstName;
        string lastName;
        switch(atoi(userInput.c_str())){
            case 1 :
                cout<<"Exiting Program\n"<<endl; 
                return 0;
            case 2 :
                cout<<"Search for a student(s)\n";
                cout<<"****************************************************************\n";
                if(merged == false){
                    cout<<"(1) - Search in domestic student list\n";
                    cout<<"(2) - Search in international student list\n";
                    cout<<"Enter input: ";
                    cin>>sInput1;
                    cout<<"\n\n";
                    //error checking input
                    while(!inputIsValid(sInput1,2)){
                        cout<<"(1) - Search in domestic student list\n";
                        cout<<"(2) - Search in international student list\n";
                        cout<<"Enter input: ";
                        cin>>sInput1;
                        cout<<"\n\n";
                    }
                }
                else{
                    sInput1 = "3";
                }
                
                cout<<"| (1) - Search by applicationID\n";
                cout<<"| (2) - Search by CGPA\n";
                cout<<"| (3) - Search by research score\n";
                cout<<"| (4) - Search by full name\n";
                cout<<"| (5) - Search by CGPA and research score threshold\n\n";
                cout<<"| (6) - Run unit test\n";
                cout<<"| Enter input: ";
                cin>>sInput2;
                cout<<"\n\n";
                //error checking input
                while(!inputIsValid(sInput2,5)){
                    cout<<"| (1) - Search by applicationID\n";
                    cout<<"| (2) - Search by CGPA\n";
                    cout<<"| (3) - Search by research score\n";
                    cout<<"| (4) - Search by full name\n";
                    cout<<"| (5) - Search by CGPA and research score threshold\n\n";
                    cout<<"| Enter input: ";
                    cin>>sInput2;
                    cout<<"\n\n";
                }

                switch(atoi(sInput2.c_str())){
                    case 1 :
                        cout<<"Input applicationID: ";
                        cin>>sInput3;
                        if(merged == false){
                            if(atoi(sInput1.c_str()) == 1){
                                domesticStudentList.searchApplicationID(atoi(sInput3.c_str()));
                            }
                            else{
                                internationalStudentList.searchApplicationID(atoi(sInput3.c_str()));
                            }
                        }
                        else{
                            studentList.searchApplicationID(atoi(sInput3.c_str()));
                        }
                        break;
                    case 2 :
                        cout<<"Input CGPA: ";
                        cin>>fInput;
                        fInput = round1f(fInput);
                        if(merged == false){
                            if(atoi(sInput1.c_str()) == 1){
                                domesticStudentList.searchCGPA(fInput);
                            }
                            else{
                                internationalStudentList.searchCGPA(fInput);
                            }
                        }
                        else{
                            studentList.searchCGPA(fInput);
                        }
                        break;
                    case 3 :
                        cout<<"Input research score: ";
                        cin>>sInput3;
                        if(merged == false){
                            if(atoi(sInput1.c_str()) == 1){
                                domesticStudentList.searchResearchScore(atoi(sInput3.c_str()));
                            }
                            else{
                                internationalStudentList.searchResearchScore(atoi(sInput3.c_str()));
                            }
                        }
                        else{
                            studentList.searchResearchScore(atoi(sInput3.c_str()));
                        }
                        break;
                    case 4 :
                        cout<<"Input first name: ";
                        cin>>firstName;
                        cout<<"Input last name: ";
                        cin>>lastName;
                        formatString(firstName);
                        formatString(lastName);
                        if(merged == false){
                           if(atoi(sInput1.c_str()) == 1){
                                domesticStudentList.searchName(firstName,lastName);
                            }
                            else{
                                internationalStudentList.searchName(firstName,lastName);
                            }
                        }
                        else{
                            studentList.searchName(firstName,lastName);
                        }
                        break;
                    case 5 :
                        cout<<"Input CGPA threshold: ";
                        cin>>fInput;
                        fInput = round1f(fInput);
                        cout<<"Input research score threshold: ";
                        cin>>sInput3;
                        if(merged == false){
                           if(atoi(sInput1.c_str()) == 1){
                                domesticStudentList.searchThreshold(fInput,atoi(sInput3.c_str()));
                            }
                            else{
                                internationalStudentList.searchThreshold(fInput,atoi(sInput3.c_str()));
                            }
                        }
                        else{
                            studentList.searchThreshold(fInput,atoi(sInput3.c_str()));
                        }
                        break;
                    case 6 :
                        void UnitTest(LinkedList<DomesticStudent>& domesticStudentList, LinkedList<InternationalStudent>& internationalStudentList, LinkedList<Student> studentList, int& studentNum);
                }
                break;
            case 3:
                cout<<"Print a list"<<endl;
                cout<<"****************************************************************\n";
                if(merged == false){
                    cout<<"(1) - Print domestic student list\n";
                    cout<<"(2) - Print international student list\n";
                    cout<<"Enter input: ";
                    cin>>sInput1;
                    cout<<"\n\n";
                    //error checking input
                    while(!inputIsValid(sInput1,3)){
                        cout<<"(1) - Print domestic student list\n";
                        cout<<"(2) - Print international student list\n";
                        cout<<"Enter input: ";
                        cin>>sInput1;
                        cout<<"\n\n";
                    }
                }
                else{
                    sInput1 = "3";
                }
                switch(atoi(sInput1.c_str())){
                    case 1 :
                        domesticStudentList.print();
                        break;
                    case 2 :
                        internationalStudentList.print();
                        break;
                    case 3 :
                        studentList.print();
                        break;
                }
                break;
            case 4 :
                cout<<"Create a new student"<<endl;
                cout<<"****************************************************************\n";
                cout<<"(1) - Create a new domestic student\n";
                cout<<"(2) - Create a new international student\n\n";
                cout<<"Enter input: ";
                cin>>sInput1;
                cout<<"\n\n";
                //error checking inputs
                while(!inputIsValid(sInput1,2)){
                    cout<<"(1) - Create a new domestic student\n";
                    cout<<"(2) - Create a new international student\n\n";
                    cout<<"Enter input: ";
                    cin>>sInput1;
                    cout<<"\n\n";
                }

                switch(atoi(sInput1.c_str())){
                    case 1 :
                        if(merged == false){
                            insertDomesticStudent(domesticStudentList,studentNum);
                        }
                        else{
                            insertDomesticStudent(studentList,studentNum);
                        }
                        break;
                    case 2 :
                        if(merged == false){
                            insertInternationalStudent(internationalStudentList,studentNum);
                        }
                        else{
                            insertInternationalStudent(studentList,studentNum);
                        }
                        break;
                }
                break;
            case 5 :
                cout<<"Delete a student"<<endl;
                cout<<"****************************************************************\n";
                if(merged == false){
                    cout<<"(1) - Delete a domestic student\n";
                    cout<<"(2) - Delete a international student\n\n";
                    cout<<"Enter input: ";
                    cin>>sInput1;
                    cout<<"\n\n";
                    //error checking inputs
                    while(!inputIsValid(sInput1,2)){
                        cout<<"(1) - Delete a domestic student\n";
                        cout<<"(2) - Delete a international student\n\n";
                        cout<<"Enter input: ";
                        cin>>sInput1;
                        cout<<"\n\n";
                    }
                    switch(atoi(sInput1.c_str())){
                    case 1 :
                        deleteDomesticStudent(domesticStudentList);
                        break;
                    case 2 :
                        deleteInternationalStudent(internationalStudentList);
                        break;
                    }
                }
                else{
                    deleteStudent(studentList);
                }
                break;
            case 6 :
                cout<<"Delete head and tail nodes of a list\n";
                cout<<"****************************************************************\n";
                if(merged == false){
                    cout<<"(1) - Delete head and tail of domestic student\n";
                    cout<<"(2) - Delete head and tail of international student\n\n";
                    cout<<"Enter input: ";
                    cin>>sInput1;
                    cout<<"\n\n";
                    //error checking inputs
                    while(!inputIsValid(sInput1,2)){
                        cout<<"(1) - Delete head and tail of domestic student\n";
                        cout<<"(2) - Delete head and tail of international student\n\n";
                        cout<<"Enter input: ";
                        cin>>sInput1;
                        cout<<"\n\n";
                    }
                    switch(atoi(sInput1.c_str())){
                        case 1 :
                            domesticStudentList.delete_head_tail();
                            break;
                        case 2 :
                            internationalStudentList.delete_head_tail();
                            break;
                    }
                }
                else{
                    studentList.delete_head_tail();
                }
                break;
            case 7 :
                cout<<"Unit Test"<<endl;
                cout<<"****************************************************************\n";
                UnitTest(domesticStudentList, internationalStudentList, studentList, studentNum);
                break;
            case 8 :
                cout<<"Merge the domestic and international student list"<<endl;
                cout<<"****************************************************************\n";
                studentList = mergeList(domesticStudentList,internationalStudentList);
                studentList.print(); 
                merged = true;
                break;
        }        
    }

}