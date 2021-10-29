// #include "Ticket.cpp"

// #include <iostream>
// using namespace std;


// vector<Task> mockTasks() {
//   vector<Task> emptyTaskList;
//   Task first = Task("Pick bread", emptyTaskList);
//   Task second = Task("Pick topping ", emptyTaskList);
//   Task third = Task("Pick garnish", emptyTaskList);
//   Task fourth = Task("Heat under grill", emptyTaskList);
  
//   vector<Task> children;
//   children.push_back(second);
//   children.push_back(third);
//   children.push_back(fourth);

//   first.AddChild("Slice").AddChild("Choose thickness");
//   first.AddChild("Toast");
//   first.children[0].SetComplete();
//   first.children[0].children[0].SetComplete();
//   return *first;
// }


// int main() {
//   Ticket ticketA = new Ticket("Make Sandwich", mockTasks());
//   cout << "Welcome To The KanBan Board" << endl;
//   ticketA.DisplayTicket();
// }