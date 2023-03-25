#include "Person.h"

class Mechanic : public Person {
private:
  int counter;
  Appointment *apps;

public:
  Mechanic();

  void setCounter(int c);
  void setApps(Appointment *n);

  int getCounter();
  Appointment *getApps();

  bool isAvailable(Appointment ap);
  void addApp(int k, int c);

  void printInfo();
};