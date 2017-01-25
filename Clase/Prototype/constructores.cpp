
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void pln(string in){
  cout << in << endl;
}

struct A {
  int x, y;
  /*
  A(int x = 0) : x(x){
    //Default constructor, default init
    cout << "Default constructor\n";
  }*/
  A() = default;
  explicit A(int x, int y) : x(x), y(y) {
    //Params constructor
    cout << "Params constructor\n";
  }
  A(const A& old){
    //Copy constructor
    pln("Copy constructor");
    //this->x = old.x;
    //this->y = old.y;
  }
  A(A&& a){
    pln("Move constructor");
  }

};

A llamaCopyConst(A a){
  A temp(a);
  return temp;
}

int main(){
  A b;

  A a = move(b);

  return 0;
}
