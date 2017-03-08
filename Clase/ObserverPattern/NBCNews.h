//
// Created by franspaco on 8/03/17.
//

#ifndef OBSERVERPATTERN_NBCNEWS_H
#define OBSERVERPATTERN_NBCNEWS_H


#include "Observer.h"

class NBCNews : public Observer{
public:
    NBCNews(){
        name = "NBC News";
    }

};


#endif //OBSERVERPATTERN_NBCNEWS_H
