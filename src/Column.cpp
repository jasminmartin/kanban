#include <string>

using namespace std;

class Column {
public:
  string columnName;
  Ticket *first;
  int length;

  Column(string columnName) {
    first = 0;
    this->columnName = columnName;
    this->length = 0;
  }

  bool IsEmpty() { return (first == 0); }

  void Insert(Ticket *newTicket) {
    newTicket->next = first;
    first = newTicket;
    this->length++;
  }

  Ticket *DeleteFirstTicket() {
    Ticket *temp = first;
    first = first->next;
    return temp;
  }

  Ticket *DeleteTicket(int key) {
    Ticket *current = first;
    Ticket *previous = first;

    while (current->ref != key) {
      if (current->next == 0) {
        return 0;
      } else {
        previous = current;
        current = current->next;
      }
    }
    if (current == first) {
      first = first->next;
      this->length--;
    } else {
      previous->next = current->next;
    }
    return current;
  }

  Ticket *Find(int key) {
    Ticket *current = first;
    while (current->ref != key) {
      if (current->next == 0) {
        return 0;
      } else {
        current = current->next;
      }
    }
    return current;
  }

  void DisplayTickets() {
    Ticket *current = first;
    while (current != 0) {
      current->DisplayTicket();
      cout << "" << endl;
      current = current->next;
    }
  }

  void DisplayTicketsAndTasks() {
    Ticket *current = first;
    while (current != 0) {
      current->DisplayTasks();
      current = current->next;
    }
  }

  string GetColumnName() { return columnName; }
};