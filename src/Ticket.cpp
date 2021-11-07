#include <iostream>

#include "Task.cpp"

using namespace std;

class Ticket {
public:
  vector<Task> tasks;
  string title;
  Ticket *next;
  int ref;
  inline static int highest_ref = 0;
  vector<int> blockers; 

  Ticket(string title, vector<Task> tasks) : blockers(){
    this->title = title;
    this->tasks = tasks;
    this->ref = ++highest_ref;
    this->blockers = vector<int>();
  }

  void DisplayTicket() {
    cout << this->ref << ": " << this->title ;
  }

  void DisplayTasks() {
    cout << "Reference: " << this->ref << endl;
    cout << "Title: " << this->title << endl;
    for (int i = 0; i < this->tasks.size(); i++) {
      this->tasks[i].DisplayTree();
    }
  }

  int getTicketReference() { return this->ref; }

  bool operator!=(const Ticket &rhd) {
    if (this->ref != rhd.ref) {
      return true;
    } else
      return false;
  }
  bool operator<(const Ticket &rhd) {
    if (this->ref < rhd.ref) {
      return true;
    } else
      return false;
  }
  bool operator==(const Ticket &rhd) {
    if (this->ref == rhd.ref) {
      return true;
    } else
      return false;
  }
  bool operator>(const Ticket &rhd) {
    if (this->ref > rhd.ref) {
      return true;
    } else
      return false;
  }
};