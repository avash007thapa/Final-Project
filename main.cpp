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
LinkedList<Student> mergeList(LinkedList<DomesticStudent>& domesticList, LinkedList<InternationalStudent>& internationalList){
    LinkedList<Student> returnList;
    LinkedList<DomesticStudent> CopyOfDomesticList;
    CopyOfDomesticList.head = (domesticList.deepCopyLinkedList(domesticList.head));

    typename LinkedList<InternationalStudent>::NodePtr here = internationalList.head;
    while(here != nullptr){
        if(!here->student.getToeflScore().passed()){
            here = here->link;
        }
        returnList.insertNode(here->student);
    }
    return returnList;
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
        cout<<"ERROR: PROVINCE MUST BE EITHER BC,NL,PE,NS,NB,QC,ON,MB.SK,AB,YT,NT,NU"<<endl;
        cout<<"***EXITING PROGRAM***"<<endl; 
        exit(-1);
    }      

    //inserting student to domesticStudentList
    DomesticStudent domesticStudent(firstName,lastName,CGPA,researchScore,(20200000 + index),province);
    domesticStudentList.insertNode(domesticStudent);
    
    index++; 
  }
  //closing the file
  domesticFile.close();
  cout<<domesticStudentList<<endl;




  
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
    InternationalStudent internationalStudent(firstName,lastName,CGPA,researchScore,(20200100 + index),country,toeflScore);
    internationalStudentList.insertNode(internationalStudent);
    index++;
  }
  
  //closing file
  internationalFile.close();
  cout<<"Printign international student list\n";
  cout<<internationalStudentList<<endl;


  
  // M E N U 
  
  cout<<"TESTING\n\n\n"<<endl;
  studentList = mergeList(domesticStudentList,internationalStudentList);
  

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