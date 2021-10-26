#include <iostream>
#include <vector>

using namespace std;

enum Status { complete, partial, incomplete };


class Task {
    public:
    string title;
    Status status;
    vector<Task> children;


    Task(string title, vector<Task> children) {
        this->title = title;
        this->children = children;
        this->status = incomplete;
    }

    void DisplayTree() {
        this->DisplayTree(0);
    }

    void DisplayTree(int depth) {
        for (int i = 0; i < depth; i++) {
            cout << "-";
        }
        cout <<"Depth: " << depth;
        cout <<", Title: " << this->title;
        cout <<", Status: " << this->status << endl;
        DisplayChildren(depth + 1);
    }

    void DisplayChildren(int depth) {
        for(int i=0; i < this->children.size(); i++) {
            this->children[i].DisplayTree(depth);
        }
    }

    Task& AddChild(string name) {
        Task newTask = Task(name, vector<Task>());
        this->children.push_back(newTask);
        return this->children.back();
    }

    void SetComplete() {
        this->status= complete;
    }
    
    void SetPartial() {
        this->status= incomplete;
    }

    void SetIncomplete() {
        this->status= incomplete;
    }

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

  Task fifth = Task("Fifth", children);
  first.DisplayTree();
  fifth.DisplayTree();

   
    first.AddChild("Foo").AddChild("Bar").AddChild("Baz");
    first.AddChild("Bing");
    first.AddChild("Bang").AddChild("Bop");

    first.DisplayTree();
    cout << first.children[0].title << endl;
};