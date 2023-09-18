/**
 * @file main.cpp
 * @author Sialas Tripp
 * @brief program that sorts the table by the last name, first name, and by SSN indirectly with pointers, using a dummy csv data. 
 *        The user interacts with the program to do print the relevant data in ascending order or a binary search to get the 
 *        relevant data from the file.
 * @date 2023-09-18
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "index.h"
using namespace std;

int main()
{
    ifstream file;
    openfile(file);
    vector<Student> data;
    readData(data, file);
    Student *indexBySsn[data.size()];
    Student *indexByLastName[data.size()];
    Student *indexByFirstName[data.size()];
    sortDataByLastName(data, indexByLastName);
    sortDataBySsn(data, indexBySsn);
    sortDataByFirstName(data, indexByFirstName);
    printOutput(data, indexByLastName, indexBySsn, indexByFirstName);

    return 0;
}