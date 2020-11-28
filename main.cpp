using namespace std;
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "studentList.hpp"
#include "domStuList.hpp"
//#include "internationalStudent.hpp"




using namespace std;

void outputMenu(){
  cout<<"\n*************M E N U *************\n";
  cout << "Input one of the following";
  cout << "\n****************************************************************\n";
  cout << " (0) - EXIT\n";
  cout << " (1) - INSERT\n";
  cout << " (2) - DELETE\n";
  cout << " (3) - MERGE\n";
  cout << "\n****************************************************************\n";    
} 


int main(){
  
  //Getting data from the .txt files

  //Reading the domestic-stu.txt file and exit if failed
  DomesticStudent domesticArr[100];
  string firstName, lastName, province, s_CGPA, s_researchScore, line;
  string provinceARR[13]= {"BC","NL","PE","NS","NB","QC","ON","MB","SK","AB","YT","NT","NU" };
  string countryARR[5] = {"Canada","China","India","Iran","Korea"};
  float CGPA;
  int researchScore, index = 0;
  
  

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
  
  
  //inputing data into domesitcArr
  while(getline(domesticFile, line) ) {

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
    domesticArr[index].setFirstName(firstName);

    //get lastName separated by comma
    getline(ss, lastName, ',');
    lastName[0] = toupper(lastName[0]);
    for(int i=1; i<lastName.length();i++){
      lastName[i] = tolower(lastName[i]);
    }   
    domesticArr[index].setLastName(lastName);

    //get province separated by comma
    getline(ss, province, ',');   
    domesticArr[index].setProvince(province);
    
    
    //get cpga separated by comma, and convert string to float
    getline(ss, s_CGPA, ',');
    CGPA = atof(s_CGPA.c_str());
    domesticArr[index].setCGPA(CGPA);

    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    domesticArr[index].setResearchScore(researchScore);

    //setting application ID
    domesticArr[index].setApplicationID(20200000 + index);

    //print the student info to the screen
    cout << "Domestic student " << index + 1 << " ";
    cout << domesticArr[index].getFirstName() << " ";
	  cout << domesticArr[index].getLastName() << " from ";
    cout << domesticArr[index].getProvince() << " province has CGPA of ";
    cout << domesticArr[index].getCGPA() << ", and research score of ";
    cout << domesticArr[index].getResearchScore() << endl;
    index++;

    //PART 2

    //NUMBER 1
    // ****TESTING FOR MISSING INPUT******
    if(firstName.empty() ||  lastName.empty() || province.empty() || s_CGPA.empty() || s_researchScore.empty() ){
      cout<<"MISSING INPUTS FOR DOMESTIC STUDENT.\n";
      exit(-1);
    }
      
    //NUMBER 3 part B
    //TESTING FOR PROVINCE INPUT FROM FILE
    //Province must be of the following:BC,NL,PE,NS,NB,QC,ON,MB.SK,AB,YT,NT,NU
    //MAKE AN ARRAY OF STRING AND USE A FOR LOOP TO CHECK     
    int found =0;
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
  }
  //closing the file
  domesticFile.close();




  
  //Reading the international-stu.txt file and exit if failed
  InternationalStudent internationalArr[100];
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
    internationalArr[index].setFirstName(firstName);

    //get lastName separated by comma
    getline(ss, lastName, ',');
    lastName[0] = toupper(lastName[0]);
    for(int i=1; i<lastName.length();i++){
      lastName[i] = tolower(lastName[i]);
    }   
    internationalArr[index].setLastName(lastName);

    //get country separated by comma
    getline(ss, country, ',');
    country[0] = toupper(country[0]);
    for(int i=1; i<country.length();i++){
      country[i] = tolower(country[i]);
    }  
    internationalArr[index].setCountry(country);

    //get cpga separated by comma, and convert string to float
    getline(ss, s_CGPA, ',');
    CGPA = atof(s_CGPA.c_str());
    internationalArr[index].setCGPA(CGPA);

    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    internationalArr[index].setResearchScore(researchScore);

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
    internationalArr[index].setToeflScore(toeflScore);

    //setting application ID
    internationalArr[index].setApplicationID(20200100 + index);

    //print the student info to the screen
    cout << "International student " << index + 1 << " ";
    cout << internationalArr[index].getFirstName() << " ";
	  cout << internationalArr[index].getLastName() << " from ";
    cout << internationalArr[index].getCountry() << " has CGPA of ";
    cout << internationalArr[index].getCGPA() << ", research score of ";
    cout << internationalArr[index].getResearchScore() << ", and a total toefl score of ";
    cout << internationalArr[index].getToeflScore().getTotalScore() << endl;
    index++;

    //PART 2

    //NUMBER 1
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
          cout<<"International student "<<index<<" "<< firstName<<" "<<lastName<<" from "<<country<<" has a "<<CGPA;
          cout<<", has a research score of "<<researchScore<<" ,and a total toefl score of "<</*internationalArr[i].getToeflScore().getTotalScore()*/toeflScore<<endl;
        }           
    }
    //UPDATE
    int found =0;
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
  }
  
  //closing file
  internationalFile.close();



  
  // M E N U 
  
  int menuChoice;
  
  while(true){
      outputMenu();
      cout<<"INPUT: ";
      cin >> menuChoice;
      cout << "\n\n";      
	  
    //PART 2
    //NUMBER 4
    if(menuChoice > 3 || menuChoice < 0){
      cout << "Invalid selection.  Please enter 0, 1, 2 or 3" <<endl; //invalid selection change
      outputMenu();
      cout << "INPUT: ";
      cin >> menuChoice;
    }
    
    switch (menuChoice){
      case 0 :
        cout << "EXITING PROGRAM" << endl; 
        exit(-1);
      case 1 :
        cout << "INSERT SELECTED" << endl;
        break;
      case 2 :
        cout << "DELETE SELECTED" << endl;
        break;
      case 3 :
        cout << "MERGE SELECTED" << endl;
        break;
      default:
        break; 
      }        
  }
 
  /*
  int studentType;
  int userInput; 
  cout << "G R A D U A T E   A D M I S S I O N   S Y S T E M" << endl;
  while(true){
    //asking user for which array to sort
    while(true){
      cout << " Input one of the following";
      cout << "\n****************************************************************\n";
      cout << " (0) - Exit the program\n";
      cout << " (1) - Domestic students\n";
      cout << " (2) - International students\n";
      cout << "****************************************************************\n";
      cout << "Input: ";
      cin >> studentType;
      cout << "\n\n";

      //exits while loop
      if(studentType == 0){
        cout<<"(0) Exiting program\n";
        break;
      }
      //asking user for which sorting method to use
      cout << " Input one of the following for";
      if(studentType == 1){
        cout<<" Domestic students";
        break;
      }
      else if(studentType == 2){
        cout<<" International students";
        break;
      }
      //if input is not 1 or 2 it's an invalid input
      else{
        cout<<"Invalid input\n";
      }
    }

    //exits program
    if(studentType == 0)
    {
      break;
    }
    
    
    //MENU
		cout << "\n****************************************************************\n";
    cout << " (0) - Exit the program\n";
    cout << " (1) - Sort by CGPA\n";
    cout << " (2) - Sort by research score\n";
    cout << " (3) - Sort by first name\n";
    cout << " (4) - sort by last name\n";
    cout << " (5) - sort by overall performance\n";
    cout << "****************************************************************\n";
    cout << "Input: ";
    cin >> userInput;
    cout << "\n\n";

    if(userInput == 0){
      cout<<"(0) Exiting program\n";
      break;
    }

    //sorting by CGPA 
    else if(userInput == 1){
      cout << "\n\n(1) Sort by CGPA\n";
			cout << "****************************************************************\n";
      
      if(studentType == 1){
        sortCGPA(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortCGPA(internationalArr, 0, 99);
        print(internationalArr);
      }
    }
    
    //sorting by research score
    else if (userInput == 2){
      cout << "\n\n(2) Sort by research score\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortResearchScore(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortResearchScore(internationalArr, 0, 99);
        print(internationalArr);
      }
    }

    //sorting by first name
    else if (userInput == 3){
      cout << "\n\n(3) Sort by first name\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortFirstName(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortFirstName(internationalArr, 0, 99);
        print(internationalArr);
      }
    }

    //sorting by last name
    else if (userInput == 4){
      cout << "\n\n(4) Sort by last name\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortLastName(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortLastName(internationalArr, 0, 99);
        print(internationalArr);
      }
    }

    //sorting by overall
    else if (userInput == 5){
      cout << "\n\n(5) Sort by overall\n";
			cout << "****************************************************************\n";
      if(studentType == 1){
        sortOverall(domesticArr, 0, 99);
        print(domesticArr);
      }
      else if(studentType == 2){
        sortOverall(internationalArr, 0, 99);
        printValidStudents(internationalArr);
      }
    }
  }*/
}

