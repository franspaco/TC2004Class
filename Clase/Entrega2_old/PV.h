//
// Created by franspaco on 29/03/17.
//

#ifndef ENTREGA2_PV_H
#define ENTREGA2_PV_H



// printer visitor
class PV {
public:
    virtual void visit(Laser* p, Documents * d) = 0;
    virtual void visit(Injection* p, Documents * d) = 0;
    virtual void visit(PDF* p, Documents * d) = 0;
    virtual void visit(Postscript* p, Documents * d) = 0;

    template <class T>
    static PV* getInstance(){
        static T instance;
        return &instance;
    }
};


// Printing Visitor
class PrintV : public PV {
    friend class PV;
private:
    PrintV(){}

public:
    void visit(Laser* p, Documents* d){
        cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(Injection* p, Documents * d) {

    }

    void visit(PDF* p, Documents * d) {

    }

    void visit(Postscript* p, Documents * d) {

    }

};

#endif //ENTREGA2_PV_H
