/**
 * @file index.cpp
 * @author Sialas Tripp
 * @brief Function definition file
 * @date 2023-09-18
 * 
 */
#include "index.h"

/**
 * @brief Displays menu for user
 * 
 */
void displayMenu()
{
    cout << "1. Print data in ascending order by last name\n" <<
            "2. Print data in ascending order by SSN\n" <<
            "3. Search by last name\n" <<
            "4. Search by SSN\n" <<
            "5. Print data in ascending order by first name\n" <<
            "6. Search by first name\n" <<
            "7. Exit\n" << endl <<
            "Select a Menu: ";
}

/**
 * @brief opens file
 * 
 * @param file file that is being opened (grades.csv)
 */
void openfile(ifstream &file)
{
    file.open("grades.csv");
    if (!file)
    {
        cout << "grades.csv";
        exit(1);
    }
}

/**
 * @brief reads grades.csv file into a vector of the Student struct
 * 
 * @param data vector of the Student Struct
 * @param file grades.csv that is being read into the vector
 */
void readData(vector<Student>& data, ifstream& file)
{
    string first;
    getline(file, first);
    Student temp;
    while (file.peek() != EOF)
    {
        char delim;
        file >> temp.id >> delim;
        getline(file, temp.lastName, ',');
        getline(file, temp.firstName, ',');
        getline(file, temp.ssn, ',');
        file >> temp.test[0] >> delim;
        file >> temp.test[1] >> delim;
        file >> temp.test[2] >> delim;
        file >> temp.test[3] >> delim;
        file >> temp.final >> delim; 
        file >> temp.letterGrade;
        if(file.peek() == EOF)
        {
            break;
        }
        data.push_back(temp); 
    }
}

/**
 * @brief displays original unsorted vector to user
 * 
 * @param data original unsorted vector
 */
void displayTest(vector<Student>& data)
{
    cout << "ID  Last Name  First Name SSN         Test1 Test2 Test3 Test4 Final Grade\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << setw(2) << data[i].id << "  "
        << left << setw(10) << data[i].lastName << " " 
        << left << setw(10) << data[i].firstName << " " 
        << data[i].ssn << " ";
        for (int j = 0; j < 4; ++j)
        {
            cout << right << setw(5) << data[i].test[j] << " ";
        }
        cout << right << setw(5) << data[i].final << " "
             << right << setw(5) << data[i].letterGrade << endl;
    }
    cout << endl;
}

/**
 * @brief displays the new sorted array to user
 * 
 * @param data new sorted pointer array
 * @param size size of array
 */
void displayTest(Student* data[], int size)
{
    cout << "ID  Last Name  First Name SSN         Test1 Test2 Test3 Test4 Final Grade\n";
    for (int i = 0; i < size; ++i)
    {
        cout << setw(2) << data[i]->id << "  "
        << left << setw(10) << data[i]->lastName << " " 
        << left << setw(10) << data[i]->firstName << " " 
        << data[i]->ssn << " ";
        for (int j = 0; j < 4; ++j)
        {
            cout << right << setw(5) << data[i]->test[j] << " ";
        }
        cout << right << setw(5) << data[i]->final << " "
                << right << setw(5) << data[i]->letterGrade << endl << endl;
    }

}

/**
 * @brief Sorts the data from the student struct vector indirectly by last name
 * 
 * @param data original unsorted vector
 * @param indexByLastName array of pointers that will be sorted by last name ascendingly.
 */
void sortDataByLastName(vector<Student>& data, Student* indexByLastName[]) 
{
    for (size_t i = 0; i < data.size(); ++i) 
    {
        indexByLastName[i] = &data[i];
    }

    for (size_t i = 1; i < data.size(); ++i) {
        Student *temp = indexByLastName[i];
        int j = i - 1;
        while (j >= 0 && indexByLastName[j]->lastName > temp->lastName) {
            indexByLastName[j + 1] = indexByLastName[j];
            j--;
        }
        indexByLastName[j + 1] = temp;
    }
}

/**
 * @brief Sorts the data from the student struct vector indirectly by ssn
 * 
 * @param data original unsorted vector
 * @param indexBySsn array of pointers that will be sorted by ssn ascendingly.
 */
void sortDataBySsn(vector<Student>& data, Student* indexBySsn[])
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        indexBySsn[i] = &data[i];
    }
    for (size_t i = 1; i < data.size(); ++i) 
    {
        Student *temp = indexBySsn[i];
        int j = i - 1;
        while (j >= 0 && indexBySsn[j]->ssn > temp->ssn) 
        {
            indexBySsn[j + 1] = indexBySsn[j];
            j--;
        }
        indexBySsn[j + 1] = temp;
    }

}

/**
 * @brief Sorts the data from the student struct vector indirectly by first name
 * 
 * @param data original unsorted vector
 * @param indexByFirstName Sorts the data from the student struct vector indirectly by first name
 */
void sortDataByFirstName(vector<Student>& data, Student* indexByFirstName[])
{
    for (size_t i = 0; i < data.size(); ++i) 
    {
        indexByFirstName[i] = &data[i];
    }

    for (size_t i = 1; i < data.size(); ++i) 
    {
        Student *temp = indexByFirstName[i];
        int j = i - 1;
        while (j >= 0 && indexByFirstName[j]->firstName > temp->firstName)
        {
            indexByFirstName[j + 1] = indexByFirstName[j];
            j--;
        }
        indexByFirstName[j + 1] = temp;
    }
}

/**
 * @brief Prints the sorted array by ssn
 * 
 * @param data the ssn sorted array
 * @param size size of the array
 */
void printDataBySsn(Student* data[], int size)
{
    cout << "Sorted by SSN:" << endl
         << "ID  Last Name  First Name SSN         Grade\n";
    for (int i = 0; i < size; ++i) 
    {
        cout << setw(2) << data[i]->id << "  " 
        << left << setw(10) << data[i]->lastName << " "
        << left << setw(10) << data[i]->firstName << " " 
        << data[i]->ssn << " "
        << right << data[i]->letterGrade << endl;
    }
}

/**
 * @brief Prints the sorted array by last name
 * 
 * @param data the last name sorted array
 * @param size size of the array
 */
void printDataByLastName(Student* data[], int size)
{
    cout << "Sorted by Last Name" << endl
         << "ID  Last Name  First Name SSN         Grade\n";
    for (int i = 0; i < size; ++i) 
    {
        cout << setw(2) << data[i]->id << "  " 
                << left << setw(10) << data[i]->lastName << " "
                << left << setw(10) << data[i]->firstName << " " 
                << left << setw(11) << data[i]->ssn << " "
                << right << data[i]->letterGrade << endl;
    }
    
}

/**
 * @brief Prints the sorted array by first name
 * 
 * @param data the first name sorted array
 * @param size size of the array
 */
void printDataByFirstName(Student* data[], int size)
{
    cout << "Sorted by First Name" << endl
         << "ID  Last Name  First Name SSN         Grade\n";
    for (int i = 0; i < size; ++i) 
    {
        cout << setw(2) << data[i]->id << "  " 
                << left << setw(10) << data[i]->lastName << " "
                << left << setw(10) << data[i]->firstName << " " 
                << left << setw(11) << data[i]->ssn << " "
                << right << data[i]->letterGrade << endl;
    }
}

/**
 * @brief Get the Input from user and checks if valid
 * 
 * @return int user input (1-12)
 */
int getInput()
{
    int input;
    cin >> input;
    while(input < 1 || input > 7)
    {
        cout << "Error! Please select number from the list: ";
        cin >> input;
    }
    return input;
}

/**
 * @brief loop that prints output depending on user choice
 * 
 * @param data original unsorted vector
 * @param dataLastName new sorted by last name array 
 * @param dataSsn new sorted by ssn array 
 * @param dataFirstName new sorted by first name array 
 */
void printOutput(vector<Student> &data, Student* dataLastName[], Student* dataSsn[], Student* dataFirstName[])
{
    while(1)
    {
        displayMenu();
        int choice = getInput();
        switch (choice)
        {
            case 1:
            {
                printDataByLastName(dataLastName, data.size());
                pressEnter();
            }
            break;
            case 2:
            {
                printDataBySsn(dataSsn, data.size());
                pressEnter();
            }
            break;
            case 3:
            {
                displayTest(data);
                bool found = false;
                while(!found)
                {
                    found = searchByLastName(dataLastName, data.size());
                    if(found)
                    {
                        break;
                    }
                    else
                       cout << "Error! ";  

                }
                pressEnter();
            }
            break;
            case 4:
            {
                displayTest(data);
                bool found = false;
                while(!found)
                {
                    found = searchBySsn(dataSsn, data.size());
                    if(found)
                    {
                        break;
                    }
                    else
                        cout << "Error! ";

                }
                pressEnter();
            }
            break;
            case 5:
            {
                printDataByFirstName(dataFirstName, data.size());
                pressEnter();
            }
            break;
            case 6:
            {
                displayTest(data);
                bool found = false;
                while(!found)
                {
                    found = searchByFirstName(dataFirstName, data.size());
                    if(found)
                    {
                        break;
                    }
                    else
                       cout << "Error! ";  

                }
                pressEnter();
                
            }
            break;
            case 7:
            {
                exit(1);
            }
            break;

        }
    }
}

/**
 * @brief Dynamically searches through the sorted array to find the user
 *        inputted last name and outputs all relevant info.
 * 
 * @param data sorted array by Last name
 * @param size array size
 * @return true if the inputed name was found
 * @return false if the inputed name was not found
 */
bool searchByLastName(Student* data[], int size)
{
    
    string input;
    cout << "Please enter student's last name: ";
    cin >> input;
    int first = 0;
    int last = size -1;
    int middle;
    int position = -1;
    bool found = false;
    while (!found && first <= last)
    {
        middle = first + (last - first) / 2;
        if (data[middle]->lastName == input)
        {
            found = true;
            position = middle;
            int i = position;
            cout << "ID  Last Name  First Name SSN         Test1 Test2 Test3 Test4 Final Grade\n";
            cout << setw(2) << data[i]->id << "  "
            << left << setw(10) << data[i]->lastName << " " 
            << left << setw(10) << data[i]->firstName << " " 
            << data[i]->ssn << " ";
            for (int j = 0; j < 4; ++j)
            {
                cout << right << setw(5) << data[i]->test[j] << " ";
            }
            cout << right << setw(5) << data[i]->final << " "
                 << right << setw(5) << data[i]->letterGrade << endl << endl;
        }
        else if (data[middle]->lastName > input)
        {
            last = middle - 1;
        }
        else
            first = middle + 1;
    }
  return found;

}

/**
 * @brief Dynamically searches through the sorted array to find the user
 *        inputted ssn and outputs all relevant info.
 * 
 * @param data sorted array by ssn
 * @param size array size
 * @return true if the inputed name was found
 * @return false if the inputed name was not found
 */
bool searchBySsn(Student* data[], int size)
{
    string input;
    cout << "Please enter student's ssn: ";
    cin >> input;
    int first = 0;
    int last = size -1;
    int middle;
    int position = -1;
    bool found = false;
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (data[middle]->ssn == input)
        {
            found = true;
            position = middle;
            int i = position;
            cout << "ID  Last Name  First Name SSN         Test1 Test2 Test3 Test4 Final Grade\n";
            cout << setw(2) << data[i]->id << "  "
            << left << setw(10) << data[i]->lastName << " " 
            << left << setw(10) << data[i]->firstName << " " 
            << data[i]->ssn << " ";
            for (int j = 0; j < 4; ++j)
            {
                cout << right << setw(5) << data[i]->test[j] << " ";
            }
            cout << right << setw(5) << data[i]->final << " "
                 << right << setw(5) << data[i]->letterGrade << endl << endl;
        }
        else if (data[middle]->ssn > input)
        {
            last = middle - 1;
        }
        else
            first = middle + 1;
    }
    return found;
}

/**
 * @brief Dynamically searches through the sorted array to find the user
 *        inputted first name and outputs all relevant info.
 * 
 * @param data sorted array by first name
 * @param size array size 
 * @return true if the inputed name was found 
 * @return false if the inputed name was not found
 */
bool searchByFirstName(Student* data[], int size)
{
    
    string input;
    cout << "Please enter student's first name: ";
    cin >> input;
    int first = 0;
    int last = size -1;
    int middle;
    int position = -1;
    bool found = false;
    while (!found && first <= last)
    {
        middle = first + (last - first) / 2;
        if (data[middle]->firstName == input)
        {
            found = true;
            position = middle;
            int i = position;
            cout << "ID  Last Name  First Name SSN         Test1 Test2 Test3 Test4 Final Grade\n";
            cout << setw(2) << data[i]->id << "  "
            << left << setw(10) << data[i]->lastName << " " 
            << left << setw(10) << data[i]->firstName << " " 
            << data[i]->ssn << " ";
            for (int j = 0; j < 4; ++j)
            {
                cout << right << setw(5) << data[i]->test[j] << " ";
            }
            cout << right << setw(5) << data[i]->final << " "
                 << right << setw(5) << data[i]->letterGrade << endl << endl;
        }
        else if (data[middle]->firstName > input)
        {
            last = middle - 1;
        }
        else
            first = middle + 1;
    }
  return found;
}

/**
 * @brief simple function that asks user to press enter to continue
 * 
 */
void pressEnter()
{
    cout << "\nPress enter to contine... ";
    cin.ignore();
    cin.get();
}