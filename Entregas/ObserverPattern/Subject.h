//
// Created by franspaco on 8/03/17.
//

#ifndef OBSERVERPATTERN_SUBJECT_H
#define OBSERVERPATTERN_SUBJECT_H


#include <vector>
#include <string>

class Observer;

class Subject {
protected:
    std::vector<Observer*> obs;
    std::string name;
    std::string state;

    void notifyAll();

public:
    std::string getName();

    void updateState(std::string input);

    void attach(Observer* input);
};


#endif //OBSERVERPATTERN_SUBJECT_H
