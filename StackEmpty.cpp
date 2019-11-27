#include <iostream>
#include <string>

using namespace std;

class StackEmpty {

public:
   StackEmpty(const string& msg) : msg_(msg) {}
  ~StackEmpty() {}

   string getMessage() const {return(msg_);}
private:
   string msg_;
};

// void f() {
//    throw(StackEmpty("Mr. Sulu"));
// }

// int main() {
//
//    try {
//       f();
//    }
//    catch(StackEmpty& e) {
//       cout << "You threw an StackEmpty: " << e.getMessage() << endl;
//    }
// }
