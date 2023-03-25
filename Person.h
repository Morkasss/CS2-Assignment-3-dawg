#pragma once
#include "Appointment.h"
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string name;
  string id;
  int age;

public:
  Person();

  void setName(string n);
  void setID(string n);
  void setAge(int a);

  string getName();
  string getID();
  int getAge();

  void printInfo();
};