//
// Created by franspaco on 29/03/17.
//

#ifndef ENTREGA2_DOCUMENTS_H
#define ENTREGA2_DOCUMENTS_H

#include <iostream>
#include <string>
#include "PV.h"
#include "Printers.h"

using namespace std;

class Documents{
protected:
    string name;
public:
    virtual void printOn(Printers* p) = 0;
    string getName(){ return name; }
};


class SimpleText : public Documents {
public:
    void printOn(Printers* p){
        p->accept(PV::getInstance<PrintV>(), this);
    }
};

class FormatText : public Documents {
public:
    void printOn(Printers* p){
        p->accept(PV::getInstance<PrintV>(), this);
    }
};

class Image : public Documents {
public:
    void printOn(Printers* p){
        p->accept(PV::getInstance<PrintV>(), this);
    }
};

#endif //ENTREGA2_DOCUMENTS_H
