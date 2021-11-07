#include <iostream>
#include <map>

#include "Ticket.cpp"
#include "Column.cpp"
#include "Board.cpp"

using namespace std;

Task mockTasks() {
  vector<Task> emptyTaskList;
  Task first = Task("Pick bread", emptyTaskList);
  Task second = Task("Pick topping ", emptyTaskList);
  Task third = Task("Pick garnish", emptyTaskList);
  Task fourth = Task("Heat under grill", emptyTaskList);

  vector<Task> children;
  children.push_back(second);
  children.push_back(third);
  children.push_back(fourth);

  first.AddChild("Slice").AddChild("Choose thickness");
  first.AddChild("Toast");
  first.children[0].SetComplete();
  first.children[0].children[0].SetComplete();
  return first;
};

// Task mockTickets() {
//   Ticket *ticketA = new Ticket("Make Sandwich", a);
//   Ticket *ticketB = new Ticket("Eat Sandwich", a);
//   Ticket *ticketC = new Ticket("Throw away Sandwich", a);
//   Ticket *ticketD = new Ticket("Burn saerniw", a);

//   vector<Task> children;
//   children.push_back(second);
//   children.push_back(third);
//   children.push_back(fourth);

//   first.AddChild("Slice").AddChild("Choose thickness");
//   first.AddChild("Toast");
//   first.children[0].SetComplete();
//   first.children[0].children[0].SetComplete();
//   return first;
// };

int main() {
  vector<Task> a;
  a.push_back(mockTasks());

  Ticket ticketA = Ticket("Make Sandwich", a);
  Ticket ticketB = Ticket("Eat Sandwich", a);
  Ticket ticketC = Ticket("Throw away Sandwich", a);
  Ticket ticketD = Ticket("Burn saerniw", a);

  map<int, Ticket> tickets = map<int, Ticket>();
  tickets.insert({ticketA.ref, ticketA});
  tickets.insert({ticketB.ref, ticketB});
  tickets.insert({ticketC.ref, ticketC});
  tickets.insert({ticketD.ref, ticketD});
  
  Column todo = Column("To Do");

  todo.Insert(&tickets.at(ticketA.ref));
  todo.Insert(&tickets.at(ticketB.ref));

  Column inProgress = Column("In progress");
  inProgress.Insert(&tickets.at(ticketC.ref));

  Column done = Column("Done");
  done.Insert(&tickets.at(ticketD.ref));

  vector<Column> columns;
  columns.push_back(todo);
  columns.push_back(inProgress);
  columns.push_back(done);

  Board jazBoard = Board("Jaz's Kanban Board", tickets, columns);

  jazBoard.recordBlockingRelationship(ticketC.ref, ticketD.ref);
  jazBoard.recordBlockingRelationship(ticketA.ref, ticketC.ref);

  jazBoard.sorting();
  cout << "Welcome To The KanBan Board" << endl;
  //   ticketA->DisplayTicket();

  //   cout << "All tickets" << endl;

  //   todo.DisplayTickets();

  //   cout << "All tasks" << endl;

  //   todo.DisplayTicketsAndTasks();

  //    cout << "Delete a ticket" << endl;

  //    todo.DeleteTicket(3);

  //   cout << "All tickets" << endl;

  //   todo.DisplayTickets();
  //   todo.Insert(ticketD);
  //   todo.DisplayTickets();

  jazBoard.DisplayKanbanBoard();
};