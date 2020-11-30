#include "unitTest.hpp"
#include "helper.hpp"
#include <iostream>

using namespace std;

void UnitTest(LinkedList<DomesticStudent> domesticStudentList, LinkedList<InternationalStudent> internationalStudentList, LinkedList<Student> studentList, int studentNum){

    // *******************************************************  PART 1 ********************************************************
    // *****************************************************  insertNode() ****************************************************

    // Normal case ~ expected
    DomesticStudent domStu1("nAtAsHa","Brown",(float)3.8,91,studentNum,"AB");
    studentNum++;
    domesticStudentList.insertNode(&domStu1);                                  

    // Boundary case ~ float rounds down to 4.3
    DomesticStudent domStu2("JADEN","HILL",(float)4.33,10,studentNum,"YT");
    studentNum++;
    domesticStudentList.insertNode(&domStu2);                                  


    // Error case ~ research score can't be negative
    DomesticStudent domStu3("Gurleen","Sidhu",(float)2.20,-93,studentNum,"AB");
    studentNum++;
    domesticStudentList.insertNode(&domStu3);                                  
    
    // Error Case ~ Cannot insert student with same application ID
    domesticStudentList.insertNode(&domStu1);                                  
    
    // Prints out evidence
    domesticStudentList.print();                                         



    // Normal case ~ expected
    Toefl toefl1(24,26,28,23);
    InternationalStudent intStu1("Bingyu","Lu",(float)3.80,91,20201100,"China",toefl1);
    internationalStudentList.insertNode(&intStu1);                                  


    // Boundary case ~ the score is on the edge
    Toefl toefl2(20,20,20,33);
    InternationalStudent intStu2("BOBBY","Lobby",(float)3.40,83,20201101,"India",toefl2);
    internationalStudentList.insertNode(&intStu2);                             


    // Error case ~ toefl score doesn't meet the requirements (won't merge)
    Toefl toefl3(11,13,28,23);
    InternationalStudent intStu3("Tom","Lad",(float)0.0,83,20201103,"Korea",toefl3);
    internationalStudentList.insertNode(&intStu3);                             

    // prints out evidence
    internationalStudentList.print();  

  // ***********************************************************  PART 2 ********************************************************
  // ******************************************  searchCGPA/ResearchScore/ApplicationID() ****************************************************


    cout << "\n************************************************************* These are the domestic students with (3.4) CGPA *************************************************************\n";
    domesticStudentList.searchCGPA(3.4);     // Regular case
    cout << "\n************************************************************* These are the domestic students with (4.34) CGPA *************************************************************\n";
    domesticStudentList.searchCGPA(4.34);    // Boundary case
    cout << "\n************************************************************* These are the domestic students with (4.50) CGPA *************************************************************\n";
    domesticStudentList.searchCGPA(4.50);    // Error case

    cout << "\n************************************************************* These are the international students with (3.40) CGPA *************************************************************\n";
    internationalStudentList.searchCGPA(3.40);     // Regular case
    cout << "\n************************************************************* These are the international students with (4.300000000000234020400242040023400230420340) CGPA *******************\n";
    internationalStudentList.searchCGPA(4.300000000000234020400242040023400230420340);    // Boundary case
    cout << "\n************************************************************* These are the international students with (int)(5) CGPA *************************************************************\n";
    internationalStudentList.searchCGPA((int)5);   // Error case 


    cout << "\n************************************************************* These are the domestic students with research score of (87) **********************************************\n";
    domesticStudentList.searchResearchScore(87);     // Regular case
    cout << "\n************************************************************* These are the domestic students with research score of (100.5) *************************************************************\n";
    domesticStudentList.searchResearchScore(100.4);      // Boundary case
    cout << "\n************************************************************* These are the domestic students with research score of (float)(103.0) *********************************************************\n";
    domesticStudentList.searchResearchScore((float)103.0);   // Error case

    cout << "\n************************************************************* These are the international students with research score of (87) *************************************************************\n";
    internationalStudentList.searchResearchScore(87);     // Regular case
    cout << "\n************************************************************* These are the international students with research score of (100) *************************************************************\n";
    internationalStudentList.searchResearchScore(100);    // Boundary case
    cout << "\n************************************************************* These are the international students with research score of (103) *************************************************************\n";
    internationalStudentList.searchResearchScore(103);    // Error case 


    cout << "\n************************************************************* Searching domestic students' application ID (20200064) *************************************************************\n";
    domesticStudentList.searchApplicationID(20200064);     // Regular case
    cout << "\n************************************************************* Searching domestic students' application ID (20200000) *************************************************************\n";
    domesticStudentList.searchApplicationID(20200200);     // Boundary case
    cout << "\n************************************************************* Searching domestic students' application ID (30000000) *************************************************************\n";
    domesticStudentList.searchApplicationID(30000000);     // Error case

    cout << "\n************************************************************* Searching international students' application ID (20200164) *************************************************************\n";
    internationalStudentList.searchApplicationID(20200164);     // Regular case
    cout << "\n************************************************************* Searching international students' application ID (20200199) *************************************************************\n";
    internationalStudentList.searchApplicationID(20200199);     // Boundary case
    cout << "\n************************************************************* Searching international students' application ID (30200064) *************************************************************\n";
    internationalStudentList.searchApplicationID(30200064);     // Error case 





  // ***********************************************************  PART 3 ********************************************************
    // *********************************************************  searchName() ****************************************************


    cout << "\n******************************************* Searching domestic students' by name *************************************************************\n";
    domesticStudentList.searchName("Mateo", "Powell");     // Regular case (in list)
    domesticStudentList.searchName("mateo", "powell");     // Boundary case (input does not match name in list, but program will format it)
    domesticStudentList.searchName("Mat", "Powell");       // Error case (not in list)

    cout << "\n************************************************ Searching internatinal students' by name *************************************************************\n";
    internationalStudentList.searchName("Tingting", "Zhao");     // Regular case (in list)
    internationalStudentList.searchName("tingting", "zhao");     // Boundary case (input does not match name in list, but program will format it)
    internationalStudentList.searchName("Tingting", "Ahao");     // Error case (not in list)



  // ***********************************************************  PART 4 ********************************************************
    // ******************************************************* deleteNode() ****************************************************


    cout << "\n********************************************** Deleting domestic students by first name, last name basis  *************************************************************\n";
    domesticStudentList.deleteNode("Mateo", "Powell");     // Regular case (in list)  
    domesticStudentList.deleteNode("Dylan", "Barnes");     // Boundary case (deleting head node)
    domesticStudentList.deleteNode("Hazel", "Butle");      // Error case (not in list)

    cout << "\n*********************************************** Deleting international students by first name, last name basis  *************************************************************\n";
    
    Toefl toefl5(20,20,20,20);
    InternationalStudent intStu5("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl5);
    internationalStudentList.insertNode(&intStu5);

    Toefl toefl6(20,20,20,20);
    InternationalStudent intStu6("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl6);
    internationalStudentList.insertNode(&intStu6);

    internationalStudentList.deleteNode("Setayesh", "Shams");     // Regular case (in list)
    internationalStudentList.deleteNode("Tingting", "Zhao");      // Boundary case (there are more than 1 students with this name)
    internationalStudentList.deleteNode("Tingting", "Ahao");      // Error case (not in list)

  // ***********************************************************  PART 5 ********************************************************

    cout << "\n********************************************* Deleting domestic students' linked list head and tail *************************************************************\n";
    LinkedList<DomesticStudent> domStuList1;
    LinkedList<InternationalStudent> intStuList1;
    LinkedList<Student> stuList1;
    Toefl toefl2(20,20,30,30);
    DomesticStudent a("first","last",(float)3.0,100,studentNum,"BC");
    DomesticStudent b("first","last",(float)3.0,100,studentNum+1,"BC");
    DomesticStudent b("first","last",(float)3.0,100,studentNum+2,"BC");
    domStuList1.insertNode(a);
    domStuList1.insertNode(b);
    domStuList1.insertNode(c);

    InternationalStudent a("first","last",(float)3.0,100,studentNum,"Canada",toefl2);
    InternationalStudent b("first","last",(float)3.0,100,studentNum+1,"Canada",toefl2);
    InternationalStudent b("first","last",(float)3.0,100,studentNum+2,"Canada",toefl2);
    intStuList1.insertNode(a);
    intStuList1.insertNode(b);
    intStuList1.insertNode(c);


    domStuList1.delete_head_tail(); //regular case (3 items in list)
    domStuList1.delete_head_tail(); // boundary case (1 item in list)
    domStuList1.delete_head_tail(); // error case (no elements in list)

    cout << "\n**************************************** Deleting international students' linked list head and tail *************************************************************\n";
    
    intStuList1.delete_head_tail(); //regular case (3 items in list)
    intStuList1.delete_head_tail(); // boundary case (1 item in list)
    intStuList1.delete_head_tail(); // error case (no elements in list)
     
  // ***********************************************************  PART 6 ********************************************************
   
    cout << "\n************************************** Merging domestic and international student linked lists into student linked list *************************************************************\n";
    LinkedList<DomesticStudent> domStuList2;
    LinkedList<InternationalStudent> intStuList2;
    LinkedList<Student> stuList2;

    mergeList(domesticStudentList, internationalStudentList, studentList); // Regular case
    mergeList(domStuList2,intStuList2,stuList2); // Boundary case (no items in list)
    

    cout<<"studentList\n";
    studentList.print();
    cout<<"stuList2\n";
    stuList2.print();

  //***********************************************************  PART 7 ********************************************************

    cout << "\n******************************************* Searching student objects in the merged linked list based on CGPA threshold and Research Score threshold *************************************************************\n";

    studentList.searchThreshold(4.0, 83);     // Regular case
    studentList.searchThreshold(0.0, 0);      // Boundary case (minimum; prints entire list)
    studentList.searchThreshold(4.3, 100);    // Boundary case (maximum; prints nothing)
    studentList.searchThreshold(4.7, 200);    // Error case
}