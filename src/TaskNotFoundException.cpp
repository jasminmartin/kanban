#include <exception>
#include <string>

using namespace std;
class TaskNotFoundException : public exception {
// public:
//   int ref;

//   TaskNotFoundException(int r) : ref(r) {}
public:
 virtual const char *what() const throw() {
    return "Did not find task: "; // + std::to_string(1);
  };
};