#include <iostream>
using namespace std;

class Ticket {
    public:
    int reference;
    string title;
    string tasks;
    Ticket* next;

    Ticket(int reference, string title, string tasks) {
        this->reference= reference;
        this->title = title;
        this->tasks = tasks;
    }

    void DisplayTicket() {
        cout <<"Reference: " << this->reference << endl;
        cout <<"Title: " << this->title << endl;
        cout <<"Tasks: " << this->tasks << endl;

    }

    int getTicketKey() {
        return this->reference;
    }
};