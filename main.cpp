
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


     // *********************************************************  UNIT TEST *******************************************************

  // ***********************************************************  PART 1 ********************************************************
    

    // CHECK FOR SAME APPLICATION ID



    // DomesticStudent domStu1("nAtAsHa","Brown",(float)3.80,91,20201000,"AB");
    // domesticStudentList.insertNode(&domStu1);                                  // Normal case

    // DomesticStudent domStu2("JADEN","HILL",(float)0.01,1,20201001,"YT");
    // domesticStudentList.insertNode(&domStu2);                                  // Boundary case

    // DomesticStudent domStu3("Gurleen","Sidhu",(float)2.20,-93,20201002,"AB");
    // domesticStudentList.insertNode(&domStu3);                                  // Error case

    // domesticStudentList.insertNode(&domStu1);                                  // Error Case: Same application ID

    // cout<<domesticStudentList<<endl;                                          

    // Toefl toefl1(24,26,28,23);
    // InternationalStudent intStu1("Bingyu","Lu",(float)3.80,91,20201100,"China",toefl1);
    // internationalStudentList.insertNode(&intStu1);                                  // Normal case

    // Toefl toefl2(20,20,20,20);
    // InternationalStudent intStu2("BOBBY","Lobby",(float)3.40,83,20201101,"India",toefl2);
    // internationalStudentList.insertNode(&intStu2);                             // Boundary case

    // Toefl toefl3(11,13,28,23);
    // InternationalStudent intStu3("Tom","Lad",(float)0.0,83,20201103,"Korea",toefl3);
    // internationalStudentList.insertNode(&intStu3);                             // Error case

    // cout<<internationalStudentList<<endl;  

  // ***********************************************************  PART 2 ********************************************************



    // cout << "\n************************************************************* These are the domestic students with 3.4 CGPA *************************************************************\n";
    // domesticStudentList.searchCGPA(3.4);     // Regular case
    // cout << "\n************************************************************* These are the domestic students with 4.3 CGPA *************************************************************\n";
    // domesticStudentList.searchCGPA(4.3);    // Boundary case
    // cout << "\n************************************************************* These are the domestic students with 4.5 CGPA *************************************************************\n";
    // domesticStudentList.searchCGPA(4.50);   // Error case

    // cout << "\n************************************************************* These are the international students with 3.4 CGPA *************************************************************\n";
    // internationalStudentList.searchCGPA(3.40);     // Regular case
    // cout << "\n************************************************************* These are the international students with 4.3 CGPA *************************************************************\n";
    // internationalStudentList.searchCGPA(4.300000000000234020400242040023400230420340);    // Boundary case
    // cout << "\n************************************************************* These are the international students with 4.5 CGPA *************************************************************\n";
    // internationalStudentList.searchCGPA((int)5);   // Error case 


    // cout << "\n************************************************************* These are the domestic students with research score of 87 *************************************************************\n";
    // domesticStudentList.searchResearchScore((float)87.987);     // Regular case
    // cout << "\n************************************************************* These are the domestic students with research score of 100 *************************************************************\n";
    // domesticStudentList.searchResearchScore(100);    // Boundary case
    // cout << "\n************************************************************* These are the domestic students with research score of 103 *************************************************************\n";
    // domesticStudentList.searchResearchScore((float)103.0);   // Error case

    // cout << "\n************************************************************* These are the international students with research score of 87 *************************************************************\n";
    // internationalStudentList.searchResearchScore(87);     // Regular case
    // cout << "\n************************************************************* These are the international students with research score of 100 *************************************************************\n";
    // internationalStudentList.searchResearchScore(100);    // Boundary case
    // cout << "\n************************************************************* These are the international students with research score of 103 *************************************************************\n";
    // internationalStudentList.searchResearchScore(103);   // Error case 


    // cout << "\n************************************************************* Searching domestic students' application ID *************************************************************\n";
    // domesticStudentList.searchApplicationID(20200064);     // Regular case
    // domesticStudentList.searchApplicationID(20200000);    // Boundary case
    // domesticStudentList.searchApplicationID(30000000);   // Error case

    // cout << "\n************************************************************* Searching international students' application ID *************************************************************\n";
    // internationalStudentList.searchApplicationID(20200164);     // Regular case
    // internationalStudentList.searchApplicationID(20200199);    // Boundary case
    // internationalStudentList.searchApplicationID(30200064);   // Error case 





  // ***********************************************************  PART 3 ********************************************************

                                                              // FIND TWO CASES WITH SAME NAMEs

    // cout << "\n************************************************************* Searching domestic students' by name *************************************************************\n";
    // domesticStudentList.searchName("Mateo", "Powell");     // Regular case
    // domesticStudentList.searchName("mateo", "powell");    // Boundary case
    // domesticStudentList.searchName("Mat", "Powell");   // Error case

    // cout << "\n************************************************************* Searching internatinal students' by name *************************************************************\n";
    // internationalStudentList.searchName("Tingting", "Zhao");     // Regular case
    // internationalStudentList.searchName("tingting", "zhao");    // Boundary case
    // internationalStudentList.searchName("Tingting", "Ahao");   // Error case



  // ***********************************************************  PART 4 ********************************************************



    // cout << "\n************************************************************* Deleting domestic students by first name, last name basis  *************************************************************\n";
    // domesticStudentList.deleteNode("Mateo", "Powell");     // Regular case   
    // domesticStudentList.deleteNode("Dylan", "Barnes");     // Boundary case (deletes head)
    // domesticStudentList.deleteNode("Hazel", "Butle");    // Error case

    // cout<<domesticStudentList<<endl;


    // cout << "\n************************************************************* Deleting international students by first name, last name basis  *************************************************************\n";
    
    // Toefl toefl5(20,20,20,20);
    // InternationalStudent intStu5("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl5);
    // internationalStudentList.insertNode(&intStu5);

    // Toefl toefl6(20,20,20,20);
    // InternationalStudent intStu6("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl6);
    // internationalStudentList.insertNode(&intStu6);

    // internationalStudentList.deleteNode("Tingting", "Zhao");     // Regular case
    // internationalStudentList.deleteNode("setayesh", "Shams");    // Boundary case
    // internationalStudentList.deleteNode("Tingting", "Ahao");   // Error case

    // cout<<internationalStudentList<<endl;

  // ***********************************************************  PART 5 ********************************************************

    // cout << "\n************************************************************* Deleting domestic students' linked list head and tail *************************************************************\n";
    
    
    // domesticStudentList.delete_head_tail();
    // cout<<domesticStudentList<<endl;
  // ***********************************************************  PART 6 ********************************************************

  // ***********************************************************  PART 7 ********************************************************















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