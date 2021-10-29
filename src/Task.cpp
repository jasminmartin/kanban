#include <iostream>
#include <vector>
#include <optional>

#include "TaskNotFoundException.cpp"

using namespace std;

enum TaskStatus { Complete, Partial, InComplete };

class Task {
public:
  string title;
  TaskStatus status;
  vector<Task> children;
  int ref;
  inline static int highest_ref = 0;
  TaskNotFoundException taskNotFound;

  Task(string title, vector<Task> children) {
    this->title = title;
    this->children = children;
    this->status = InComplete;
    this->ref = ++highest_ref;
  }

  void DisplayTree() { this->DisplayTree(0); }

  void DisplayTree(int depth) {
    for (int i = 0; i < depth; i++) {
      cout << "---";
    }
    cout << ", Reference: " << ref;
    cout << ", Title: " << this->title;
    cout << ", Status: " << this->getStatus(status) << endl;
    DisplayChildren(depth + 1);
  }

  void DisplayChildren(int depth) {
    for (int i = 0; i < this->children.size(); i++) {
      this->children[i].DisplayTree(depth);
    }
  }

  Task &AddChild(string name) {
    Task newTask = Task(name, vector<Task>());
    this->children.push_back(newTask);
    return this->children.back();
  }

  
  bool Delete(int ref) {
    for (int i = 0; i < this->children.size(); i++) {
      if (this->children[i].ref == ref) {
        cout << "Found task: " + this->title << endl;
        this->children.erase(this->children.begin() + i);
        return true;
      }
      if (this->children[i].Delete(ref)) {
        return true;
      }
    }
    return false;
  }

  optional<Task> RecFindChild(int ref) {
    if (this->ref == ref) {
      cout << "Found task: " + this->title << endl;
      return optional(*this);
    }

    for (int i = 0; i < this->children.size(); i++) {
      return this->children[i].RecFindChild(ref);
    }

    return {};
  }


  const char *getStatus(enum TaskStatus task) {
    switch (task) {
    case Complete:
      return "Complete";
    case Partial:
      return "Partial";
    case InComplete:
      return "InComplete";
    }
  }

  void SetComplete() { this->status = Complete; }

  void SetPartial() { this->status = InComplete; }

  void SetIncomplete() { this->status = InComplete; }
};

int main() {
  cout << "Task Tree Test" << endl;

  vector<Task> emptyTaskList;

  Task first = Task("First", emptyTaskList);

  Task second = Task("Second", emptyTaskList);
  Task third = Task("Third", emptyTaskList);
  Task fourth = Task("Fourth", emptyTaskList);

  vector<Task> children;
  children.push_back(second);
  children.push_back(third);
  children.push_back(fourth);

  cout<< children.size() << endl;
  children.erase(children.begin() + 1);
  cout<< children.size() << endl;

  Task fifth = Task("Fifth", children);

  first.AddChild("Foo").AddChild("Bar").AddChild("Baz");
  first.AddChild("Too");
  first.children[0].SetComplete();
  first.children[0].children[0].SetComplete();

  first.DisplayTree();

  auto deleted = first.Delete(6);
  if (deleted) {
    cout << "FOUND IT!" << endl;
  } else {
    cout << "Not there..." << endl;
  }
    first.DisplayTree();
};