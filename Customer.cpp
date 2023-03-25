#include "Customer.h"

Customer::Customer() : Person() {
  mechanicID = "";
  appointment.hour = 0;
  appointment.min = 0;
}

string Customer::getMechanicID() { return mechanicID; }
Appointment Customer::getApp() { return appointment; }

void Customer::setMechanicID(string n) { mechanicID = n; }
void Customer::setApp(Appointment app) { appointment = app; }

bool Customer::operator==(Customer &c) {
  if (appointment.hour == c.appointment.hour &&
      appointment.min == c.appointment.min)
    return true;
  else
    return false;
}

bool Customer::operator>(Customer &c) {
  if (appointment.hour > c.appointment.hour)
    return true;
  else if (appointment.hour < c.appointment.hour)
    return false;
  else {
    if (appointment.min > c.appointment.min)
      return true;
    else
      return false;
  }
}

bool Customer::operator<(Customer &c) {
  if (appointment.hour < c.appointment.hour)
    return true;
  else if (appointment.hour > c.appointment.hour)
    return false;
  else {
    if (appointment.min < c.appointment.min)
      return true;
    else
      return false;
  }
}

void Customer::printInfo() {
  Person::printInfo();

  cout << "Mechanic ID appointed: " << mechanicID << " at " << appointment.hour << ":" << appointment.min<<endl;
}