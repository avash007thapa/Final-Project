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

using namespace std;


// void insertDomestic(DomesticStudent student, LinkedList<Student>& linkedList){
//     try{
// 		    auto prev = linkedList.head;
//         auto here = linkedList.head; 
//         //cout<<typeid(student).name()<<endl;
//         auto newNode = new typename LinkedList<DomesticStudent>::Node(student);
     
//         //if list is empty
//         if(linkedList.head == nullptr){
//             linkedList.head = newNode;
//             linkedList.tail = LinkedList.head;
//             return;
//         }
//         while (here != nullptr){
//             if(compareOverall(here->student,newNode->student) == 1){
//                 if(prev == linkedList.head){
//                     newNode->link = here;
//                     linkedList.head = newNode;
//                 }
//                 else{
//                     prev->link = newNode;
//                     newNode->link = here;
//                 }
//                 break;
//             }
//             //if end of list insert at tail
//             else if(here->link == nullptr){
//                 here->link = newNode;
//                 linkedList.tail = newNode;
//                 break;
//             }
            
//             //itterating through linked list
//             prev = here;
//             here = here->link;
// 		    } 
//     }
//     catch(bad_alloc){
//         std::cerr<<"Error(insertNode): bad_alloc\n";
//         std::exit(1);
//     }
// }


void outputMenu(){
  cout<<"\n*************M E N U *************\n";
  cout << "Input one of the following";
  cout << "\n****************************************************************\n";
  cout << " (0) - Exit the program\n";
  cout << " (1) - Insert a student into the list\n";
  cout << " (2) - Delete a student from the list\n";
  cout << " (3) - Merge the domestic student list and international student list\n";
  cout << "\n****************************************************************\n";    
} 

//Merge (merges a domestic list and an international list into a student list)
void mergeList(LinkedList<DomesticStudent>& domesticList, LinkedList<InternationalStudent>& internationalList, LinkedList<Student>& studentList){
    //LinkedList<Student> returnList;
    
    auto dHere = domesticList.head;
    while(dHere != nullptr){
        //cout<<typeid(dHere->student).name()<<endl;
        studentList.insertNode(dHere->student);
        dHere = dHere->link;
    }

    auto iHere = internationalList.head;
    
    while(iHere != nullptr){
        if(!iHere->student->getToeflScore().passed()){
            iHere = iHere->link;
        }
        studentList.insertNode(iHere->student);
        iHere = iHere->link;
    }
    //return returnList;
}

int main(){
  
  //Getting data from the .txt files

  //Reading the domestic-stu.txt file and exit if failed
  LinkedList<Student> studentList;
  LinkedList<DomesticStudent> domesticStudentList;
  LinkedList<InternationalStudent> internationalStudentList;
  string firstName, lastName, province, s_CGPA, s_researchScore, line;
  string provinceARR[13]= {"BC","NL","PE","NS","NB","QC","ON","MB","SK","AB","YT","NT","NU"};
  string countryARR[5] = {"Canada","China","India","Iran","Korea"};
  float CGPA;
  int researchScore,index = 0;
  

  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  if (domesticFile.is_open()){
    
    cout<<endl<<"The "<<"domestic-stu.txt"<<" file was opened successfully!\n";
    cout<<"\nFile processing has now begun...\n\n";
  
  }
  
  

  while(getline(domesticFile, line) ) {

    istringstream ss(line);
    
    //getting inputs
    getline(ss, firstName, ',');
    firstName[0] = toupper(firstName[0]);
    for(int i=1; i<firstName.length();i++){
      firstName[i] = tolower(firstName[i]);
    } 
    getline(ss, lastName, ',');
    lastName[0] = toupper(lastName[0]);
    for(int i=1; i<lastName.length();i++){
      lastName[i] = tolower(lastName[i]);
    }   
    getline(ss, province, ',');   
    getline(ss, s_CGPA, ',');
    CGPA = atof(s_CGPA.c_str());
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    //testing for missing inputs from file
    if(firstName.empty() ||  lastName.empty() || province.empty() || s_CGPA.empty() || s_researchScore.empty() ){
      cout<<"MISSING INPUTS FOR DOMESTIC STUDENT.\n";
      exit(-1);
    }

    //testing for correct province  
    int found = 0;
    for (int i = 0; i < 13; i++){
       if(province == provinceARR[i]){    
            found++;
        } 
    }
    if(found < 1){
        cout<<"ERROR: PROVINCE MUST BE EITHER BC,NL,PE,NS,NB,QC,ON,MB,SK,AB,YT,NT,NU"<<endl;
        cout<<"***EXITING PROGRAM***"<<endl; 
        exit(-1);
    }      

    //inserting student to domesticStudentList
    DomesticStudentPtr domesticStudent = new DomesticStudent(firstName,lastName,CGPA,researchScore,(20200000 + index),province);
    domesticStudentList.insertNode(domesticStudent);
    
    index++; 
  }
  //closing the file
  domesticFile.close();
 // cout<<domesticStudentList<<endl;




  
  //Reading the international-stu.txt file and exit if failed
  string country,s_reading,s_listening,s_speaking,s_writing;
  int reading, listening, speaking, writing;
  index = 0;

  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  getline(internationalFile, line);
  cout << "File format: " << line << endl;

  while( getline(internationalFile, line) ) {

    istringstream ss(line);

    //get firstName separated by comma
    //PART 2 Number 2
    //Iniatilizing the first Character of the string to Upper-case and the rest 
    //of the string to lower-case
    getline(ss, firstName, ',');
    firstName[0] = toupper(firstName[0]);
    for(int i=1; i<firstName.length();i++){
      firstName[i] = tolower(firstName[i]);
    }   
    //get lastName separated by comma
    getline(ss, lastName, ',');
    lastName[0] = toupper(lastName[0]);
    for(int i=1; i<lastName.length();i++){
      lastName[i] = tolower(lastName[i]);
    }   
    //get country separated by comma
    getline(ss, country, ',');
    country[0] = toupper(country[0]);
    for(int i=1; i<country.length();i++){
      country[i] = tolower(country[i]);
    }  
    //get cpga separated by comma, and convert string to float
    getline(ss, s_CGPA, ',');
    CGPA = atof(s_CGPA.c_str());
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    //get reading separated by comma, and convert it to int
    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    //get listening separated by comma, and convert it to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());
    //get speaking separated by comma, and convert it to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());
    //get writing separated by comma, and convert it to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());
    //setting toefl scores
    Toefl toeflScore(reading,listening,speaking,writing);

    //****TESTING FOR MISSING INPUT******
    if(firstName.empty() ||  lastName.empty() || country.empty() || s_CGPA.empty() || s_researchScore.empty() ){
      cout<<"MISSING INPUTS FOR INTERNATIONAL STUDENT.\n";
      exit(-1);
    }

    //NUMBER 3 B
    //****TESTING FOR INVALID INPUTS FOR INTERNATIONAL STUDENT FILE
    //UPDATE
    
    for(int i =0; i < line.length(); i++){
        if(country =="Idian"){
          cout<<"Idian is a typo, but this program can fix that to Indian"<<endl;
          country = "India";
        }           
    }
    //UPDATE
    int found = 0;
    for (int i = 0; i < 13; i++){
       if(country == countryARR[i]){    
            found++;
        } 
    }
    if(found < 1){
        cout<<"ERROR: COUNTRY MUST BE EITHER Canada,India,Iran,Korea"<<endl;
        cout<<"***EXITING PROGRAM***"<<endl; 
        exit(-1);
    }       

    //creating international student
    InternationalStudentPtr internationalStudent = new InternationalStudent(firstName,lastName,CGPA,researchScore,(20200100 + index),country,toeflScore);
    internationalStudentList.insertNode(internationalStudent);
    index++;
  }
  
  //closing file
  internationalFile.close();
  cout<<"Printing international student list\n";
  //cout<<internationalStudentList<<endl;


  
  // M E N U 
  
  cout<<"TESTING\n\n\n"<<endl;







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


    cout << "\n************************************************************* Deleting international students by first name, last name basis  *************************************************************\n";
    
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

    
  // ***********************************************************  PART 6 ********************************************************

  // ***********************************************************  PART 7 ********************************************************





























  mergeList(domesticStudentList,internationalStudentList,studentList);
  //cout<<studentList<<endl;
  //studentList.print();

  //DomesticStudentPtr a = dynamic_cast<DomesticStudentPtr>(student);

  // studentList.insertNode(*student);
  // cout<<studentList<<endl;
  //studentList.head->student.getProvince();
  //cout<<studentList<<endl;
  //studentList = mergeList(domesticStudentList,internationalStudentList);
  

  // int menuChoice;
  
  // while(true){
  //     outputMenu();
  //     cout<<"INPUT: ";
  //     cin >> menuChoice;
  //     cout << "\n\n";      
	  
  //   //PART 2
  //   //NUMBER 4
  //   if(menuChoice > 3 || menuChoice < 0){
  //     cout << "Invalid selection.  Please enter 0, 1, 2 or 3" <<endl; //invalid selection change
  //     outputMenu();
  //     cout << "INPUT: ";
  //     cin >> menuChoice;
  //   }
    
  //   switch (menuChoice){
  //     case 0 :
  //       cout << "EXITING PROGRAM" << endl; 
  //       exit(-1);
  //     case 1 :
  //       cout << "INSERT SELECTED" << endl;
  //       break;
  //     case 2 :
  //       cout << "DELETE SELECTED" << endl;
  //       break;
  //     case 3 :
  //       cout << "MERGE SELECTED" << endl;
  //       break;
  //     default:
  //       break; 
  //     }        
  // }
}