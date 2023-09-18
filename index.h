/**
 * @file index.h
 * @author Sialas Tripp
 * @brief function header file
 * @date 2023-09-15
 * 
 */

#ifndef INDEX_H
#define INDEX_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
struct Student
{
    int id;
    string lastName;
    string firstName;
    string ssn;
    float test[4];
    float final;
    string letterGrade;
};

void displayMenu();
void openfile(ifstream &file);
void readData(vector<Student> &data, ifstream &file);
void sortDataByLastName(vector<Student>& data, Student* indexByLastName[]);
void sortDataBySsn(vector<Student>& data, Student* indexBySsn[]);
void sortDataByFirstName(vector<Student>& data, Student* indexByFirstName[]);
void printDataByLastName(Student* data[], int size);
void printDataBySsn(Student* data[], int size);
void printDataByFirstName(Student* data[], int size);
void printOutput(vector<Student> &data, Student* dataLastName[], Student* dataSsn[], Student* dataFirstName[]);
bool searchByLastName(Student* data[], int size);
bool searchBySsn(Student* data[], int size);
bool searchByFirstName(Student* data[], int size);
int getInput();
void pressEnter();
void displayTest(vector<Student>& data);
void displayTest(Student* data[], int size);
#endif // STUDENTS_H