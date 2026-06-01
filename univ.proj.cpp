#include <iostream>
#include "university.h"
#include <vector>
#include <string>
using namespace std;
bool studentlogin()
{
  bool yus = 1;
  string username = "student1", password = "student123", username1, pass1;
  cout << "Enter username and password " << endl;
  cout << "Username : ";
  cin >> username1;
  cout << endl
       << "Password : ";
  cin >> pass1;
  if (username1 != username || password != pass1)
  {
    cout << "ERROR!! INVALID ID OR PASSWORD " << endl;
    yus = 0;
  }
  return yus;
}
bool proflogin()
{
  bool yus = 1;
  string username = "prof1", password = "prof123", username1, pass1;
  cout << "Enter username and password " << endl;
  cout << "Username : ";
  cin >> username1;
  cout << endl
       << "Password : ";
  cin >> pass1;
  if (username1 != username || password != pass1)
  {
    cout << "ERROR!! INVALID ID OR PASSWORD " << endl;
    yus = 0;
  }
  return yus;
}
bool adminlogin()
{
  bool yus = 1;
  string username = "admin", password = "admin123", username1, pass1;
  cout << "Enter username and password " << endl;
  cout << "Username : ";
  cin >> username1;
  cout << endl
       << "Password : ";
  cin >> pass1;
  if (username1 != username || password != pass1)
  {
    cout << "ERROR!! INVALID ID OR PASSWORD " << endl;
    yus = 0;
  }
  return yus;
}
void adminMenu(university &uni)
{

  cout << "Tell about the task which you want to do " << endl;
  int x = 0;
  cout << "1)  Add a student \n2)  Add a professor \n3)  Add a course \n4)  Assign professor to a course" << endl;
  cin >> x;
  switch (x)
  {
  case 1:
  {
    /* code */
    string s;
    int id;
    cout << "Give name and StudentId for student to be added " << endl;
    cout << "Name : ";
    cin >> s;
    cout << endl
         << "StudentId : ";
    cin >> id;
    uni.addstudent(student(id, s));
    break;
  }
  case 2:
  {
    string s;
    int id;
    cout << "Give name and professorId for Professor to be added " << endl;
    cout << "Name : ";
    cin >> s;
    cout << endl
         << "ProfessorId : ";
    cin >> id;
    uni.addprofessor(professor(id, s));
    break;
  }
  case 3:
  {
    int courseId;
    int professorId;
    string title;
    cout << "Give CourseId and title of the course" << endl;
    cout << "CourseId : ";
    cin >> courseId;
    // cout<< "   ProfessorId : ";
    // cin>>professorId;
    cout << " Title of the subject : ";
    cin >> title;
    cout << endl;
    uni.addcourse(course(courseId, title));
    break;
  }
  case 4:
  {
    int professorId;
    string name;
    int courseid;
    cout << "Enter professorId and name of the professor" << endl;
    cout << "ProfessorId : ";
    cin >> professorId;
    cout << endl;
    cout << "Enter the name of professor : ";
    cin >> name;
    cout << "Enter the courseId at which professor is to be assigned : ";
    cin >> courseid;
    uni.assignproftocourse(courseid, professorId);
  }

  default:
  {
    cout << "Invalid choice";
    break;
  }
  }
}
void professormenu(university &uni)
{
  cout << "Welcome to prof menu" << endl;
  cout << "You can assign grades to students with studentId";
  cout << "Enter the profId : ";
  int profId, courseId;
  cin >> profId;
  int studentId;
  cout << endl
       << "Enter the studentId : ";
  cin >> studentId;
  cout << endl
       << "Enter course Id : ";
  cin >> courseId;
  cout << endl
       << "Enter the grade out of 100 : ";
  int x;
  cin >> x;
  // uni.assignstudentgrades(studentId);
  uni.editgradeofastudent(studentId, courseId, x, profId);
}
void studentmenu(university &uni)
{
  cout << "Welcome to student menu" << endl
       << "Enter your studentId : ";
  int id;
  cin >> id;
  student *s = uni.findStudent(id);

  cout << "You can perform two tasks " << endl
       << "1) View enrolled courses\n2) View grades" << endl
       << "Tell what you need to do : ";
  int x;
  cin >> x;
  switch (x)
  {
  case 1:
  {
    /* code */
    for (int i = 0; i < s->registeredcourseIds.size(); i++)
    {
      cout << s->registeredcourseIds[i] << "  " << endl;
    }

    break;
  }
  case 2:
  {
    cout << " Grades are as follows " << endl;
    for (int i = 0; i < s->registeredcourseIds.size(); i++)
    {
      cout << s->registeredcourseIds[i] << "  :   ";
      cout << s->grade[s->registeredcourseIds[i]] << "  " << endl;
    }
    break;
  }

  default:
  {
    cout << "invalid";
    break;
  }
  }
}
int main()
{
  university uni;
  uni.addstudent(student(1, "Arpit"));
  uni.addstudent(student(2, "Ayush"));
  uni.addprofessor(professor(87, "Panchal"));
  uni.addprofessor(professor(65, "Mahesh"));
  uni.addcourse(course(101, "DSA"));
  uni.loadData();

  while (true)
  {
    int choice;
    cout << "1. Admin\n2. Professor\n3. Student\n4. Exit\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      if (adminlogin())
        adminMenu(uni);
      else
        continue;
      break;
    case 2:
      if (proflogin())
        professormenu(uni);
      else
        continue;
      break;
    case 3:
      if (studentlogin())
        studentmenu(uni);
      else
        continue;
      break;
    case 4:
      exit(0);
    }
  }
  uni.saveData();

  // cout << " -- --UNIVERSITY_DATA-- --" << endl;
  // uni.showallstudents();
  // uni.showallprofessors();

  // uni.showallcourses();
  // uni.enrollStudentInCourse(1, 501);
  // uni.assignproftocourse(101, 501);

  // uni.showcoursesofstudents(1);
  // uni.showstudentsincourse(501);
  // uni.showprofessorofcourse(501);
}
//g++ *.cpp -o ums
//ums
