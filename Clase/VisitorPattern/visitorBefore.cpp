#include <iostream>

using namespace std;

class Number {
public:
    virtual void add() = 0;
    virtual void count() = 0;
    virtual void substract() = 0;
    virtual void presentacion() = 0;
};

class Integer : public Number {
    static int countInts;
public:
    void add() {
        countInts++;
    }

    void substract() {
        countInts--;
    }

    void count() {
        cout << countInts;
    }

    void presentacion() {
      cout << "I am Integer\n";
    }

};

int Integer::countInts=0;

class Double : public Number {
    static int countDouble;
public:
    void add() {
        countDouble++;
    }

    void substract() {
        countInts--;
    }

    void count() {
        cout << countInts;
    }

    void presentacion() {
      cout << "I am Double\n";
    }
};

int Double::countDouble=0;

int main() {
    Number* n[] ={new Integer, new Double};

    for(int i=0; i< 5; i++) {
        for (int j = 0; j < 2; j++) {
            n[j]->add();
        }
    }

    n[1]->count();
    n[0]->count();
}
