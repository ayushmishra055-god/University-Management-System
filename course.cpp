#include "course.h"
#include "student.h"
#include "university.h"
using namespace std;
course::course(int id, string title)
{
  this->courseId = id;
  this->title = title;
}
int course::getId() const
{
  return courseId;
}
string course::getTitle() const
{
  return title;
}
void course::assignProfessor(int id)
{
  professorId = id;
}
void course::addStudent(int studentId)
{
  enrolledStudentIds.push_back(studentId);
}

