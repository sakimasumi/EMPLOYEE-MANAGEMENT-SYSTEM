#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
using namespace std::chrono_literals;
using namespace std;
//Styling function
//set string into title case
string Title(const string &str) {
string titl;
for (int i = 0; i < str.length(); i++){
    char c = str[i];
    if (i == 0){
        titl += toupper(c);//set the first character into uppercase
    }
    else if (i != 0){
        titl += (tolower(c));//other character set to lower case
    }
}
return titl;
}
//Coloring the text using enum
enum Colour{
    Orange,
    Red,
    Yellow,
    LightGreen,
    DarkGreen,
    LightBlue,
    DarkBlue,
    DefaultColor
} ;

//function for coloring the text
void Color(Colour color ){
    switch(color){
        case 0: cout << "\033[38;2;255;165;0m" ;break;//orange...
        case 1:  cout << "\033[38;2;255;69;0m";break;//red
        case 2:  cout << "\033[38;2;255;215;0m" ;break;//yellow
        case 3: cout << "\033[38;2;173;255;47m";break;//light green
        case 4: cout << "\033[38;2;0;255;0m";break;//dark green
        case 5: cout << "\033[38;2;0;255;255m";break;//light blue
        case 6:cout << "\033[38;2;0;191;255m";break;// dark blue
        case 7: cout << "\033[0m";break;//default color
    }
}
//set text to center
void setcenter(const string& text, int width) {
    int padding = int(width - text.length())/2;
    if (padding > 0) {
        cout <<setfill(' ')<< setw(padding) << "" << text << setw(padding) << "";
    } else {
        cout << text ;
    }
}
//make title
void title(const string& title){
    Color(Orange);
    cout << "\n\t\t\t\t    ------------";

    cout << "------------";

    cout << "---------------\n";
    cout << "\t\t\t\t    ";


    setcenter(title,36);

    cout << "\n\t\t\t\t    ---------------";

    cout << "------------";

    cout << "------------\n\n\n";
};
//set function that when usr press enter to load to next line
void pressEnterToSth(string something){
    int process;
    Color(Yellow);
    cout << "\t\t\t\t    Press Enter to "<<something << "......";
    cin.get();
    Color(Yellow);
    cout << "\n\n\t\t\t\t Loading";
    for (process = 0; process < 25; process++)
    {
        std::this_thread::sleep_for(20ms);
        cout << ".";
    }
    Color(Yellow);
}
//double link list that store employee info

struct Employee {
    string name;
    int age;
    string gender;
    string phoneNumber;
    string id;
    string department;
    string position;
    float salary;
    string startWork;
    Employee* next;
    Employee* previous;
};

struct ListEmployee {
    int n;
    Employee* head;
    Employee* tail;
};
//create empty list
ListEmployee* emptyList() {
    ListEmployee* myList = new ListEmployee();
    myList->n = 0;
    myList->head = NULL;
    myList->tail = NULL;
    return myList;
}
// Create the database
void createDataBase(const string& filename) {
    ifstream fileCheck(filename);
    // Check if the file exists
    if (!fileCheck) {
        ofstream file(filename);
        if (file.is_open()) {
            // Sample data
            file << "Pisey,F,e20220225,I2,AMS,19,081688651,2500$,2022\n";
            file << "Alya,F,e20220226,I2,AMS,19,012582939,2500$,2022\n";
            file << "Panha,F,e20220227,I2,AMS,19,061788887,2500$,2022\n";
            file.close();
            cout << "Database created\n";
        } else {
            cout << "Error creating database\n";
        }
    } else {
        cout << "Database already exists\n";
    }
}
//The introduction page
void welcomePage(){
    cout << "\n\t\t\t\t";
    title("Employee Management System");
  
    cout << "\t\t\t\t";
    cout << "Prepared By    :    Group 5  ";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Mini Project   :    Employee Management System";
    cout << "\n\n";
    pressEnterToSth("Continue");
    Color(LightGreen);
}

//add employee info to begin of DLL
void addEmployeeBegin(ListEmployee* myList, const string& newName, int newAge, const string& newGender,
                      const string& newPhoneNumber, const string& newId, const string& newDepartment,
                      const string& newPosition, float newSalary, const string& newStartWork) {
    Employee* newEmployee = new Employee();
    newEmployee->name = newName;
    newEmployee->age = newAge;
    newEmployee->gender = newGender;
    newEmployee->phoneNumber = newPhoneNumber;
    newEmployee->id = newId;
    newEmployee->department = newDepartment;
    newEmployee->position = newPosition;
    newEmployee->salary = newSalary;
    newEmployee->startWork = newStartWork;
    newEmployee->previous = nullptr;
    newEmployee->next = myList->head;

    if (myList->head != nullptr) {
        myList->head->previous = newEmployee;
    }
    myList->head = newEmployee;

    if (myList->n == 0) {
        myList->tail = newEmployee;
    }

    myList->n++;

    // Add data to file.csv
    ofstream file("Info.csv", ios::app);
    if (file.is_open()) {
        file << Title(newEmployee->name)<< "," << Title(newEmployee->gender) << ","
             << newEmployee->id << "," << Title(newEmployee->position) << ","
             << Title(newEmployee->department) <<","<< newEmployee->age << "," <<newEmployee->phoneNumber << "," << newEmployee->salary <<"$"<< "," << newEmployee->startWork << "\n";
        file.close();
    } else {
        cerr << "Unable to open file for writing.\n";
    }
}
//add employee to end of DLL
void addEmployeeEnd(ListEmployee* myList, const string& newName, int newAge, const string& newGender,
                    const string& newPhoneNumber, const string& newId, const string& newDepartment,
                    const string& newPosition, float newSalary, const string& newStartWork) {
    if (myList->n == 0) {
        addEmployeeBegin(myList, newName, newAge, newGender, newPhoneNumber, newId, newDepartment, newPosition, newSalary, newStartWork);
    } else {
        Employee* newEmployee = new Employee();
        newEmployee->name = newName;
        newEmployee->age = newAge;
        newEmployee->gender = newGender;
        newEmployee->phoneNumber = newPhoneNumber;
        newEmployee->id = newId;
        newEmployee->department = newDepartment;
        newEmployee->position = newPosition;
        newEmployee->salary = newSalary;
        newEmployee->startWork = newStartWork;
        newEmployee->previous = myList->tail;
        newEmployee->next = nullptr;

        myList->tail->next = newEmployee;
        myList->tail = newEmployee;
        myList->n++;

        // Add data to file
        ofstream file("Info.csv", ios::app);
        if (file.is_open()) {
            file << Title(newEmployee->name) << ","  << Title(newEmployee->gender) << ","
                 << newEmployee->id << "," << Title(newEmployee->position) << ","
                 << Title(newEmployee->department) << "," << newEmployee->age << "," << newEmployee->phoneNumber << ","<< newEmployee->salary <<"$"<< "," << newEmployee->startWork << "\n";
            file.close();
        } else {
            cerr << "Unable to open file for writing.\n";
        }
    }
}
//display function from file.csv
void displayEmployeeInfo() {
    ifstream file("Info.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file for reading.\n";
        return;
    }

    string records;
    while(file.peek()!=EOF){
        string records;
        getline(file,records);
        cout<<"\t\t\t\t";
        cout<<records<<endl;
    }

    file.close();
}
//search info by id function
void searchById(ListEmployee* list) {
    string idSearch;
    cout << "Enter ID to search: ";
    cin >> idSearch;
//cannot open file
    ifstream file("Info.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file for reading.\n";
        return;
    }

    bool found = false;
    Employee newData;
    string line;
    //get info from file.csv
    while (getline(file, line)) {
        stringstream ss(line);
        //id found
        getline(ss, newData.name, ',');
        getline(ss, newData.gender, ',');
        getline(ss, newData.id, ',');
        getline(ss, newData.position, ',');
        getline(ss, newData.department, ',');
        ss>>newData.age;
        ss>>newData.phoneNumber;
        ss>>newData.salary;
        ss>>newData.startWork;
        ss.ignore();
      
        if (idSearch == newData.id) {
            cout<<"\t\t\t\t\n";
            cout << newData.name << "," << newData.gender << ","
                 << newData.id << "," << newData.position << ","
                << newData.department << ","<< newData.age<<newData.phoneNumber<<"\n";
            found = true;
            break;
        }
    }
//id not found
    if (!found) {
        cout << "\t\t\t\tEmployee with ID " << idSearch << " not found.\n";
    }

    file.close();
}
//change employee information at specific position that usr want
//to change
void changeInfoEmployee(ListEmployee *myList) {
    Employee newData;
    //get new info from usr
    int position;
    cout<<"\t\t\t\tEnter name: "; cin>>newData.name;
    cout<<"\t\t\t\tEnter age: "; cin>>newData.age;
    cout<<"\t\t\t\tEnter gender: "; cin>>newData.gender;
    cout<<"\t\t\t\tEnter id: "; cin>>newData.id;
    cout<<"\t\t\t\tEnter phone number: "; cin>>newData.phoneNumber;
    cout<<"\t\t\t\tEnter Title: "; cin>>newData.position;
    cout<<"\t\t\t\tEnter department: "; cin>>newData.department;
    cout<<"\t\t\t\tEnter salary: "; cin>>newData.salary;
    cout<<"\t\t\t\tEnter start year: "; cin>>newData.startWork;
    //enter the position that will be replaced
    cout<<"\t\t\t\tPlease enter the position that you want to change: ";
    cout<<endl;
    cout<<"\t\t\t\tEnter position: "; cin>>position;
    //read file.csv
    fstream read_file;
    read_file.open("Info.csv");
    //check if file cannot be opened
    if (read_file.fail()){
        cout<<"\t\t\t\tError opening file. File does not exist!";
    }
    vector<string> lines;
    string line;
    while (getline(read_file,line)){
        lines.push_back(line);
    }
    read_file.close();
    //check if position is greater than line size
    if (position>lines.size()){
        cout<<"\t\t\t\tPosition "<<position<<" not in the file"<<endl;
        cout<<"\t\t\t\tFile has "<<lines.size()<<" lines."<<endl;
    }
    ofstream write_file;
    write_file.open("Info.csv");
    if (write_file.fail()){
        cout<<"\t\t\t\tError open file. File does not exist."<<endl;
        
    }
    position--;
    for (int i=0; i<lines.size();i++){
        //check position
        if (i!=position){
            write_file<<lines[i]<<endl;

        }
        else{
            write_file<< Title(newData.name) << "," <<Title(newData.gender) << "," <<newData.id << "," <<Title(newData.position) << ","
            << Title(newData.department) << "," << newData.age << "," << newData.phoneNumber<< ","
            << newData.salary << "$" << "," << newData.startWork << "\n";
            
        }
    }
    write_file.close();
    displayEmployeeInfo();

    
}
//delete employee information
void deletespec(){
    int pos;
    cout<<"\t\t\t\tRemove position: ";
    cin>>pos;
    fstream read_file;
    read_file.open("Info.csv");
    //check if file cannot be opened
    if (read_file.fail()){
        cout<<"\t\t\t\tError opening file. File does not exist!";
    }
    vector<string> lines;
    string line;
    while (getline(read_file,line)){
        lines.push_back(line);
    }
    read_file.close();
    //check if position is greater than line size
    if (pos>lines.size()){
        cout<<"\t\t\t\tPosition "<<pos<<" not in the file"<<endl;
        cout<<"\t\t\t\tFile has "<<lines.size()<<" lines."<<endl;
    }
    ofstream write_file;
    write_file.open("Info.csv");
    if (write_file.fail()){
        cout<<"\t\t\t\tError open file. File does not exist."<<endl;
        
    }
    pos--;
    for (int i=0; i<lines.size();i++){
        //check position
        if (i!=pos){
            write_file<<lines[i]<<endl;
        }
        else{
            write_file<<"";
            
        }
    }
    write_file.close();
    
}
//exit function
void callExit(){
    Color(Red);
    cout << "\n";
    cout << "\t\t\t\t\t";
    cout << "You are out of the System.";
    cout << "\n\n";
    cout << "\t\t\t\t";
    exit(0);
}
//main function
void mainLogin(ListEmployee* ls){
    int choose = 0;
    ListEmployee* List = emptyList();

    while (choose != 6) {
        title("Welcome to Employee Management System!");
        cout << "\t\t\t\t\t";
        Color(LightBlue);
        cout << "Choose from the Menu: " << endl
             << "\t\t\t\t\t1. Add employee information." << endl
             << "\t\t\t\t\t2. Display information." << endl
             << "\t\t\t\t\t3. Search information by ID." << endl
             << "\t\t\t\t\t4. Change employee information." <<endl
             << "\t\t\t\t\t5. Delete specific row."<<endl
             << "\t\t\t\t\t6. Exit program." << endl;
        cout << "\n\n\t\t\t\t\tYour choice: ";
        cin >> choose;

        switch (choose) {
            case 1: {//adding employee info
                Color(LightBlue);
                cout<<"\n\n\t\t\t\t";
                cout<<"Adding Employee Information...\n";
                int person;
                cout<<"\t\t\t\t";
                cout << "How many employees do you want to add to this list? ";
                cin >> person;
                
                for (int i = 1; i <= person; i++) {
                    string name, gender, phoneNumber, id, department, position, startWork;
                    int age;
                    float salary;
                    cout<<"\t\t\t\t";
                    cout << "Enter employee information:" << endl;
                    cout<<"\t\t\t\t";
                    cout << "Employee " << i << ":" << endl;
                    cout<<"\t\t\t\t";
                    cout << "Employee Name: "; cin>>name;
                    cout<<"\t\t\t\t";
                    cout << "Employee Age: "; cin >> age;
                    cout<<"\t\t\t\t";
                    cout << "Employee Gender: "; cin >> gender;cout<<"\t\t\t\t";
                    cout << "Employee ID: "; cin >> id;cout<<"\t\t\t\t";
                    cout << "Employee Phone Number: "; cin >> phoneNumber;cout<<"\t\t\t\t";
                    cout << "Employee Title: "; cin >> position;cout<<"\t\t\t\t";
                    cout << "Employee Department: "; cin >> department;cout<<"\t\t\t\t";
                    cout << "Employee Salary: "; cin >> salary;cout<<"\t\t\t\t";
                    cout << "Employee Start Working Year: "; cin >> startWork;cout<<"\t\t\t\t";

                    addEmployeeEnd(List, name, age, gender, phoneNumber, id, department, position, salary, startWork);
                    cout<<"\t\t\t\tAdding successfully...\n";
                                    }
                break;
            }
            case 2: {//display all employee info
                Color(Yellow);
                cout<<"\t\t\t\t";
                cout<<"Display all employee information...\n";cout<<"\t\t\t\t";
                cout<<"Loading ...\n";
                displayEmployeeInfo();
                break;
            }
            case 3: {
                //searching employee info by id
                Color(DarkGreen);
                cout<<"\t\t\t\t";
                cout<<"Searching employee information by ID...\n";cout<<"\t\t\t\t";
                cout<<"Loading ...\n";
                searchById(List);
                break;
            }
            case 4: {
                //updating employee info at specific position
                Color(Orange);
                cout<<"\t\t\t\t";
                cout<<"\t\t\t\tUpdating employee information...\n";
                changeInfoEmployee(List);
                cout<<"\t\t\t\tUpdating successfully...";
                break;
            }
            case 5: {
                Color(LightGreen);
                //delete specific row that usr want to delete
                cout<<"\t\t\t\t";
                cout<<"Delete Employee Info...";
                cout<<endl;
                deletespec();
                cout<<"\t\t\t\tAfter Deletion:"<<endl;
                displayEmployeeInfo();
                break;
            }
            case 6: {
                //exit program
                callExit();
                break;
            }
            default: {
                Color(Red);
                cout<<"\t\t\t\t";
                cout << "Invalid choice. Please try again!" << endl;cout<<"\t\t\t\t";
                pressEnterToSth("Choose again");
                mainLogin(ls);
            }
        }
    }

    // Clean up memory
    Employee* current = List->head;
    while (current != NULL) {
        Employee* next = current->next;
        delete current;
        current = next;
    }
    delete List;
}
#endif
