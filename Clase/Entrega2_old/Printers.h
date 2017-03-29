//
// Created by franspaco on 29/03/17.
//

#ifndef ENTREGA2_PRINTERS_H
#define ENTREGA2_PRINTERS_H

#include <iostream>
#include <string>

class PV;
class Documents;

using namespace std;

class Printers{
protected:
    string name;

public:
    virtual void accept(PV*, Documents* d) = 0;
    string getName() { return name; }
};

class Laser : public Printers {
public:
    void accept(PV* pv, Documents* d);
};

class Injection : public Printers {
public:
    void accept(PV* pv, Documents* d);
};

class PDF : public Printers {
public:
    void accept(PV* pv, Documents* d);
};

class Postscript : public Printers {
public:
    void accept(PV* pv, Documents* d);
};

#include "PV.h"

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

#endif //ENTREGA2_PRINTERS_H
