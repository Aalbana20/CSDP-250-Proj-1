#ifndef COURSELIST_H
#define COURSELIST_H

#include <iostream>
#include <string>

using namespace std;

class CourseList 
{
private:
    struct CourseNode 
    {
        double grade;
        int hours;
        string code;
        CourseNode* next;
        CourseNode* prev;

        CourseNode(double grade, int hours, string code) : grade(grade), hours(hours), code(code), next(nullptr), prev(nullptr) {}
    };

    CourseNode* head;
    CourseNode* tail;

public:
    CourseList();
    ~CourseList();
  
    void deleteNode(double &grade, int &hours, string &code);
    void insertNode(double grade, int hours, string code);
    void deleteallNodes();
    void display() const;
};

#endif 