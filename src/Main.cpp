#include "Column.cpp"

#include <iostream>
using namespace std;

int main() {
  Column *todo = new Column("To Do");
  todo->Insert(new Ticket(1,"Finish DSA","a"));
  todo->Insert(new Ticket(2,"Graduate","b"));

  Column *progress = new Column("In Progress");
  progress->Insert(new Ticket(1,"Allocate grade","c"));
  progress->Insert(new Ticket(2,"Mark report","d"));

  Column *done = new Column("Done");
  done->Insert(new Ticket(1,"Make Kanban board","e"));
  done->Insert(new Ticket(2,"Write report","f"));

  cout << "Welcome To The KanBan Board" << endl;

}