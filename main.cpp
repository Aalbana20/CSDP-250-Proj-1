#include <iostream>
#include "CourseList.h"
using namespace std;

int main()
{
    CourseList list;
    int choice;
    string code;
    double grade;
    int hours;
 

    do 
    {
        cout << "---Welcome to the Menu---\n";
        
        cout << "1. Insert a course\n";
        cout << "2. Delete a course\n";
        cout << "3. Delete all courses\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter course code: " << endl;
            cin>>code;
           
            cout << "Enter student grade: " << endl;
            cin >> grade;
            cout << "Enter credit hours: " << endl;
            cin >> hours;
            list.insertNode(grade, hours, code);
            break;

        case 2:
            cout << "Enter Course code: " << endl;
            cin>>code;
            cout << "Enter student grade: " << endl;
            cin >> grade;
            cout << "Enter credit hours: " << endl;
            cin >> hours;
            list.deleteNode(grade, hours, code);
            break;

        case 3:
            
            list.deleteallNodes();
            cout << "All courses have been deleted.\n";
            break;
        
        case 4:
            cout << "Student List:\n";
            list.display();
            break;

        case 5:
            cout << "Exiting the program, thank you.\n";
            break;

        default:
            cout << "Invalid choice, choose an option between 1-5. \n";
        }

    } while (choice != 5);
    
    return 0;
}