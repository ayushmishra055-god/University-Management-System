#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
using namespace std;
class professor
{
private:
  int professorId;
  string name;

public:
  professor(int id, string name);
  int getId() const;
  string getName() const;
  
};
#endif