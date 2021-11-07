#include <iostream>
#include <map>
#include "Ticket.cpp"
#include "Column.cpp"
#include "Board.cpp"

using namespace std;

Task mockTasks() {
  // Creating tasks
  vector<Task> emptyTaskList;
  Task first = Task("Pick bread", emptyTaskList);
  Task second = Task("Pick topping ", emptyTaskList);
  Task third = Task("Pick garnish", emptyTaskList);
  Task fourth = Task("Heat under grill", emptyTaskList);

  // Adding tasks to a vector
  vector<Task> children;
  children.push_back(second);
  children.push_back(third);
  children.push_back(fourth);

  // Inserting sub-tasks to tasks
  first.AddChild("Slice").AddChild("Choose thickness");
  first.AddChild("Toast");
  first.AddChild("Butter");

  // Completing tasks and sub-tasks
  first.children[0].SetComplete();
  first.children[0].children[0].SetComplete();

  // Display tree
  cout << "\n ************** Example task tree **************" << endl;
  first.DisplayTree();

  // Demonstrating delete a task
  cout << "\n ************** Example deleting a task **************" << endl;
  first.Delete(5);
  first.DisplayTree();

  // Inserting a task
  cout << "\n ************** Example inserting a task **************" << endl;
  first.AddChild("Butter");
  first.DisplayTree();

  return first;
};

int main() {
  // Adding the task tree to a vector
  vector<Task> tasktree;
  tasktree.push_back(mockTasks());

  // Creating tickets
  Ticket ticketA = Ticket("Make Sandwich", tasktree);
  Ticket ticketB = Ticket("Eat Sandwich", tasktree);
  Ticket ticketC = Ticket("Throw away Sandwich", tasktree);
  Ticket ticketD = Ticket("Burn Sarnie", tasktree);

  // Display a ticket
  cout << "\n ************** Example ticket **************" << endl;
  ticketA.DisplayTicket();

  cout << "\n ************** Example task tree **************" << endl;
  ticketA.DisplayTasks();

  // Adding the tickets to the map for the the graph
  map<int, Ticket> tickets = map<int, Ticket>();
  tickets.insert({ticketA.ref, ticketA});
  tickets.insert({ticketB.ref, ticketB});
  tickets.insert({ticketC.ref, ticketC});
  tickets.insert({ticketD.ref, ticketD});

  // Creating a column and inserting tickets
  Column todo = Column("To Do");
  todo.Insert(&tickets.at(ticketA.ref));
  todo.Insert(&tickets.at(ticketB.ref));

  cout << "\n ************** Example column **************" << endl;
  todo.GetColumnName();
  todo.DisplayTickets();

  cout << "\n ************** Example Deleting a Ticket **************" << endl;
  todo.DeleteTicket(2);
  todo.DisplayTickets();

  cout << "\n ************** Example Inserting a Ticket **************" << endl;
  todo.Insert(&tickets.at(ticketB.ref));
  todo.DisplayTickets();

  // Creating a column and inserting tickets
  Column inProgress = Column("In Progress");
  inProgress.Insert(&tickets.at(ticketC.ref));

  // Creating a column and inserting tickets
  Column done = Column("Done");
  done.Insert(&tickets.at(ticketD.ref));

  // Adding columns to a vector
  vector<Column> columns;
  columns.push_back(todo);
  columns.push_back(inProgress);
  columns.push_back(done);

  // Adding the vector of columns and tickets to the board
  Board jazBoard = Board("Jaz's Kanban Board", tickets, columns);

  // Creating relationships between tickets
  cout << "\n ************** Creating ticket relationships **************" << endl;
  jazBoard.recordBlockingRelationship(ticketC.ref, ticketD.ref);
  jazBoard.recordBlockingRelationship(ticketA.ref, ticketC.ref);
  jazBoard.recordBlockingRelationship(ticketB.ref, ticketD.ref);

  // Sorting the relationships
  cout << "\n ************** The order the tickets must be completed in due to blockers **************" << endl;
  jazBoard.sorting();
};