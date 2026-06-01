#include "student.h"
#include "course.h"
#include "university.h"
using namespace std;
student::student(int id, string name)
{
  this->StudentId = id;
  this->name = name;
}
int student::getId() const { return StudentId; }
string student::getName() const { return name; }

void student::dropCourse(int courseId)
{
  // later
}


void student::enrollcourse(int id)
{
  registeredcourseIds.push_back(id);
}
