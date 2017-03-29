/*
 * Francisco Huelsz Prince
 * A01019512
 *
 * README:
 * New documents should be added on NewDocuments.h
 * New printers should be added on lines:
 *  - 70
 *  - 140
 *  - 93
 *  - 198
 * (Or otherwise indicated by a line of "####### . . . ")
 *
 * Compilation line:
 * g++ -o test1 main.cpp -std=c++11
 */


#include <iostream>
#include <string>

class PV;
class Documents;

using namespace std;


// PRINTERS PARENT CLASS *******************************************************
class Printers{
protected:
    string name;

public:
    virtual void accept(PV*, Documents* d) = 0;
    string getName() { return name; }
};

class Laser : public Printers {
public:
  Laser(){
    name = "Laser";
  }
    void accept(PV* pv, Documents* d);
};

class Injection : public Printers {
public:
  Injection(){
    name = "Injection";
  }
    void accept(PV* pv, Documents* d);
};

class PDF : public Printers {
public:
  PDF(){
    name = "PDF";
  }
    void accept(PV* pv, Documents* d);
};

class Postscript : public Printers {
public:
  Postscript(){
    name = "Postscript";
  }
    void accept(PV* pv, Documents* d);
};

// #############################################################################
// ********************!  ADD NEW PRINTERS HERE !*******************************
// Printers must implement a constructor to set their name and the
// method void accept(PV* pv, Documents* d);

class Portable : public Printers {
public:
  Portable(){
    name = "Portable";
  }
  void accept(PV* pv, Documents* d);
};

// *****************************************************************************

// Printer Visitor
class PV {
public:
    virtual void visit(Laser* p, Documents * d) = 0;
    virtual void visit(Injection* p, Documents * d) = 0;
    virtual void visit(PDF* p, Documents * d) = 0;
    virtual void visit(Postscript* p, Documents * d) = 0;

// #############################################################################
// ***********************! ADD NEW PRINTERS HERE !*****************************
// e.g.: virtual void visit(<NAME>* p, Documents* d) = 0;

    virtual void visit(Portable* p, Documents* d) = 0;

// *****************************************************************************

    template <class T>
    static PV* getInstance(){
        static T instance;
        return &instance;
    }
};


class Documents{
protected:
    string name;
public:
    void printOn(Printers* p);
    string getName(){ return name; }
};

// Printing Visitor
class PrintV : public PV {
    friend class PV;
private:
    PrintV(){}

public:
    void visit(Laser* p, Documents* d){
        cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(Injection* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(PDF* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(Postscript* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

// #############################################################################
// ***************************  ADD NEW PRINTERS HERE **************************
// e.g. void visit(<NAME>* p, Documents* d) { /* . . . */ }

    void visit(Portable* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }
// *****************************************************************************
};

// Generic accept
//  Placed here for simplicity of adding new document types
//  since it only requires info from the parent class.
//  Should a printer require specific parts from a child of Documents
//  this should not be used, and implemented in the children instead.
void Documents::printOn(Printers* p){
  p->accept(PV::getInstance<PrintV>(), this);
}

class SimpleText : public Documents {
public:
  SimpleText(){
    name = "SimpleText";
  }
};

class FormatText : public Documents {
public:
  FormatText(){
    name = "FormatText";
  }
};

class Image : public Documents {
public:
  Image(){
    name = "Image";
  }
};

#include "NewDocuments.h"

void Laser::accept(PV* pv, Documents* d) {
  pv->visit(this, d);
}

void Injection::accept(PV* pv, Documents* d) {
  pv->visit(this, d);
}

void PDF::accept(PV* pv, Documents* d) {
  pv->visit(this, d);
}

void Postscript::accept(PV* pv, Documents* d) {
  pv->visit(this, d);
}

// #############################################################################
// ***************************  ADD NEW PRINTERS HERE **************************
// e.g.:
//  void <NAME>::accept(PV* pv, Documents* d) {
//    pv->visit(this, d);
//  }
void Portable::accept(PV* pv, Documents* d) {
  pv->visit(this, d);
}
// *****************************************************************************

class Main {
public:
    void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters){
        for(int i = 0; i < countDocs; i++){
            for(int j = 0; j < countPrinters; j++){
                d[i]->printOn(p[j]);
            }
        }
    }
};

int main() {
  int docSize = 5;
  int prtSize = 5;
    Main m;
    Documents ** d = new Documents*[docSize];
    Printers ** p = new Printers*[prtSize];

    d[0] = new SimpleText();
    d[1] = new FormatText();
    d[2] = new Image();
    d[3] = new Poster();
    d[4] = new Flyer();

    p[0] = new Laser();
    p[1] = new PDF();
    p[2] = new Postscript();
    p[3] = new Portable();
    p[4] = new Injection();

    m.printAllDocuments(d, docSize, p, prtSize);

    for(int i = 0; i<docSize; i++){
      delete d[i];
    }
    for(int i = 0; i<prtSize; i++){
      delete p[i];
    }

    delete[] d;
    delete[] p;

    return 0;
}
