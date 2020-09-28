//
//  Erik Pantoja
//  Assignment5 - Binary Search
//  Data Structures 2019
//  Created by Erik on 9/25/19.
//  Copyright © 2019 Erik. All rights reserved.
//

//Included Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class binarySearch // All functions and data - going through class
{
    /* Student records should include Student ID, Name, GPA, Student Address, and
    a pointer which points to (10+) test scores for each student record located  somewhere in the program or from a second file.*/
    
public:
    struct student
    {
        int studentID;
        string studentName; //
        string studentAddress;
        float GPA;
        int *testScore; // using array pointer to store records
    };
    
    // Format Functions
    void introduction(); // For readability
    void conclusion(); // For readability
    // Utility Functions
    student push(student);
    student pop();
    bool readFile(vector <student> &studentList);
    void print(vector<student> const &input);
    int binarySearchi(vector<student>, int l, int r, int x);
    void recurrsion(vector<student>, int result);

};

int main() {
    binarySearch mainStack; // Creating object
    mainStack.introduction(); // For readability
    vector<binarySearch::student> studentList; // Vector to hold the student records
    binarySearch::student data;
    
    //Task 1, Task 2 - save records from file to vector of structs with student grades
    if(!mainStack.readFile(studentList)) // Adding Student records from text file
    {
    cout << "ERROR: Could not read the input file" << endl;
    return 1;
    }
    
    // Adding Sample grades to each record from program
    int a1[10] = {86,68,50,99,67,97,54,65,35,71};studentList.at(0).testScore = a1;
    int a2[10] = {98,68,50,99,67,94,50,96,90,77};studentList.at(1).testScore = a2;
    int a3[10] = {85,68,56,15,67,97,54,65,35,70};studentList.at(2).testScore = a3;
    int a4[10] = {86,68,50,99,58,86,59,98,35,77};studentList.at(3).testScore = a4;
    int a5[10] = {86,79,50,99,67,97,90,65,97,77};studentList.at(4).testScore = a5;
    int a6[10] = {53,68,53,76,67,97,57,98,35,74};studentList.at(5).testScore = a6;
    int a7[10] = {86,68,50,39,88,97,54,65,35,77};studentList.at(6).testScore = a7;
    int a8[10] = {34,67,50,99,67,90,56,65,35,72};studentList.at(7).testScore = a8;
    int a9[10] = {86,68,26,99,67,97,78,99,99,77};studentList.at(8).testScore = a9;
    int a10[10] = {99,66,50,99,54,96,54,65,35,76};studentList.at(9).testScore = a10;
    int a11[10] = {86,68,50,99,67,97,54,65,35,71};studentList.at(10).testScore = a11;
    int a12[10] = {98,38,50,39,67,94,50,96,90,77};studentList.at(11).testScore = a12;
    int a13[10] = {22,68,56,53,67,97,54,65,35,70};studentList.at(12).testScore = a13;
    int a14[10] = {86,58,50,99,58,86,59,98,35,77};studentList.at(13).testScore = a14;
    int a15[10] = {86,79,50,99,67,97,90,65,97,77};studentList.at(14).testScore = a15;
    int a16[10] = {53,55,53,26,67,97,34,98,35,74};studentList.at(15).testScore = a16;
    int a17[10] = {86,68,50,99,88,97,54,65,35,77};studentList.at(16).testScore = a17;
    int a18[10] = {54,67,50,99,67,90,56,65,35,98};studentList.at(17).testScore = a18;
    int a19[10] = {86,68,26,99,67,97,78,99,99,77};studentList.at(18).testScore = a19;
    int a20[10] = {99,35,50,39,54,96,54,35,35,76};studentList.at(19).testScore = a20;
    
    //Task 3 - display all records/including scores - could use POP
    cout << "Task 1 - 3 - Displaying all records in vector including scores "<<endl<<endl;
    mainStack.print(studentList);
    cout <<" -------------------------------------------------------------------------------------"<<endl;
    
    //Task 4 - Use recursive binary search to find student ID - at the end
    cout << "Task 4 - Searching for Student ID at the end of the vector " <<endl<<endl;
    int size = 20;
    int result = mainStack.binarySearchi(studentList, 0, size - 1, 20);
    mainStack.recurrsion(studentList, result); cout << endl <<endl;
    cout <<" -------------------------------------------------------------------------------------"<<endl;
    
    //Task 5 - Use recursive binary search to find 3-5 student IDs in the vector
    cout << "Task 5 - Searching for Student Id's including 3, 7, 9 " <<endl<<endl;
    result = mainStack.binarySearchi(studentList, 0, size - 1, 3);
    mainStack.recurrsion(studentList, result);
    result = mainStack.binarySearchi(studentList, 0, size - 1, 7);
    mainStack.recurrsion(studentList, result);
    result = mainStack.binarySearchi(studentList, 0, size - 1, 9);
    mainStack.recurrsion(studentList, result); cout << endl <<endl;
    cout <<" -------------------------------------------------------------------------------------"<<endl;
    
    // Task 6 - Use recursive binary search to look for record not in vector
    cout << "Task 6 - Searching for a record not in vector " <<endl;
    
    result = mainStack.binarySearchi(studentList, 0, size - 1, 22);
    mainStack.recurrsion(studentList, result);
    cout <<" -------------------------------------------------------------------------------------"<<endl;
    
    mainStack.conclusion(); // For readability
    return 0;
}


// Functions Defined



//Readability Functions Defined
void binarySearch::introduction(){
    cout <<"Asssignment 5 Binary Search  " << endl<<endl;
    cout <<"This program will:" <<endl<<endl;
    cout <<"1. Create a file of at least 20 student records sorted by student ID" <<endl;
    cout <<"2. Read student records into a vector " <<endl;
    cout <<"3. Display the 20+ student records (entire record, not just ID) and associated test scores." <<endl;
    cout <<"4. Use recursive binary search to search a student-ID at the end of the vector. "<<endl;
    cout <<"5. Use recursive binary search to search three-five student-IDs in the vector. "<<endl;
    cout <<"6. Use recursive binary search to search a student-ID which is not in the vector."<<endl<<endl;
    cout <<" -------------------------------------------------------------------------------------"<<endl;
}

void binarySearch::conclusion(){
    cout << endl << "Created by Erik Pantoja, For Data Structures Fall 2019 " <<endl<<endl;
}

bool binarySearch::readFile(vector <binarySearch::student> &studentList)
{
ifstream infile("/users/erik/desktop/Assignment5/grades.txt");
    if(infile.fail()){
        return false;
    }
binarySearch::student k;
while(infile >> k.studentID){
infile >> k.studentName >> k.studentAddress >> k.GPA;
studentList.push_back(k);
}
infile.close();
return true;
}

void binarySearch::print(vector<student> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << " Student ID is: "<< input.at(i).studentID << "    Student Name is: " << input.at(i).studentName << "    Student Address is: " << input.at(i).studentAddress << "    Student GPA is: " << input.at(i).GPA <<endl;
        cout << "Student " << input.at(i).studentID << " Test Scores are: ";
        for ( int n = 0; n < 10; n++ ) {
        cout << (*input.at(i).testScore + n) << " ";
        }
        cout <<endl;
    } cout <<endl;
}

int binarySearch::binarySearchi(vector<student> studentList, int a, int b, int c)
{
    if (b >= a) {
        int mid = a + (b - a) / 2;
        if (studentList[mid].studentID == c)
            return mid;
        if (studentList[mid].studentID > c)
            return binarySearchi(studentList, a, mid - 1, c);
        return binarySearchi(studentList, mid + 1, b, c);
    }
    return -1;
}

void binarySearch::recurrsion(vector<binarySearch::student> studentList, int result){
    if (result == -1){
        cout << "The record was not found in the vector" <<endl;
        return;
    }
     cout << " Student ID is: "<< studentList.at(result).studentID << "    Student Name is: " << studentList.at(result).studentName << "    Student Address is: " << studentList.at(result).studentAddress << "    Student GPA is: " << studentList.at(result).GPA <<endl;
      cout << "Student " << studentList.at(result).studentID << " Test Scores are: ";
      for ( int n = 0; n < 10; n++ ) {
      cout << (*studentList.at(result).testScore + n) << " ";
      }
    cout <<endl<<endl;
}
