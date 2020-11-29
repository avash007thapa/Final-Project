
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


//outputs the main menu
void outputMenu(){
    cout << "Input one of the following";
    cout << "\n****************************************************************\n";
    cout << " (1) - Exit the program\n";
    cout << " (2) - Create new student\n";
    cout << " (3) - Delete a student\n";
    cout << " (4) - Merge the domestic student list and international student list";
    cout << "\n****************************************************************\n";    
} 

void domFile2DomList(LinkedList<DomesticStudent>& domesticStudentList, int& studentNum){
    string firstName, lastName, province, s_CGPA, s_researchScore, line;
    float CGPA;
    int researchScore;
    
    //opens domestic-stu.txt file
    ifstream domesticFile("domestic-stu.txt");
    if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        exit(-1);
    }

    //prints file format
    getline(domesticFile, line);
    cout << "File format: " << line << endl;

    //checks if domestic file is open
    if (domesticFile.is_open()){   
        cout<<endl<<"The "<<"domestic-stu.txt"<<" file was opened successfully!\n";
        cout<<"\nFile processing has now begun...\n\n";
    }
    

    //gets inputs from text file and inputs into linked list
    while(getline(domesticFile, line) ) {
        istringstream ss(line);
        
        //getting inputs
        getline(ss, firstName, ',');
        formatString(firstName);

        getline(ss, lastName, ',');
        formatString(lastName);

        getline(ss, province, ','); 
        provinceIsValid(province);

        getline(ss, s_CGPA, ',');
        CGPA = atof(s_CGPA.c_str());

        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        //testing for missing inputs from file
        if(firstName.empty() ||  lastName.empty() || province.empty() || s_CGPA.empty() || s_researchScore.empty() ){
            cout<<"Error(domFile2DomList): Missing inputs from file\n";
            exit(-1);
        }

        //inserting domestic student to domesticStudentList
        DomesticStudentPtr domesticStudent = new DomesticStudent(firstName,lastName,CGPA,researchScore,(20200000 + studentNum),province);
        domesticStudentList.insertNode(domesticStudent);
        
        studentNum++; 
    }
    //closing the file
    domesticFile.close();
}

void intFile2IntList(LinkedList<InternationalStudent>& internationalStudentList, int& studentNum){
    string firstName, lastName, s_CGPA, s_researchScore, country, s_reading, s_listening, s_speaking, s_writing, line;
    float CGPA;
    int reading, listening, speaking, writing,researchScore;
    
    //opens international-stu.txt file
    ifstream internationalFile("international-stu.txt");
    if(!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        exit(-1);
    }

    //prints file format
    getline(internationalFile, line);
    cout << "File format: " << line << endl;

    //checks if internatinal file is open
    if (internationalFile.is_open()){   
        cout<<endl<<"The "<<"international-stu.txt"<<" file was opened successfully!\n";
        cout<<"\nFile processing has now begun...\n\n";
    }

    //gets inputs from text file and inputs into lined list
    while( getline(internationalFile, line) ) {
        istringstream ss(line);

        //getting inputs
        getline(ss, firstName, ',');
        formatString(firstName);

        getline(ss, lastName, ',');
        formatString(lastName);

        getline(ss, country, ',');
        formatString(country);
        countryIsValid(country);

        getline(ss, s_CGPA, ',');
        CGPA = atof(s_CGPA.c_str());

        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());

        getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());

        getline(ss, s_speaking, ',');
        speaking = atoi(s_speaking.c_str());

        getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());
        
        //testing for missing inputs from file
        if(firstName.empty() ||  lastName.empty() || country.empty() || s_CGPA.empty() || s_researchScore.empty() ){
            cout<<"Error(intFile2IntList): Missing inputs from file\n";
            exit(-1);
        }

        //inserting international student to internationalStudentList
        Toefl toeflScore(reading,listening,speaking,writing);
        InternationalStudentPtr internationalStudent = new InternationalStudent(firstName,lastName,CGPA,researchScore,(20200100 + studentNum),country,toeflScore);
        internationalStudentList.insertNode(internationalStudent);

        studentNum++;
  }
  //closing file
  internationalFile.close();
}

void formatString(string& input){
    input[0] = toupper(input[0]);
    for(int i = 1; i < input.length(); i++){
        input[i] = tolower(input[i]);
    } 
}

void provinceIsValid(string& province){
    string provinces[13]= {"BC","NL","PE","NS","NB","QC","ON","MB","SK","AB","YT","NT","NU"};
    
    //formatting province
    province[0] = toupper(province[0]); 
    province[1] = toupper(province[1]); 
    
    //checking if province exist
    for (int i = 0; i < 13; i++){
        if(province == provinces[i]){    
            return;
        } 
    }
    cout<<"Error(provinceIsValid): Province "<<province<<" is not valid"<<endl;
    cout<<"Exiting Program"<<endl; 
    exit(-1);
}

void countryIsValid(string& country){
    string countries[5] = {"Canada","China","India","Iran","Korea"};
    
    //fixing any country named "Idian" to India
    if(country == "Idian"){
        cout<<"Warning: \"Idian\" is a typo, \"Idian\" changed to \"India\""<<endl;
        country = "India";
    }           

    //checking if country exists
    for(int i = 0; i < 13; i++){
        if(country == countries[i]){    
            return;
        } 
    }
    cout<<"Error(countryIsValid): Country "<<country<<" is not valid"<<endl;
    cout<<"Exiting Program"<<endl; 
    exit(-1);  
}

bool inputIsValid(string input){
    int num = atoi(input.c_str());
    if(num == NULL || num < 1 || num > 4){
        cout<<"Error: \""<<input<<"\" is an invalid input\n\n";
        return false;
    }
    return true;
}

void insertDomesticStudent(LinkedList<DomesticStudent>& domesticStudentList,int& studentNum){
    string firstName, lastName, province, s_CGPA, s_researchScore, line;
    float CGPA;
    int researchScore;

    //getting inputs
    cout<<"First Name: ";
    cin>>firstName;
    formatString(firstName);

    cout<<"\nLast Name: ";
    cin>>lastName;
    formatString(lastName);

    cout<<"\nProvince: ";
    cin>>province;
    provinceIsValid(province);

    cout<<"\nCGPA: ";
    cin>>s_CGPA;
    CGPA = atof(s_CGPA.c_str());

    cout<<"\nResearch Score: ";
    cin>>s_researchScore;
    researchScore = atoi(s_researchScore.c_str());

    //inserting domestic student to domesticStudentList
    DomesticStudentPtr domesticStudent = new DomesticStudent(firstName,lastName,CGPA,researchScore,(20200000 + studentNum),province);
    domesticStudentList.insertNode(domesticStudent);

    cout<<"\n\nInserted:\n"<<*domesticStudent<<endl;
    studentNum++;
}

void insertInternationalStudent(LinkedList<InternationalStudent>& internationalStudentList, int& studentNum){
    string firstName, lastName, s_CGPA, s_researchScore, country, s_reading, s_listening, s_speaking, s_writing, line;
    float CGPA;
    int reading, listening, speaking, writing,researchScore;
    
    //getting inputs
    cout<<"First Name: ";
    cin>>firstName;
    formatString(firstName);

    cout<<"\nLast Name: ";
    cin>>lastName;
    formatString(lastName);

    cout<<"\nCountry: ";
    cin>>country;
    formatString(country);
    countryIsValid(country);

    cout<<"\nCGPA: ";
    cin>>CGPA;
    CGPA = atof(s_CGPA.c_str());

    cout<<"\nResearch Score: ";
    cin>>researchScore;
    researchScore = atoi(s_researchScore.c_str());

    cout<<"\nToefl Reading Score: ";
    cin>>s_reading;
    reading = atoi(s_reading.c_str());

    cout<<"\nToefl Listening Score: ";
    cin>>s_listening;
    listening = atoi(s_listening.c_str());

    cout<<"\nToefl Speaking Score: ";
    cin>>s_speaking;
    speaking = atoi(s_speaking.c_str());

    cout<<"\nToefl Writing Score: ";
    cin>>s_writing;
    writing = atoi(s_writing.c_str());

    //inserting international student to internationalStudentList
    Toefl toeflScore(reading,listening,speaking,writing);
    InternationalStudentPtr internationalStudent = new InternationalStudent(firstName,lastName,CGPA,researchScore,(20200100 + studentNum),country,toeflScore);
    internationalStudentList.insertNode(internationalStudent);

    studentNum++;
}

void deleteDomesticStudent(LinkedList<DomesticStudent>& domesticStudentList){
    string firstName, lastName;
    cout<<"First Name: ";
    cin>>firstName;
    formatString(firstName);

    cout<<"\nLast Name: ";
    cin>>lastName;
    formatString(lastName);

    domesticStudentList.deleteNode(firstName,lastName);
}

void deleteInternationalStudent(LinkedList<InternationalStudent>& internationalStudentList){
    string firstName, lastName;
    cout<<"First Name: ";
    cin>>firstName;
    formatString(firstName);

    cout<<"\nLast Name: ";
    cin>>lastName;
    formatString(lastName);

    internationalStudentList.deleteNode(firstName,lastName);
}









//Merge (merges a domestic list and an international list into a student list)
LinkedList<Student> mergeList(LinkedList<DomesticStudent>& domesticList, LinkedList<InternationalStudent>& internationalList){
    LinkedList<Student> returnList;
    
    auto dHere = domesticList.head;
    while(dHere != nullptr){
        //cout<<typeid(dHere->student).name()<<endl;
        returnList.insertNode(dHere->student);
        dHere = dHere->link;
    }

    auto iHere = internationalList.head;
    
    while(iHere != nullptr){
        if(!iHere->student->getToeflScore().passed()){
            iHere = iHere->link;
        }
        returnList.insertNode(iHere->student);
        iHere = iHere->link;
    }
    return returnList;
}