//
// Created by franspaco on 8/03/17.
//

#ifndef OBSERVERPATTERN_OBSERVER_H
#define OBSERVERPATTERN_OBSERVER_H


#include <map>
#include <iostream>
#include <typeinfo>
#include "Subject.h"

class Subject;

class Observer {
protected:
    std::map<Subject*, std::string> observees;
public:
    void attach(Subject* newPtr);

    void notify(Subject* obs, std::string inpt);

    std::string getStatus(Subject* in);
};


#endif //OBSERVERPATTERN_OBSERVER_H
