/*
Department maintains a student information. The file contains roll number, name, division and address.
  Allow user to add, delete information of student. Display information of particular employee. 
  If record of student does not exist an appropriate message is displayed.
  If it is, then the system displays the student details. Use sequential file to main the data. */



#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student
{
    int roll;
    string name;
    string designation,Adress;
};
void addStudent()
{
    Student s;
    cout << "Student Roll No: ";
    cin >> s.roll;
    cout << "Enter student name: ";
    cin >> s.name;
    cout << "Enter student division: ";
    cin >> s.designation;
    cout << "Enter Student Address: ";
    cin >> s.Adress;
    ofstream file("Student.txt", ios::app);
    file << s.roll << " " << s.name << " " << s.designation << " "<<s.Adress<<endl;
    file.close();
}
void deleteStudent()
{
    int roll;
    cout << "Enter the Roll No.to delete: ";
    cin >> roll;
    ifstream file("Student.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;
    while (file >> s.roll >> s.name >> s.designation >> s.Adress)
    {
        if (s.roll != roll)
        {
            temp << s.roll << " " << s.name << " " << s.designation << " "<<s.Adress<<endl;
        }
        else
        {
            found = true;
        }
    }
    file.close();
    temp.close();
    remove("s.txt");
    rename("temp.txt", "s.txt");
    if (found)
    {
        cout << "Student deleted successfully." << endl;
    }
    else
    {
        cout << "Student not found." << endl;
    }
}
void displaystudent()
{
    int roll;
    cout << "Enter the roll of the student to display: ";
    cin >> roll;
    ifstream file("Student.txt");
    Student s1;
    bool found = false;
    while (file >> s1.roll >> s1.name >> s1.designation >> s1.Adress)
    {
        if (s1.roll== roll)
        {
            found = true;
            cout << "Roll: " << s1.roll << endl;
            cout << "Name: " << s1.name << endl;
            cout << "Designation: " << s1.designation << endl;
            cout << "Salary: " << s1.Adress<< endl;
            break;
        }
    }
    file.close();
    if (!found)
    {
        cout << "Student not found." << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            displaystudent();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
