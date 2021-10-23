#include <iostream>
using namespace std;

enum Status { complete, partial, incomplete };


class Task {
    public:
    string title;
    Status status;
    size_t numberOfChildren;
    Task** children;


    Task(string title, Task** children, size_t numberOfChildren) {
        this->title = title;
        this->children = children;
        this->status = incomplete;
        this->numberOfChildren=numberOfChildren;
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
        for(int i=0; i < numberOfChildren; i++) {
            this->children[i]->DisplayTree(depth);
        }
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

  Task* emptyTaskList[] = {};
   
  Task first = Task("First", emptyTaskList, 0);

//   Task* second = new Task("Second", emptyTaskList, 0);
//   Task* third = new Task("Third", emptyTaskList, 0);
//   Task* fourth = new Task("Fourth", emptyTaskList, 0);

//   Task* childArray[] = {second, third, fourth};

//   Task("Fifth", childArray, 3).DisplayTree();

    first.DisplayTree();

    //TODO: switch to std::vector for children (to allow add/remove)
    //first.addChild(new Task("foo", emptyTaskList, 0));

    first.DisplayTree();
};