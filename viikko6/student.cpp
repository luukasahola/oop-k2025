#include "student.h"


Student::Student(string s, int a)
{
    Student::setName(s);
    Student::setAge(a);
    cout << "Student " << s << " initialized with age " << a << "." << endl;
}

void Student::setAge(int a)
{
    Age = a;
}

void Student::setName(string s)
{
    Name = s;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentInfo()
{
    cout << Student::getName() << " : " << Student::getAge() << endl;
}

