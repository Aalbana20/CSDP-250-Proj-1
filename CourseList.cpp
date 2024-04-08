#include "CourseList.h"

CourseList::CourseList() :
    head(nullptr), tail(nullptr) 
{
}

CourseList::~CourseList()
{
    deleteallNodes();
}

void CourseList::deleteallNodes() 
{
    CourseNode* current = head;
    while (current != nullptr) 
    {
        CourseNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

void CourseList::deleteNode(double &grade, int &hours, string &code) 
{
    CourseNode* current = head;
    CourseNode* prev = nullptr;
    
    while (current != nullptr && (current->grade != grade || current->hours != hours || current->code != code)) 
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) 
    {
        cout << "Course grade: " << grade << ", credit hours: " << hours << ", course code: " << code << " not found" << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    if (current == tail) 
    {
        tail = prev;
    }

    delete current;
}

void CourseList::insertNode(double grade, int hours, string code) 
{

 for (char c : code) 
    {
        if (!isdigit(c)) 
        {
            cout << "Invalid code: " << endl;
            return;
        }
    }
    
    
    int courseCode = stoi(code);
    
    
    cout << "Course code: " << courseCode << endl;
    
    
    CourseNode* newNode = new CourseNode(grade, hours, code);
    
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) 
    {
        head->prev = newNode;
    }

    head = newNode;

    if (tail == nullptr) 
    {
        tail = newNode;
    }
}

void CourseList::display() const 
{
    CourseNode* current = head;
    
    while (current != nullptr) 
    {
        cout << " Course code: " << current->code << ", Credit hours: " << current->hours << ", Grade: " << current->grade << endl;
        current = current->next;
    }
}
