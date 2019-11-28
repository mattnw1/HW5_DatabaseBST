#include <iostream>
#include <string>

// /*Michael Kulinich
// 2328386
// kulinich@chapman.edu
// Matthew Nwerem
// 2277158
// nwere100@mail.chapman.edu

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
