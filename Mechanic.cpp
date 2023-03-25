#include "Mechanic.h"

Mechanic::Mechanic() : Person() {
  counter = 0;
  apps = new Appointment[24];
}

void Mechanic::setCounter(int c) { counter = c; }
void Mechanic::setApps(Appointment *a) { apps = a; }

int Mechanic::getCounter() { return counter; }
Appointment *Mechanic::getApps() { return apps; }

bool Mechanic::isAvailable(Appointment ap) {
  for (int i = 0; i < counter; i++) {
    if (apps[i].hour == ap.hour && apps[i].min == ap.min) {
      return false;
    }
  }

  return true;
}

void Mechanic::addApp(int h, int m) {
  apps[counter].hour = h;
  apps[counter].min = m;
  counter++;
}

void Mechanic::printInfo() {
  Person::printInfo();
  cout << "Total number of appointments: " << counter << endl;
  for (int i = 0; i < counter; i++) {
    cout << apps[i].hour << " : " << apps[i].min << endl;
  }
  cout << endl;
}