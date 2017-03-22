#include<iostream>

using namespace std;

class Visitor;
class Number {
protected:
  string qnSoy;
public:
  string getQnSoy() { return qnSoy; }
  virtual void accept(Visitor*) = 0;
};

class Integer : public Number {
public:
  Integer() {
    qnSoy = "Integer";
  }
  static int countInts;
  void accept(Visitor*);
};

int Integer::countInts = 0;

class Double : public Number {
public:
  Double() {
    qnSoy = "Double";
  }
  static int countDouble;
  void accept(Visitor*);
};

int Double::countDouble = 0;

class Visitor {
public:
  virtual void visit(Integer*) = 0;
  virtual void visit(Double*) = 0;

  template <class T>
  static Visitor* getInstance(){
    static T instance;
    return &instance;
  }
};

class CountVisitor : public Visitor {
  friend class Visitor;
private:
  CountVisitor(){}
public:

  void visit(Integer* i) {
    cout << Integer::countInts << endl;
  }

  void visit(Double* i) {
    cout << Double::countDouble << endl;
  }
};

class AddVisitor : public Visitor {
  friend class Visitor;
private:
  AddVisitor(){}
public:

  void visit(Integer* i) {
    Integer::countInts++;
  }
  void visit(Double* i) {
    Double::countDouble++;
  }
};

class SubstractVisitor : public Visitor {
  friend class Visitor;
private:
  SubstractVisitor(){}
public:

  void visit(Integer* i) {
    Integer::countInts--;
  }
  void visit(Double* i) {
    Double::countDouble--;
  }
};

class PresentacionVisitor : public Visitor {
  friend class Visitor;
private:
  PresentacionVisitor(){}
public:

  void visit(Integer* i) {
    cout << "I am " << i->getQnSoy() << endl;
  }
  void visit(Double* i) {
    cout << "I am " << i->getQnSoy() << endl;
  }
};

void Double::accept(Visitor* v) {
  v->visit(this);
}

void Integer::accept(Visitor* v) {
  v->visit(this);
}

int main() {
  Visitor* a = Visitor::getInstance<AddVisitor>();
  Visitor* c = Visitor::getInstance<CountVisitor>();
  Visitor* s = Visitor::getInstance<SubstractVisitor>();
  Visitor* p = Visitor::getInstance<PresentacionVisitor>();

  Number* n[] ={new Integer, new Double};

  for(int i=0; i< 5; i++) {
    for (int j = 0; j < 2; j++) {
      n[j]->accept(a);
    }
  }

  n[1]->accept(c);
  n[0]->accept(c);

  n[0]->accept(s);
  n[0]->accept(c);

  n[0]->accept(p);
  n[1]->accept(p);
}
