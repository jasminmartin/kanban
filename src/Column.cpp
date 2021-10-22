#include "Ticket.cpp"

class Column {
public:
  string columName;
  Ticket *first;

  Column(string columName) {
    first = 0;
    this->columName = columName;
  }

  bool IsEmpty() { return (first == 0); }

  void Insert(Ticket *newTicket) {
    newTicket->next = first;
    first = newTicket;
  }

  Ticket *DeleteFirstTicket() {
    Ticket *temp = first;
    first = first->next;
    return temp;
  }

  Ticket *DeleteTicket(int key) {
    Ticket *current = first;
    Ticket *previous = first;

    while (current->reference != key) {
      if (current->next == 0) {
        return 0;
      } else {
        previous = current;
        current = current->next;
      }
    }
    if (current == first) {
      first = first->next;
    } else {
      previous->next = current->next;
    }
    return current;
  }

  Ticket *Find(int key) {
    Ticket *current = first;
    while (current->reference != key) {
      if (current->next == 0) {
        return 0;
      } else {
        current = current->next;
      }
    }
    return current;
  }

  void Display() {
    Ticket *current = first;
    while (current != 0) {
      current->DisplayTicket();
      current = current->next;
    }
  }

  string GetColumnName() {
      return columName;
  }
};