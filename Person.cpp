#include "Person.h"

Person::Person() {
  name = "";
  id = "";
  age=0;
}

void Person::setName(string n) { name = n; }
void Person::setID(string i) { id = i; }
void Person::setAge(int a) { age = a; }

string Person::getName() { return name; }
string Person::getID() { return id; }
int Person::getAge() { return age; }

void Person::printInfo() {
  cout << "Name : " << name << endl;
  cout << "ID   : " << id << endl;
  cout << "Age  : " << age << endl;
}