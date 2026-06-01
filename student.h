#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
class student
{
private:
  /* data */
  string name;
  int StudentId;

public:
  vector<int> registeredcourseIds;
  unordered_map<int,int> grade;//grading
  student(int id, string name);

  int getId() const;
  string getName() const;

  void registeredCourse(int courseId);
  void dropCourse(int courseId);
  
  void enrollcourse(int id);
  void assigngrades(student* s,int courseIds[],int grade);
};
#endif 