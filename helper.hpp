#ifndef HELPER
#define HELPER

#include <iostream>
#include "linkedList.hpp"

void outputMenu();

void domFile2DomList(LinkedList<DomesticStudent>& domesticStudentList, int& studentNum);

void intFile2IntList(LinkedList<InternationalStudent>& internationalStudent, int& studentNum);

void formatString(string& input);

void provinceIsValid(string& province);

void countryIsValid(string& country);

bool inputIsValid(string input,int numOfInputs);

void insertDomesticStudent(LinkedList<DomesticStudent>& linkedList,int& studentNum);

void insertDomesticStudent(LinkedList<Student>& linkedList,int& studentNum);

void insertInternationalStudent(LinkedList<InternationalStudent>& linkedList, int& studentNum);

void insertInternationalStudent(LinkedList<Student>& linkedList, int& studentNum);

void deleteDomesticStudent(LinkedList<DomesticStudent>& domesticStudentList);

void deleteInternationalStudent(LinkedList<InternationalStudent>& internationalStudentList);

void deleteStudent(LinkedList<Student>& studentList);

#endif