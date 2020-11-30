#include "unitTest.hpp"
#include "helper.hpp"
#include <iostream>

using namespace std;

void UnitTest(int studentNum){

    // *******************************************************  PART 1 ********************************************************
    // *****************************************************  insertNode() ****************************************************

    LinkedList<DomesticStudent> domStuList1;
    LinkedList<InternationalStudent> intStuList1;
    LinkedList<Student> stuList1;

    //getting inputs from domestic-stu.txt and putting it into domStuList1
    domFile2DomList(domStuList1,studentNum);

    //getting inputs from international-stu.txt and putting it into intStuList1
    intFile2IntList(intStuList1,studentNum);


    // Normal case ~ expected
    DomesticStudentPtr domStu1 = new DomesticStudent ("nAtAsHa","Brown",(float)3.8,91,studentNum,"AB");
    domStuList1.insertNode(domStu1);                                  

    // Boundary case ~ float rounds down to 4.3
    DomesticStudentPtr domStu2 = new DomesticStudent ("JADEN","HILL",(float)4.33,10,studentNum+1,"YT");
    domStuList1.insertNode(domStu2);                                  


    // Error case ~ research score can't be negative
    DomesticStudentPtr domStu3 = new DomesticStudent ("Gurleen","Sidhu",(float)2.20,-93,studentNum+2,"AB");
    domStuList1.insertNode(domStu3);                                  
    
    // Error Case ~ Cannot insert student with same application ID
    domStuList1.insertNode(domStu1);                                  
    
    // Prints out evidence
    domStuList1.print();                                         



    // Normal case ~ expected
    Toefl toefl1(24,26,28,23);
    InternationalStudentPtr intStu1 = new InternationalStudent ("Bingyu","Lu",(float)3.80,91,20201100,"China",toefl1);
    intStuList1.insertNode(intStu1);                                  


    // Boundary case ~ the score is on the edge
    Toefl toefl2(20,20,20,33);
    InternationalStudentPtr intStu2 = new InternationalStudent ("BOBBY","Lobby",(float)3.40,83,20201101,"India",toefl2);
    intStuList1.insertNode(intStu2);                             


    // Error case ~ toefl score doesn't meet the requirements (won't merge)
    Toefl toefl3(11,13,28,23);
    InternationalStudentPtr intStu3 = new InternationalStudent ("Tom","Lad",(float)0.0,83,20201103,"Korea",toefl3);
    intStuList1.insertNode(intStu3);                             

    // prints out evidence
    intStuList1.print();  

  // ***********************************************************  PART 2 ********************************************************
  // ******************************************  searchCGPA/ResearchScore/ApplicationID() ****************************************************


    cout << "\n************************************************************* These are the domestic students with (3.4) CGPA *************************************************************\n";
    domStuList1.searchCGPA(3.4);     // Regular case
    cout << "\n************************************************************* These are the domestic students with (4.34) CGPA *************************************************************\n";
    domStuList1.searchCGPA(4.34);    // Boundary case
    cout << "\n************************************************************* These are the domestic students with (4.50) CGPA *************************************************************\n";
    domStuList1.searchCGPA(4.50);    // Error case

    cout << "\n************************************************************* These are the international students with (3.40) CGPA *************************************************************\n";
    intStuList1.searchCGPA(3.40);     // Regular case
    cout << "\n************************************************************* These are the international students with (4.300000000000234020400242040023400230420340) CGPA *******************\n";
    intStuList1.searchCGPA(4.300000000000234020400242040023400230420340);    // Boundary case
    cout << "\n************************************************************* These are the international students with (int)(5) CGPA *************************************************************\n";
    intStuList1.searchCGPA((int)5);   // Error case 


    cout << "\n************************************************************* These are the domestic students with research score of (87) **********************************************\n";
    domStuList1.searchResearchScore(87);     // Regular case
    cout << "\n************************************************************* These are the domestic students with research score of (100.5) *************************************************************\n";
    domStuList1.searchResearchScore(100.4);      // Boundary case
    cout << "\n************************************************************* These are the domestic students with research score of (float)(103.0) *********************************************************\n";
    domStuList1.searchResearchScore((float)103.0);   // Error case

    cout << "\n************************************************************* These are the international students with research score of (87) *************************************************************\n";
    intStuList1.searchResearchScore(87);     // Regular case
    cout << "\n************************************************************* These are the international students with research score of (100) *************************************************************\n";
    intStuList1.searchResearchScore(100);    // Boundary case
    cout << "\n************************************************************* These are the international students with research score of (103) *************************************************************\n";
    intStuList1.searchResearchScore(103);    // Error case 


    cout << "\n************************************************************* Searching domestic students' application ID (20200064) *************************************************************\n";
    domStuList1.searchApplicationID(20200064);     // Regular case
    cout << "\n************************************************************* Searching domestic students' application ID (20200000) *************************************************************\n";
    domStuList1.searchApplicationID(20200000);     // Boundary case
    cout << "\n************************************************************* Searching domestic students' application ID (30000000) *************************************************************\n";
    domStuList1.searchApplicationID(30000000);     // Error case

    cout << "\n************************************************************* Searching international students' application ID (20200164) ******************************************************\n";
    intStuList1.searchApplicationID(20200294);     // Regular case
    cout << "\n************************************************************* Searching international students' application ID (20200200) *****************************************************\n";
    intStuList1.searchApplicationID(20200200);     // Boundary case
    cout << "\n************************************************************* Searching international students' application ID (30200064) ****************************************************\n";
    intStuList1.searchApplicationID(30200064);     // Error case 





  // ***********************************************************  PART 3 ********************************************************
    // *********************************************************  searchName() ****************************************************


    cout << "\n******************************************* Searching domestic students' by name *************************************************************\n";
    domStuList1.searchName("Mateo", "Powell");     // Regular case (in list)
    domStuList1.searchName("mateo", "powell");     // Boundary case (input does not match name in list, but program will format it)
    domStuList1.searchName("Mat", "Powell");       // Error case (not in list)

    cout << "\n************************************************ Searching internatinal students' by name *************************************************************\n";
    intStuList1.searchName("Tingting", "Zhao");     // Regular case (in list)
    intStuList1.searchName("tingting", "zhao");     // Boundary case (input does not match name in list, but program will format it)
    intStuList1.searchName("Tingting", "Ahao");     // Error case (not in list)



  // ***********************************************************  PART 4 ********************************************************
    // ******************************************************* deleteNode() ****************************************************


    cout << "\n********************************************** Deleting domestic students by first name, last name basis  ****************************************\n";
    domStuList1.deleteNode("Mateo", "Powell");     // Regular case (in list)  
    domStuList1.deleteNode("Dylan", "Barnes");     // Boundary case (deleting head node)
    domStuList1.deleteNode("Hazel", "Butle");      // Error case (not in list)

    cout << "\n*********************************************** Deleting international students by first name, last name basis  ********************************************\n";
    
    Toefl toefl5(20,20,20,20);
    InternationalStudentPtr intStu5 = new InternationalStudent ("Tingting","Zhao",(float)3.40,83,20201107,"Korea",toefl5);
    intStuList1.insertNode(intStu5);

    intStuList1.deleteNode("Setayesh", "Shams");     // Regular case (in list)
    intStuList1.deleteNode("Tingting", "Zhao");      // Boundary case (there are more than 1 students with this name)
    intStuList1.deleteNode("Tingting", "Ahao");      // Error case (not in list)

  // ***********************************************************  PART 5 ********************************************************

    cout << "\n********************************************* Deleting domestic students' linked list head and tail *********************************************\n";
    
    Toefl toefl4(20,20,30,30);

    studentNum++;
    InternationalStudentPtr d = new InternationalStudent ("first1","last",(float)3.0,100,studentNum,"Canada",toefl4);
    InternationalStudentPtr e = new InternationalStudent("first2","last",(float)3.0,100,studentNum+1,"Canada",toefl4);
    InternationalStudentPtr f = new InternationalStudent("first3","last",(float)3.0,100,studentNum+2,"Canada",toefl4);
    intStuList1.insertNode(d);
    intStuList1.insertNode(e);
    intStuList1.insertNode(f);


    domStuList1.delete_head_tail(); //regular case (3 items in list)
    domStuList1.delete_head_tail(); // boundary case (1 item in list)
    domStuList1.delete_head_tail(); // error case (no elements in list)

    cout << "\n**************************************** Deleting international students' linked list head and tail *******************************************\n";
    
    intStuList1.delete_head_tail(); //regular case (3 items in list)
    intStuList1.delete_head_tail(); // boundary case (1 item in list)
    intStuList1.delete_head_tail(); // error case (no elements in list)
     
  // ***********************************************************  PART 6 ********************************************************
   
    cout << "\n**************************** Merging domestic and international student linked lists into student linked list **********************************************\n";
    LinkedList<DomesticStudent> domStuList2;
    LinkedList<InternationalStudent> intStuList2;
    LinkedList<Student> stuList2;

    mergeList(domStuList1, intStuList1, stuList1); // Regular case
    mergeList(domStuList2,intStuList2,stuList2); // Boundary case (no items in list)
    

    cout<<"studentList\n";
    stuList1.print();
    cout<<"stuList2\n";
    stuList2.print();

  //***********************************************************  PART 7 ********************************************************

    cout << "\n******************************************* Searching student objects in the merged linked list based on CGPA threshold and Research Score threshold *************************************************************\n";

    stuList1.searchThreshold(4.0, 83);     // Regular case
    stuList1.searchThreshold(0.0, 0);      // Boundary case (minimum; prints entire list)
    stuList1.searchThreshold(4.3, 100);    // Boundary case (maximum; prints nothing)
    stuList1.searchThreshold(4.7, 200);    // Error case
}