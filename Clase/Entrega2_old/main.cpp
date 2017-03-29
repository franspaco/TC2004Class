#include <iostream>

#include "Documents.h"
#include "Printers.h"

class Main {
public:
    void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters){
        for(int i = 0; i < countDocs; i++){
            for(int j = 0; j < countPrinters; j++){
                d[i]->printOn(p[i]);
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}