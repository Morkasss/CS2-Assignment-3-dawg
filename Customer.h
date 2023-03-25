#include "Person.h"

class Customer : public Person {
private:
  string mechanicID;
  Appointment appointment;

public:
  Customer();

  string getMechanicID();
  Appointment getApp();

  void setMechanicID(string n);
  void setApp(Appointment app);

  // operator overloading
  bool operator==(Customer &c);
  bool operator>(Customer &c);
  bool operator<(Customer &c);

  void printInfo();
};