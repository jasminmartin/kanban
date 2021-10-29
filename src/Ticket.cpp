#include <iostream>

#include "Task.cpp"

using namespace std;

class Ticket {
public:
  vector<Task> tasks;
  int reference;
  string title;
  Ticket *next;
  int ref;
  inline static int highest_ref = 0;

  Ticket(string title, vector<Task> tasks) {
    this->reference = reference;
    this->title = title;
    this->tasks = tasks;
    this->ref = ++highest_ref;
  }

  void DisplayTicket() {
    cout << "Reference: " << this->reference << endl;
    cout << "Title: " << this->title << endl;
    DisplayTasks();
  }

  void DisplayTasks() {
    for (int i = 0; i < this->tasks.size(); i++) {
      this->tasks[i].DisplayTree();
    }
  }

  int getTicketReference() { return this->reference; }

  bool operator!=(const Ticket &rhd) {
    if (this->reference != rhd.reference) {
      return true;
    } else
      return false;
  }
  bool operator<(const Ticket &rhd) {
    if (this->reference < rhd.reference) {
      return true;
    } else
      return false;
  }
  bool operator==(const Ticket &rhd) {
    if (this->reference == rhd.reference) {
      return true;
    } else
      return false;
  }
  bool operator>(const Ticket &rhd) {
    if (this->reference > rhd.reference) {
      return true;
    } else
      return false;
  }
};