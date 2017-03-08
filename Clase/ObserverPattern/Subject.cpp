//
// Created by franspaco on 8/03/17.
//

#include "Subject.h"
#include "Observer.h"

void Subject::notifyAll(){
    for(Observer* a : obs){
        a->notify(this, state);
    }
}

void Subject::updateState(std::string input){
    state = input;
    notifyAll();
}

void Subject::attach(Observer* input){
    obs.push_back(input);
}
