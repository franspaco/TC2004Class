//
// Created by franspaco on 8/02/17.
//

#ifndef PRIMERPARCIAL_VIDEOJUEGO_H
#define PRIMERPARCIAL_VIDEOJUEGO_H

#include <iostream>
#include <string>

using namespace std;

class Videojuego {
protected:
    string name;
    int no_serie;
    int rating;
    double costo;

    void setNo_setrie(int in){
        no_serie = in;
    }

public:
    Videojuego(){}
    Videojuego(string _name, int _no_serie, int _rating, double _costo) :
        name(_name), no_serie(_no_serie), rating(_rating), costo(_costo) {}

    string getName(){
        return name;
    }

    int getNo_serie() {
        return no_serie;
    }

    int getRating() {
        return rating;
    }

    double getCosto() {
        return costo;
    }

    void setName(const string &name) {
        Videojuego::name = name;
    }

    void setNo_serie(int no_serie) {
        Videojuego::no_serie = no_serie;
    }

    void setRating(int rating) {
        Videojuego::rating = rating;
    }

    void setCosto(double costo) {
        Videojuego::costo = costo;
    }

    virtual Videojuego* clonar(int new_no_serie) = 0;

    virtual void print(){
        cout << "\"" << name << "\"\n - NS: " << no_serie << "\n - Cost: " << costo << "\n - Rating: " << rating << endl;
    }

    template <class T>
    static Videojuego * factoryMethod() {
        T * t =  new T();
        return t;
    }
};

template <class Genero>
class ClonVJ : public Videojuego {
    Videojuego* clonar(int new_no_serie) {
        Videojuego * temp = new Genero(dynamic_cast<Genero&>(*this));
        cout << "NAME: " << name << endl;
        temp->setName(name);
        temp->setNo_serie(new_no_serie);
        return temp;
    }
};

class Estrategia : public ClonVJ<Estrategia> {
private:
    int dificultad;  // rating de 0 a 100
public:
    Estrategia(){};
    Estrategia(string _name, int _no_serie, int _rating, double _costo){
        name = _name;
        no_serie =_no_serie;
        rating =_rating;
        costo = _costo;
    }

    Estrategia(string _name, int _no_serie, int _rating, double _costo, int _dif){
        name = _name;
        no_serie =_no_serie;
        rating =_rating;
        costo = _costo;
        dificultad = _dif;
    }

    void print(){
        Videojuego::print();
        cout << " - Extra: " << dificultad << endl;
    }
};

class Aventura : public ClonVJ<Aventura> {
private:
    int algo1;
public:
    Aventura(){};
    Aventura(string _name, int _no_serie, int _rating, double _costo){
        name = _name;
        no_serie =_no_serie;
        rating =_rating;
        costo = _costo;
    }

    Aventura(string _name, int _no_serie, int _rating, double _costo, int _dif){
        name = _name;
        no_serie =_no_serie;
        rating =_rating;
        costo = _costo;
        algo1= _dif;
    }

    void print(){
        Videojuego::print();
        cout << " - Extra: " << algo1 << endl;
    }
};

class Aprendizaje : public ClonVJ<Aprendizaje> {
private:
    int algo1;
public:
    Aprendizaje(){};
    Aprendizaje(string _name, int _no_serie, int _rating, double _costo){
        name = _name;
        no_serie =_no_serie;
        rating =_rating;
        costo = _costo;
    }

    Aprendizaje(string _name, int _no_serie, int _rating, double _costo, int _dif){
        name = _name;
        no_serie =_no_serie;
        rating =_rating;
        costo = _costo;
        algo1 = _dif;
    }

    void print(){
        Videojuego::print();
        cout << " - Extra: " << algo1 << endl;
    }
};


#endif //PRIMERPARCIAL_VIDEOJUEGO_H
