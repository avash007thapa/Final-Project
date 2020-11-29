
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
      
        //error checking input
        while(!inputIsValid(userInput,7)){
            
            outputMenu();

            cout<<"Enter input: ";
            cin>>userInput;
            cout<<"\n\n";
        }

        //main menu
        float fInput;
        string sInput1;
        string sInput2;
        string sInput3;
        string sInput4;
        string firstName;
        string lastName;
        bool merged = false;
        switch(atoi(userInput.c_str())){
            case 1 :
                cout<<"Exiting Program\n"<<endl; 
                return 0;
            case 2 :
                
                if(merged == false){
                    cout<<"Search for a student(s)\n";
                    cout<<"****************************************************************\n";
                    cout<<"(1) - Search in domestic student list\n";
                    cout<<"(2) - Search in international student list\n";
                    cout<<"Enter input: ";
                    cin>>sInput1;
                    cout<<"\n\n";
                    //error checking input
                    while(!inputIsValid(sInput1,2)){
                        cout<<"Search for a student(s)\n";
                        cout<<"****************************************************************\n";
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
                
                
                cout<<"(1) - Search by applicationID\n";
                cout<<"(2) - Search by CGPA\n";
                cout<<"(3) - Search by research score\n";
                cout<<"(4) - Search by full name\n";
                cout<<"(5) - Search by CGPA and research score threshold\n\n";
                cout<<"Enter input: ";
                cin>>sInput2;
                cout<<"\n\n";
                //error checking input
                while(!inputIsValid(sInput2,5)){
                    cout<<"(1) - Search by applicationID\n";
                    cout<<"(2) - Search by CGPA\n";
                    cout<<"(3) - Search by research score\n";
                    cout<<"(4) - Search by full name\n";
                    cout<<"(5) - Search by CGPA and research score threshold\n\n";
                    cout<<"Enter input: ";
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
                }
                break;
            case 3:
                cout<<"Print a list"<<endl;
                cout<<"****************************************************************\n";
                cout<<"(1) - Print domestic student list\n";
                cout<<"(2) - Print international student list\n";
                cout<<"(3) - Print student list\n\n";
                cout<<"Enter input: ";
                cin>>sInput2;
                cout<<"\n\n";
                //error checking input
                while(!inputIsValid(sInput2,3)){
                    cout<<"(1) - Print domestic student list\n";
                    cout<<"(2) - Print international student list\n";
                    cout<<"(3) - Print student list\n\n";
                    cout<<"Enter input: ";
                    cin>>sInput2;
                    cout<<"\n\n";
                }

                switch(atoi(sInput2.c_str())){
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
                cin>>sInput2;
                cout<<"\n\n";
                //error checking inputs
                while(!inputIsValid(sInput2,2)){
                    cout<<"(1) - Create a new domestic student\n";
                    cout<<"(2) - Create a new international student\n\n";
                    cout<<"Enter input: ";
                    cin>>sInput2;
                    cout<<"\n\n";
                }

                switch(atoi(sInput2.c_str())){
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
                    cin>>sInput2;
                    cout<<"\n\n";
                    //error checking inputs
                    while(!inputIsValid(sInput2,2)){
                        cout<<"(1) - Delete a domestic student\n";
                        cout<<"(2) - Delete a international student\n\n";
                        cout<<"Enter input: ";
                        cin>>sInput2;
                        cout<<"\n\n";
                    }
                    switch(atoi(sInput2.c_str())){
                    case 1 :
                        deleteDomesticStudent(domesticStudentList);
                    case 2 :
                        deleteInternationalStudent(internationalStudentList);
                    }
                }
                else{
                    deleteStudent(studentList);
                }
                break;
            case 6 :
                cout<<"Delete head and tail nodes of domestic and international student list\n";
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
                        case 2 :
                            internationalStudentList.delete_head_tail();
                    }
                }
                else{
                    studentList.delete_head_tail();
                }
                break;
            case 7 :
                cout<<"Merge the domestic and international student list"<<endl;
                cout<<"****************************************************************\n";
                studentList = mergeList(domesticStudentList,internationalStudentList);
                studentList.print(); 
                break;
        }        
    }


     // *********************************************************  UNIT TEST *******************************************************

  // ***********************************************************  PART 1 ********************************************************
    

    // CHECK FOR SAME APPLICATION ID



    DomesticStudent domStu1("nAtAsHa","Brown",(float)3.80,91,20201000,"AB");
    domesticStudentList.insertNode(&domStu1);                                  // Normal case

    DomesticStudent domStu2("JADEN","HILL",(float)0.01,1,20201001,"YT");
    domesticStudentList.insertNode(&domStu2);                                  // Boundary case

    DomesticStudent domStu3("Gurleen","Sidhu",(float)2.20,-93,20201002,"AB");
    domesticStudentList.insertNode(&domStu3);                                  // Error case

    domesticStudentList.insertNode(&domStu1);                                  // Error Case: Same application ID

    cout<<domesticStudentList<<endl;                                          

    Toefl toefl1(24,26,28,23);
    InternationalStudent intStu1("Bingyu","Lu",(float)3.80,91,20201100,"China",toefl1);
    internationalStudentList.insertNode(&intStu1);                                  // Normal case

    Toefl toefl2(20,20,20,20);
    InternationalStudent intStu2("BOBBY","Lobby",(float)3.40,83,20201101,"India",toefl2);
    internationalStudentList.insertNode(&intStu2);                             // Boundary case

    Toefl toefl3(11,13,28,23);
    InternationalStudent intStu3("Tom","Lad",(float)0.0,83,20201103,"Korea",toefl3);
    internationalStudentList.insertNode(&intStu3);                             // Error case

    cout<<internationalStudentList<<endl;  

  // ***********************************************************  PART 2 ********************************************************



    cout << "\n************************************************************* These are the domestic students with 3.4 CGPA *************************************************************\n";
    domesticStudentList.searchCGPA(3.4);     // Regular case
    cout << "\n************************************************************* These are the domestic students with 4.3 CGPA *************************************************************\n";
    domesticStudentList.searchCGPA(4.3);    // Boundary case
    cout << "\n************************************************************* These are the domestic students with 4.5 CGPA *************************************************************\n";
    domesticStudentList.searchCGPA(4.50);   // Error case

    cout << "\n************************************************************* These are the international students with 3.4 CGPA *************************************************************\n";
    internationalStudentList.searchCGPA(3.40);     // Regular case
    cout << "\n************************************************************* These are the international students with 4.3 CGPA *************************************************************\n";
    internationalStudentList.searchCGPA(4.300000000000234020400242040023400230420340);    // Boundary case
    cout << "\n************************************************************* These are the international students with 4.5 CGPA *************************************************************\n";
    internationalStudentList.searchCGPA((int)5);   // Error case 


    cout << "\n************************************************************* These are the domestic students with research score of 87 *************************************************************\n";
    domesticStudentList.searchResearchScore((float)87.987);     // Regular case
    cout << "\n************************************************************* These are the domestic students with research score of 100 *************************************************************\n";
    domesticStudentList.searchResearchScore(100);    // Boundary case
    cout << "\n************************************************************* These are the domestic students with research score of 103 *************************************************************\n";
    domesticStudentList.searchResearchScore((float)103.0);   // Error case

    cout << "\n************************************************************* These are the international students with research score of 87 *************************************************************\n";
    internationalStudentList.searchResearchScore(87);     // Regular case
    cout << "\n************************************************************* These are the international students with research score of 100 *************************************************************\n";
    internationalStudentList.searchResearchScore(100);    // Boundary case
    cout << "\n************************************************************* These are the international students with research score of 103 *************************************************************\n";
    internationalStudentList.searchResearchScore(103);   // Error case 


    cout << "\n************************************************************* Searching domestic students' application ID *************************************************************\n";
    domesticStudentList.searchApplicationID(20200064);     // Regular case
    domesticStudentList.searchApplicationID(20200000);    // Boundary case
    domesticStudentList.searchApplicationID(30000000);   // Error case

    cout << "\n************************************************************* Searching international students' application ID *************************************************************\n";
    internationalStudentList.searchApplicationID(20200164);     // Regular case
    internationalStudentList.searchApplicationID(20200199);    // Boundary case
    internationalStudentList.searchApplicationID(30200064);   // Error case 





  // ***********************************************************  PART 3 ********************************************************

                                                              // FIND TWO CASES WITH SAME NAMES

    cout << "\n************************************************************* Searching domestic students' by name *************************************************************\n";
    domesticStudentList.searchName("Mateo", "Powell");     // Regular case
    domesticStudentList.searchName("mateo", "powell");    // Boundary case
    domesticStudentList.searchName("Mat", "Powell");     // Error case

    cout << "\n************************************************************* Searching internatinal students' by name *************************************************************\n";
    internationalStudentList.searchName("Tingting", "Zhao");     // Regular case
    internationalStudentList.searchName("tingting", "zhao");    // Boundary case
    internationalStudentList.searchName("Tingting", "Ahao");   // Error case



  // ***********************************************************  PART 4 ********************************************************



    cout << "\n************************************************************* Deleting domestic students by first name, last name basis  *************************************************************\n";
    domesticStudentList.deleteNode("Mateo", "Powell");     // Regular case   
    domesticStudentList.deleteNode("Dylan", "Barnes");     // Boundary case (deletes head)
    domesticStudentList.deleteNode("Hazel", "Butle");    // Error case

    cout<<domesticStudentList<<endl;


    cout << "\n************************************************************* Deleting international students by first name, last name basis  *************************************************************\n";
    
    Toefl toefl5(20,20,20,20);
    InternationalStudent intStu5("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl5);
    internationalStudentList.insertNode(&intStu5);

    Toefl toefl6(20,20,20,20);
    InternationalStudent intStu6("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl6);
    internationalStudentList.insertNode(&intStu6);

    internationalStudentList.deleteNode("Tingting", "Zhao");     // Regular case
    internationalStudentList.deleteNode("setayesh", "Shams");    // Boundary case
    internationalStudentList.deleteNode("Tingting", "Ahao");   // Error case

    cout<<internationalStudentList<<endl;

  // ***********************************************************  PART 5 ********************************************************

    cout << "\n************************************************************* Deleting domestic students' linked list head and tail *************************************************************\n";
    
    domesticStudentList.delete_head_tail();
    cout<<domesticStudentList<<endl;
     
  // ***********************************************************  PART 6 ********************************************************
   
    cout << "\n************************************************************* Merging domestic and international student linked lists into student linked list *************************************************************\n";
    //Toefl toefl_1(NULL,NULL,NULL,NULL);
    
    DomesticStudent dstu1;
    InternationalStudent istu1;
    //dstu1.head = NULL;
    //istu1.head = NULL;
    studentList = mergeList(domesticStudentList, internationalStudentList); // Regular case
    // Boundary case ?
    //studentList = mergeList(dstu1, istu1);// Error case ? (merging two empty lists)
    cout<<studentList<<endl;

  //***********************************************************  PART 7 ********************************************************

    cout << "\n************************************************************* Searching student objects in the merged linked list based on CGPA threshold and Research Score threshold *************************************************************\n";

    studentList.searchThreshold(4.0, 83);     // Regular case
    studentList.searchThreshold(0.0, 0);     // Boundary case (minimum; prints entire list)
    studentList.searchThreshold(4.3, 100);  // Boundary case (maximum; prints nothing)
    studentList.searchThreshold(4.7, 200); // Error case

    cout<<studentList<<endl;














//   mergeList(domesticStudentList,internationalStudentList,studentList);
  //cout<<studentList<<endl;
  //studentList.print();

  //DomesticStudentPtr a = dynamic_cast<DomesticStudentPtr>(student);

  // studentList.insertNode(*student);
  // cout<<studentList<<endl;
  //studentList.head->student.getProvince();
  //cout<<studentList<<endl;
  //studentList = mergeList(domesticStudentList,internationalStudentList);
  





        //     cout<<"Enter input: ";
        //     cin>>userInput;
        //     cout<<"\n\n";
        // }
        

}