
template <class T>

class Queue {
private:
  // creates a dynamic array
  T *a;
  int rear;
  int front;
  int nItems;

public:
  Queue() {
    // initailzes the array size to a picked number (200)
    a = new T[200];
    rear = -1;
    front = 0;
    nItems = 0;
  }
  void push(T x) {
    if (rear == 200)
      rear = 0;
    else
      rear++;
    a[rear] = x;

    nItems++;
  }
  T pop() {
    T x = a[front];
    if (front == 200)
      front = 0;
    else
      front++;

    nItems--;

    return x;
  }
  bool isEmpty() {
    if (nItems == 0)
      return true;
    else
      return false;
  }
  int length() { return nItems; }
};