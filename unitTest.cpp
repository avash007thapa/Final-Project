#include "unitTest.hpp"
#include <iostream>

using namespace std;

void UnitTest(LinkedList<DomesticStudent>& domesticStudentList, LinkedList<InternationalStudent>& internationalStudentList, LinkedList<Student> studentList, int& studentNum){
    
    
    // ******************************************************* UNIT TEST *******************************************************

    // *******************************************************  PART 1 ********************************************************
    // *****************************************************  insertNode() ****************************************************

    DomesticStudent domStu1("nAtAsHa","Brown",(float)3.80,91,studentNum,"AB");
    studentNum++;
    domesticStudentList.insertNode(&domStu1);                                  // Normal case

    DomesticStudent domStu2("JADEN","HILL",(float)0.01,1,20201001,"YT");
    domesticStudentList.insertNode(&domStu2);                                  // Boundary case

    DomesticStudent domStu3("Gurleen","Sidhu",(float)2.20,-93,20201002,"AB");
    domesticStudentList.insertNode(&domStu3);                                  // Error case

    domesticStudentList.insertNode(&domStu1);                                  // Error Case: Same application ID

    domesticStudentList.print();                                         

    Toefl toefl1(24,26,28,23);
    InternationalStudent intStu1("Bingyu","Lu",(float)3.80,91,20201100,"China",toefl1);
    internationalStudentList.insertNode(&intStu1);                                  // Normal case

    Toefl toefl2(20,20,20,20);
    InternationalStudent intStu2("BOBBY","Lobby",(float)3.40,83,20201101,"India",toefl2);
    internationalStudentList.insertNode(&intStu2);                             // Boundary case

    Toefl toefl3(11,13,28,23);
    InternationalStudent intStu3("Tom","Lad",(float)0.0,83,20201103,"Korea",toefl3);
    internationalStudentList.insertNode(&intStu3);                             // Error case

    internationalStudentList.print();  

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

    domesticStudentList.print();


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

    internationalStudentList.print();

  // ***********************************************************  PART 5 ********************************************************

    cout << "\n************************************************************* Deleting domestic students' linked list head and tail *************************************************************\n";
    
    domesticStudentList.delete_head_tail();
    domesticStudentList.print();

    cout << "\n************************************************************* Deleting international students' linked list head and tail *************************************************************\n";
    
    internationalStudentList.delete_head_tail();
    internationalStudentList.print();
     
  // ***********************************************************  PART 6 ********************************************************
   
    cout << "\n************************************************************* Merging domestic and international student linked lists into student linked list *************************************************************\n";
    //Toefl toefl_1(NULL,NULL,NULL,NULL);
    
    DomesticStudent dstu1;
    InternationalStudent istu1;
    //dstu1.head = NULL;
    //istu1.head = NULL;
    mergeList(domesticStudentList, internationalStudentList, studentList); // Regular case
    // Boundary case ?
    //studentList = mergeList(dstu1, istu1);// Error case ? (merging two empty lists)
    studentList.print();

  //***********************************************************  PART 7 ********************************************************

    cout << "\n************************************************************* Searching student objects in the merged linked list based on CGPA threshold and Research Score threshold *************************************************************\n";

    studentList.searchThreshold(4.0, 83);     // Regular case
    studentList.searchThreshold(0.0, 0);     // Boundary case (minimum; prints entire list)
    studentList.searchThreshold(4.3, 100);  // Boundary case (maximum; prints nothing)
    studentList.searchThreshold(4.7, 200); // Error case

    studentList.print();
}