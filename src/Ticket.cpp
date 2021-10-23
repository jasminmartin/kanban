#include <iostream>
#include "DependencyGraph.cpp"
using namespace std;

class Ticket {
    public:
    int reference;
    string title;
    Ticket* next;
    float x;
    float y; 

    Ticket(int reference, string title, string tasks) {
        this->reference= reference;
        this->title = title;
        this->tasks = tasks;
        x=0;
        y=0;
    }

    void DisplayTicket() {
        cout <<"Reference: " << this->reference << endl;
        cout <<"Title: " << this->title << endl;
        cout <<"Tasks: " << this->tasks << endl;

    }

    int getTicketReference() {
        return this->reference;
    }

  bool operator!=(const Ticket &rhd) {
      if(this->reference != rhd.reference) {
          return true;
      } else return false;
  }
  bool operator<(const Ticket &rhd) {
          if(this->reference < rhd.reference) {
          return true;
      } else return false;
  }
  bool operator==(const Ticket &rhd) {
          if(this->reference == rhd.reference) {
          return true;
      } else return false;
  }
  bool operator>(const Ticket &rhd) {
          if(this->reference > rhd.reference) {
          return true;
      } else return false;
  }
};