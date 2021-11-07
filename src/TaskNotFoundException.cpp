#include <exception>
#include <string>

using namespace std;
class TaskNotFoundException : public exception {

public:
 virtual const char *what() const throw() {
    return "Did not find task: ";
};
};