//
// Created by franspaco on 8/03/17.
//

#include "Observer.h"
void Observer::attach(Subject* newPtr){
    observees[newPtr] = "";
}

void Observer::notify(Subject* obs, std::string inpt){
    observees[obs] = inpt;
    std::cout << name << " got: \"" << inpt << "\" from: " << obs->getName() << std::endl;
}

std::string Observer::getStatus(Subject* in){
    return observees[in];
}