#include "student.h"



int main ()
{
  int selection = 0;
  vector<Student *>studentList;
  string name;
  int age;

  vector<Student *>::iterator it;

  do
    {
      cout<<endl;
      cout<<"Select"<<endl;
      cout<<"Add students = 0"<<endl;
      cout<<"Print all students = 1"<<endl;
      cout<<"Sort and print students according to Name = 2"<<endl;
      cout<<"Sort and print students according to Age = 3"<<endl;
      cout<<"Find and print student = 4"<<endl;
      cout <<"Exit the program = 5"<<endl;
      cout<<"Select an option: ";
      cin>>selection;

      switch(selection)
      {
        case 0:
          cout << "Enter the student's name: ";
          cin >> name;
          cout << "Enter the student's age: ";
          cin >> age;
          studentList.emplace_back(new Student(name,age));
          break;
        case 1:
            for(auto* loop : studentList)
            {
              loop->printStudentInfo();
            }
          break;

        case 2:
          sort(studentList.begin(),studentList.end(),[](Student * a, Student * b){return (a->getName()<b->getName());});
          for(auto* loop : studentList)
          {
            loop->printStudentInfo();
          }
          break;

        case 3:
         sort(studentList.begin(),studentList.end(),[](Student * a, Student * b){return (a->getAge()>b->getAge());});
         for(auto* loop : studentList)
         {
           loop->printStudentInfo();
         }
          break;
        case 4:
          cout << "Enter the name of searched student: ";
          cin >> name;
          it = find_if(studentList.begin(),studentList.end(),[name](Student * b){return name == b->getName();});
          if(it != studentList.end())
          {
            cout << "Student " << name << " found." << endl;
          }
          else
          {
              cout << "The student you were searching for was not found." << endl;
          }
          break;
        case 5:
          return 0;
        default:
          cout<< "Wrong selection, stopping..."<<endl;
          break;
      }
    }while(selection < 6);

  return 0;
}
