#ifndef COURSE_H
#define COURSE_H
#include "student.h"
#include <string>
#include <vector>
using namespace std;
class course
{
private:
  /* data */

public:
  int courseId;
  int professorId;
  string title;
  vector<int> enrolledStudentIds;
  course(int id, string title);
  int getId() const;
  string getTitle() const;
  void assignProfessor(int id);
  void addStudent(int studentId);
  // student* findStudent(int Id);
  
};
#endif