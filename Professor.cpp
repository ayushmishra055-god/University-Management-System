#include "Professor.h"
#include "university.h"
using namespace std;
professor::professor(int id, string name)
{
  this->professorId = id;
  this->name = name;
}
int professor::getId() const
{
  return professorId;
}
string professor::getName() const
{
  return name;
}
