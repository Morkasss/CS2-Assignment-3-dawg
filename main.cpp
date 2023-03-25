#include "Customer.h"
#include "Mechanic.h"
#include "Queue.h"
#include <fstream>

int main() {
  // opens the mechanics.txt file to read all of its data
  ifstream in("mechanics.txt");
  if (in.fail()) {
    cout << "failed to open file" << endl;
    return 0;
  }
  // reads the file for the number of mechanics that are in N
  int A;
  in >> A;
  // creates an array of object
  Mechanic *mech = new Mechanic[A];
  string name, id;
  int age;
  int M, h, m;
  // loops the mechnics one by one to read the names, ages, id's and appointments
  for (int i = 0; i < A; i++) {
    in >> name;
    mech[i].setName(name);
    in >> age;
    mech[i].setAge(age);
    in >> id;
    mech[i].setID(id);
    in >> M;
    for (int j = 0; j < M; j++) {
      in >> h;
      in >> m;
      mech[i].addApp(h, m);
    }
  }
  // closes the file
  in.close();
  // this prints all the mechanics information
  cout << "List of avvailable mechanics : " << endl;
  for (int i = 0; i < A; i++) {
    mech[i].printInfo();
  }
  cout << "------------------------" << endl;
  in.open("customers.txt");
  if (in.fail()) {
    cout << "failed to open file" << endl;
    return 0;
  }
  // Reads the number of customers
  int NCus;
  in >> NCus;
  // Creates an array of the customer object
  Customer *customers = new Customer[NCus];
  for (int i = 0; i < NCus; i++) {
    in >> name;
    customers[i].setName(name);
    in >> age;
    customers[i].setAge(age);
    in >> id;
    customers[i].setID(id);
    // Reads appointment data then assigns this to each customer
    in >> h;
    in >> m;
    Appointment app;
    app.hour = h;
    app.min = m;
    customers[i].setApp(app);
  }
  in.close();

  // Sorts the customers based on appointment time
  for (int i = 0; i < NCus - 1; i++) {
    for (int j = 0; j < NCus - 1; j++) {
      if (customers[j] > customers[j + 1]) {
        swap(customers[j], customers[j + 1]);
      }
    }
  }

  // These are to loop the customers and mechanics array and then put each in their own queue
  Queue<Customer> qCus;
  for (int i = 0; i < NCus; i++) {
    qCus.push(customers[i]);
  }

  Queue<Mechanic> qMec;
  for (int i = 0; i < A; i++) {
    qMec.push(mech[i]);
  }

  // loops the queue until it is empty
  cout << "Customers After Adding The Appointments : " << endl;
  while (!qCus.isEmpty()) {
    // reads the first customer to assign them to a new mechanic then loops on the mechanics queue until it finds the first available one
    Customer t = qCus.pop();
    for (int i = 0; i < qMec.length(); i++) {
      Mechanic c = qMec.pop();

      if (c.isAvailable(t.getApp())) {
        t.setMechanicID(c.getID());
        t.printInfo();
        qMec.push(c);
        break;
      }

      qMec.push(c);
    }
  }
}