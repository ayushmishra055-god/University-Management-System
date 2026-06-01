#include "university.h"
#include <fstream>
#include <sstream>

using namespace std;
void university::addstudent(student s)
{
  students.push_back(s);
}
void university::addprofessor(professor p)
{
  professors.push_back(p);
}
void university::addcourse(course c)
{
  courses.push_back(c);
}
void university::showallstudents()
{
  cout << "Students: " << endl;
  for (auto &s : students)
  {
    cout << "ID: " << s.getId() << "  " << "Name: " << s.getName() << endl;
  }
}
void university::showallprofessors()
{
  cout << "Professors: " << endl;
  for (auto &s : professors)
  {
    cout << "ID: " << s.getId() << "  " << "Name: " << s.getName() << endl;
  }
}
void university::showallcourses()
{
  cout << "Courses : " << endl;
  for (auto &s : courses)
  {
    cout << "ID: " << s.getId() << "  " << "Name: " << s.getTitle() << endl;
  }
}
void university::enrollStudentInCourse(int studentId, int courseId)
{
  student *s = findStudent(studentId);
  course *c = findCourse(courseId);

  if (!s || !c)
  {
    cout << "Invalid student or course ID\n";
    return;
  }
  for (int i = 0; i < s->registeredcourseIds.size(); i++)
  {
    if (courseId == s->registeredcourseIds[i])
    {
      cout << "Student already enrolled in the course!!" << endl;
      return;
    }
  }

  s->enrollcourse(courseId);
  c->addStudent(studentId);
}
void university::assignproftocourse(int courseId, int ProfId)
{
  course *c = findCourse(courseId);
  professor *p = findProfessor(ProfId);

  if (!c || !p)
  {
    cout << "Invalid" << endl;
    return;
  }
  c->assignProfessor(ProfId);
}
void university::showcoursesofstudents(int studentId)
{
  student *s = findStudent(studentId);
  if (!s)
  {
    cout << "Student ID is invalid" << endl;
    return;
  }
  cout << "Registered Courses are " << endl;
  for (int i = 0; i < s->registeredcourseIds.size(); i++)
  {
    cout << s->registeredcourseIds[i] << endl;
  }
}
student *university::findStudent(int Id)
{
  for (auto &s : students)
  {
    if (s.getId() == Id)
      return &s;
  }
  return nullptr;
}
course *university::findCourse(int courseId)
{
  for (auto &c : courses)
  {
    if (c.getId() == courseId)
    {
      return &c;
    }
  }
  return nullptr;
}
professor *university::findProfessor(int id)
{
  for (auto &p : professors)
  {
    if (p.getId() == id)
      return &p;
  }
  return nullptr;
}
void university::showstudentsincourse(int courseId)
{
  course *c = findCourse(courseId);
  if (!c)
  {
    cout << "Invalid CourseId" << endl;
    return;
  }
  cout << "StudentIds are" << endl;
  for (int i = 0; i < c->enrolledStudentIds.size(); i++)
  {
    cout << c->enrolledStudentIds[i] << endl;
  }
}
void university::showprofessorofcourse(int courseId)
{
  course *c = findCourse(courseId);
  if (!c)
  {
    cout << "Invalid CourseId";
    return;
  }
  cout << "ProfessorId is   " << c->professorId << endl;
}
void university::assignstudentgrades(int studentId)
{
  student *s = findStudent(studentId);
  if (!s)
  {
    cout << "Student ID is invalid" << endl;
    return;
  }
  cout << "Enter grades for respective courses " << endl;
  for (int i = 0; i < s->registeredcourseIds.size(); i++)
  {
    int grades = 0;
    cout << s->registeredcourseIds[i] << "  ";
    cin >> grades;
    s->grade[s->registeredcourseIds[i]] = grades;
  }
  //   if (course->getProfessor() != professorId) {
  //     cout << "Access denied: Professor not assigned to this course\n";
  //     return;
  // }
}
void university::showgrades(int studentId)
{
  student *s = findStudent(studentId);
  if (!s)
  {
    cout << "Student ID is invalid" << endl;
    return;
  }
  cout << "Grades for student with studentId" << s->getId() << "are as follows  " << endl;
  for (int i = 0; i < s->registeredcourseIds.size(); i++)
  {
    cout << s->registeredcourseIds[i] << " : " << s->grade[s->registeredcourseIds[i]] << endl;
  }
}
void university::editgradeofastudent(int studentId, int CourseId, int x, int profId)
{
  student *s = findStudent(studentId);
  professor *p = findProfessor(profId);
  course *c = findCourse(CourseId);
  if (!s)
  {
    cout << "Student ID is invalid" << endl;
    return;
  }
  if (!c)
  {
    cout << "Course Id is invalid" << endl;
    return;
  }
  if (!p)
  {
    cout << "Prof Id is invalid" << endl;
    return;
  }
  if (c->professorId != profId)
  {
    cout << "Invalid Prof Id...Access denied" << endl;
    return;
  }

  bool yes = false;
  int i = 0;
  for (; i < s->registeredcourseIds.size(); i++)
  {
    if (CourseId == s->registeredcourseIds[i])
      yes = true;
    return;
  }
  if (!yes)
  {
    cout << "This courseId is not registered with this student" << endl;
    return;
  }
  cout << "Enter the grade outof 100 : ";
  cin >> x;

  if (x < 0 || x > 100)
  {
    cout << "Invalid grade" << endl;
    return;
  }
  s->grade[s->registeredcourseIds[i] = x];
  cout << "Grade assigned successfully";
}
void university::saveData()
{
  ofstream fs("student.txt");
  for (auto &s : students)
  {
    fs << s.getId() << " " << s.getName() << endl;
    for (int i = 0; i < s.registeredcourseIds.size(); i++)
      fs << s.registeredcourseIds[i] << endl;
  }
  fs.close();
  ofstream fp("professor.txt");
  for (auto &p : professors)
    fp << p.getId() << " " << p.getName() << endl;

  fp.close();
  // ofstream fp("professors.txt");
  // for (auto &p : professors)
  //   fp << p.getId() << " " << p.getName() << endl;
  // fp.close();

  ofstream fc("course.txt");
  for (auto &c : courses)
  {
    fc << c.getId() << " " << c.getTitle() << " " << c.professorId;
    for (int sid : c.enrolledStudentIds)
      fc << " " << sid;
    fc << endl;
  }
  fc.close();
}
void university::loadData()
{
  {
    ifstream fs("student.txt");
    if (fs)
    {
      int id;
      string name;
      while (fs >> id >> name)
      {
        student s(id, name);
        string line;
        getline(fs, line);
        stringstream ss(line);
        int cid;
        while (ss >> cid)
          s.enrollcourse(cid);
        students.push_back(s);
      }
    }
    fs.close();
  }
  ifstream fp("professor.txt");
  if (fp)
  {
    int id;
    string name;
    while (fp >> id >> name)
      professors.push_back(professor(id, name));
  }
  fp.close();
  ifstream fc("courses.txt");
  if (fc)
  {
    int id, profId;
    string name;
    while (fc >> id >> name >> profId)
    {
      course c(id, name);
      c.assignProfessor(profId);
      string line;
      getline(fc, line);
      stringstream ss(line);
      int sid;
      while (ss >> sid)
        c.addStudent(sid);
      courses.push_back(c);
    }
  }
  fc.close();
}