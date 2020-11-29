#ifndef HELPER
#define HELPER

#include <iostream>
#include "linkedList.hpp"

void outputMenu();

void domFile2DomList(LinkedList<DomesticStudent>& domesticStudentList);

void intFile2IntList(LinkedList<InternationalStudent>& internationalStudent);

void formatString(string& input);

void provinceIsValid(string province);

void countryIsValid(string& country);

bool inputIsValid(string input);

void insertDomesticStudent(LinkedList<DomesticStudent>& domesticStudentList,int& studentNum);

void insertInternationalStudent(LinkedList<InternationalStudent>& internationalStudentList, int& studentNum);

#endif