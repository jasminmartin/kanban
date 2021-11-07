#include <string>
#include <set>

using namespace std;

class Board {
public:
  map<int, Ticket> tickets;
  vector<Column> columns;
  string boardName;

  Board(string boardName, map<int, Ticket> tickets, vector<Column> columns) {
    this->boardName = boardName;
    this->tickets = tickets;
    this->columns = columns;
  }

  void AddColumn(string columnName) {
    Column *newColumn = new Column(columnName);
    this->columns.push_back(*newColumn);
  }

  int FindColumn(string columnName) {
    for (int i = 0; i < columns.size(); i++) {
      if (columns[i].GetColumnName() == columnName) {
        return i;
      } else
        return -1;
    }
  }

  void DeleteColumn(string *columnName) {
    int position = FindColumn(*columnName);
    if (position > 0) {
      columns.erase(columns.begin() + position);
    } else {
      cout << "Could delete column: " << columnName << endl;
    }
  }

  void recordBlockingRelationship(int blockedRef, int blockerRef) {   
    this->tickets.find(blockedRef)->second.blockers.push_back(blockerRef);
  }

  void visit(vector<Ticket*> &sorted, set<int> &seen, int ref) {
    auto blockers = this->tickets.at(ref).blockers;
  
    if (blockers.size() >= 1) {
        for(auto it = blockers.begin(); it != blockers.end(); it++) {   
            visit(sorted, seen, *it);
        }
    } 

    if (seen.find(ref) == seen.end()) {
        seen.insert(ref);
        sorted.push_back(&this->tickets.at(ref));
    } 
  }

  void sorting() {
    auto sorted =  vector<Ticket*>();
    auto seen = set<int>();

    for (auto it = tickets.begin(); it != tickets.end(); it++) {
        if (seen.find(it->first) == seen.end()) {
            visit(sorted, seen, it->first);
        }
    } 
    
    for (auto it = sorted.begin(); it != sorted.end(); it++) {
        (*it)->DisplayTicket();
        cout << endl;
    }
  }

  void DisplayKanbanBoard() {
    for (int i = 0; i < columns.size(); i++) {
      cout << columns[i].GetColumnName() << "                   ";
    }
  }
};