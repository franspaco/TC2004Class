//
// Created by franspaco on 8/02/17.
//

#ifndef PRIMERPARCIAL_INVENTARIO_H
#define PRIMERPARCIAL_INVENTARIO_H

#include <map>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

#include "Videojuego.h"

class Inventario {
private:
    Inventario() {}
    Inventario(int size) { inv.resize(size); }
    Inventario(Inventario const&) {}

    //map<int, Videojuego* > inv;
    vector<Videojuego*> inv;

    deque<Videojuego*> deleted;

public:
    static Inventario& getInstance() {
        static Inventario instance;
        return instance;
    }

    void addGame(Videojuego * in){
        inv.push_back(in);
    }

    void deleteGame(int NS){
        int indx = searchNS(NS);
        if(indx == -1)
            return;

        deleted.push_back(inv[indx]);

        if(deleted.size()>3){
            deleted.pop_front();
        }

        inv.erase(inv.begin() + indx);
    }

    void undoDelete(){
        if(deleted.size() > 0){
            Videojuego * temp = deleted.back();
            deleted.pop_back();
            inv.push_back(temp);
        }
    }

    void sortPrice(bool asc){
        if(asc){
            sort(inv.begin(),inv.end(), [](Videojuego* a, Videojuego* b) { return a->getCosto() < b->getCosto();} );
        }else{
            sort(inv.begin(),inv.end(), [](Videojuego* a, Videojuego* b) { return a->getCosto() > b->getCosto();} );
        }
        print();
    }

    int searchNS(int in){
        for(int i = 0; i < inv.size(); i++){
            if(in == inv[i]->getNo_serie()){
                return i;
            }
        }
        return -1;
    }

    int searchName(string in){
        for(int i = 0; i < inv.size(); i++){
            if(in == inv[i]->getName()){
                return i;
            }
        }
        return -1;
    }

    Videojuego * getIndex(int indx){
        return inv[indx];
    }

    Videojuego * search(string in) {
        int indx = searchName(in);
        return (indx != -1) ? inv[indx] : nullptr ;
    }

    Videojuego * search(int in){
        int indx = searchNS(in);
        return (indx != -1) ? inv[indx] : nullptr ;
    }

    int getSize(){
        return inv.size();
    }

    void print(){
        vector<Videojuego* >::iterator it;
        for(auto const &pair : inv){
            pair->print();
        }
    }

};


#endif //PRIMERPARCIAL_INVENTARIO_H
