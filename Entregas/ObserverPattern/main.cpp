#include <iostream>
#include "Reforma.h"
#include "PenaNieto.h"
#include "DTrump.h"
#include "NBCNews.h"

int main() {

    Reforma r;
    NBCNews nbc;

    PenaNieto pn;
    DTrump dt;

    pn.attach(&r);
    dt.attach(&r);
    dt.attach(&nbc);

    pn.updateState("hello");

    dt.updateState("wall");

    std::cout << nbc.getStatus(&dt) << std::endl;

    return 0;
}