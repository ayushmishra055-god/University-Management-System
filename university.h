#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include <vector>
#include "course.h"
#include "Professor.h"
#include "student.h"
// #include "university.h"
using namespace std;
class university
{
private:
public:
  vector<student> students;
  vector<professor> professors;
  vector<course> courses;
  void addstudent(student s);
  void addprofessor(professor p);
  void addcourse(course c);

  void saveData();
  void loadData();

  student *findStudent(int id);
  course *findCourse(int id);
  professor *findProfessor(int id);

  void showallstudents();
  void showallprofessors();
  void showallcourses();
  // student *findStudent(int id);
  // course *findCourse(int courseId);
  // professor *findProfessor(int id);
  void enrollStudentInCourse(int StudentId, int CourseId);
  void assignproftocourse(int courseId, int ProfId);
  void showcoursesofstudents(int studentId);
  void showstudentsincourse(int courseId);
  void showprofessorofcourse(int couseId);
  void assignstudentgrades(int studentId);
  void showgrades(int studentId);
  void editgradeofastudent(int studentId, int courseId, int x, int profId);
};
#endif